#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	int16_t cTaskConfig::getOpenType()
	{
		return mOpenType;
	}
	
	int32_t cTaskConfig::getOpenId()
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
	
	cTaskConfig::cTaskConfig()
		: mOpenType (0)
		, mOpenId (0)
		, mName ("")
		, mText ("")
	{
	}
	
	cTaskConfig::~cTaskConfig()
	{
		mName = "";
		mText = "";
		mOpenType = 0;
		mOpenId = 0;
	}
#endif
	
}
