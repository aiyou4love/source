#include "../../System.hpp"

namespace cc {
	
	int32_t RoleItem::getServerId()
	{
		return mServerId;
	}
	
	int32_t RoleItem::getRoleId()
	{
		return mRoleId;
	}
	
	int16_t RoleItem::getRoleType()
	{
		return mRoleType;
	}
	
	const char * RoleItem::getRoleName()
	{
		return mRoleName.c_str();
	}
	
    int16_t RoleItem::getRoleRace()
	{
		return mRoleRace;
	}
	
	int16_t RoleItem::getRoleStep()
	{
		return mRoleStep;
	}
	
	int32_t RoleItem::getRoleLevel()
	{
		return mRoleLevel;
	}
	
	int64_t RoleItem::getId()
	{
		int64_t result_ = mServerId;
		result_ <<= 32;
		return (result_ | mRoleId);
	}
	
	void RoleItem::runClear()
	{
		mServerId = 0;
		mRoleId = 0;
		mRoleType = 0;
		mRoleName = "";
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
	
	int64_t RoleItem::getKey()
	{
		return getId();
	}
	
	bool RoleItem::isDefault()
	{
		return ( (0 == mServerId ) || (0 == mRoleId )
				|| (0 == mRoleType ) || ("" == mRoleName )
				|| (0 == mRoleRace ) || (0 == mRoleStep )
				|| (0 == mRoleLevel ) );
	}
	
	RoleItem::RoleItem()
		: mServerId (0)
		, mRoleId (0)
		, mRoleType (0)
		, mRoleName ("")
		, mRoleRace (0)
		, mRoleStep (0)
		, mRoleLevel (0)
	{
	}
	
	RoleItem::RoleItem(RoleItem& nRoleItem)
		: mServerId (nRoleItem.mServerId)
		, mRoleId (nRoleItem.mRoleId)
		, mRoleType (nRoleItem.mRoleType)
		, mRoleName (nRoleItem.mRoleName)
		, mRoleRace (nRoleItem.mRoleRace)
		, mRoleStep (nRoleItem.mRoleStep)
		, mRoleLevel (nRoleItem.mRoleLevel)
	{
	}
	
	RoleItem::~RoleItem()
	{
		mServerId = 0;
		mRoleId = 0;
		mRoleType = 0;
		mRoleName = "";
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
	
}
