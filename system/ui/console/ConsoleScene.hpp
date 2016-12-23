#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleScene : noncopyable
	{
	public:
		void loadUi(const char * nName, bool nTick);
		
		void noticeUi(const char * nName, OrderValue& nOrderValue);
		
		void closeUi(const char * nName);
		
		void refreshUi();
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		CommandArgsPtr popCommandArgs();
		void runCommandArgs();
		
		void runUpdate();
		void runTick();
		
		void runClose();
		void runClear();
		
		ConsoleScene();
		~ConsoleScene();
		
	private:
		deque<ConsoleUiPtr> mConsoleUis;
		
		int32_t mTickTime;
		
		deque<CommandArgsPtr> mCommandArgs;
		mutex mMutex;
	};
	typedef SPTR<ConsoleScene> ConsoleScenePtr;
#endif
	
}
