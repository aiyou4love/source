#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void insertProperty(int32_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr * getProperty(int32_t nPropertyId);
		
		void pushValue(ValuePtr& nValue);
		ValuePtr popValue();
		
		list<TriggerPtr>& getTriggers();
		
		void setState(int32_t nState);
		int32_t getState();
		
		Entity();
		virtual ~Entity();
		
	private:
		map<int32_t, PropertyPtr> mPropertys;
		
		list<TriggerPtr> mTriggers;
		int32_t mState;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
