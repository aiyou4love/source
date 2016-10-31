#pragma once

namespace cc {
	
	class MultiCurl : public noncopyable
	{
	public:
		void pushHandle(BaseCurlPtr& nBaseCurl);
		
		void runHandle();
		
		MultiCurl();
		~MultiCurl();
		
	private:
		map<intptr_t, BaseCurlPtr> mBaseCurls;
		
		CURLM * mHandle;
	};
	typedef SPTR<MultiCurl> MultiCurlPtr;
	
}
