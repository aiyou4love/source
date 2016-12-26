#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	struct EroleReward
	{
		static const int16_t mGetList = 1;
		static const int16_t mGetInfo = 2;
	};
	
	void cRoleAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mRoleRewards.find(nDoingId);
		if ( it == mRoleRewards.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		RoleRewardPtr& roleReward_ = it->second;
		vector<int8_t>& params_ = roleReward_->getParams();
		int16_t type_ = roleReward_->getType();
		if (EroleReward::mGetInfo == type_) {
			RoleEngine& roleEngine_ = RoleEngine::instance();
			string roleInfos_ = roleEngine_.getRoleInfos();
			nValue->pushString(roleInfos_.c_str());
		} else if (EroleReward::mGetList == type_) {
			RoleEngine& roleEngine_ = RoleEngine::instance();
			int64_t accountId_ = nValue->getInt64(params_[0]);
			int8_t errorCode_ = roleEngine_.runRoleList(accountId_);
			nValue->pushInt8(errorCode_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	cRoleAspect& cRoleAspect::instance()
	{
		return mRoleAspect;
	}
	
	cRoleAspect::cRoleAspect()
	{
	}
	
	cRoleAspect::~cRoleAspect()
	{
	}
	
	cRoleAspect cRoleAspect::mRoleAspect;
#endif
	
}
