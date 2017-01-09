#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cLoginResult : noncopyable
	{
	public:
		ServerItemPtr& getServerItem();
		RoleItemPtr& getRoleItem();
		
		int64_t getAccountId();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtr(mServerItem, "mServerItem");
			nSerialize.runStreamPtr(mRoleItem, "mRoleItem");
			nSerialize.runNumber(mAccountId, "mAccountId");
			
			ServerEngine& serverEngine_ = ServerEngine::instance();
			serverEngine_.pushServerItem(mServerItem);
			serverEngine_.runSave();
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cLoginResult();
		~cLoginResult();
		
	private:
		ServerItemPtr mServerItem;
		RoleItemPtr mRoleItem;
		int64_t mAccountId;
	};
	typedef SPTR<cLoginResult> cLoginResultPtr;
#endif
	
}
