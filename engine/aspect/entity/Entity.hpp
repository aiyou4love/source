#pragma once

namespace cc {
	
	class Trigger;
	typedef SPTR<Trigger> TriggerPtr;
	class Entity : public SinkMgr
	{
	public:
		void insertProperty(int16_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr * getProperty(int16_t nPropertyId);
		
		void pushTrigger(EntityPtr& nEntity, int32_t nActionId);
		void pushTrigger(EntityPtr& nEntity, ValuePtr& nValue);
		void pushTrigger(EntityPtr& nEntity, SinkPtr& nSink);
		
		void runTrigger();
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		void setState(int32_t nState);
		int32_t getState();
		
		void setEntityType(int16_t nEntityType);
		int16_t getEntityType();
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int16_t, PropertyPtr> mPropertys;
		
		list<TriggerPtr> mTriggers;
		int16_t mTriggerId;
		
		int16_t mEntityType;
		
		int32_t mState;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
