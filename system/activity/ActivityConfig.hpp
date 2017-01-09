#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ActivityConfig : noncopyable
	{
	public:
		const char * getName();
		const char * getText();
		int16_t getOpenType();
		int32_t getOpenId();
		
		int32_t getActivityId();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mActivityId, "activityId");
			nSerialize->runNumber(mOpenType, "openType");
			nSerialize->runNumber(mOpenId, "openId");
			nSerialize->runNumber(mName, "name");
			nSerialize->runNumber(mText, "text");
		}
		
		bool isDefault();
		int32_t getKey();
		
		ActivityConfig();
		~ActivityConfig();
		
	private:
		int32_t mActivityId;
		int16_t mOpenType;
		int32_t mOpenId;
		string mName;
		string mText;
	};
	typedef SPTR<ActivityConfig> ActivityConfigPtr;
#endif
	
}
