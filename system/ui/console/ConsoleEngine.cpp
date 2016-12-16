#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleEngine::showUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t type_ = nName.getType();
		bool show_ = false;
		if (mSceneType == type_) {
			show_ = true;
		}
		if ( EuiType::mGame != type_ ) {
			auto it = mConsoleScenes.find(type_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, type_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->showUi(name_, show_);
		} else {
			mConsoleScene->showUi(name_, show_);
		}
	}
	
	void ConsoleEngine::loadUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t type_ = nName.getType();
		if ( EuiType::mGame != type_ ) {
			auto it = mConsoleScenes.find(type_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, type_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->loadUi(name_);
		} else {
			mConsoleScene->loadUi(name_);
		}
	}
	
	void ConsoleEngine::refreshUi(UiName& nName, OrderValue& nOrderValue)
	{
		const char * name_ = nName.getName();
		int8_t type_ = nName.getType();
		bool show_ = false;
		if (mSceneType == type_) {
			show_ = true;
		}
		if ( EuiType::mGame != type_ ) {
			auto it = mConsoleScenes.find(type_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, type_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->refreshUi(name_, nOrderValue, show_);
		} else {
			mConsoleScene->refreshUi(name_, nOrderValue, show_);
		}
	}
	
	void ConsoleEngine::closeUi(UiName& nName)
	{
		const char * name_ = nName.getName();
		int8_t type_ = nName.getType();
		bool show_ = false;
		if (mSceneType == type_) {
			show_ = true;
		}
		if ( EuiType::mGame != type_ ) {
			auto it = mConsoleScenes.find(type_);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, type_);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->closeUi(name_, show_);
		} else {
			mConsoleScene->closeUi(name_, show_);
		}
	}
	
	void ConsoleEngine::clearUi(int8_t nType)
	{
		bool show_ = false;
		if (mSceneType == nType) {
			show_ = true;
		}
		if ( EuiType::mGame != nType ) {
			auto it = mConsoleScenes.find(nType);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, nType);
				return;
			}
			ConsoleScenePtr& consoleScene_ = it->second;
			consoleScene_->clearUi(show_);
		} else {
			mConsoleScene->clearUi(show_);
		}
	}
	
	void ConsoleEngine::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		if ( EuiType::mGame != mSceneType ) {
			auto it = mConsoleScenes.find(mSceneType);
			if ( it == mConsoleScenes.end() ) {
				LOGE("[%s]%d", __METHOD__, mSceneType);
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
		if ( EuiType::mGame != mSceneType ) {
			mConsoleScene->runUpdate(false);
		} else {
			mConsoleScene->runUpdate(true);
		}
	}
	
	void ConsoleEngine::runUpdateUi()
	{
		auto it = mConsoleScenes.begin();
		for ( ; it != mConsoleScenes.end(); ++it ) {
			ConsoleScenePtr& consoleScene_ = it->second;
			int8_t sceneType_ = it->first;
			if (sceneType_ == mSceneType) {
				consoleScene_->runUpdate(true);
			} else {
				consoleScene_->runUpdate(false);
			}
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
		
		mSceneType = EuiType::mMain;
	}
	
	void ConsoleEngine::setSceneType(int8_t nSceneType)
	{
		mSceneType = nSceneType;
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
		
		ConsoleScenePtr gameScene_(new ConsoleScene());
		mConsoleScenes[EuiType::mGame] = gameScene_;
		ConsoleScenePtr mainScene_(new ConsoleScene());
		mConsoleScenes[EuiType::mMain] = mainScene_;
		ConsoleScenePtr endScene_(new ConsoleScene());
		mConsoleScenes[EuiType::mEnd] = endScene_;
		
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
