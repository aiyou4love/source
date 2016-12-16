#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ConsoleEngine : public IUiEngine
	{
	public:
		void showUi(UiName& nName);
		void loadUi(UiName& nName);
		
		void refreshUi(UiName& nName, OrderValue& nOrderValue);
		
		void closeUi(UiName& nName);
		void clearUi(int8_t nType);
		
		void pushCommandArgs(CommandArgsPtr& nCommandArgs);
		
		void runUpdateGame();
		void runUpdateUi();
		
		void setSceneType(int8_t nSceneType);
		
		void runPreinit();
		void runLuaApi();
		void runInit();
		
		void runClose();
		void runClear();
		
		static ConsoleEngine& instance();
		
		ConsoleEngine();
		~ConsoleEngine();
		
	private:
		map<int8_t, ConsoleScenePtr> mConsoleScenes;
		ConsoleScenePtr mConsoleScene;
		atomic<int8_t> mSceneType;
		
		static ConsoleEngine mConsoleEngine;
	};
#endif
	
}
