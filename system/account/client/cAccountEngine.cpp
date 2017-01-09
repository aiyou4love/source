#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
		const char * getAccountPassword();
		const char * getAccountName();
		
		int16_t getAccountType();
		int64_t getAccountId();
	
	int32_t cAccountEngine::getServerId()
	{
		return mAccount.getServerId();
	}
	
	void cAccountEngine::runLoad()
	{
		mAccount.runLoad();
	}
	
	void cAccountEngine::runSave()
	{
		mAccount.runSave();
	}
	
	void cAccountEngine::runClear()
	{
		mAccount.runClear();
	}
	
	void cAccountEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		
		lifeCycle_.m_tLoadBegin.connect(bind(&cAccountEngine::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&cAccountEngine::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&cAccountEngine::runClear, this));
	}
	
	cAccountEngine& cAccountEngine::instance()
	{
		return mAccountEngine;
	}
	
	cAccountEngine::cAccountEngine()
	{
	}
	
	cAccountEngine::~cAccountEngine()
	{
	}
	
	cAccountEngine cAccountEngine::mAccountEngine;
#endif
	
}
