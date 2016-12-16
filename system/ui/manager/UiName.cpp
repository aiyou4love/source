#include "../../System.hpp"

namespace cc {
	
	const char * UiName::getName()
	{
		return mName.c_str();
	}
	
	int8_t UiName::getEngine()
	{
		return mEngine;
	}
	
	int8_t UiName::getType()
	{
		return mType;
	}
	
	UiName::UiName()
		: mName ("")
		, mEngine (0)
		, mType (0)
	{
	}
	
	UiName::~UiName()
	{
		mEngine = 0;
		mName = "";
		mType = 0;
	}
	
}
