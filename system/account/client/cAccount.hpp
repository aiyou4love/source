#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccount : public Account
	{
	public:
		void setServerId(int32_t nServerId);
		int32_t getServerId();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runNumber(mPassword, "mPassword");
			nSerialize.runNumber(mName, "mName");
			
			nSerialize.runNumber(mServerId, "mServerId");
			
			nSerialize.runNumber(mType, "mType");
			nSerialize.runNumber(mId, "mId");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		void runClear();
		
		cAccount();
		~cAccount();
		
	private:
		int32_t mServerId;
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
