#pragma once

namespace cc {
	
	class Account : public Entity
	{
	public:
		void setRoleItem(RoleItemPtr& nRoleItem);
		RoleItemPtr& getRoleItem();
		
		void setPassword(const char * nPassword);
		const char * getPassword();
		
		void setName(const char * nName);
		const char * getName();
		
		void setType(int16_t nType);
		int16_t getType();
		
		void setId(int64_t nId);
		int64_t getId();
		
		void runClear();
		
		Account();
		virtual ~Account();
		
	protected:
		RoleItemPtr mRoleItem;
		
		string mPassword;
		string mName;
		
		int16_t mType;
		int64_t mId;
	};
	
}
