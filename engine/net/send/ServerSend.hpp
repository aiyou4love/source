#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class ServerSend : public ISend
	{
	public:
		void sendValue(ValuePtr& nValue);
		
		void setAppType(int16_t nAppType);
		void setAppNo(int32_t nAppNo);
		
		ServerSend();
		~ServerSend();
		
	private:
		int16_t mAppType;
		int32_t mAppNo;
		
		int64_t mAppId;
	};
#endif
	
}
