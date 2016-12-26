#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * mRoleListUrl = "roleList";
	int8_t RoleEngine::runRoleList(int64_t nAccountId)
	{
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getServerTime();
		int64_t seconds_ = nowTime_ - mUpdateTime;
		if ( (mUpdateTime > 0) && (seconds_ < 43200) ) {
			return 1;
		}
		
		UrlMgr& urlMgr_ = UrlMgr::instance();
		
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		const char * operatorName_ = workDirectory_.getOperatorName();
		int16_t versionNo_ = workDirectory_.getVersionNo();
		
		cRoleListResult roleListResult_;
		if ( !urlMgr_.runStream(roleListResult_, mRoleListUrl, roleListResult_.streamName(),
			operatorName_, versionNo_, nAccountId) ) {
			return 0;
		}
		
		ServerEngine& serverEngine_ = ServerEngine::instance();
		list<ServerItemPtr>& serverItems_ = roleListResult_.getServerItems();
		auto it1 = serverItems_.begin();
		for ( ; it1 != serverItems_.end(); ++it1 ) {
			ServerItemPtr& serverItem_ = (*it1);
			if ( serverItem_->isDefault() ) {
				return 2;
			}
			serverEngine_.pushServerItem(serverItem_);
		}
		serverEngine_.runSave();
		
		list<RoleItemPtr>& roleItems_ = roleListResult_.getRoleItems();
		auto it0 = roleItems_.begin();
		for ( ; it0 != roleItems_.end(); ++it0 ) {
			RoleItemPtr& roleItem_ = (*it0);
			if ( roleItem_->isDefault() ) {
				return 2;
			}
			int64_t id_ = roleItem_->getId();
			mRoleItems[id_] = roleItem_;
		}
		this->runSave();
		
		return 1;
	}
	
	string RoleEngine::getRoleInfos()
	{
		LuaWriter luaWriter_;
		luaWriter_.luaMapStreamPtrs<map<int64_t, RoleItemPtr>, RoleItemPtr>(mRoleItems, "roleItems");
		return luaWriter_.getLuaValue();
	}
	
	const char * RoleEngine::saveName()
	{
		return "roleList";
	}
	
	const char * RoleEngine::saveUrl()
	{
		return "roleList.json";
	}
	
	const char * RoleEngine::streamName()
	{
		return "roleEngine";
	}
	
	const char * RoleEngine::streamUrl()
	{
		return "roleEngine.json";
	}
	
	void RoleEngine::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&RoleEngine::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&RoleEngine::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&RoleEngine::runClear, this));
	}
	
	void RoleEngine::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<RoleEngine>(this, saveUrl(), saveName());
	}
	
	void RoleEngine::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<RoleEngine>(this, saveUrl(), saveName());
	}
	
	void RoleEngine::runClear()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	RoleEngine& RoleEngine::instance()
	{
		return mRoleEngine;
	}
	
	RoleEngine::RoleEngine()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	RoleEngine::~RoleEngine()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	RoleEngine RoleEngine::mRoleEngine;
#endif
	
}
