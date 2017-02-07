#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	RoleItem * cRoleList::getRoleItem(int32_t nServerId)
	{
		auto it = mRoleItems.begin();
		for ( ; it != mRoleItems.end(); ++it ) {
			RoleItemPtr& roleItem_ = it->second;
			int32_t serverId_ = roleItem_->getServerId();
			if (serverId_ == nServerId) {
				return ( roleItem_.get() );
			}
		}
		return nullptr;
	}
	
	void cRoleList::pushRoleItem(RoleItemPtr& nRoleItem)
	{
		int64_t id_ = nRoleItem->getId();
		mRoleItems[id_] = nRoleItem;
		this->runSave();
	}
	
	const char * mRoleListUrl = "roleList";
	int8_t cRoleList::runRoleList(int64_t nAccountId)
	{
		cServerTime& serverTime_ = cServerTime::instance();
		int64_t nowTime_ = serverTime_.getLocalTime();
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
	
	string cRoleList::getListInfos()
	{
		LuaWriter luaWriter_;
		luaWriter_.luaMapStreamPtrs<map<int64_t, RoleItemPtr>, RoleItemPtr>(mRoleItems, "roleItems");
		return luaWriter_.getLuaValue();
	}
	
	const char * cRoleList::saveName()
	{
		return "roleListSave";
	}
	
	const char * cRoleList::saveUrl()
	{
		return "roleListSave.json";
	}
	
	const char * cRoleList::streamName()
	{
		return "roleList";
	}
	
	const char * cRoleList::streamUrl()
	{
		return "roleList.json";
	}
	
	void cRoleList::runPreinit()
	{
		LifeCycle& lifeCycle_ = LifeCycle::instance();
		lifeCycle_.m_tLoadBegin.connect(bind(&cRoleList::runLoad, this));
		lifeCycle_.m_tSaveBegin.connect(bind(&cRoleList::runSave, this));
		lifeCycle_.m_tClearEnd.connect(bind(&cRoleList::runClear, this));
	}
	
	void cRoleList::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cRoleList>(this, saveUrl(), saveName());
	}
	
	void cRoleList::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cRoleList>(this, saveUrl(), saveName());
	}
	
	void cRoleList::runClear()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	cRoleList& cRoleList::instance()
	{
		return mRoleList;
	}
	
	cRoleList::cRoleList()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	cRoleList::~cRoleList()
	{
		mRoleItems.clear();
		mUpdateTime = 0;
	}
	
	cRoleList cRoleList::mRoleList;
#endif
	
}
