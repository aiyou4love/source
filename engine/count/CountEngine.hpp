#pragma once

namespace cc {
	
	class CountEngine : noncopyable
	{
	public:
		CountIndexPtr& getCountIndex(int16_t nIndex);
		int16_t getIntN(int16_t nIndex);
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, CountIndexPtr>(mCountIndexs, "countIndexs", "countIndex");
			} else if ( 0 == strcmp(intName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int16_t, IntIndexPtr>(mIntIndexs, "intIndexs", "intIndex");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * intName();
		const char * intUrl();
		
		static CountEngine& instance();
		
		void runPreinit();
		void runLoad();
		void runClear();
		
		CountEngine();
		~CountEngine();
		
	private:
		map<int16_t, CountIndexPtr> mCountIndexs;
		map<int16_t, IntIndexPtr> mIntIndexs;
		
		static CountEngine mCountEngine;
	};
	
}
