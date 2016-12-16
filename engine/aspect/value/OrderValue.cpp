#include "../../Engine.hpp"

namespace cc {
	
	IndexValue& OrderValue::getIndexValue()
	{
		return mIndexValue;
	}
	
	ValuePtr& OrderValue::getValue()
	{
		return mValue;
	}
	
	OrderValue::OrderValue(IndexValue& nIndexValue, ValuePtr& nValue)
		: mIndexValue (nIndexValue)
		, mValue (nValue)
	{
	}
	
	OrderValue::~OrderValue()
	{
	}
	
}
