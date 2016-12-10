#include "../../System.hpp"

namespace cc {
	
	void UiManager::showUi(const char * nName, int8_t nType)
	{
		auto it = mUiEngines.find(nType);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]nType:%d", __METHOD__, nType);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->showUi(nName);
	}
	
	void UiManager::loadUi(const char * nName, int8_t nType)
	{
		auto it = mUiEngines.find(nType);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]nType:%d", __METHOD__, nType);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->loadUi(nName);
	}
	
	void UiManager::refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue, int8_t nType)
	{
		auto it = mUiEngines.find(nType);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]nType:%d", __METHOD__, nType);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->refreshUi(nName, nIndexValue, nValue);
	}
	
	void UiManager::closeUi(const char * nName, int8_t nType)
	{
		auto it = mUiEngines.find(nType);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]nType:%d", __METHOD__, nType);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->closeUi(nName);
	}
	
	void UiManager::runClose(int8_t nType)
	{
		auto it = mUiEngines.find(nType);
		if ( it == mUiEngines.end() ) {
			LOGE("[%s]nType:%d", __METHOD__, nType);
			return;
		}
		IUiEngine * uiEngine_ = it->second;
		uiEngine_->runClose();
	}
	
	void UiManager::registerEngine(int8_t nType, IUiEngine * nUiEngine)
	{
		mUiEngines[nType] = nUiEngine;
	}
	
	void UiManager::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		//lifeCycle_.m_tCloseBegin.connect(bind(&UiManager::runClose, this));
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
