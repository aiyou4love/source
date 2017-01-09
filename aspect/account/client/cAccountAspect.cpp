#include "../../Aspect.hpp"

namespace cc {
	
#ifdef __CLIENT__
	struct EregisterUiReward
	{
		static const int16_t mBegin = 1;
		
		static const int16_t mCheckName = 1;
		static const int16_t mIsRegister = 2;
		static const int16_t mCheckPassword = 3;
		static const int16_t mRunRegister = 4;
		
		static const int16_t mEnd = 9;
	};
	
	struct EloginUiCondition
	{
		static const int16_t mBegin = 1;
		
		static const int16_t mIsLogin = 1;
		
		static const int16_t mEnd = 4;
	};
	
	struct EloginUiReward
	{
		static const int16_t mBegin = 10;
		
		static const int16_t mRunLogin = 10;
		
		static const int16_t mEnd = 14;
	};
	
	struct EenterUiReward
	{
		static const int16_t mBegin = 15;
		
		static const int16_t mAccountCancel = 15;
		static const int16_t mEnterUiInfo = 16;
		
		static const int16_t mEnd = 19;
	};
	
	struct EcreateUiReward
	{
		static const int16_t mBegin = 20;
		
		static const int16_t mRunCreate = 20;
		
		static const int16_t mEnd = 24;
	};
	
	struct EserverListUiReward
	{
		static const int16_t mBegin = 25;
		
		static const int16_t mGetAccountId = 25;
		static const int16_t mServerId = 26;
		static const int16_t mGetServerId = 27;
		
		static const int16_t mEnd = 29;
	};
	
	bool cAccountAspect::runLoginCondition(AccountConditionPtr& nAccountCondition, EntityPtr& nEntity, ValuePtr& nValue)
	{
		int16_t type_ = nAccountCondition->getType();
		int8_t param_ = nAccountCondition->getParam();
		
		if ( type_ == EloginUiCondition::mIsLogin ) {
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			return ( accountEngine_.getAccountId() > 0 );
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
		return true;
	}
	
	void cAccountAspect::runRegisterReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue)
	{
		vector<int8_t>& params_ = nAccountReward->getParams();
		int16_t type_ = nAccountReward->getType();
		
		if ( type_ == EregisterUiReward::mCheckName ) {
			string accountName_ = nValue->getString(params_[0]);
			int8_t errorCode_= stringAccount(accountName_);
			nValue->pushInt8(errorCode_);
		} else if ( type_ == EregisterUiReward::mIsRegister ) {
			string accountName_ = nValue->getString(params_[0]);
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int8_t errorCode_ = accountEngine_.isRegister(accountName_.c_str());
			nValue->pushInt8(errorCode_);
		} else if ( type_ == EregisterUiReward::mCheckPassword ) {
			string password_ = nValue->getString(params_[0]);
			int8_t errorCode_= stringPassword(password_);
			nValue->pushInt8(errorCode_);
		} else if ( type_ == EregisterUiReward::mRunRegister ) {
			string accountName_ = nValue->getString(params_[0]);
			string accountPassword_ = nValue->getString(params_[1]);
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int8_t errorCode_ = accountEngine_.runRegister(accountName_.c_str(), accountPassword_.c_str());
			nValue->pushInt8(errorCode_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	void cAccountAspect::runLoginReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue)
	{
		vector<int8_t>& params_ = nAccountReward->getParams();
		int16_t type_ = nAccountReward->getType();
		
		if ( type_ == EloginUiReward::mRunLogin ) {
			string accountName_ = nValue->getString(params_[0]);
			string accountPassword_ = nValue->getString(params_[1]);
			int16_t accountType_ = nValue->getInt16(params_[2]);
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int8_t errorCode_ = accountEngine_.runLogin(accountName_.c_str(), accountPassword_.c_str(), accountType_);
			nValue->pushInt8(errorCode_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	void cAccountAspect::runEnterReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue)
	{
		vector<int8_t>& params_ = nAccountReward->getParams();
		int16_t type_ = nAccountReward->getType();
		
		if ( type_ == EenterUiReward::mRunCancel ) {
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			accountEngine_.runCancel();
		} else if ( type_ == EenterUiReward::mEnterInfo ) {
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			const char * accountName_ = accountEngine_.getAccountName();
			int32_t roleId_ = accountEngine_.getRoleId();
			int32_t serverId_ = accountEngine_.getServerId();
			nValue->pushString(accountName_);
			nValue->pushInt32(roleId_);
			nValue->pushInt32(serverId_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	void cAccountAspect::runCreateReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue)
	{
		vector<int8_t>& params_ = nAccountReward->getParams();
		int16_t type_ = nAccountReward->getType();
		
		if ( type_ == EcreateUiReward::mRunCreate ) {
			string roleName_ = nValue->getString(params_[0]);
			int16_t roleRace_ = nValue->getInt16(params_[1]);
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int8_t errorCode_ = accountEngine_.roleCreate(roleName_.c_str(), roleRace_);
			nValue->pushInt8(errorCode_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	void cAccountAspect::runServerListReward(AccountRewardPtr& nAccountReward, EntityPtr& nEntity, ValuePtr& nValue)
	{
		vector<int8_t>& params_ = nAccountReward->getParams();
		int16_t type_ = nAccountReward->getType();
		
		if ( type_ == EserverListUiReward::mAccountId ) {
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int64_t accountId_ = accountEngine_.getAccountId();
			nValue->pushInt64(accountId_);
		} else if ( type_ == EserverListUiReward::mServerId ) {
			int32_t serverId_ = nValue->getInt32(params_[0]);
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			accountEngine_.setServerId(serverId_);
		}  else if ( type_ == EserverListUiReward::mGetServerId ) {
			cAccountEngine& accountEngine_ = cAccountEngine::instance();
			int32_t serverId_ = accountEngine_.getServerId();
			nValue->pushInt32(serverId_);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	bool cAccountAspect::runCondition(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mAccountConditions.find(nDoingId);
		if ( it == mAccountConditions.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return false;
		}
		AccountConditionPtr& accountCondition_ = it->second;
		int16_t type_ = accountCondition_->getType();
		
		if ( (type_ >= EloginUiCondition::mBegin) && (type_ <= EloginUiCondition::mEnd) ) {
			return this->runLoginCondition(accountCondition_, nEntity, nValue);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
		return false;
	}
	
	void cAccountAspect::runReward(int32_t nDoingId, EntityPtr& nEntity, ValuePtr& nValue)
	{
		auto it = mAccountRewards.find(nDoingId);
		if ( it == mAccountRewards.end() ) {
			LOGE("[%s]doingId:%d", __METHOD__, nDoingId);
			return;
		}
		AccountRewardPtr& acountReward_ = it->second;
		vector<int8_t>& params_ = acountReward_->getParams();
		int16_t type_ = acountReward_->getType();
		
		if ( (type_ >= EregisterUiReward::mBegin) && (type_ <= EregisterUiReward::mEnd) ) {
			return this->runRegisterReward(acountReward_, nEntity, nValue);
		} else if ( (type_ >= EloginUiReward::mBegin) && (type_ <= EloginUiReward::mEnd) ) {
			return this->runLoginReward(acountReward_, nEntity, nValue);
		} else if ( (type_ >= EenterUiReward::mBegin) && (type_ <= EenterUiReward::mEnd) ) {
			return this->runEnterReward(acountReward_, nEntity, nValue);
		} else if ( (type_ >= EcreateUiReward::mBegin) && (type_ <= EcreateUiReward::mEnd) ) {
			return this->runCreateReward(acountReward_, nEntity, nValue);
		} else if ( (type_ >= EserverListUiReward::mBegin) && (type_ <= EserverListUiReward::mEnd) ) {
			return this->runServerListReward(acountReward_, nEntity, nValue);
		} else {
			LOGE("[%s]type:%d", __METHOD__, type_);
		}
	}
	
	cAccountAspect& cAccountAspect::instance()
	{
		return mAccountAspect;
	}
	
	cAccountAspect::cAccountAspect()
	{
		
	}
	
	cAccountAspect::~cAccountAspect()
	{
		
	}
	
	cAccountAspect cAccountAspect::mAccountAspect;
#endif

}
