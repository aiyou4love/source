#include "../../Engine.hpp"

namespace cc {
	
	NetIpPtr * NetIpMgr::findNetIp(int16_t nAppType, int32_t nAppNo)
	{
		auto it = mNetIps.begin();
		for ( ; it != mNetIps.end(); ++it ) {
			NetIpPtr& netIp_ = it->second;
			int16_t appType_ = netIp_->getAppType();
			int32_t appNo_ = netIp_->getAppNo();
			if ( (appType_ == nAppType) 
				&& (appNo_ == nAppNo) ) {
				return (&netIp_);
			}
		}
		return nullptr;
	}
	
	NetIpPtr * NetIpMgr::findNetIp(int16_t nAppType)
	{
		auto it = mNetIps.begin();
		for ( ; it != mNetIps.end(); ++it ) {
			NetIpPtr& netIp_ = it->second;
			int16_t appType_ = netIp_->getAppType();
			if ( nAppType == appType_ ) {
				return (&netIp_);
			}
		}
		return nullptr;
	}
	
	NetIpPtr * NetIpMgr::findNetIp(int64_t nAppId)
	{
		auto it = mNetIps.find(nAppId);
		if ( it == mNetIps.end() ) {
			LOGE("[%s]%lld", __METHOD__, nAppId);
			return nullptr;
		}
		NetIpPtr& netIp_ = it->second;
		return (&netIp_);
	}
	
	NetIpPtr * NetIpMgr::findNetIp()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType0_ = workDirectory_.getAppType();
		int32_t appNo0_ = workDirectory_.getAppNo();
		
		auto it = mNetIps.begin();
		for ( ; it != mNetIps.end(); ++it ) {
			NetIpPtr& netIp_ = it->second;
			int16_t appType1_ = netIp_->getAppType();
			int32_t appNo1_ = netIp_->getAppNo();
			if ( (appType1_ == appType0_) 
				&& (appNo1_ == appNo0_) ) {
				return (&netIp_);
			}
		}
		return nullptr;
	}
	
	void NetIpMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tInitBegin.connect(bind(&NetIpMgr::runInit, this));
		lifeCycle_.m_tClearEnd.connect(bind(&NetIpMgr::runClear, this));
	}
	
	const char * mNetUrl = "netList";
	void NetIpMgr::initNet()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		int16_t classifyId_ = workDirectory_.getClassifyId();
		
		if ( !urlMgr_.runStream(this, mNetUrl, netName(), operatorName_, versionNo_, classifyId_) ) {
			LOGE("[%s]%s", __METHOD__, mNetUrl);
		}
	}
	
	bool NetIpMgr::isInit()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType_ = workDirectory_.getAppType();
		if ( EappType::mGameClient == appType_ ) {
			return false;
		}
		return true;
	}
	
	void NetIpMgr::runInit()
	{
		if ( this->isInit() ) {
			this->initNet();
		}
	}
	
	void NetIpMgr::runClear()
	{
		mNetIps.clear();
	}
	
	const char * NetIpMgr::netName()
	{
		return "netUrl";
	}
	
	const char * NetIpMgr::netUrl()
	{
		return "netUrl.json";
	}
	
	NetIpMgr& NetIpMgr::instance()
	{
		return mNetIpMgr;
	}
	
	NetIpMgr::NetIpMgr()
	{
		this->runClear();
	}
	
	NetIpMgr::~NetIpMgr()
	{
		this->runClear();
	}
	
	NetIpMgr NetIpMgr::mNetIpMgr;
	
}
