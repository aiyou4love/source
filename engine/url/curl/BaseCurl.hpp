#pragma once

namespace cc {
	
	class UrlInfo;
	typedef SPTR<UrlInfo> UrlInfoPtr;
	class BaseCurl : noncopyable
	{
	public:
		void runCurlValue(int16_t nValueType, const char * nPath = nullptr);
		
		void setUrlInfo(UrlInfoPtr& nUrlInfo);
		void setValue(ValuePtr& nValue);
		void runValue();
		
		const char * getValue();
		
		CURL * getHandle();
		
		void runDebugInfo();
		void runInit(const char * nUrl);
		bool runPerform();
		
		BaseCurl();
		~BaseCurl();
		
	protected:
		CurlValuePtr mCurlValue;
		
		UrlInfoPtr * mUrlInfo;
		ValuePtr mValue;
		
		CURL * mHandle;
	};
	typedef SPTR<BaseCurl> BaseCurlPtr;
	
}
