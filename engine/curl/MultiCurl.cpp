#include "../Engine.hpp"

namespace cc {
	
	void MultiCurl::pushHandle(BaseCurlPtr& nBaseCurl)
	{
		CURL * handle_ = nBaseCurl->getHandle();
		CURLMcode errorCode_ = curl_multi_add_handle(mHandle, handle_);
		if ( CURLM_OK != errorCode_ ) {
			LOGE("[%s]%s", __METHOD__, curl_multi_strerror(errorCode_));
			return;
		}
		mBaseCurls[(intptr_t)handle_] = nBaseCurl;
	}
	
	void MultiCurl::runHandle()
	{
		CURLMcode errorCode_ = CURLM_OK; int handles_ = 0;
		errorCode_ = curl_multi_perform(mHandle, &handles_);
		if ( CURLM_OK != errorCode_ ) {
			LOGE("[%s]perform:%s", __METHOD__, curl_multi_strerror(errorCode_));
			return;
		}
		if ( handles_ <= 0 ) {
			return;
		}
		int maxfd_ = 0; fd_set readSet_, writeSet_, exceptSet_;
		FD_ZERO(&readSet_); FD_ZERO(&writeSet_); FD_ZERO(&exceptSet_);
		errorCode_ = curl_multi_fdset(mHandle, &readSet_, &writeSet_, &exceptSet_, &maxfd_);
		if ( CURLM_OK != errorCode_ ) {
			LOGE("[%s]fdset:%s", __METHOD__, curl_multi_strerror(errorCode_));
			return;
		}
		if ( maxfd_ <= 0 ) {
			LOGW("[%s]maxfd_:%d", __METHOD__, maxfd_);
			return;
		}
		long timeout_ = 0; 
		errorCode_ = curl_multi_timeout(mHandle, &timeout_);
		if ( CURLM_OK != errorCode_ ) {
			LOGE("[%s]timeout:%s", __METHOD__, curl_multi_strerror(errorCode_));
			return;
		}
		if ( timeout_ <= 0 ) {
			LOGE("[%s]timout no:%d", __METHOD__, timeout_);
			return;
		}
		struct timeval time_;
		time_.tv_sec = timeout_ / 1000;
		time_.tv_usec = (timeout_ % 1000) * 1000;
		if (select(maxfd_ + 1, &readSet_, &writeSet_, &exceptSet_, &time_) < 0) {
			LOGE("[%s]select:%s", __METHOD__, strerror(errno));
			return;
		}
		int queue_ = 0;
		CURLMsg * urlMsg_ = curl_multi_info_read(mHandle, &queue_);
		while ( nullptr != urlMsg_ ) {
			if (urlMsg_->msg == CURLMSG_DONE) {
				CURL * handle_ = urlMsg_->easy_handle;
				curl_multi_remove_handle(mHandle, handle_);
				auto it = mBaseCurls.find((intptr_t)handle_);
				if ( it != mBaseCurls.end() ) {
					BaseCurlPtr& baseCurl_ = it->second;
					baseCurl_->runValue();
					mBaseCurls.erase(it);
				} else {
					LOGE("[%s]curlfind", __METHOD__);
				}
			}
			urlMsg_ = curl_multi_info_read(mHandle, &queue_);
		}
	}
	
	MultiCurl::MultiCurl()
	{
		mHandle = curl_multi_init();
		
		mBaseCurls.clear();
	}
	
	MultiCurl::~MultiCurl()
	{
		curl_multi_cleanup(mHandle);
		mHandle = nullptr;
		
		mBaseCurls.clear();
	}
	
}
