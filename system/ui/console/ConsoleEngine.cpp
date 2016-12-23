#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleEngine::topScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrentScene) {
			mLastScene = static_cast<int8_t>(mCurrentScene);
			mCurrentScene = scene_;
		}
	}
	
	void ConsoleEngine::refreshScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrentScene) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		if ( EuiScene::mGame != scene_ ) {
			auto it = mConsoleScenes.find(scene_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, scene_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->refreshUi();
		} else {
			mConsoleScene->refreshUi();
		}
	}
	
	void ConsoleEngine::backScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrentScene) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		mCurrentScene = static_cast<int8_t>(mLastScene);
		mLastScene = EuiScene::mMain;
	}
	
	void ConsoleEngine::loadUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		bool tick_ = nName.isTick();
		if ( EuiScene::mGame != scene_ ) {
			auto it = mConsoleScenes.find(scene_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, scene_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->loadUi(name_, tick_);
		} else {
			mConsoleScene->loadUi(name_, tick_);
		}
	}
	
	void ConsoleEngine::noticeUi(UiName& nName, OrderValue& nOrderValue)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		if ( EuiScene::mGame != scene_ ) {
			auto it = mConsoleScenes.find(scene_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, scene_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->noticeUi(name_, nOrderValue);
		} else {
			mConsoleScene->noticeUi(name_, nOrderValue);
		}
	}
	
	void ConsoleEngine::closeUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		if ( EuiScene::mGame != scene_ ) {
			auto it = mConsoleScenes.find(scene_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, scene_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->closeUi(name_);
		} else {
			mConsoleScene->closeUi(name_);
		}
	}
	
	void ConsoleEngine::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		if ( EuiScene::mGame != mCurrentScene ) {
			auto it = mConsoleScenes.find(mCurrentScene);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, mCurrentScene);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->pushCommandArgs(nCommandArgs);
		} else {
			mConsoleScene->pushCommandArgs(nCommandArgs);
		}
	}
	
	void ConsoleEngine::runUpdateGame()
	{
		mConsoleScene->runUpdate();
	}
	
	void ConsoleEngine::runUpdateUi()
	{
		auto it = mConsoleScenes.begin();
		for ( ; it != mConsoleScenes.end(); ++it ) {
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->runUpdate();
		}
	}
	
	void ConsoleEngine::runClose()
	{
		auto it = mConsoleScenes.begin();
		for ( ; it != mConsoleScenes.end(); ++it ) {
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->runClose();
		}
		if (nullptr != mConsoleScene) {
			mConsoleScene->runClose();
		}
		mCurrentScene = EuiScene::mMain;
		mLastScene = EuiScene::mMain;
	}
	
	void ConsoleEngine::runClear()
	{
		auto it = mConsoleScenes.begin();
		for ( ; it != mConsoleScenes.end(); ++it ) {
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->runClear();
		}
		mConsoleScenes.clear();
		
		if (nullptr != mConsoleScene) {
			mConsoleScene->runClear();
		}
		mConsoleScene.reset();
		
		mCurrentScene = EuiScene::mMain;
		mLastScene = EuiScene::mMain;
	}
	
	void ConsoleEngine::runPreinit()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		if (!workDirectory_.isConsole()) return;
		
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tRunLuaApi.connect(bind(&ConsoleEngine::runLuaApi, this));
		lifeCycle_.m_tIniting.connect(bind(&ConsoleEngine::runInit, this));
		lifeCycle_.m_tCloseBegin.connect(bind(&ConsoleEngine::runClose, this));
		lifeCycle_.m_tClearBegin.connect(bind(&ConsoleEngine::runClear, this));
	}
	
	void ConsoleEngine::runInit()
	{
		cout.imbue(locale(""));
		
		UiManager& uiManager_ = UiManager::instance();
		uiManager_.registerEngine(EuiEngine::mConsole, this);
		
		ConsoleScenePtr mainScene_(new ConsoleScene());
		mConsoleScenes[EuiScene::mMain] = mainScene_;
		ConsoleScenePtr popScene_(new ConsoleScene());
		mConsoleScenes[EuiScene::mPop] = popScene_;
		mConsoleScene.reset(new ConsoleScene());
		
		ConsoleUiUpdateClone consoleUiUpdateClone_;
		ConsoleGameUpdateClone consoleGameUpdateClone_;
		ConsoleInputClone consoleInputClone_;
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(&consoleUiUpdateClone_);
		handleEngine_.addContext(&consoleGameUpdateClone_);
		handleEngine_.addContext(&consoleInputClone_);
	}
	
	void ConsoleEngine::runLuaApi()
	{
		ConsoleUi::runLuaApi();
	}
	
	ConsoleEngine& ConsoleEngine::instance()
	{
		return mConsoleEngine;
	}
	
	ConsoleEngine::ConsoleEngine()
	{
		this->runClear();
	}
	
	ConsoleEngine::~ConsoleEngine()
	{
		this->runClear();
	}
	
	ConsoleEngine ConsoleEngine::mConsoleEngine;
#endif
	
}
