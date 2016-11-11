#include "../../Serialize.hpp"

namespace cc {
	
	void Int32Count::setInt(int16_t nId, int32_t nValue)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] = nValue;
		mIntArray->runDirty();
	}
	
	int32_t Int32Count::getInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return 0;
		}
		return mValue[nId - 1];
	}
	
	void Int32Count::addInt(int16_t nId, int32_t nValue)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] += nValue;
	}
	
	void Int32Count::addInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] += 1;
	}
	
	void Int32Count::pushInt(int32_t nValue)
	{
		for (int16_t i = 0; i < N; ++i) {
			if ( 0 == mValue[i] ) {
				mValue[i] = nValue;
			}
		}
		mIntArray->runDirty();
	}
	
	void Int32Count::popInt16(int16_t nValue)
	{
		for (int16_t i = 0; i < N; ++i) {
			if ( nValue == int16_t(mValue[i] >> 16) ) {
				mValue[i] = 0;
			}
		}
		mIntArray->runDirty();
	}
	
	void Int32Count::popInt(int32_t nValue)
	{
		for (int16_t i = 0; i < N; ++i) {
			if ( nValue == mValue[i] ) {
				mValue[i] = 0;
			}
		}
		mIntArray->runDirty();
	}
	
	void Int32Count::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > N) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		mValue[nId - 1] = 0;
	}
	
	void Int32Count::runReset()
	{
		for (int16_t i = 0; i < N; ++i) {
			mValue[i] = 0;
		}
		mIntArray->runDirty();
	}
	
	void Int32Count::runInit(IntArray * nIntArray, int16_t nBegin, int16_t nEnd, int16_t nC)
	{
		this->runInit(nIntArray, nBegin, nEnd);
	}
	
	void Int32Count::runInit(IntArray * nIntArray, int16_t nBegin, int16_t nEnd)
	{
		mValue = nIntArray->rangeInts(nBegin, nEnd);
		mIntArray = nIntArray;
		N = nEnd - nBegin;
	}
	
	Int32Count::Int32Count()
		: mIntArray (nullptr)
		, mValue (nullptr)
		, N (0)
	{
	}
	
	Int32Count::Int32Count(IntArray * nIntArray, int16_t nBegin, int16_t nEnd)
	{
		runInit(nIntArray, nBegin, nEnd);
	}
	
	Int32Count::~Int32Count()
	{
		mIntArray = nullptr;
		mValue = nullptr;
		N = 0;
	}
	
}
