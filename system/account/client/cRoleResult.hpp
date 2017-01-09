#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class cRoleResult : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.runStreamPtr(mRoleItem, "mRoleItem");
			nSerialize.runNumber(mErrorCode, "mErrorCode");
			nSerialize.runNumber(mAccountId, "mAccountId");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		RoleItemPtr& getRoleItem();
		int64_t getAccountId();
		int32_t getErrorCode();
		
		cRoleResult();
		~cRoleResult();
		
	private:
		RoleItemPtr mRoleItem;
		
		int64_t mAccountId;
		int32_t mErrorCode;
	};
	typedef std::shared_ptr<cRoleResult> cRoleResultPtr;
#endif
	
}
