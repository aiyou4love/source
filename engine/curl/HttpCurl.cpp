#include "../Engine.hpp"

namespace cc {
	
	#define JSONHEADER "content-type:application/json;charset=utf-8"
	#define XMLHEADER "content-type:application/xml;charset=utf-8"
	
	void HttpCurl::runHttpPost(const char * nValue)
	{
		curl_easy_setopt(mHandle, CURLOPT_POSTFIELDS, nValue);
		curl_easy_setopt(mHandle, CURLOPT_POST, 1);
	}
	
	void HttpCurl::runHttpHeader(int8_t nType)
	{
		if (1 == nType) {
			mCurlList = curl_slist_append(NULL, XMLHEADER);
			curl_easy_setopt(mHandle, CURLOPT_HTTPHEADER, mCurlList);
		} else {
			mCurlList = curl_slist_append(NULL, JSONHEADER);
			curl_easy_setopt(mHandle, CURLOPT_HTTPHEADER, mCurlList);
		}
	}
	
	void HttpCurl::freeHttpHeader()
	{
		curl_slist_free_all(mCurlList);
		mCurlList = nullptr;
	}
	
	void HttpCurl::runTimeout(int16_t nTimeout)
	{
		curl_easy_setopt(mHandle, CURLOPT_TIMEOUT, nTimeout);
		curl_easy_setopt(mHandle, CURLOPT_NOSIGNAL, 1L);
	}
	
	void HttpCurl::runSSL()
	{
		curl_easy_setopt(mHandle, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(mHandle, CURLOPT_SSL_VERIFYHOST, true);
	}
	
	HttpCurl::HttpCurl()
		: mCurlList (nullptr)
	{
	}
	
	HttpCurl::~HttpCurl()
	{
		if (nullptr != mCurlList) {
			this->freeHttpHeader();
		}
	}
	
}
