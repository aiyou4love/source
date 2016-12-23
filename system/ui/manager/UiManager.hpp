#pragma once

namespace cc {
	
	class UiManager : noncopyable
	{
	public:
		void topScene(UiName& nName);
		void refreshScene(UiName& nName);
		void backScene(UiName& nName);
		
		void loadUi(UiName& nName);
		
		void noticeUi(UiName& nName, OrderValue& nOrderValue);
		
		void closeUi(UiName& nName);
		
		string uiEventPath(const char * nPath, int8_t nType);
		const char * getUiEventName(int8_t nType);
		string uiJsonPath(const char * nPath, int8_t nType);
		const char * getUiJsonName(int8_t nType);
		string uiLuaPath(const char * nPath, int8_t nType);
		const char * getUiLuaName(int8_t nType);
		string uiStringPath(const char * nPath, int8_t nType);
		string getUiStringName(int8_t nType);
		string uiCorePath(const char * nPath, int8_t nType);
		const char * getUiCoreName(int8_t nType);
		
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
