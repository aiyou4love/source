#include "../../Serialize.hpp"

namespace cc {
	
	void Int16Count::setInt(int16_t nId, int16_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 2;
		int16_t bit_ = (nId - 1) % 2;
		if (0 == bit_) {
			mValue[id_] &= 0xFFFF0000;
			mValue[id_] |= nValue;
		} else {
			int32_t value_ = (nValue << 16);
			mValue[id_] &= 0xFFFF;
			mValue[id_] |= value_;
		}
		(*mIntArray)->runDirty();
	}
	
	int16_t Int16Count::getInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return 0;
		}
		int16_t id_ = (nId - 1) / 2;
		int16_t bit_ = (nId - 1) % 2;
		if (0 == bit_) {
			return ( int16_t(mValue[id_] & 0xFFFF) );
		} else {
			return ( int16_t(mValue[id_] >> 16) );
		}
	}
	
	void Int16Count::addInt(int16_t nId, int16_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 2;
		int16_t bit_ = (nId - 1) % 2;
		if (0 == bit_) {
			int16_t value_ = int16_t(mValue[id_] & 0xFFFF);
			value_ += nValue;
			
			mValue[id_] &= 0xFFFF0000;
			mValue[id_] |= value_;
		} else {
			int16_t value_ = int16_t(mValue[id_] >> 16);
			value_ += nValue;
			
			int32_t value0_ = (value_ << 16);
			mValue[id_] &= 0xFFFF;
			mValue[id_] |= value0_;
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::addInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 2;
		int16_t bit_ = (nId - 1) % 2;
		if (0 == bit_) {
			int16_t value_ = int16_t(mValue[id_] & 0xFFFF);
			value_ += 1;
			
			mValue[id_] &= 0xFFFF0000;
			mValue[id_] |= value_;
		} else {
			int16_t value_ = int16_t(mValue[id_] >> 16);
			value_ += 1;
			
			int32_t value0_ = (value_ << 16);
			mValue[id_] &= 0xFFFF;
			mValue[id_] |= value0_;
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::pushInt(int16_t nValue)
	{
		for (int16_t i = 0; i < (N * 2); ++i) {
			if ( 0 == (i % 2) ) {
				int16_t value_ = int16_t(mValue[i / 2] & 0xFFFF);
				if ( 0 != value_ ) {
					continue;
				}
				mValue[i / 2] |= nValue;
				break;
			} else {
				int16_t value_ = int16_t(mValue[i / 2] >> 16);
				if ( 0 != value_ ) {
					continue;
				}
				int32_t value0_ = (nValue << 16);
				mValue[i / 2] |= value0_;
				break;
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::popInt(int16_t nValue)
	{
		for (int16_t i = 0; i < (N * 2); ++i) {
			if ( 0 == (i % 2) ) {
				int16_t value_ = int16_t(mValue[i / 2] & 0xFFFF);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[i / 2] &= 0xFFFF0000;
				break;
			} else {
				int16_t value_ = int16_t(mValue[i / 2] >> 16);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[i / 2] &= 0xFFFF;
				break;
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		if ( 0 == (nId % 2) ) {
			mValue[nId / 2] &= 0xFFFF0000;
		} else {
			mValue[nId / 2] &= 0xFFFF;
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::runReset()
	{
		for (int16_t i = 0; i < N; ++i) {
			mValue[i] = 0;
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC)
	{
		this->runInit(nIntArray, nBegin, nEnd);
	}
	
	void Int16Count::runInit(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd)
	{
		mValue = nIntArray->rangeInts(nBegin, nEnd);
		mIntArray = (&nIntArray);
		N = nEnd - nBegin;
	}
	
	Int16Count::Int16Count()
		: mIntArray (nullptr)
		, mValue (nullptr)
		, N (0)
	{
	}
	
	Int16Count::Int16Count(IntArrayPtr& nIntArray, int16_t nBegin, int16_t nEnd)
	{
		runInit(nIntArray, nBegin, nEnd);
	}
	
	Int16Count::~Int16Count()
	{
		mIntArray = nullptr;
		mValue = nullptr;
		N = 0;
	}
	
}
