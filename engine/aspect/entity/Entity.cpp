#include "../../Engine.hpp"

namespace cc {
	
	void Entity::insertProperty(int16_t nPropertyId, PropertyPtr& nProperty)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it != mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return;
		}
		mPropertys[nPropertyId] = nProperty;
	}
	
	PropertyPtr * Entity::getProperty(int16_t nPropertyId)
	{
		auto it = mPropertys.find(nPropertyId);
		if (it == mPropertys.end()) {
			LOGE("[%s]%d", __METHOD__, nPropertyId);
			return nullptr;
		}
		return (&(it->second));
	}
	
	void Entity::pushTrigger(EntityPtr& nEntity, int32_t nActionId)
	{
		if (nActionId <= 0) return;
		TriggerPtr trigger_(new Trigger());
		trigger_->setEntity(nEntity);
		trigger_->setActionId(nActionId);
		mTriggers.push_back(trigger_);
	}
	
	void Entity::pushTrigger(EntityPtr& nEntity, ValuePtr& nValue)
	{
		TriggerPtr trigger_(new Trigger());
		trigger_->setEntity(nEntity);
		trigger_->setValue(nValue);
		mTriggers.push_back(trigger_);
	}
	
	void Entity::pushTrigger(EntityPtr& nEntity, SinkPtr& nSink)
	{
		int32_t actionId_ = nSink->getActionId();
		int32_t deleteId_ = nSink->getDeleteId();
		this->pushTrigger(nEntity, actionId_);
		this->pushTrigger(nEntity, deleteId_);
	}
	
	void Entity::runTrigger()
	{
		if (mTriggerId > 0) {
			LOGE("[%s]%d", __METHOD__, mTriggerId);
			mTriggerId++;
			return;
		}
		mTriggerId++;
		
		SelectEngine& selectEngine_ = SelectEngine::instance();
		
		auto it = mTriggers.begin();
		for ( ; it != mTriggers.end(); ++it ) {
			TriggerPtr& trigger_ = (*it);
			EntityPtr& entity_ = trigger_->getEntity();
			ValuePtr& value_ = trigger_->getValue();
			selectEngine_.runIfSelect(entity_, value_);
		}
		
		mTriggers.clear();
		mTriggerId = 0;
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
	
	void Entity::setEntityType(int16_t nEntityType)
	{
		mEntityType = nEntityType;
	}
	
	int16_t Entity::getEntityType()
	{
		return mEntityType;
	}
	
	Entity::Entity()
	{
		mPropertys.clear();
		mValues.clear();
		
		mTriggers.clear();
		
		mTriggerId = 0;
		
		mState = 0;
		
		mEntityType = 0;
	}
	
	Entity::~Entity()
	{
		mPropertys.clear();
		mValues.clear();
		
		mTriggers.clear();
		
		mTriggerId = 0;
		
		mState = 0;
		
		mEntityType = 0;
	}
	
}
