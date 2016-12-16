#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleScene;
	class ConsoleUi : noncopyable
	{
	public:
		void runCommand(CommandArgsPtr& nCommandArgs);
		
		void runInit(const char * nName);
		
		void runRefresh(const char * nName, OrderValue& nOrderValue);
		
		void runText();
		void runShow();
		
		void runClose();
		void pushClose();
		
		const char * getName();
		
		static void runLuaApi();
		
	private:
		void initEvent(const char * nPath);
		void initLua(const char * nPath);
		void initCore(const char * nPath);
		void initUi(const char * nPath);
		void initString(const char * nPath);
		
		const char * getText(const char * nKey);
		void printText(const char * nKey);
		void coutText(const char * nText);
		
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
		
		void setScene(ConsoleScene * nConsoleScene);
		
		ConsoleUi();
		~ConsoleUi();
		
	private:
		map<int16_t, ConsoleItemPtr> mConsoleItems;
		map<int32_t, StringTablePtr> mStringTables;
		
		ConsoleScene * mConsoleScene;
		
		LuaThreadPtr mLuaThread;
		set<string> mOnEvents;
		string mName;
	};
	typedef SPTR<ConsoleUi> ConsoleUiPtr;
#endif
	
}
