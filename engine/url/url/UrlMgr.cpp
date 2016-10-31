#include "../../Engine.hpp"

namespace cc {
	
	const char * UrlMgr::streamName()
	{
		return "urlMgr";
	}
	
	const char * UrlMgr::streamUrl()
	{
		return "urlMgr.json";
	}
	
	void UrlMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&UrlMgr::runLoad, this));
		lifeCycle_.m_tClearEnd.connect(bind(&UrlMgr::runClear, this));
	}
	
	void UrlMgr::runLoad()
	{
		TableEngine& tableEngine_ = TableEngine::instance();
		tableEngine_.runReader<UrlMgr>(this, streamUrl(), streamName());
	}
	
	void UrlMgr::runClear()
	{
		mUrlInfos.clear();
	}
	
	UrlMgr& UrlMgr::instance()
	{
		return mUrlMgr;
	}
	
	UrlMgr::UrlMgr()
	{
		mUrlInfos.clear();
	}
	
	UrlMgr::~UrlMgr()
	{
		mUrlInfos.clear();
	}
	
	UrlMgr UrlMgr::mUrlMgr;
	
}
