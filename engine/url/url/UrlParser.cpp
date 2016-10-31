#include "../../Engine.hpp"

namespace cc {
	
	const char * UrlParser::getUrlBody()
	{
		return mUrl.c_str();
	}
	
	EurlType UrlParser::getUrlType()
	{
		return mUrlType;
	}
	
	UrlParser::UrlParser(const char * nUrl)
	{
		if ( 0 == strncmp(nUrl, "http://", 7) ) {
			mUrlType = EurlType::mHttp;
			mUrl = nUrl;
		} else if ( 0 == strncmp(nUrl, "arc://", 6) ) {
			mUrlType = EurlType::mArc;
			mUrl = nUrl + 6;
		} else if ( 0 == strncmp(nUrl, "https://", 8) ) {
			mUrlType = EurlType::mHttps;
			mUrl = nUrl;
		} else {
			LOGE("[%s]%s", __METHOD__, nUrl);
			mUrlType = EurlType::mNone;
			mUrl = "";
		}
	}
	
	UrlParser::~UrlParser()
	{
		mUrlType = EurlType::mNone;
		mUrl = "";
	}
	
}
