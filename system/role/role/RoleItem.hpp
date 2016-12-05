#pragma once

namespace cc {
	
	class RoleItem : public Property
	{
	public:
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mServerId, "mServerId");
			nSerialize->runNumber(mRoleId, "mRoleId");
			nSerialize->runNumber(mRoleType, "mRoleType");
			nSerialize->runNumber(mRoleName, "mRoleName");
			nSerialize->runNumber(mRoleRace, "mRoleRace");
			nSerialize->runNumber(mRoleStep, "mRoleStep");
			nSerialize->runNumber(mRoleLevel, "mRoleLevel");
		}
		
		int32_t getServerId();
        int32_t getRoleId();
        int16_t getRoleType();
        const char * getRoleName();
        int16_t getRoleRace();
        int16_t getRoleStep();
        int32_t getRoleLevel();
		
		int64_t getId();
		
		int64_t getKey();
		bool isDefault();
		
		RoleItem();
		RoleItem(RoleItem& nRoleItem);
		~RoleItem();
		
	private:
		int32_t mServerId;
        int32_t mRoleId;
        int16_t mRoleType;
        string mRoleName;
        int16_t mRoleRace;
        int16_t mRoleStep;
        int32_t mRoleLevel;
	};
	typedef SPTR<RoleItem> RoleItemPtr;
	
}
