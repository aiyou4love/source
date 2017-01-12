#include "../../Engine.hpp"

namespace cc {
	
	int32_t IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		if ( mIsNet && (!nValue->checkValue(mIndexs)) ) {
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
	
	bool IfSelect::isNet()
	{
		if ( mIndexs.size() >= 0 ) {
			return false;
		}
		return mIsNet;
	}
	
	void IfSelect::setAuthority(int16_t nAuthority)
	{
		mAuthority = nAuthority;
	}
	
	int16_t IfSelect::getAuthority()
	{
		return mAuthority;
	}
	
	bool IfSelect::isDefault()
	{
		return ( (0 == mIfSelectId) || (mSelectors.size() <= 0) );
	}
	
	int32_t IfSelect::getKey()
	{
		return mIfSelectId;
	}
	
	IfSelect::IfSelect()
	{
		mSelectors.clear();
		mIndexs.clear();
		mIsNet = false;
		mIfSelectId = 0;
		mAuthority = 0;
	}
	
	IfSelect::~IfSelect()
	{
		mSelectors.clear();
		mIndexs.clear();
		mIsNet = false;
		mIfSelectId = 0;
		mAuthority = 0;
	}
	
}
