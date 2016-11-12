#include "../../Serialize.hpp"

namespace cc {
	
	void IntCount::setInt(int16_t nId, int16_t nValue)
	{
		if ( (nId < 1) || (nId > I) || (nValue > M) ) {
			LOGE("[%s]%d,%d,%d,%d", __METHOD__, I, nId, nValue, M);
			return;
		}
		int16_t start_ = (nId - 1) * C;
		int16_t end_ = nId * C;
		int16_t index0_ = start_ / 32;
		int16_t pos0_ = start_ % 32;
		int16_t index1_ = end_ / 32;
		int16_t pos1_ = end_ % 32;
		if (index0_ == index1_) {
			mValue[index0_] &= (~(M << pos0_));
			mValue[index0_] &= (~(((~nValue) & M) << pos0_));
		} else {
			mValue[index0_] <<= (32 - pos0_);
			mValue[index0_] >>= (32 - pos0_);
			mValue[index0_] &= (~((~nValue) << (32 - pos0_)));
			if (pos1_ > 0) {
				mValue[index1_] >>= pos1_;
				mValue[index1_] <<= pos1_;
				mValue[index1_] &= (~(((~nValue) & M) >> (32 - pos0_)));
			}
		}
		(*mIntArray)->runDirty();
	}
	
	int16_t IntCount::getInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > I) ) {
			LOGE("[%s]%d,%d", __METHOD__, I, nId);
			return 0;
		}
		int16_t start_ = (nId - 1) * C;
		int16_t end_ = nId * C;
		int16_t index0_ = start_ / 32;
		int16_t pos0_ = start_ % 32;
		int16_t index1_ = end_ / 32;
		int16_t pos1_ = end_ % 32;
		int32_t value_ = mValue[index0_] >> pos0_;
		if ( (index0_ != index1_) && (pos1_ > 0) ) {
			value_ |= (mValue[index1_] << (32 - pos0_));
		}
		value_ &= M;
		return static_cast<int16_t>(value_);
	}
	
	void IntCount::addInt(int16_t nId, int16_t nValue, bool nCycle)
	{
		if ( (nId < 1) || (nId > I) || (nValue > M) ) {
			LOGE("[%s]%d,%d,%d,%d", __METHOD__, I, nId, nValue, M);
			return;
		}
		int16_t start_ = (nId - 1) * C;
		int16_t end_ = nId * C;
		int16_t index0_ = start_ / 32;
		int16_t pos0_ = start_ % 32;
		int16_t index1_ = end_ / 32;
		int16_t pos1_ = end_ % 32;
		int32_t value_ = mValue[index0_] >> pos0_;
		if ( (index0_ != index1_) && (pos1_ > 0) ) {
			value_ |= (mValue[index1_] << (32 - pos0_));
		}
		value_ &= M;
		value_ += nValue;
		if (value_ > M) {
			if (nCycle) {
				value_ -= M;
			} else {
				value_ = M;
			}
		}
		if (index0_ == index1_) {
			mValue[index0_] &= (~(M << pos0_));
			mValue[index0_] &= (~(((~value_) & M) << pos0_));
		} else {
			mValue[index0_] <<= (32 - pos0_);
			mValue[index0_] >>= (32 - pos0_);
			mValue[index0_] &= (~((~value_) << (32 - pos0_)));
			if (pos1_ > 0) {
				mValue[index1_] >>= pos1_;
				mValue[index1_] <<= pos1_;
				mValue[index1_] &= (~(((~value_) & M) >> (32 - pos0_)));
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void IntCount::addInt(int16_t nId, bool nCycle)
	{
		this->addInt(nId, 1, nCycle);
	}
	
	void IntCount::pushInt(int16_t nValue)
	{
		if (nValue > M) {
			LOGE("[%s]%d,%d,%d", __METHOD__, I, nValue, M);
			return;
		}
		for (int16_t i = 1; i <= I; ++i) {
			int16_t value_ = this->getInt(i);
			if ( 0 == value_ ) {
				this->setInt(i, value_);
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void IntCount::popInt(int16_t nValue)
	{
		for (int16_t i = 1; i <= I; ++i) {
			int16_t value_ = this->getInt(i);
			if ( nValue == value_ ) {
				this->runReset(i);
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void IntCount::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > I) ) {
			LOGE("[%s]%d,%d", __METHOD__, I, nId);
			return;
		}
		int16_t start_ = (nId - 1) * C;
		int16_t end_ = nId * C;
		int16_t index0_ = start_ / 32;
		int16_t pos0_ = start_ % 32;
		int16_t index1_ = end_ / 32;
		int16_t pos1_ = end_ % 32;
		int32_t value_ = 0;
		if (index0_ == index1_) {
			mValue[index0_] = (~(M << pos0_));
		} else {
			if (pos1_ > 0) {
				mValue[index1_] >>= pos1_;
				mValue[index1_] <<= pos1_;
			}
			mValue[index0_] <<= (32 - pos0_);
			mValue[index0_] >>= (32 - pos0_);
		}
		(*mIntArray)->runDirty();
	}
	
	void IntCount::runReset()
	{
		for (int16_t i = 0; i < N; ++i)
		{
			mValue[i] = 0;
		}
		(*mIntArray)->runDirty();
	}
	
	void IntCount::runInit(IntArrayPtr& nIntArray,
		int16_t nBegin, int16_t nEnd, int16_t nC)
	{
		mValue = nIntArray->rangeInts(nBegin, nEnd);
		mIntArray = (&nIntArray);
		N = nEnd - nBegin;
		M = static_cast<int16_t>(::pow(2, nC)) - 1;
		C = nC; I = (32 * N) / C;
	}
	
	IntCount::IntCount()
		: mIntArray (nullptr)
		, mValue (nullptr)
		, N (0)
		, M (0)
		, C (0)
		, I (0)
	{
	}
	
	IntCount::IntCount(IntArrayPtr& nIntArray, 
		int16_t nBegin, int16_t nEnd, int16_t nC)
	{
		runInit(nIntArray, nBegin, nEnd, nC);
	}
	
	IntCount::~IntCount()
	{
		mIntArray = nullptr;
		mValue = nullptr;
		N = 0; M = 0;
		C = 0; I = 0;
	}
	
}
