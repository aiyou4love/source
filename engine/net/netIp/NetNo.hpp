#pragma once

namespace cc {
	
	class NetNo : noncopyable
	{
	public:
		int32_t getAppNo();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mServerId, "mServerId");
			nSerialize->runNumber(mAppNo, "mAppNo");
		}
		
		bool isDefault();
		int32_t getKey();
		
		NetNo();
		~NetNo();
		
	private:
		int32_t mServerId;
		int32_t mAppNo;
	};
	typedef SPTR<NetNo> NetNoPtr;
	
}
