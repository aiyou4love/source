#include "../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	int16_t ActivityConfig::getOpenType()
	{
		return mOpenType;
	}
	
	int32_t ActivityConfig::getOpenId()
	{
		return mOpenId;
	}
	
	const char * ActivityConfig::getName()
	{
		return mName.c_str();
	}
	
	const char * ActivityConfig::getText()
	{
		return mText.c_str();
	}
	
	int32_t ActivityConfig::getActivityId()
	{
		return mActivityId;
	}
	
	bool ActivityConfig::isDefault()
	{
		return (0 == mActivityId);
	}
	
	int32_t ActivityConfig::getKey()
	{
		return mActivityId;
	}
	
	ActivityConfig::ActivityConfig()
		: mActivityId (0)
		, mOpenType (0)
		, mOpenId (0)
		, mName ("")
		, mText ("")
	{
	}
	
	ActivityConfig::~ActivityConfig()
	{
		mActivityId = 0;
		mName = "";
		mText = "";
		mOpenType = 0;
		mOpenId = 0;
	}
#endif
	
}
