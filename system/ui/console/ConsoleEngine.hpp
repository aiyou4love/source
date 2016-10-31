#pragma once

namespace cc {
	
	class ConsoleEngine : public IUiEngine
	{
	public:
		void showUi(const char * nName);
		void loadUi(const char * nName);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue);
		
		void closeUi(const char * nName);
		void runClose();
		void runClear();
		
		void pushClose(const char * nName);
		void clearClose();
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		CommandArgsPtr popCommandArgs();
		
		void runCommandArgs();
		
	private:
		void runRefresh();
		
	public:
		void runPreinit();
		void runLuaApi();
		void runInit();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		deque<ConsoleUiPtr> mConsoleUis;
		list<ConsoleUiPtr> mCloseUis;
		
		deque<CommandArgsPtr> mCommandArgs;
		mutex mMutex;
		
		static ConsoleEngine mConsoleEngine;
	};
	
}
