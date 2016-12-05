#include "../../System.hpp"

namespace cc {
	
	void Account::setRoleItem(RoleItemPtr& nRoleItem)
	{
		mRoleItem = nRoleItem;
	}
	
	RoleItemPtr& Account::getRoleItem()
	{
		return mRoleItem;
	}
	
	void Account::setAuthority(int16_t nAuthority)
	{
		mAuthority = nAuthority;
	}
	
	int16_t Account::getAuthority()
	{
		return mAuthority;
	}
	
	void Account::setType(int16_t nType)
	{
		mType = nType;
	}
	
	int16_t Account::getType()
	{
		return mType;
	}
	
	void Account::setId(int64_t nId)
	{
		mId = nId;
	}
	
	int64_t Account::getId()
	{
		return mId;
	}
	
	void Account::runClear()
	{
		mAuthority = 0;
		
		mType = 0;
		mId = 0;
	}
	
	Account::Account()
		: mAuthority (0)
		, mType (0)
		, mId (0)
	{
	}
	
	Account::~Account()
	{
		mAuthority = 0;
		
		mType = 0;
		mId = 0;
	}
	
}
