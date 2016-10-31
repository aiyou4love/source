#include "../../Engine.hpp"

namespace cc {
	
	void UrlInfo::runFormat(boost::format& nFormat)
	{
		
	}
	
	int16_t UrlInfo::getDispatchId()
	{
		return mDispatchId;
	}
	
	int32_t UrlInfo::getSelectId()
	{
		return mSelectId;
	}
	
	int8_t UrlInfo::getType()
	{
		return mType;
	}
	
	bool UrlInfo::isDefault()
	{
		return ( (0 == mId) || ("" == mValue) );
	}
	
	int32_t UrlInfo::getKey()
	{
		return mId;
	}
	
	UrlInfo::UrlInfo()
		: mId (0)
		, mValue ("")
		, mTimeout (10)
		, mBody ("")
		, mType (0)
		, mSSL (false)
		, mSelectId (0)
		, mDispatchId (0)
	{
	}
	
	UrlInfo::~UrlInfo()
	{
		mTimeout = 10;
		mId = 0;
		mValue = "";
		mBody = "";
		mType = 0;
		mSSL = false;
		mSelectId = 0;
		mDispatchId = 0;
	}
	
}
