#pragma once

namespace cc {
	
	class Entity : noncopyable
	{
	public:
		void insertProperty(int16_t nPropertyId, PropertyPtr& nProperty);
		PropertyPtr * getProperty(int16_t nPropertyId);
		
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
		
		int16_t mEntityType;
		
		int32_t mState;
		
		deque<ValuePtr> mValues;
		mutex mMutex;
	};
	
}
