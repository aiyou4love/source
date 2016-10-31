#pragma once

namespace cc {
	
	class UrlInfo : noncopyable
	{
	public:
		void runFormat(boost::format& nFormat);
		
		template <typename T0, typename ... T1>
		void runFormat(boost::format& nFormat, T0& nT0, T1& ... nT1)
		{
			nFormat % nT0;
			runFormat(nFormat, nT1 ...);
		}
		
		template <typename ... T1>
		void runHttpCurl(HttpCurl& nHttpCurl, T1 ... nArgs)
		{
			if ( "" == mBody ) {
				boost::format format_(mValue.c_str());
				this->runFormat(format_, nArgs ...);
				string value_ = format_.str().c_str();
				nHttpCurl.runInit(value_.c_str());
			} else {
				nHttpCurl.runInit(mValue.c_str());
				
				boost::format format_(mBody.c_str());
				this->runFormat(format_, nArgs ...);
				string body_ = format_.str().c_str();
				string value_ = stringDelete(body_, '\\');
			#ifdef __WINDOW__
				value_ = GBKToUTF8(value_.c_str());
			#endif
				nHttpCurl.runHttpPost(value_.c_str());
			}
			nHttpCurl.runTimeout(mTimeout);
			nHttpCurl.runHttpHeader(mType);
			if (mSSL) {
				nHttpCurl.runSSL();
			}
		}
		
		template <typename ... T1>
		void runHttpCurl(HttpCurl * nHttpCurl, T1 ... nArgs)
		{
			if ( "" == mBody ) {
				boost::format format_(mValue.c_str());
				this->runFormat(format_, nArgs ...);
				string value_ = format_.str().c_str();
				nHttpCurl->runInit(value_.c_str());
			} else {
				nHttpCurl->runInit(mValue.c_str());
				
				boost::format format_(mBody.c_str());
				this->runFormat(format_, nArgs ...);
				string body_ = format_.str().c_str();
				string value_ = stringDelete(body_, '\\');
			#ifdef __WINDOW__
				value_ = GBKToUTF8(value_.c_str());
			#endif
				nHttpCurl->runHttpPost(value_.c_str());
			}
			nHttpCurl->runTimeout(mTimeout);
			nHttpCurl->runHttpHeader(mType);
			if (mSSL) {
				nHttpCurl->runSSL();
			}
		}
		
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mDispatchId, "dispatchId");
			nSerialize->runNumber(mSelectId, "selectId");
			nSerialize->runNumber(mTimeout, "timeout");
			nSerialize->runNumber(mBody, "body");
			nSerialize->runNumber(mValue, "value");
			nSerialize->runNumber(mSSL, "ssl");
			nSerialize->runNumber(mType, "type");
			nSerialize->runCrc32(mId, "id");
		}
		int16_t getDispatchId();
		int32_t getSelectId();
		int8_t getType();
		bool isDefault();
		int32_t getKey();
		
		UrlInfo();
		~UrlInfo();
		
	private:
		int16_t mDispatchId;
		int32_t mSelectId;
		int16_t mTimeout;
		string mBody;
		string mValue;
		bool mSSL;
		int8_t mType;
		int32_t mId;
	};
	typedef SPTR<UrlInfo> UrlInfoPtr;
	
}
