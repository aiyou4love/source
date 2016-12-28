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
	
	void Account::setPassword(const char * nPassword)
	{
		mPassword = nPassword;
	}
	
	const char * Account::getPassword()
	{
		return mPassword.c_str();
	}
	
	void Account::setName(const char * nName)
	{
		mName = nName;
	}
	
	const char * Account::getName()
	{
		return mName.c_str();
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
		mRoleItem->runClear();
		
		mPassword = "";
		mName = "";
		
		mType = 0;
		mId = 0;
	}
	
	Account::Account()
		: mRoleItem (new RoleItem())
		, mType (0)
		, mId (0)
		, mPassword ("")
		, mName ("")
	{
	}
	
	Account::~Account()
	{
		this->runClear();
	}
	
}
