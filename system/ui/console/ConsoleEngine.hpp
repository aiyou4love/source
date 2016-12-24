#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleEngine : public IUiEngine
	{
	public:
		void topScene(UiName& nName);
		void clearScene(UiName& nName);
		void refreshScene(UiName& nName);
		void backScene(UiName& nName);
		
		void loadUi(UiName& nName);
		
		void noticeUi(UiName& nName, OrderValue& nOrderValue);
		
		void closeUi(UiName& nName);
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		
		void runUpdateGame();
		void runUpdateUi();
		
		bool isStop();
		
		void runPreinit();
		void runLuaApi();
		void runInit();
		void noticeStop();
		void noticeStart();
		
		void runClose();
		void runClear();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		map<int8_t, ConsoleScenePtr> mConsoleScenes;
		ConsoleScenePtr mConsoleScene;
		atomic<int8_t> mCurrentScene;
		atomic<int8_t> mLastScene;
		atomic<bool> mStop;
		
		static ConsoleEngine mConsoleEngine;
	};
#endif
	
}
