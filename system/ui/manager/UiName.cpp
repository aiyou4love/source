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
	
	int8_t UiName::getScene()
	{
		return mScene;
	}
	
	bool UiName::isTick()
	{
		return mTick;
	}
	
	UiName::UiName()
		: mName ("")
		, mEngine (0)
		, mScene (0)
		, mTick (false)
	{
	}
	
	UiName::~UiName()
	{
		mEngine = 0;
		mName = "";
		mScene = 0;
		mTick = false;
	}
	
}
