#pragma once

namespace cc {
	
	class NetInfo : noncopyable
	{
	public:
		int64_t getStartTime();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mStartTime, "mStartTime");
			
			nSerialize->runNumber(mAppNo, "mAppNo");
		}
		
		bool isDefault();
		int32_t getKey();
		
		NetInfo();
		~NetInfo();
		
	private:
		int64_t mStartTime;
		
		int32_t mAppNo;
	};
	typedef SPTR<NetInfo> NetInfoPtr;
	
}
