#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		void setRoleItem(RoleItemPtr& nRoleItem);
		RoleItemPtr& getRoleItem();
		
		void setAuthority(int16_t nAuthority);
		int16_t getAuthority();
		
		void setType(int16_t nType);
		int16_t getType();
		
		void setId(int64_t nId);
		int64_t getId();
		
		virtual void runClear();
		
		Account();
		virtual ~Account();
		
	protected:
		RoleItemPtr mRoleItem;
		
		int16_t mAuthority;
		
		int16_t mType;
		int64_t mId;
	};
	
}
