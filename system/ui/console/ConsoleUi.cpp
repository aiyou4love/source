#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ConsoleUi::runInit(const char * nName, bool nTick)
	{
		mName = nName;
		if (nTick) {
			mTick = 1;
		}
		
		UiManager& uiManager_ = UiManager::instance();
		string uiEventPath_ = uiManager_.uiEventPath(nName, EuiEngine::mConsole);
		string uiCorePath_ = uiManager_.uiCorePath(nName, EuiEngine::mConsole);
		string uiComPath_ = uiManager_.uiCommonPath(nName, EuiEngine::mConsole);
		string uiLuaPath_ = uiManager_.uiLuaPath(nName, EuiEngine::mConsole);
		string uiJsonPath_ = uiManager_.uiJsonPath(nName, EuiEngine::mConsole);
		string uiStringPath_ = uiManager_.uiStringPath(nName, EuiEngine::mConsole);
		
		this->initEvent(uiEventPath_.c_str());
		this->initUi(uiJsonPath_.c_str());
		this->initString(uiStringPath_.c_str());
		this->initCore(uiCorePath_.c_str());
		this->initCommon(uiComPath_.c_str());
		this->initLua(uiLuaPath_.c_str());
	}
	
	void ConsoleUi::runNotice(const char * nName, OrderValue& nOrderValue)
	{
		IndexValue& indexValue_ = nOrderValue.getIndexValue();
		ValuePtr& value_ = nOrderValue.getValue();
		
		auto it = mOnEvents.find(nName);
		if ( it == mOnEvents.end() ) {
			LOGE("[%s]%s", __METHOD__, nName);
			return;
		}
		mLuaThread->runCall<void, IndexValue *, ValuePtr&>(nName, &indexValue_, value_);
	}
	
	void ConsoleUi::runText()
	{
		mLuaThread->runCall<void>("showText");
	}
	
	void ConsoleUi::runShow()
	{
		mLuaThread->runCall<void>("runShow");
		
		auto it = mConsoleItems.begin();
		for ( ; it != mConsoleItems.end(); ++it ) {
			int16_t itemId_ = it->first;
			auto it1 = mHides.find(itemId_);
			if ( it1 != mHides.end() ) {
				continue;
			}
			ConsoleItemPtr& consoleItem_ = it->second;
			const char * key_ = consoleItem_->getName();
			const char * value_ = this->getText(key_);
			cout << itemId_;
			cout << ":) ";
			cout << value_ << endl;
		}
	}
	
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
	
	void ConsoleUi::coutText(const char * nText)
	{
		cout << nText;
	}
	
	void ConsoleUi::coutInt(int32_t nText)
	{
		cout << nText;
	}
	
	void ConsoleUi::hideItem(int16_t nItemId)
	{
		mHides.insert(nItemId);
	}
	
	void ConsoleUi::showItem(int16_t nItemId)
	{
		mHides.erase(nItemId);
	}
	
	void ConsoleUi::runTick()
	{
		if (2 <= mTick) {
			mLuaThread->runCall<void>("runTick");
		} else if (0 < mTick) {
			mTick++;
		} else {
			return;
		}
	}
	
	void ConsoleUi::showTick()
	{
		if (2 <= mTick) {
			mLuaThread->runCall<void>("showTick");
		}
	}
	
	void ConsoleUi::runClose()
	{
		mLuaThread->runCall<void>("runClose");
		
		mLuaThread->runClose();
		mLuaThread.reset();
		
		mConsoleItems.clear();
		mStringTables.clear();
		
		mOnEvents.clear();
		
		mHides.clear();
		
		mName = "";
		mTick = 0;
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
	
	void ConsoleUi::initCommon(const char * nPath)
	{
		mLuaThread->openFile(nPath);
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
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::printText, "printText");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::coutText, "coutText");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::coutInt, "coutInt");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::hideItem, "hideItem");
		luaEngine_.runMethod<ConsoleUi>(&ConsoleUi::showItem, "showItem");
	}
	
	ConsoleUi::ConsoleUi()
		: mName ("")
		, mLuaThread (nullptr)
		, mTick (0)
	{
		mConsoleItems.clear();
		mStringTables.clear();
		mOnEvents.clear();
		mHides.clear();
	}
	
	ConsoleUi::~ConsoleUi()
	{
		mConsoleItems.clear();
		mStringTables.clear();
		mOnEvents.clear();
		mHides.clear();
		
		mLuaThread.reset();
		
		mName = "";
		mTick = 0;
	}
#endif
	
}
