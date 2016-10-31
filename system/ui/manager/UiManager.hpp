#pragma once

namespace cc {
	
	class UiManager : noncopyable
	{
	public:
		void showUi(const char * nName);
		void loadUi(const char * nName);
		
		void refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue);
		
		void closeUi(const char * nName);
		void runClose();
		
		void registerEngine(IUiEngine * nUiEngine);
		
		void runPreinit();
		void runClear();
		
		static UiManager& instance();
		
		UiManager();
		~UiManager();
		
	private:
		list<IUiEngine *> mUiEngines;
		
		static UiManager mUiManager;
	};
	
}
