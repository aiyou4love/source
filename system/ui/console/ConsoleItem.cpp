#include "../../System.hpp"

namespace cc {
	
#ifdef __CLIENT__
	const char * ConsoleItem::getMethod()
	{
		return mMethod.c_str();
	}
	
	const char * ConsoleItem::getName()
	{
		return mName.c_str();
	}
	
	int8_t ConsoleItem::getType()
	{
		return mType;
	}
	
	bool ConsoleItem::isDefault()
	{
		return ( (0 == mIndex) || (0 == mType) || ("" == mName) );
	}
	
	int16_t ConsoleItem::getKey()
	{
		return mIndex;
	}
	
	ConsoleItem::ConsoleItem()
		: mMethod ("")
		, mType (0)
		, mIndex (0)
		, mName ("")
	{
	}
	
	ConsoleItem::~ConsoleItem()
	{
		mMethod = "";
		mType = 0;
		mIndex = 0;
		mName = "";
	}
#endif
	
}
