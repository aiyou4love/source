#pragma once

namespace cc {
	
	class ServerItem : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mServerId, "mServerId");
			nSerialize->runNumber(mServerName, "mServerName");
			nSerialize->runNumber(mServerNo, "mServerNo");
		}
		
		int32_t getServerId();
        const char * getServerName();
        int16_t getServerNo();
		
		bool isDefault();
		int32_t getKey();
		
		ServerItem();
		~ServerItem();
		
	private:
		int32_t mServerId;
        string mServerName;
        int32_t mServerNo;
	};
	typedef SPTR<ServerItem> ServerItemPtr;
	
}
