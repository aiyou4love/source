#include "../../Engine.hpp"

namespace cc {
	
	int16_t Sink::getSinkId()
	{
		return mSinkId;
	}
	
	int16_t Sink::getSinkType()
	{
		return mSinkType;
	}
	
	int32_t Sink::getSinkValue()
	{
		return mSinkValue;
	}
	
	int32_t Sink::getActionId()
	{
		return mActionId;
	}
	
	int32_t Sink::getDeleteId()
	{
		return mDeleteId;
	}
	
	int16_t Sink::getKey()
	{
		return mSinkId;
	}
	
	bool Sink::isDefault()
	{
		return ( (0 == mSinkId) || (0 == mSinkType)
			|| (0 == mSinkValue) || (0 == mActionId) );
	}
	
	Sink::Sink()
		: mSinkType (0)
		, mSinkValue (0)
		, mSinkId (0)
		, mActionId (0)
		, mDeleteId (0)
	{
	}
	
	Sink::~Sink()
	{
		mSinkType = 0;
		mSinkValue = 0;
		mSinkId = 0;
		mActionId = 0;
		mDeleteId = 0;
	}
	
}
