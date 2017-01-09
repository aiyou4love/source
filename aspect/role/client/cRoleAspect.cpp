#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	struct EroleReward
	{
		static const int16_t mGetRoleList = 1;
		static const int16_t mRoleListInfo = 2;
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
		if (EroleReward::mRoleListInfo == type_) {
			cRoleList& roleList_ = cRoleList::instance();
			string listInfos_ = roleList_.getListInfos();
			nValue->pushString(listInfos_.c_str());
		} else if (EroleReward::mGetRoleList == type_) {
			cRoleList& roleList_ = cRoleList::instance();
			int64_t accountId_ = nValue->getInt64(params_[0]);
			int8_t errorCode_ = roleList_.runRoleList(accountId_);
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
