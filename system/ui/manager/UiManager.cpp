#include "../../System.hpp"

namespace cc {
	
	void UiManager::topScene(UiName& nName)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->topScene(nName);
	}
	
	void UiManager::refreshScene(UiName& nName)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->refreshScene(nName);
	}
	
	void UiManager::backScene(UiName& nName)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->backScene(nName);
	}
	
	void UiManager::loadUi(UiName& nName)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->loadUi(nName);
	}
	
	void UiManager::noticeUi(UiName& nName, OrderValue& nOrderValue)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->noticeUi(nName, nOrderValue);
	}
	
	void UiManager::closeUi(UiName& nName)
	{
		int8_t engine_ = nName.getEngine();
		
		auto it = mUiEngines.find(engine_);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]%d", __METHOD__, engine_);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->closeUi(nName);
	}
	
	string UiManager::uiEventPath(const char * nPath, int8_t nType)
	{
		const char * eventName_ = this->getUiEventName(nType);
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		return workDirectory_.getUiPath(nPath, eventName_);
	}
	
	const char * UiManager::getUiEventName(int8_t nType)
	{
		if (EuiEngine::mConsole == nType) {
			return "/event.con.json";
		} else if (EuiEngine::mCocos2dx == nType) {
			return "/event.2dx.json";
		} else if (EuiEngine::mUE4 == nType) {
			return "/event.ue4.json";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/event.json";
		}
	}
	
	string UiManager::uiJsonPath(const char * nPath, int8_t nType)
	{
		const char * jsonName_ = this->getUiJsonName(nType);
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		return workDirectory_.getUiPath(nPath, jsonName_);
	}
	
	const char * UiManager::getUiJsonName(int8_t nType)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		
		if (EuiEngine::mConsole == nType) {
			if (workDirectory_.isJson()) {
				return "/ui.con.json";
			} else {
				return "/ui.con.xml";
			}
		} else if (EuiEngine::mCocos2dx == nType) {
			if (workDirectory_.isJson()) {
				return "/ui.2dx.json";
			} else {
				return "/ui.2dx.xml";
			}
		} else if (EuiEngine::mUE4 == nType) {
			if (workDirectory_.isJson()) {
				return "/ui.ue4.json";
			} else {
				return "/ui.ue4.xml";
			}
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			if (workDirectory_.isJson()) {
				return "/ui.json";
			} else {
				return "/ui.xml";
			}
		}
	}
	
	string UiManager::uiLuaPath(const char * nPath, int8_t nType)
	{
		const char * luaName_ = this->getUiLuaName(nType);
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		return workDirectory_.getUiPath(nPath, luaName_);
	}
	
	const char * UiManager::getUiLuaName(int8_t nType)
	{
		if (EuiEngine::mConsole == nType) {
			return "/ui.con.lua";
		} else if (EuiEngine::mCocos2dx == nType) {
			return "/ui.2dx.lua";
		} else if (EuiEngine::mUE4 == nType) {
			return "/ui.ue4.lua";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/ui.lua";
		}
	}
	
	string UiManager::uiStringPath(const char * nPath, int8_t nType)
	{
		string stringName_ = this->getUiStringName(nType);
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		return workDirectory_.getUiPath(nPath, stringName_.c_str());
	}
	
	string UiManager::getUiStringName(int8_t nType)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		
		string result_ = "/string.";
		result_ += workDirectory_.getLanguage();
		if (EuiEngine::mConsole == nType) {
			result_ += ".con.json";
		} else if (EuiEngine::mCocos2dx == nType) {
			result_ += ".2dx.json";
		} else if (EuiEngine::mUE4 == nType) {
			result_ += ".ue4.json";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			result_ += ".json";
		}
		return result_;
	}
	
	string UiManager::uiCorePath(const char * nPath, int8_t nType)
	{
		const char * coreName_ = this->getUiCoreName(nType);
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		return workDirectory_.getUiPath(nPath, coreName_);
	}
	
	const char * UiManager::getUiCoreName(int8_t nType)
	{
		if (EuiEngine::mConsole == nType) {
			return "/core.con.lua";
		} else if (EuiEngine::mCocos2dx == nType) {
			return "/core.2dx.lua";
		} else if (EuiEngine::mUE4 == nType) {
			return "/core.ue4.lua";
		} else {
			LOGE("[%s]%d", __METHOD__, nType);
			return "/core.lua";
		}
	}
	
	void UiManager::registerEngine(int8_t nType, IUiEngine * nUiEngine)
	{
		mUiEngines[nType] = nUiEngine;
	}
	
	void UiManager::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tClearEnd.connect(bind(&UiManager::runClear, this));
	}
	
	void UiManager::runClear()
	{
		mUiEngines.clear();
	}
	
	UiManager& UiManager::instance()
	{
		return mUiManager;
	}
	
	UiManager::UiManager()
	{
		mUiEngines.clear();
	}
	
	UiManager::~UiManager()
	{
		mUiEngines.clear();
	}
	
	UiManager UiManager::mUiManager;
	
}
