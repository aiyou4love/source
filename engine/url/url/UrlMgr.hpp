#pragma once

namespace cc {
	
	class UrlMgr : noncopyable
	{
	public:
		template <typename ... T1>
		void runHttp(ValuePtr& nValue, int8_t& nType, const char * nUrl, T1 ... nArgs)
		{
			int32_t urlId_ = stringCrc(nUrl);
			
			auto it = mUrlInfos.find(urlId_);
			if ( it == mUrlInfos.end() ) {
				LOGE("[%s]%s", __METHOD__, nUrl);
				return;
			}
			UrlInfoPtr& urlInfo_ = it->second;
			nType = urlInfo_->getType();
			
			HttpCurl * httpCurl_ = new HttpCurl();
			httpCurl_->runCurlValue(EcurlValue::mString);
			urlInfo_->runHttpCurl(httpCurl_, nArgs ...);
			BaseCurlPtr baseCurl_(httpCurl_);
			CurlEngine& curlEngine_ = CurlEngine::instance();
			curlEngine_.pushHandle(baseCurl_);
		}
		
		template <typename ... T1>
		bool runHttp(string& nValue, int8_t& nType, const char * nUrl, T1 ... nArgs)
		{
			int32_t urlId_ = stringCrc(nUrl);
			
			auto it = mUrlInfos.find(urlId_);
			if ( it == mUrlInfos.end() ) {
				LOGE("[%s]%s", __METHOD__, nUrl);
				return false;
			}
			UrlInfoPtr& urlInfo_ = it->second;
			nType = urlInfo_->getType();
			
			HttpCurl httpCurl_;
			httpCurl_.runCurlValue(EcurlValue::mString);
			urlInfo_->runHttpCurl(httpCurl_, nArgs ...);
			if ( !httpCurl_.runPerform() ) {
				LOGE("[%s]%s perform", __METHOD__, nUrl);
				return false;
			}
			httpCurl_.freeHttpHeader();
			const char * result_ = httpCurl_.getValue();
			if ( 0 == strcmp(result_, "") ) {
				LOGE("[%s]%s null", __METHOD__, nUrl);
				return false;
			}
		#ifdef __WINDOW__
			nValue = UTF8ToGBK(result_);
		#else
			nValue = result_;
		#endif
			return true;
		}
		
		template <typename T0, typename ... T1>
		bool runNumber(T0& nValue, const char * nUrl, T1 ... nArgs)
		{
			string value_(""); int8_t type_ = 0;
			if (!runHttp(value_, type_, nUrl, nArgs ...)) {
				return false;
			}
			nValue = convertValue<string, T0>(value_);
			return true;
		}
		
		template <class T>
		void runValue(T& nValue, const char * nString, int8_t nType, const char * nName)
		{
			if (1 == nType) {
				XmlReader xmlReader_;
				xmlReader_.stringValue(nString);
				IoReader<XmlReader> ioReader_(xmlReader_);
				ioReader_.selectStream(nName);
				nValue.headSerialize(ioReader_, nName);
			} else if (2 == nType) {
				JsonReader jsonReader_;
				jsonReader_.stringValue(nString);
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue.headSerialize(ioReader_, nName);
			} else {
				LOGE("[%s]%d", __METHOD__, nType);
			}
		}
		
		template <class T>
		void runValue(T * nValue, const char * nString, int8_t nType, const char * nName)
		{
			if (1 == nType) {
				XmlReader xmlReader_;
				xmlReader_.stringValue(nString);
				IoReader<XmlReader> ioReader_(xmlReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			} else if (2 == nType) {
				JsonReader jsonReader_;
				jsonReader_.stringValue(nString);
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			} else {
				LOGE("[%s]%d", __METHOD__, nType);
			}
		}
		
		template <class T>
		void runValue(SPTR<T>& nValue, const char * nString, int8_t nType, const char * nName)
		{
			if (1 == nType) {
				XmlReader xmlReader_;
				xmlReader_.stringValue(nString);
				IoReader<XmlReader> ioReader_(xmlReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			} else if (2 == nType) {
				JsonReader jsonReader_;
				jsonReader_.stringValue(nString);
				IoReader<JsonReader> ioReader_(jsonReader_);
				ioReader_.selectStream(nName);
				nValue->headSerialize(ioReader_, nName);
			} else {
				LOGE("[%s]%d", __METHOD__, nType);
			}
		}
		
		template <typename T0, typename ... T1>
		bool runStream(T0& nValue, const char * nUrl, const char * nName, T1 ... nArgs)
		{
			string value_(""); int8_t type_ = 0;
			if (!runHttp(value_, type_, nUrl, nArgs ...)) {
				return false;
			}
			runValue(nValue, value_.c_str(), type_, nName);
			return true;
		}
		
		template <typename T0, typename ... T1>
		bool runStream(T0 * nValue, const char * nUrl, const char * nName, T1 ... nArgs)
		{
			string value_(""); int8_t type_ = 0;
			if (!runHttp(value_, type_, nUrl, nArgs ...)) {
				return false;
			}
			runValue(nValue, value_.c_str(), type_, nName);
			return true;
		}
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runMapStreamPtrs<int32_t, UrlInfoPtr>(mUrlInfos, "urlInfos", "urlInfo");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		static UrlMgr& instance();
		
		UrlMgr();
		~UrlMgr();
		
	private:
		map<int32_t, UrlInfoPtr> mUrlInfos;
		
		static UrlMgr mUrlMgr;
	};
	
}
