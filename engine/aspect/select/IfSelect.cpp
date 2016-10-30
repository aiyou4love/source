#include "../../Engine.hpp"

namespace cc {
	
	void IfSelect::runIfSelect(EntityPtr& nEntity, ValuePtr& nValue)
	{
		WorkDirectory& workDirectory_ = WorkDirectory::instance();
		if ( workDirectory_.getAppType() != mAppType ) {
			LOGE("[%s]%d", __METHOD__, mIfSelectId);
			return;
		}
		if ( mIsIndex && (!nValue->checkValue(mIndexs)) ) {
			LOGE("[%s]%d", __METHOD__, mIfSelectId);
			return;
		}
		auto it = mSelectors.begin();
		for ( ; it != mSelectors.end(); ++it ) {
			SelectorPtr& selector_ = it->second;
			if (selector_->runSelect(nEntity, nValue)) {
				break;
			}
		}
	}
	
	bool IfSelect::isDefault()
	{
		return ( (0 == mIfSelectId) || (0 == mAppType) || (mSelectors.size() <= 0) );
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
