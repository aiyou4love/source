#include "../Aspect.hpp"

namespace cc {
	
	const char * LuaCondition::getFunction()
	{
		return mFunction.c_str();
	}
	
	const char * LuaCondition::getScript()
	{
		return mScript.c_str();
	}
	
	bool LuaCondition::isDefault()
	{
		return ((0 == mIndex) || ("" == mFunction) || ("" == mScript));
	}
	
	int32_t LuaCondition::getKey()
	{
		return mIndex;
	}
	
	LuaCondition::LuaCondition()
		: mFunction ("")
		, mScript("")
		, mIndex (0)
	{
	}
	
	LuaCondition::~LuaCondition()
	{
		mFunction = "";
		mScript = "";
		
		mIndex = 0;
	}
	
}
