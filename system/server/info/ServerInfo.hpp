#pragma once

namespace cc {
	
	class ServerInfo : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mServerStart, "mServerStart");
			nSerialize->runNumber(mServerNo, "mServerNo");
		}
		
		int64_t getServerStart();
        int32_t getServerNo();
		
		bool isDefault();
		int32_t getKey();
		
		ServerInfo();
		~ServerInfo();
		
	private:
        int64_t mServerStart;
        int32_t mServerNo;
	};
	typedef SPTR<ServerInfo> ServerInfoPtr;
	
}
