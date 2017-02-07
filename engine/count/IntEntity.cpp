#include "../Engine.hpp"

namespace cc {
	
	void IntEntity::initIntIndex(IntIndexPtr& nIntIndex)
	{
		int16_t type_ = nIntIndex->getType();
		int16_t count_ = nIntIndex->getCount();
		int16_t id_ = nIntIndex->getKey();
		
		IntArrayPtr intArray_(new IntArray());
		intArray_->runInit(type_, count_);
		mIntArrays[id_] = intArray_;
	}
	
	void IntEntity::clearIntArray(int16_t nType)
	{
		auto it = mIntArrays.begin();
		for ( ; it != mIntArrays.end(); ++it ) {
			IntArrayPtr& intArray_ = it->second;
			int16_t type_ = intArray_->getType();
			if (nType != type_) {
				continue;
			}
			intArray_->runClear();
		}
	}
	
	IntArray * IntEntity::findIntArray(int16_t nIntId)
	{
		auto it = mIntArrays.find(nIntId);
		if ( it == mIntArrays.end() ) {
			LOGE("[%s]%d", __METHOD__, nIntId);
			return nullptr;
		}
		IntArrayPtr& intArray_ = it->second;
		return ( intArray_.get() );
	}
	
	IntEntity::IntEntity()
	{
		mIntArrays.clear();
	}
	
	IntEntity::~IntEntity()
	{
		mIntArrays.clear();
	}
	
}
