#include "../../Dispatch.hpp"

namespace cc {
	
#ifdef __CLIENT__
	void cAccount::setServerId(int32_t nServerId)
	{
		mServerId = nServerId;
	}
	
	int32_t cAccount::getServerId()
	{
		return mServerId;
	}
	
	void cAccount::runLoad()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runReader<cAccount>(this, streamUrl(), streamName());
	}
	
	void cAccount::runSave()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		userDefault_.runSave<cAccount>(this, streamUrl(), streamName());
	}
	
	const char * cAccount::streamName()
	{
		return "account";
	}
	
	const char * cAccount::streamUrl()
	{
		return "account.json";
	}
	
	cAccount::cAccount()
		: mServerId (0)
	{
	}
	
	cAccount::~cAccount()
	{
		mServerId = 0;
	}
#endif
	
}
