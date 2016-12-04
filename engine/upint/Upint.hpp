#pragma once

namespace cc {
	
	class Upint : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			if ( 0 == strcmp("upintSave", nName) ) {
			nSerialize->runNumber(mUpdateName, "mUpdateName");
			nSerialize->runNumber(mUpdateNo, "mUpdateNo");
			} else if ( 0 == strcmp("mUpInt", nName) ) {
			nSerialize->runCrc32(mUpdateName, "mUpdateName");
			nSerialize->runNumber(mUpdateNo, "mUpdateNo");
			} else {
				LOGE("[%s]%s", __METHOD__, nName);
			}
		}
		
		int32_t getUpdateNo();
		
		bool isDefault();
		int32_t getKey();
		
		Upint();
		~Upint();
		
	private:
        int32_t mUpdateName;
        int32_t mUpdateNo;
	};
	typedef SPTR<Upint> UpintPtr;
	
}
