#pragma once

namespace cc {
	
	class CountEngine : noncopyable
	{
	public:
		void initCount(ICount * nCount, EntityPtr& nEntity, CountIndexPtr& nCountIndex);
		void initCount(ICount * nCount, EntityPtr& nEntity, const char * nIndex);
		
		void clearEntity(int16_t nType, EntityPtr& nEntity);
		void initEntity(EntityPtr& nEntity);
		
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
