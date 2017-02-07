#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleList : noncopyable
	{
	public:
		RoleItem * getRoleItem(int32_t nServerId);
		void pushRoleItem(RoleItemPtr& nRoleItem);
		
		int8_t runRoleList(int64_t nAccountId);
		string getListInfos();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
				nSerialize.runNumber(mUpdateTime, "updateTime");
			} else if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
				
				ServerEngine& serverEngine_ = ServerEngine::instance();
				serverEngine_.headSerialize(nSerialize, serverEngine_.streamName());
				serverEngine_.runSave();
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * saveName();
		const char * saveUrl();
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		static cRoleList& instance();
		
		cRoleList();
		~cRoleList();
		
	private:
		map<int64_t, RoleItemPtr> mRoleItems;
		int64_t mUpdateTime;
		
		static cRoleList mRoleList;
	};
#endif
	
}
