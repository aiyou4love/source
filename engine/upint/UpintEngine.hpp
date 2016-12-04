#pragma once

namespace cc {
	
	class UpintEngine : noncopyable
	{
	public:
		void saveUpdate(const char * nUpdateName);
		bool isUpdate(const char * nUpdateName);
		
		void runPreinit();
		void runLoad();
		void runSave();
		void runClear();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, UpintPtr>(mUrls, "mUpInts", "mUpInt");
			} else if ( 0 == strcmp(saveName(), nName) ) {
				nSerialize.template runMapStreamPtrs<int32_t, UpintPtr>(mNows, "nows", "now");
				nSerialize.template runMapStreamPtrs<int32_t, UpintPtr>(mUrls, "urls", "url");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * saveName();
		const char * saveUrl();
		
		static UpintEngine& instance();
		
		UpintEngine();
		~UpintEngine();
		
	private:
		map<int32_t, UpintPtr> mUrls;
		map<int32_t, UpintPtr> mNows;
		
		static UpintEngine mUpintEngine;
	};
	
}
