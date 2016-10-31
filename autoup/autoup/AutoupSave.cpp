#include "../AutoupInc.hpp"

namespace cc {
	
	void AutoupSave::runUpdate(AutoupItemPtr& nAutoupItem)
	{
		mUpdateNo = nAutoupItem->getUpdateNo();
	}
	
	bool AutoupSave::isUpdate(AutoupItemPtr& nAutoupItem)
	{
		return (mUpdateNo != nAutoupItem->getUpdateNo());
	}
	
	const char * AutoupSave::getKey()
	{
		return mUpdateName.c_str();
	}
	
	AutoupSave::AutoupSave()
		: mUpdateName("")
		, mUpdateNo(0)
	{
	}
	
	AutoupSave::AutoupSave(AutoupItemPtr& nAutoupItem)
	{		
		mUpdateName = nAutoupItem->getUpdateName();
		mUpdateNo = nAutoupItem->getUpdateNo();
	}
	
	AutoupSave::~AutoupSave()
	{		
		mUpdateName = "";
		mUpdateNo = 0;
	}
	
}
