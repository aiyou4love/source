#include "../../Engine.hpp"

namespace cc {
	
	int32_t IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		if ( workDirectory_.getAppType() != mAppType ) {
			LOGE("[%s]1:%d", __METHOD__, mIfSelectId);
			return 0;
		}
		if ( mIsIndex && (!nValue->checkValue(mIndexs)) ) {
			LOGE("[%s]2:%d", __METHOD__, mIfSelectId);
			return 0;
		}
		auto it = mSelectors.begin();
		for ( ; it != mSelectors.end(); ++it ) {
			SelectorPtr& selector_ = it->second;
			if (selector_->runSelect(nEntity, nValue)) {
				return selector_->getRewardId();
			}
		}
		LOGE("[%s]3:%d", __METHOD__, mIfSelectId);
		return 0;
	}
	
	int32_t IfSelect::getIfSelectId()
	{
		return mIfSelectId;
	}
	
	bool IfSelect::isDefault()
	{
		return ( (0 == mIfSelectId) || (0 == mAppType)
			|| (mSelectors.size() <= 0) );
	}
	
	int32_t IfSelect::getKey()
	{
		return mIfSelectId;
	}
	
	IfSelect::IfSelect()
	{
		mSelectors.clear();
		mIndexs.clear();
		mIfSelectId = 0;
		mAppType = 0;
		mIsIndex = false;
	}
	
	IfSelect::~IfSelect()
	{
		mSelectors.clear();
		mIndexs.clear();
		mIfSelectId = 0;
		mAppType = 0;
		mIsIndex = false;
	}
	
}
