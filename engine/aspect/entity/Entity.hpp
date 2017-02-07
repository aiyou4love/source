#pragma once

namespace cc {
	
	class Trigger;
	typedef SPTR<Trigger> TriggerPtr;
	class Entity : public SinkMgr
	{
	public:
		void insertProperty(int16_t nPropertyId, PropertyPtr& nProperty);
		Property * getProperty(int16_t nPropertyId);
		
		void pushTrigger(EntityPtr& nEntity, int32_t nActionId);
		void pushTrigger(EntityPtr& nEntity, ValuePtr& nValue);
		void pushTrigger(EntityPtr& nEntity, Sink * nSink);
		
		void runTrigger();
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		void setState(int32_t nState);
		int32_t getState();
		
		void setEntityType(int16_t nEntityType);
		int16_t getEntityType();
		
		void setAuthority(int16_t nAuthority);
		int16_t getAuthority();
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int16_t, PropertyPtr> mPropertys;
		
		list<TriggerPtr> mTriggers;
		int16_t mTriggerId;
		
		int16_t mEntityType;
		int16_t mAuthority;
		
		int32_t mState;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
