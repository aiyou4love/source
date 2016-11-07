#include "../../Engine.hpp"

namespace cc {
	
	void BaseCurl::runCurlValue(int16_t nValueType, const char * nPath)
	{
		if (nValueType == EcurlValue::mString) {
			mCurlValue.reset(new CurlString());
		} else if (nValueType == EcurlValue::mFile) {
			mCurlValue.reset(new CurlFile(nPath));
		} else {
			LOGE("[%s]%d", __METHOD__, nValueType);
			return;
		}
		CurlFun_t curlFile_ = mCurlValue->getCurlFun();
		curl_easy_setopt(mHandle, CURLOPT_WRITEFUNCTION, curlFile_);
		void * curlValue_ = mCurlValue->getCurlValue();
		curl_easy_setopt(mHandle, CURLOPT_WRITEDATA, curlValue_);
	}
	
	void BaseCurl::setUrlInfo(UrlInfoPtr& nUrlInfo)
	{
		mUrlInfo = (&nUrlInfo);
	}
	
	void BaseCurl::setValue(ValuePtr& nValue)
	{
		mValue = nValue;
	}
	
	void BaseCurl::runValue()
	{
	#ifdef __WINDOW__
		string value_ = UTF8ToGBK(mCurlValue->getValue());
	#else
		string value_ = mCurlValue->getValue();
	#endif
		mValue->pushString(value_.c_str());
		int16_t dispatchId_ = (*mUrlInfo)->getDispatchId();
		DispatchEngine& dispatchEngine_ = DispatchEngine::instance();
		IDispatch * dispatch_ = dispatchEngine_.findDispatch(dispatchId_);
		dispatch_->pushValue(mValue);
	}
	
	void BaseCurl::runDebugInfo()
	{
		curl_easy_setopt(mHandle, CURLOPT_VERBOSE, 1L);
	}
	
	void BaseCurl::runInit(const char * nUrl)
	{
		mHandle = curl_easy_init();
		
		curl_easy_setopt(mHandle, CURLOPT_URL, nUrl);
	}
	
	bool BaseCurl::runPerform()
	{
		CURLcode curlCode_ = curl_easy_perform(mHandle);
		if(CURLE_OK != curlCode_) {
			const char * errorCode_ = curl_easy_strerror(curlCode_);
			LOGE("[%s]%s", __METHOD__, errorCode_);
			return false;
		}
		return true;
	}
	
	const char * BaseCurl::getValue()
	{
		return mCurlValue->getValue();
	}
	
	CURL * BaseCurl::getHandle()
	{
		return mHandle;
	}
	
	BaseCurl::BaseCurl()
		: mHandle (nullptr)
		, mUrlInfo (nullptr)
	{
		mCurlValue.reset();
	}
	
	BaseCurl::~BaseCurl()
	{
		mCurlValue.reset();
		mUrlInfo = nullptr;
		
		curl_easy_cleanup(mHandle);
		mHandle = nullptr;
	}
	
}
