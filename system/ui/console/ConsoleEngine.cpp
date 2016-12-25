#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleEngine::topScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrent) {
			mLast1 = static_cast<int8_t>(mLast0);
			mLast0 = static_cast<int8_t>(mCurrent);
			mCurrent = scene_;
		}
	}
	
	void ConsoleEngine::clearScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if ( EuiScene::mMain == scene_ ) {
			mUiScene->runClose();
		} else if ( EuiScene::mGame == scene_ ) {
			mGameScene->runClose();
		} else {
			mExistScene->runClose();
		}
	}
	
	void ConsoleEngine::refreshScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrent) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		if ( EuiScene::mMain == scene_ ) {
			mUiScene->refreshUi();
		} else if ( EuiScene::mGame == scene_ ) {
			mGameScene->refreshUi();
		} else {
			mExistScene->refreshUi();
		}
	}
	
	void ConsoleEngine::drawScene()
	{
		if ( EuiScene::mMain == mCurrent ) {
			mUiScene->refreshUi();
		} else if ( EuiScene::mGame == mCurrent ) {
			mGameScene->refreshUi();
		} else {
			mExistScene->refreshUi();
		}
	}
	
	void ConsoleEngine::backScene(UiName& nName)
	{
		int8_t scene_ = nName.getScene();
		if (scene_ != mCurrent) {
			LOGE("[%s]", __METHOD__);
			return;
		}
		mCurrent = static_cast<int8_t>(mLast0);
		mLast0 = static_cast<int8_t>(mLast1);
		mLast1 = EuiScene::mMain;
	}
	
	void ConsoleEngine::loadUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		bool tick_ = nName.isTick();
		if ( EuiScene::mMain == scene_ ) {
			mUiScene->loadUi(name_, tick_);
		} else if ( EuiScene::mGame == scene_ ) {
			mGameScene->loadUi(name_, tick_);
		} else {
			mExistScene->loadUi(name_, tick_);
		}
	}
	
	void ConsoleEngine::noticeUi(UiName& nName, OrderValue& nOrderValue)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		if ( EuiScene::mMain == scene_ ) {
			mUiScene->noticeUi(name_, nOrderValue);
		} else if ( EuiScene::mGame == scene_ ) {
			mGameScene->noticeUi(name_, nOrderValue);
		} else {
			mExistScene->noticeUi(name_, nOrderValue);
		}
	}
	
	void ConsoleEngine::closeUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t scene_ = nName.getScene();
		if ( EuiScene::mMain == scene_ ) {
			mUiScene->closeUi(name_);
		} else if ( EuiScene::mGame == scene_ ) {
			mGameScene->closeUi(name_);
		} else {
			mExistScene->closeUi(name_);
		}
	}
	
	void ConsoleEngine::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		if ( EuiScene::mMain == mCurrent ) {
			mUiScene->pushCommandArgs(nCommandArgs);
		} else if ( EuiScene::mGame == mCurrent ) {
			mGameScene->pushCommandArgs(nCommandArgs);
		} else {
			mExistScene->pushCommandArgs(nCommandArgs);
		}
	}
	
	void ConsoleEngine::runUpdateGame()
	{
		if ( EuiScene::mGame != mCurrent ) {
			mGameScene->runUpdate(false);
		} else {
			mGameScene->runUpdate(true);
		}
	}
	
	void ConsoleEngine::runUpdateUi()
	{
		if ( EuiScene::mMain == mCurrent ) {
			mUiScene->runUpdate(true);
		} else if ( EuiScene::mGame == mCurrent ) {
			mUiScene->runUpdate(false);
		} else {
			mUiScene->runUpdate(false);
			mExistScene->runUpdate(true);
		}
	}
	
	void ConsoleEngine::runClose()
	{
		if (nullptr != mUiScene) {
			mUiScene->runClose();
		}
		if (nullptr != mGameScene) {
			mGameScene->runClose();
		}
		if (nullptr != mExistScene) {
			mExistScene->runClose();
		}
		mCurrent = EuiScene::mMain;
		mLast0 = EuiScene::mMain;
		mLast1 = EuiScene::mMain;
	}
	
	void ConsoleEngine::runClear()
	{
		if (nullptr != mUiScene) {
			mUiScene->runClear();
		}
		mUiScene.reset();
		if (nullptr != mGameScene) {
			mGameScene->runClear();
		}
		mGameScene.reset();
		if (nullptr != mExistScene) {
			mExistScene->runClear();
		}
		mExistScene.reset();
		
		mCurrent = EuiScene::mMain;
		mLast0 = EuiScene::mMain;
		mLast1 = EuiScene::mMain;
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
		
		mUiScene.reset(new ConsoleScene());
		mGameScene.reset(new ConsoleScene());
		mExistScene.reset(new ConsoleScene());
		
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
