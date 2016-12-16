#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleScene : noncopyable
	{
	public:
		void showUi(const char * nName, bool nShow);
		void loadUi(const char * nName);
		
		void refreshUi(const char * nName, OrderValue& nOrderValue, bool nShow);
		
		void closeUi(const char * nName, bool nShow);
		void clearUi(bool nShow);
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		CommandArgsPtr popCommandArgs();
		void runCommandArgs(bool nShow);
		
		void runUpdate(bool nShow);
		
		void runClose();
		void runClear();
		
		void pushClose(const char * nName);
		void clearClose();
		
		void runRefresh();
		
	public:
		ConsoleScene();
		~ConsoleScene();
		
	private:
		deque<ConsoleUiPtr> mConsoleUis;
		list<ConsoleUiPtr> mCloseUis;
		
		deque<CommandArgsPtr> mCommandArgs;
		mutex mMutex;
	};
	typedef SPTR<ConsoleScene> ConsoleScenePtr;
#endif
	
}
