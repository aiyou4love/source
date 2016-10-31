#include "../Aspect.hpp"

namespace cc {
		
	const char * LuaReward::getFunction()
	{
		return mFunction.c_str();
	}
	
	const char * LuaReward::getScript()
	{
		return mScript.c_str();
	}
	
	bool LuaReward::isDefault()
	{
		return ((0 == mIndex) || ("" == mFunction) || ("" == mScript));
	}
	
	int32_t LuaReward::getKey()
	{
		return mIndex;
	}
	
	LuaReward::LuaReward()
		: mFunction ("")
		, mScript ("")
		, mIndex (0)
	{
	}
	
	LuaReward::~LuaReward()
	{
		mFunction = "";
		mScript = "";
		mIndex = 0;
	}
	
}
