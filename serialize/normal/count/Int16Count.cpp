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
			int32_t value_ = (nValue << 16);
			mValue[id_] &= 0xFFFF;
			mValue[id_] |= value_;
		} else {
			mValue[id_] &= 0xFFFF0000;
			mValue[id_] |= nValue;
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
			return ( int16_t(mValue[id_] >> 16) );
		} else {
			mValue[id_] &= 0xFFFF0000;
			mValue[id_] |= nValue;
		}
	}
	
	void Int16Count::addInt(int16_t nId, int32_t nValue)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] += nValue;
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::addInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] += 1;
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::pushInt(int32_t nValue)
	{
		for (int16_t i = 0; i < N; ++i) {
			if ( 0 == mValue[i] ) {
				mValue[i] = nValue;
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void Int16Count::popInt(int32_t nValue)
	{
		for (int16_t i = 0; i < N; ++i) {
			if ( nValue == mValue[i] ) {
				mValue[i] = 0;
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
		mValue[nId - 1] = 0;
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
