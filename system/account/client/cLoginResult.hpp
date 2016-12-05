#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cLoginResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtrs<list<ServerItemPtr>, ServerItemPtr>(mServerItems, "mServerItems", "mServerItem");
			
			nSerialize.runStreamPtr(mRoleItem, "mRoleItem");
			
			nSerialize.runNumber(mAccountId, "mAccountId");
			nSerialize.runNumber(mAuthority, "mAuthority");
			
			UpintEngine& upintEngine_ = UpintEngine::instance();
			upintEngine_.headSerialize(nSerialize, nName);
			upintEngine_.runSave();
			
			ServerEngine& serverEngine_ = ServerEngine::instance();
			auto it = mServerItems.begin();
			for ( ; it != mServerItems.end(); ++it ) {
				ServerItemPtr& serverItem_ = (*it);
				serverEngine_.pushServerItem(serverItem_);
			}
			serverEngine_.runSave();
		}
		
		const char * streamName();
		const char * streamUrl();
		
		ServerItemPtr& getServerItem();
		RoleItemPtr& getRoleItem();
		
		int64_t getAccountId();
		int16_t getAuthority();
		
		cLoginResult();
		~cLoginResult();
		
	private:
		list<ServerItemPtr> mServerItems;
		RoleItemPtr mRoleItem;
		
		int64_t mAccountId;
		int16_t mAuthority;
	};
	typedef SPTR<cLoginResult> cLoginResultPtr;
#endif
	
}
