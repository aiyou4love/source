#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleScene::loadUi(const char * nName, bool nTick)
	{
		ConsoleUiPtr consoleUi_(new ConsoleUi());
		consoleUi_->runInit(nName, nTick);
		mConsoleUis.push_back(consoleUi_);
	}
	
	void ConsoleScene::noticeUi(const char * nName, OrderValue& nOrderValue)
	{
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runNotice(nName, nOrderValue);
		}
	}
	
	void ConsoleScene::closeUi(const char * nName)
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
	}
	
	void ConsoleScene::refreshUi()
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
	
	void ConsoleScene::runCommandArgs()
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
	}
	
	void ConsoleScene::runUpdate(bool nShow)
	{
		this->runCommandArgs();
		
		cServerTime& serverTime_ = cServerTime::instance();
		int32_t nowTime_ = serverTime_.getBootTime();
		if ( (nowTime_ - mTickTime) > 1 ) {
			this->runTick(nShow);
			mTickTime = nowTime_;
		}
	}
	
	void ConsoleScene::runTick(bool nShow)
	{
		if ( mConsoleUis.size() <= 0 ) {
			return;
		}
		auto it = mConsoleUis.begin();
		for ( ; it != mConsoleUis.end(); ++it ) {
			ConsoleUiPtr& consoleUi_ = (*it);
			consoleUi_->runTick();
		}
		if (nShow) {
			ConsoleUiPtr& consoleUi_ = mConsoleUis.back();
			consoleUi_->showTick();
		}
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
	
	ConsoleScene::ConsoleScene()
	{
		cServerTime& serverTime_ = cServerTime::instance();
		mTickTime = serverTime_.getBootTime();
		
		mConsoleUis.clear();
		mCommandArgs.clear();
	}
	
	ConsoleScene::~ConsoleScene()
	{
		mConsoleUis.clear();
		mCommandArgs.clear();
		
		mTickTime = 0;
	}
#endif
	
}
