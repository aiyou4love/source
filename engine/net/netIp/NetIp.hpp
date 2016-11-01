#pragma once

namespace cc {
	
	class NetIp : noncopyable
	{
	public:
		const char * getPort();
		const char * getIp();
		int16_t getAppType();
		int32_t getAppNo();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mAppNo, "mAppNo");
			nSerialize->runNumber(mAppType, "mAppType");
			nSerialize->runNumber(mPort, "mPort");
			nSerialize->runNumber(mIp, "mIp");
		}
		
		bool isDefault();
		int64_t getKey();
		
		NetIp();
		~NetIp();
		
	private:
		int32_t mAppNo;
		int16_t mAppType;
		string mPort;
		string mIp;
	};
	typedef SPTR<NetIp> NetIpPtr;
	
}
