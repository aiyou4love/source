#include "../System.hpp"

namespace cc {
	
	void ServerEngine::pushServerItem(ServerItemPtr& nServerItem)
	{
		int32_t serverId_ = nServerItem->getServerId();
		mServerItems[serverId_] = nServerItem;
	}
	
	string ServerEngine::getServerName(int32_t nServerId)
	{
		auto it = mServerItems.find(nServerId);
		if ( it == mServerItems.end() ) {
			LOGE("[%s]%d", __METHOD__, nServerId);
			return "";
		}
		ServerItemPtr& serverItem_ = it->second;
		return serverItem_->getServerName();
	}
	
	string ServerEngine::getServerInfos()
	{
		LuaWriter luaWriter_;
		luaWriter_.luaMapStreamPtrs<map<int32_t, ServerItemPtr>, ServerItemPtr>(mServerItems, "serverItems");
		return luaWriter_.getLuaValue();
	}
	
	void ServerEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ServerEngine::runLoad, this));
		lifeCycle_.m_tIniting.connect(bind(&ServerEngine::runInit, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ServerEngine::runClear, this));
	}
	
	void ServerEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<ServerEngine>(this, streamUrl(), streamName());
	}
	
	const char * mServerUrl = "serverList";
	bool ServerEngine::isInit()
	{
		if ( mServerItems.size() <= 0 ) {
			return true;
		}
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		int16_t appType_ = workDirectory_.getAppType();
		if ( EappType::mGameClient == appType_ ) {
			return false;
		}
		UpintEngine& upintEngine_ = UpintEngine::instance();
		if ( upintEngine_.isUpdate(mServerUrl) ) {
			return true;
		}
		return false;
	}
	
	void ServerEngine::initServer()
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		UrlMgr& urlMgr_ = UrlMgr::instance();
		if ( !urlMgr_.runStream(this, mServerUrl, streamName(),
			operatorName_, versionNo_) ) {
			LOGE("[%s]%s", __METHOD__, mServerUrl);
			return;
		}
		this->runSave();
		
		UpintEngine& upintEngine_ = UpintEngine::instance();
		upintEngine_.saveUpdate(mServerUrl);
	}
	
	void ServerEngine::runInit()
	{
		if ( !this->isInit() ) {
			return;
		}
		this->initServer();
	}
	
	void ServerEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<ServerEngine>(this, streamUrl(), streamName());
	}
	
	void ServerEngine::runClear()
	{
		mServerItems.clear();
	}
	
	const char * ServerEngine::streamName()
	{
		return "serverEngine";
	}
	
	const char * ServerEngine::streamUrl()
	{
		return "serverEngine.json";
	}
	
	ServerEngine& ServerEngine::instance()
	{
		return mServerEngine;
	}
	
	ServerEngine::ServerEngine()
	{
		mServerItems.clear();
	}
	
	ServerEngine::~ServerEngine()
	{
		mServerItems.clear();
	}
	
	ServerEngine ServerEngine::mServerEngine;
	
}
