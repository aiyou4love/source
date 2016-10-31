#include "../AutoupInc.hpp"

namespace cc {
	
	void AutoupCurl::runCurlValue(CurlFun nCurlFun, void * nCurlValue)
	{
		curl_easy_setopt(mHandle, CURLOPT_WRITEFUNCTION, nCurlFun);
		curl_easy_setopt(mHandle, CURLOPT_WRITEDATA, nCurlValue);
	}
	
	void AutoupCurl::runTimeout(int16_t nTimeout)
	{
		curl_easy_setopt(mHandle, CURLOPT_TIMEOUT, nTimeout);
	}
	
	void AutoupCurl::runInit(const char * nUrl)
	{
		#define UTF8HEADER "content-type:application/json;charset=utf-8"
		mHandle = curl_easy_init();
		curl_easy_setopt(mHandle, CURLOPT_URL, nUrl);
		curl_slist * curlList_ = curl_slist_append(NULL, UTF8HEADER);
		curl_easy_setopt(mHandle, CURLOPT_HTTPHEADER, curlList_);
	}
	
	bool AutoupCurl::runPerform()
	{
		CURLcode curlCode_ = curl_easy_perform(mHandle);
		if(CURLE_OK != curlCode_) {
			const char * erro_ = curl_easy_strerror(curlCode_);
			LOGERROR("[%s]%s", __METHOD__, erro_);
			return false;
		}
		return true;
	}
	
	AutoupCurl::AutoupCurl()
		: mHandle (nullptr)
	{
	}
	
	AutoupCurl::~AutoupCurl()
	{
		curl_easy_cleanup(mHandle);
		mHandle = nullptr;
	}
	
}
