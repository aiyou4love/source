#include "../../Engine.hpp"

namespace cc {
	
	NetIp * NetIpMgr::findNetIp(int16_t nAppType, int32_t nAppNo)
	{
		auto it = mNetIps.begin();
		for ( ; it != mNetIps.end(); ++it ) {
			NetIpPtr& netIp_ = it->second;
			int16_t appType_ = netIp_->getAppType();
			int32_t appNo_ = netIp_->getAppNo();
			if ( (appType_ == nAppType) 
				&& (appNo_ == nAppNo) ) {
				return ( netIp_.get() );
			}
		}
		return nullptr;
	}
	
	NetIp * NetIpMgr::findNetIp(int16_t nAppType)
	{
		auto it = mNetIps.begin();
		for ( ; it != mNetIps.end(); ++it ) {
			NetIpPtr& netIp_ = it->second;
			int16_t appType_ = netIp_->getAppType();
			if ( nAppType == appType_ ) {
				return ( netIp_.get() );
			}
		}
		return nullptr;
	}
	
	NetIp * NetIpMgr::findNetIp(int64_t nAppId)
	{
		auto it = mNetIps.find(nAppId);
		if ( it == mNetIps.end() ) {
			LOGE("[%s]%lld", __METHOD__, nAppId);
			return nullptr;
		}
		NetIpPtr& netIp_ = it->second;
		return ( netIp_.get() );
	}
	
	NetIp * NetIpMgr::findNetIp()
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
				return ( netIp_.get() );
			}
		}
		return nullptr;
	}
	
	void NetIpMgr::pushNetIp(NetIpPtr& nNetIp)
	{
		mNetIps[nNetIp->getKey()] = nNetIp;
	}
	
	void NetIpMgr::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&NetIpMgr::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&NetIpMgr::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&NetIpMgr::runClear, this));
	}
	
	void NetIpMgr::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<NetIpMgr>(this, netUrl(), netName());
	}
	
	void NetIpMgr::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<NetIpMgr>(this, netUrl(), netName());
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
