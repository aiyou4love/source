#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void ServerEngine::pushServerItem(ServerItemPtr& nServerItem)
	{
		int32_t serverId_ = nServerItem->getServerId();
		if (0 == serverId_) return;
		mServerItems[serverId_] = nServerItem;
	}
	
	void ServerEngine::pushServerInfo(ServerInfoPtr& nServerInfo)
	{
		int32_t serverNo_ = nServerInfo->getServerNo();
		if (0 == serverId_) return;
		mServerInfos[serverNo_] = nServerInfo;
	}
	
	const char * ServerEngine::getServerName(int32_t nServerId)
	{
		auto it = mServerItems.find(nServerId);
		if ( it == mServerItems.end() ) {
			LOGE("[%s]%d", __METHOD__, nServerId);
			return "";
		}
		ServerItemPtr& serverItem_ = it->second;
		return serverItem_->getServerName();
	}
	
	string ServerEngine::getServerListInfo()
	{
		LuaWriter luaWriter_;
		luaWriter_.luaMapStreamPtrs<map<int32_t, ServerItemPtr>, ServerItemPtr>(mServerItems, "mServerList");
		return luaWriter_.getLuaValue();
	}
	
	void ServerEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&ServerEngine::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&ServerEngine::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&ServerEngine::runClear, this));
	}
	
	void ServerEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<ServerEngine>(this, saveUrl(), saveName());
	}
	
	void ServerEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<ServerEngine>(this, saveUrl(), saveName());
	}
	
	void ServerEngine::runClear()
	{
		mServerInfos.clear();
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
	
	const char * ServerEngine::saveName()
	{
		return "serverSave";
	}
	
	const char * ServerEngine::saveUrl()
	{
		return "serverSave.json";
	}
	
	ServerEngine& ServerEngine::instance()
	{
		return mServerEngine;
	}
	
	ServerEngine::ServerEngine()
	{
		mServerInfos.clear();
		mServerItems.clear();
	}
	
	ServerEngine::~ServerEngine()
	{
		mServerInfos.clear();
		mServerItems.clear();
	}
	
	ServerEngine ServerEngine::mServerEngine;
#endif
	
}
