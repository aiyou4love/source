#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleListResult : noncopyable
	{
	public:
		list<ServerItemPtr>& getServerItems();
		list<RoleItemPtr>& getRoleItems();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runStreamPtrs<list<ServerItemPtr>, ServerItemPtr>(mServerItems, "mServerList", "mServerItem");
			nSerialize.template runStreamPtrs<list<RoleItemPtr>, RoleItemPtr>(mRoleItems, "mRoleList", "mRoleItem");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cRoleListResult();
		~cRoleListResult();
		
	private:
		list<ServerItemPtr> mServerItems;
		list<RoleItemPtr> mRoleItems;
	};
	typedef SPTR<cRoleListResult> cRoleListResultPtr;
#endif
	
}
