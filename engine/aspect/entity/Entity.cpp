#include "../../Engine.hpp"

namespace cc {
	
	void Entity::insertProperty(int32_t nPropertyId, PropertyPtr& nProperty)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it != mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return;
		}
		mPropertys[nPropertyId] = nProperty;
	}
	
	PropertyPtr * Entity::getProperty(int32_t nPropertyId)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it == mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return nullptr;
		}
		return (&(it->second));
	}
	
	list<TriggerPtr>& Entity::getTriggers()
	{
		return mTriggers;
	}
	
	void Entity::pushValue(ValuePtr& nValue)
	{
		LKGUD<mutex> lock_(mMutex);
		mValues.push_back(nValue);
	}
	
	ValuePtr Entity::popValue()
	{
		LKGUD<mutex> lock_(mMutex);
		ValuePtr value_;
		if (mValues.size() > 0) {
			value_ = mValues.front();
			mValues.pop_front();
		}
		return value_;
	}
	
	void Entity::setState(int32_t nState)
	{
		mState = nState;
	}
	
	int32_t Entity::getState()
	{
		return mState;
	}
	
	Entity::Entity()
	{
		mPropertys.clear();
		mValues.clear();
		
		mTriggers.clear();
		
		mState = 0;
	}
	
	Entity::~Entity()
	{
		mPropertys.clear();
		mValues.clear();
		
		mTriggers.clear();
		
		mState = 0;
	}
	
}
