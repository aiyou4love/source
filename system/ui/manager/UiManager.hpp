#pragma once

namespace cc {
	
	class UiManager : noncopyable
	{
	public:
		void showUi(const char * nName, int8_t nType);
		void loadUi(const char * nName, int8_t nType);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue, int8_t nType);
		
		void closeUi(const char * nName, int8_t nType);
		void runClose(int8_t nType);
		
		void registerEngine(int8_t nType, IUiEngine * nUiEngine);
		
		void runPreinit();
		void runClear();
		
		static UiManager& instance();
		
		UiManager();
		~UiManager();
		
	private:
		map<int8_t, IUiEngine *> mUiEngines;
		
		static UiManager mUiManager;
	};
	
}
