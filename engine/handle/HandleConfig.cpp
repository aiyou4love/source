#include "../Engine.hpp"

namespace cc {
	
	list<int16_t>& HandleConfig::getIndexs()
	{
		return mIndexs;
	}
	
	const char * HandleConfig::getName()
	{
		return mName.c_str();
	}
	
	bool HandleConfig::isDefault()
	{
		return ( ("" == mName) || (0 == mIndexs.size()) );
	}
	
	const char * HandleConfig::getKey()
	{
		return mName.c_str();
	}
	
	HandleConfig::HandleConfig()
		: mName ("")
	{
		mIndexs.clear();
	}
	
	HandleConfig::~HandleConfig()
	{
		mIndexs.clear();
		mName = "";
	}
	
}
