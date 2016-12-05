#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cAccount : public Account
	{
	public:
		void setPassword(const char * nPassword);
		const char * getPassword();
		
		void setName(const char * nName);
		const char * getName();
		
		void runClear();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtr(mRoleItem, "mRoleItem");
			
			nSerialize.runNumber(mPassword, "mPassword");
			nSerialize.runNumber(mName, "mName");
			
			nSerialize.runNumber(mAuthority, "mAuthority");
			
			nSerialize.runNumber(mType, "mType");
			nSerialize.runNumber(mId, "mId");
		}
		const char * streamName();
		const char * streamUrl();
		
		void runLoad();
		void runSave();
		
		cAccount();
		~cAccount();
		
	private:
		string mPassword;
		string mName;
	};
	typedef SPTR<cAccount> cAccountPtr;
#endif
	
}
