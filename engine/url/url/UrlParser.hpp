#pragma once

namespace cc {
	
	class UrlParser : noncopyable
	{
	public:
		const char * getUrlBody();
		EurlType getUrlType();
		
		UrlParser(const char * nUrl);
		~UrlParser();
		
	private:
		EurlType mUrlType;
		string mUrl;
	};
	
}
