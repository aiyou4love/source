#include "../../System.hpp"

namespace cc {
	
	void ConsoleUi::runCommand(CommandArgsPtr& nCommandArgs)
	{
		int16_t itemIndex_ = (int16_t)(nCommandArgs->getSelectId());
		auto it = mConsoleItems.find(itemIndex_);
		if (it == mConsoleItems.end()) {
			LOGE("[%s]%d", __METHOD__, itemIndex_);
			return;
		}
		ConsoleItemPtr& consoleItem_ = it->second;
		const char * method_ = consoleItem_->getMethod();
		int8_t type_ = consoleItem_->getType();
		if (1 == type_) {
			mLuaThread->runCall<void>(method_);
		} else if (2 == type_) {
			int8_t count_ = nCommandArgs->getCommandCount();
			if (count_ > 0) {
				const char * commandArgs_ = nCommandArgs->getCommandArgs(1);
				 mLuaThread->runCall<void, const char *>(method_, commandArgs_);
			}
		} else {
			LOGE("[%s]%d", __METHOD__, type_);
		}
	}
	
	void ConsoleUi::runInit(const char * nName)
	{
		mName = nName;
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		string uiEventPath_ = workDirectory_.uiEventPath(nName);
		string uiCorePath_ = workDirectory_.uiCorePath(nName);
		string uiLuaPath_ = workDirectory_.uiLuaPath(nName);
		string uiJsonPath_ = workDirectory_.uiJsonPath(nName);
		string uiStringPath_ = workDirectory_.uiStringPath(nName);
		
		this->initEvent(uiEventPath_.c_str());
		this->initUi(uiJsonPath_.c_str());
		this->initString(uiStringPath_.c_str());
		this->initCore(uiCorePath_.c_str());
		this->initLua(uiLuaPath_.c_str());
	}
	
	void ConsoleUi::runRefresh(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue)
	{
		auto it = mOnEvents.find(nName);
		if ( it == mOnEvents.end() ) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		mLuaThread->runCall<void, IndexValue *, ValuePtr&>(nName, &nIndexValue, nValue);
	}
	
	void ConsoleUi::runText()
	{
		mLuaThread->runCall<void>("showText");
	}
	
	void ConsoleUi::runShow()
	{
		mLuaThread->runCall<void>("runShow");
		cout << endl;
		
		auto it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			ConsoleItemPtr& consoleItem_ = it->second;
			const char * key_ = consoleItem_->getName();
			const char * value_ = this->getText(key_);
			cout << it->first;
			cout << ":) ";
			cout << value_ << endl;
		}
	}
	
	const char * ConsoleUi::getText(const char * nKey)
	{
		int32_t crcId_ = stringCrc(nKey);
		auto it = mStringTables.find(crcId_);
		if ( it == mStringTables.end() ) {
			LOGE("[%s]%s", __METHOD__, nKey);
			return "";
		}
		StringTablePtr& stringTable_ = it->second;
		return stringTable_->getValue();
	}
	
	void ConsoleUi::printText(const char * nKey)
	{
		int32_t crcId_ = stringCrc(nKey);
		auto it = mStringTables.find(crcId_);
		if ( it == mStringTables.end() ) {
			LOGE("[%s]%s", __METHOD__, nKey);
			return;
		}
		StringTablePtr& stringTable_ = it->second;
		cout << stringTable_->getValue();
	}
	
	void ConsoleUi::runClose()
	{
		mLuaThread->runCall<void>("runClose");
		
		mLuaThread->runClose();
		mLuaThread.reset();
		
		mConsoleItems.clear();
		mStringTables.clear();
		
		mOnEvents.clear();
		
		mName = "";
	}
	
	void ConsoleUi::pushClose()
	{
		ConsoleEngine& consoleEngine_ = ConsoleEngine::instance();
		consoleEngine_.pushClose(mName.c_str());
	}
	
	void ConsoleUi::initEvent(const char * nPath)
	{
		TableReader tableReader_;
		tableReader_.loadFile(nPath);
		tableReader_.selectStream(eventName());
		if ( tableReader_.runChild(eventName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, eventName());
		}
	}
	
	void ConsoleUi::initLua(const char * nPath)
	{
		mLuaThread->openFile(nPath);
		mLuaThread->runCall<void, ConsoleUi *>("runInit", this);
	}
	
	void ConsoleUi::initCore(const char * nPath)
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		mLuaThread = luaEngine_.createLuaThread(mName.c_str());
		mLuaThread->openFile(nPath);
	}
	
	void ConsoleUi::initUi(const char * nPath)
	{
		TableReader tableReader_;
		tableReader_.loadFile(nPath);
		tableReader_.selectStream(uiName());
		if ( tableReader_.runChild(uiName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, uiName());
		}
	}
	
	void ConsoleUi::initString(const char * nPath)
	{
		TableReader tableReader_;
		tableReader_.loadFile(nPath);
		tableReader_.selectStream(uiName());
		if ( tableReader_.runChild(uiName())) {
			IoReader<TableReader> ioReader_(tableReader_);
			this->headSerialize(ioReader_, stringName());
		}
	}
	
	const char * ConsoleUi::getName()
	{
		return mName.c_str();
	}
	
	const char * ConsoleUi::uiName()
	{
		return "consoleUi";
	}
	
	const char * ConsoleUi::uiUrl()
	{
		return "ui.json";
	}
	
	const char * ConsoleUi::eventName()
	{
		return "uiEvent";
	}
	
	const char * ConsoleUi::eventUrl()
	{
		return "event.json";
	}
	
	const char * ConsoleUi::stringName()
	{
		return "uiString";
	}
	
	const char * ConsoleUi::stringUrl()
	{
		return "uiString.json";
	}
	
	void ConsoleUi::runLuaApi()
	{
		LuaEngine& luaEngine_ = LuaEngine::instance();
		luaEngine_.runClass<ConsoleUi>("ConsoleUi");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::pushClose, "pushClose");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::printText, "printText");
	}
	
	ConsoleUi::ConsoleUi()
		: mName ("")
	{
		mConsoleItems.clear();
		mOnEvents.clear();
	}
	
	ConsoleUi::~ConsoleUi()
	{
		mConsoleItems.clear();
		mOnEvents.clear();
		
		mName = "";
	}
	
}
