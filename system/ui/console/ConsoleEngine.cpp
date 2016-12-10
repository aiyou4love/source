#include "../../System.hpp"

namespace cc {
	
	void ConsoleEngine::showUi(const char * nName)
	{
		this->loadUi(nName);
		this->runRefresh();
	}
	
	void ConsoleEngine::loadUi(const char * nName)
	{
		ConsoleUiPtr consoleUi_(new ConsoleUi());
		consoleUi_->runInit(nName);
		mConsoleUis.push_back(consoleUi_);
	}
	
	void ConsoleEngine::refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runRefresh(nName, nIndexValue, nValue);
		}
		this->runRefresh();
	}
	
	void ConsoleEngine::runRefresh()
	{
		//std::system("cls");
		if (mConsoleUis.empty()) {
			return;
		}
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runText();
		}
		ConsoleUiPtr& consoleUi_ = mConsoleUis.back();
		consoleUi_->runShow();
	}
	
	void ConsoleEngine::closeUi(const char * nName)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			const char * name_ = consoleUi_->getName();
			if (0 == strcmp(nName, name_)) {
				consoleUi_->runClose();
				mConsoleUis.erase(it);
				break;
			}
		}
		this->runRefresh();
	}
	
	void ConsoleEngine::runClose()
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mConsoleUis.clear();
		this->runRefresh();
	}
	
	void ConsoleEngine::runClear()
	{
		this->runClose();
		
		mCommandArgs.clear();
	}
	
	void ConsoleEngine::pushClose(const char * nName)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			const char * name_ = consoleUi_->getName();
			if (0 == strcmp(nName, name_)) {
				mCloseUis.push_back(consoleUi_);
				mConsoleUis.erase(it);
				break;
			}
		}
	}
	
	void ConsoleEngine::clearClose()
	{
		if ( mCloseUis.size() <= 0 ) {
			return;
		}
		auto it = mCloseUis.begin();
		for ( ; it != mCloseUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mCloseUis.clear();
	}
	
	void ConsoleEngine::runInit()
	{
		UiManager& uiManager_ = UiManager::instance();
		uiManager_.registerEngine(this);
		
		ConsoleUpdateClone consoleUpdateClone_;
		ConsoleInputClone consoleInputClone_;
		
		HandleEngine& handleEngine_ = HandleEngine::instance();
		handleEngine_.addContext(&consoleUpdateClone_);
		handleEngine_.addContext(&consoleInputClone_);
	}
	
	void ConsoleEngine::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		LKGUD<mutex> lock_(mMutex);
		mCommandArgs.push_back(nCommandArgs);
	}
	
	CommandArgsPtr ConsoleEngine::popCommandArgs()
	{
		LKGUD<mutex> lock_(mMutex);
		CommandArgsPtr commandArgs_;
		if (mCommandArgs.size() > 0) {
			commandArgs_ = mCommandArgs.front();
			mCommandArgs.pop_front();
		}
		return commandArgs_;
	}
	
	void ConsoleEngine::runCommandArgs()
	{
		if (mConsoleUis.empty()) {
			return;
		}
		CommandArgsPtr commandArgs_ = this->popCommandArgs();
		if (!commandArgs_) {
			return;
		}
		ConsoleUiPtr consoleUi_ = mConsoleUis.back();
		consoleUi_->runCommand(commandArgs_);
		
		this->runRefresh();
	}
	
	void ConsoleEngine::runUpdate()
	{
		this->runCommandArgs();
		this->clearClose();
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
		mConsoleUis.clear();
		mCommandArgs.clear();
		mCloseUis.clear();
	}
	
	ConsoleEngine::~ConsoleEngine()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
		mCloseUis.clear();
	}
	
	ConsoleEngine ConsoleEngine::mConsoleEngine;
	
}
