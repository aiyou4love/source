#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void insertProperty(int32_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr * getProperty(int32_t nPropertyId);
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		map<int32_t, TriggerPtr *>& getTriggers();
		void pushTrigger(TriggerPtr& nTrigger);
		void removeTrigger(int32_t nTriggerId);
		
		void setState(int32_t nState);
		int32_t getState();
		
		void setEntityType(int16_t nEntityType);
		int16_t getEntityType();
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int32_t, PropertyPtr> mPropertys;
		
		map<int32_t, TriggerPtr *> mTriggers;
		int32_t mState;
		
		int16_t mEntityType;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
