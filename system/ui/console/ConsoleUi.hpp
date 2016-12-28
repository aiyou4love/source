#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleUi : noncopyable
	{
	public:
		void runInit(const char * nName, bool nTick);
		
		void runNotice(const char * nName, OrderValue& nOrderValue);
		
		void runClose();
		
		void runText();
		void runShow();
		
		void runCommand(CommandArgsPtr& nCommandArgs);
		
		void runTick();
		void showTick();
		
		const char * getName();
		
		static void runLuaApi();
		
	private:
		void initEvent(const char * nPath);
		void initLua(const char * nPath);
		void initCore(const char * nPath);
		void initCommon(const char * nPath);
		void initUi(const char * nPath);
		void initString(const char * nPath);
		
		const char * getText(const char * nKey);
		void printText(const char * nKey);
		void coutText(const char * nText);
		void coutInt(int32_t nText);
		void hideItem(int16_t nItemId);
		void showItem(int16_t nItemId);
		
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(uiName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, ConsoleItemPtr>(mConsoleItems, "consoleItems", "consoleItem");
			} else if ( 0 == strcmp(stringName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, StringTablePtr>(mStringTables, "stringTables", "stringTable");
			} else if ( 0 == strcmp(eventName(), nName) ) {
				nSerialize.template runNumbers<string>(mOnEvents, "onEvents", "onEvent");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * uiName();
		const char * uiUrl();
		
		const char * eventName();
		const char * eventUrl();
		
		const char * stringName();
		const char * stringUrl();
		
		ConsoleUi();
		~ConsoleUi();
		
	private:
		map<int16_t, ConsoleItemPtr> mConsoleItems;
		map<int32_t, StringTablePtr> mStringTables;
		
		set<int16_t> mHides;
		
		LuaThreadPtr mLuaThread;
		set<string> mOnEvents;
		string mName;
		int8_t mTick;
	};
	typedef SPTR<ConsoleUi> ConsoleUiPtr;
#endif
	
}
