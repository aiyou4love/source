#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleScene::showUi(const char * nName, bool nShow)
	{
		this->loadUi(nName);
		if (nShow) {
			this->runRefresh();
		}
	}
	
	void ConsoleScene::loadUi(const char * nName)
	{
		ConsoleUiPtr consoleUi_(new ConsoleUi());
		consoleUi_->setScene(this);
		consoleUi_->runInit(nName);
		mConsoleUis.push_back(consoleUi_);
	}
	
	void ConsoleScene::refreshUi(const char * nName, OrderValue& nOrderValue, bool nShow)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runRefresh(nName, nOrderValue);
		}
		if (nShow) {
			this->runRefresh();
		}
	}
	
	void ConsoleScene::runRefresh()
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
	
	void ConsoleScene::closeUi(const char * nName, bool nShow)
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
		if (nShow) {
			this->runRefresh();
		}
	}
	
	void ConsoleScene::clearUi(bool nShow)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mConsoleUis.clear();
		if (nShow) {
			this->runRefresh();
		}
	}
	
	void ConsoleScene::pushCommandArgs(CommandArgsPtr& nCommandArgs)
	{
		LKGUD<mutex> lock_(mMutex);
		mCommandArgs.push_back(nCommandArgs);
	}
	
	CommandArgsPtr ConsoleScene::popCommandArgs()
	{
		LKGUD<mutex> lock_(mMutex);
		CommandArgsPtr commandArgs_;
		if (mCommandArgs.size() > 0) {
			commandArgs_ = mCommandArgs.front();
			mCommandArgs.pop_front();
		}
		return commandArgs_;
	}
	
	void ConsoleScene::runCommandArgs(bool nShow)
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
		
		if (nShow) {
			this->runRefresh();
		}
	}
	
	void ConsoleScene::runUpdate(bool nShow)
	{
		this->runCommandArgs(nShow);
		this->clearClose();
	}
	
	void ConsoleScene::runClose()
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runClose();
		}
		mConsoleUis.clear();
	}
	
	void ConsoleScene::runClear()
	{
		mConsoleUis.clear();
		
		mCommandArgs.clear();
	}
	
	void ConsoleScene::pushClose(const char * nName)
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
	
	void ConsoleScene::clearClose()
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
	
	ConsoleScene::ConsoleScene()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
		mCloseUis.clear();
	}
	
	ConsoleScene::~ConsoleScene()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
		mCloseUis.clear();
	}
#endif
	
}
