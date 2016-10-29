#include "../../Serialize.hpp"

namespace cc {
	
	const char * StringTable::getValue()
	{
		return mValue.c_str();
	}
	
	bool StringTable::isDefault()
	{
		return ( (0 == mId) || ("" == mValue) );
	}
	
	int32_t StringTable::getKey()
	{
		return mId;
	}
	
	StringTable::StringTable()
		: mValue ("")
		, mId (0)
	{
	}
	
	StringTable::~StringTable()
	{
		mValue = "";
		mId = 0;
	}
	
}
