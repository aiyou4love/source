#include "../../Serialize.hpp"

namespace cc {
	
	UserDefault& UserDefault::instance()
	{
		return mUserDefault;
	}
	
	UserDefault::UserDefault()
	{
	}
	
	UserDefault::~UserDefault()
	{
	}
	
	UserDefault UserDefault::mUserDefault;
	
}
