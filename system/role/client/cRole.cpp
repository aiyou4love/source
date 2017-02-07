#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cRole::setRoleItem(RoleItemPtr& nRoleItem)
	{
		mServerId = nRoleItem->getServerId();
		mRoleId = nRoleItem->getRoleId();
		mRoleType = nRoleItem->getRoleType();
		mRoleName = nRoleItem->getRoleName();
		mRoleRace = nRoleItem->getRoleRace();
		mRoleStep = nRoleItem->getRoleStep();
		mRoleLevel = nRoleItem->getRoleLevel();
	}
	
	void cRole::setRoleItem(RoleItem * nRoleItem)
	{
		mServerId = nRoleItem->getServerId();
		mRoleId = nRoleItem->getRoleId();
		mRoleType = nRoleItem->getRoleType();
		mRoleName = nRoleItem->getRoleName();
		mRoleRace = nRoleItem->getRoleRace();
		mRoleStep = nRoleItem->getRoleStep();
		mRoleLevel = nRoleItem->getRoleLevel();
	}
	
	int32_t cRole::getServerId()
	{
		return mServerId;
	}
	
	int32_t cRole::getRoleId()
	{
		return mRoleId;
	}
	
	int16_t cRole::getRoleType()
	{
		return mRoleType;
	}
	
	const char * cRole::getRoleName()
	{
		return mRoleName.c_str();
	}
	
    int16_t cRole::getRoleRace()
	{
		return mRoleRace;
	}
	
	int16_t cRole::getRoleStep()
	{
		return mRoleStep;
	}
	
	int32_t cRole::getRoleLevel()
	{
		return mRoleLevel;
	}
	
	int64_t cRole::getId()
	{
		return linkInt32(mServerId, mRoleId);
	}
	
	void cRole::runClear()
	{
		mServerId = 0;
		mRoleId = 0;
		mRoleType = 0;
		mRoleName = "";
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
	
	int64_t cRole::getKey()
	{
		return linkInt32(mServerId, mRoleId);
	}
	
	bool cRole::isDefault()
	{
		return ( (0 == mServerId ) || (0 == mRoleId )
				|| (0 == mRoleType ) || ("" == mRoleName )
				|| (0 == mRoleRace ) || (0 == mRoleStep )
				|| (0 == mRoleLevel ) );
	}
	
	cRole::cRole()
		: mServerId (0)
		, mRoleId (0)
		, mRoleType (0)
		, mRoleName ("")
		, mRoleRace (0)
		, mRoleStep (0)
		, mRoleLevel (0)
	{
	}
	
	cRole::~cRole()
	{
		mServerId = 0;
		mRoleId = 0;
		mRoleType = 0;
		mRoleName = "";
		mRoleRace = 0;
		mRoleStep = 0;
		mRoleLevel = 0;
	}
#endif
	
}
