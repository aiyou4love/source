#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleEngine : public IUiEngine
	{
	public:
		void topScene(UiName& nName);
		void clearScene(UiName& nName);
		void refreshScene(UiName& nName);
		void drawScene();
		void backScene(UiName& nName);
		
		void loadUi(UiName& nName);
		
		void noticeUi(UiName& nName, OrderValue& nOrderValue);
		
		void closeUi(UiName& nName);
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		
		void runUpdateGame();
		void runUpdateUi();
		
		void runPreinit();
		void runLuaApi();
		void runInit();
		
		void runClose();
		void runClear();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		ConsoleScenePtr mUiScene;
		ConsoleScenePtr mGameScene;
		ConsoleScenePtr mExistScene;
		
		atomic<int8_t> mCurrent;
		atomic<int8_t> mLast0;
		atomic<int8_t> mLast1;
		
		static ConsoleEngine mConsoleEngine;
	};
#endif
	
}
