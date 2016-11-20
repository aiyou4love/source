#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	int16_t cTaskConfig::getOpenType()
	{
		return mOpenType;
	}
	
	int16_t cTaskConfig::getOpenId()
	{
		return mOpenId;
	}
	
	const char * cTaskConfig::getName()
	{
		return mName.c_str();
	}
	
	const char * cTaskConfig::getText()
	{
		return mText.c_str();
	}
	
	TaskConfig::TaskConfig()
		: mOpenType (0)
		, mOpenId (0)
		, mName ("")
		, mText ("")
	{
	}
	
	TaskConfig::~TaskConfig()
	{
		mName = "";
		mText = "";
		mOpenType = 0;
		mOpenId = 0;
	}
#endif
	
}
