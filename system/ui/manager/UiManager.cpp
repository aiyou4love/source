#include "../../System.hpp"

namespace cc {
	
	void UiManager::showUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->showUi(nName);
		}
	}
	
	void UiManager::loadUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->loadUi(nName);
		}
	}
	
	void UiManager::refreshUi(const char * nName, IndexValue& nIndexValue, ValuePtr& nValue)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->refreshUi(nName, nIndexValue, nValue);
		}
	}
	
	void UiManager::closeUi(const char * nName)
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->closeUi(nName);
		}
	}
	
	void UiManager::runClose()
	{
		auto it = mUiEngines.begin();
		for ( ; it != mUiEngines.end(); ++it ) {
			IUiEngine * uiEngine_ = (*it);
			uiEngine_->runClose();
		}
	}
	
	void UiManager::registerEngine(IUiEngine * nUiEngine)
	{
		mUiEngines.push_back(nUiEngine);
	}
	
	void UiManager::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tCloseBegin.connect(bind(&UiManager::runClose, this));
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
