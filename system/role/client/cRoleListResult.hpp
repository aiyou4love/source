#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleListResult : noncopyable
	{
	public:
		list<RoleItemPtr>& getRoleItems();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtrs<list<RoleItemPtr>, RoleItemPtr>(mRoleItems, "mRoleItems", "mRoleItem");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		cRoleListResult();
		~cRoleListResult();
		
	private:
		list<RoleItemPtr> mRoleItems;
	};
	typedef SPTR<cRoleListResult> cRoleListResultPtr;
#endif
	
}
