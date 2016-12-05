#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class RoleEngine : noncopyable
	{
	public:
		int8_t runRoleList(int64_t nAccountId);
		string getRoleInfos();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
				nSerialize.runNumber(mUpdateTime, "updateTime");
			} else if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runMapStreamPtrs<int64_t, RoleItemPtr>(mRoleItems, "roleItems", "roleItem");
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
		
		static RoleEngine& instance();
		
		RoleEngine();
		~RoleEngine();
		
	private:
		map<int64_t, RoleItemPtr> mRoleItems;
		
		int64_t mUpdateTime;
		
		static RoleEngine mRoleEngine;
	};
#endif
	
}
