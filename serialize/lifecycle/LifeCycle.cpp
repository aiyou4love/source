#include "../Serialize.hpp"

namespace cc {
	
	void LifeCycle::runLuaApi()
	{
		this->m_tRunLuaApi();
	}
	
	void LifeCycle::loadBegin()
	{
		this->m_tLoadBegin();
	}
	
	void LifeCycle::loading()
	{
		this->m_tLoading();
	}
	
	void LifeCycle::loadEnd()
	{
		this->m_tLoadEnd();
	}
	
	void LifeCycle::initBegin()
	{
		this->m_tInitBegin();
	}
	
	void LifeCycle::initing()
	{
		this->m_tIniting();
	}
	
	void LifeCycle::initEnd()
	{
		this->m_tInitEnd();
	}
	
	void LifeCycle::startBegin()
	{
		this->m_tStartBegin();
	}
	
	void LifeCycle::starting()
	{
		this->m_tStarting();
	}
	
	void LifeCycle::startEnd()
	{
		this->m_tStartEnd();
	}
	
	void LifeCycle::runBegin()
	{
		this->m_tRunBegin();
	}
	
	void LifeCycle::running()
	{
		this->m_tRunning();
	}
	
	void LifeCycle::runEnd()
	{
		this->m_tRunEnd();
	}
	
	void LifeCycle::runJoin()
	{
		this->m_tRunJoin();
	}
	
	void LifeCycle::stopBegin()
	{
		this->m_tStopBegin();
	}
	
	void LifeCycle::stoping()
	{
		this->m_tStoping();
	}
	
	void LifeCycle::stopEnd()
	{
		this->m_tStopEnd();
	}
	
	void LifeCycle::saveBegin()
	{
		this->m_tSaveBegin();
	}
	
	void LifeCycle::saving()
	{
		this->m_tSaving();
	}
	
	void LifeCycle::saveEnd()
	{
		this->m_tSaveEnd();
	}
	
	void LifeCycle::closeBegin()
	{
		this->m_tCloseBegin();
	}
	
	void LifeCycle::closing()
	{
		this->m_tClosing();
	}
	
	void LifeCycle::closeEnd()
	{
		this->m_tCloseEnd();
	}
	
	void LifeCycle::clearBegin()
	{
		this->m_tClearBegin();
	}
	
	void LifeCycle::clearing()
	{
		this->m_tClearing();
	}
	
	void LifeCycle::clearEnd()
	{
		this->m_tClearEnd();
		
		m_tRunLuaApi.disconnect_all_slots();
		
		m_tLoadBegin.disconnect_all_slots();
		m_tLoading.disconnect_all_slots();
		m_tLoadEnd.disconnect_all_slots();
		
		m_tInitBegin.disconnect_all_slots();
		m_tIniting.disconnect_all_slots();
		m_tInitEnd.disconnect_all_slots();
		
		m_tStartBegin.disconnect_all_slots();
		m_tStarting.disconnect_all_slots();
		m_tStartEnd.disconnect_all_slots();
		
		m_tRunBegin.disconnect_all_slots();
		m_tRunning.disconnect_all_slots();
		m_tRunEnd.disconnect_all_slots();
		
		m_tRunJoin.disconnect_all_slots();
		
		m_tStopBegin.disconnect_all_slots();
		m_tStoping.disconnect_all_slots();
		m_tStopEnd.disconnect_all_slots();
		
		m_tSaveBegin.disconnect_all_slots();
		m_tSaving.disconnect_all_slots();
		m_tSaveEnd.disconnect_all_slots();
		
		m_tCloseBegin.disconnect_all_slots();
		m_tClosing.disconnect_all_slots();
		m_tCloseEnd.disconnect_all_slots();
		
		m_tClearBegin.disconnect_all_slots();
		m_tClearing.disconnect_all_slots();
		m_tClearEnd.disconnect_all_slots();
		
		m_tResumeBegin.disconnect_all_slots();
		m_tResuming.disconnect_all_slots();
		m_tResumeEnd.disconnect_all_slots();
		
		m_tPauseBegin.disconnect_all_slots();
		m_tPausing.disconnect_all_slots();
		m_tPauseEnd.disconnect_all_slots();
	}
	
	void LifeCycle::resumeBegin()
	{
		this->m_tResumeBegin();
	}
	
	void LifeCycle::resuming()
	{
		this->m_tResuming();
	}
	
	void LifeCycle::resumeEnd()
	{
		this->m_tResumeEnd();
	}
	
	void LifeCycle::pauseBegin()
	{
		this->m_tPauseBegin();
	}
	
	void LifeCycle::pausing()
	{
		this->m_tPausing();
	}
	
	void LifeCycle::pauseEnd()
	{
		this->m_tPauseEnd();
	}
	
	bool LifeCycle::isPause()
	{
		return mPause;
	}
	
	LifeCycle& LifeCycle::instance()
	{
		return mLifeCycle;
	}
	
	LifeCycle::LifeCycle()
		: mPause (false)
	{
	}
	
	LifeCycle::~LifeCycle()
	{
		mPause = false;
	}
	
	LifeCycle LifeCycle::mLifeCycle;
	
}
