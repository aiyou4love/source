#include "../../Engine.hpp"

namespace cc {
	
	void Trigger::setEntity(EntityPtr& nEntity)
	{
		mEntity = nEntity;
	}
	
	EntityPtr& Trigger::getEntity()
	{
		return mEntity;
	}
	
	void Trigger::setValue(ValuePtr& nValue)
	{
		mValue = nValue;
	}
	
	ValuePtr& Trigger::getValue()
	{
		return mValue;
	}
	
	Trigger::Trigger()
		: mEntity (nullptr)
		, mValue (nullptr)
	{
	}
	
	Trigger::~Trigger()
	{
		mEntity.reset();
		mValue.reset();
	}
	
}
