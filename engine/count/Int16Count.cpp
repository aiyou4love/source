#include "../Engine.hpp"

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
		mIntArray->runDirty();
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
	
	bool Int16Count::checkValue(int16_t nValue)
	{
		bool result_ = false;
		for (int16_t i = 0; i < (N * 2); ++i) {
			int16_t id_ = i / 2;
			int16_t bit_ = i % 2;
			if ( 0 == bit_ ) {
				int16_t value_ = int16_t(mValue[id_] & 0xFFFF);
				if ( nValue != value_ ) {
					continue;
				}
				result_ = true;
				break;
			} else {
				int16_t value_ = int16_t(mValue[id_] >> 16);
				if ( nValue != value_ ) {
					continue;
				}
				result_ = true;
				break;
			}
		}
		return result_;
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
		mIntArray->runDirty();
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
		mIntArray->runDirty();
	}
	
	void Int16Count::pushInt(int16_t nValue)
	{
		for (int16_t i = 0; i < (N * 2); ++i) {
			int16_t id_ = i / 2;
			int16_t bit_ = i % 2;
			if ( 0 == bit_ ) {
				int16_t value_ = int16_t(mValue[id_] & 0xFFFF);
				if ( 0 != value_ ) {
					continue;
				}
				mValue[id_] |= nValue;
				break;
			} else {
				int16_t value_ = int16_t(mValue[id_] >> 16);
				if ( 0 != value_ ) {
					continue;
				}
				int32_t value0_ = (nValue << 16);
				mValue[id_] |= value0_;
				break;
			}
		}
		mIntArray->runDirty();
	}
	
	void Int16Count::popInt(int16_t nValue)
	{
		for (int16_t i = 0; i < (N * 2); ++i) {
			int16_t id_ = i / 2;
			int16_t bit_ = i % 2;
			if ( 0 == bit_ ) {
				int16_t value_ = int16_t(mValue[id_] & 0xFFFF);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFF0000;
				break;
			} else {
				int16_t value_ = int16_t(mValue[id_] >> 16);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFF;
				break;
			}
		}
		mIntArray->runDirty();
	}
	
	void Int16Count::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 2)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 2;
		int16_t bit_ = (nId - 1) % 2;
		if (0 == bit_) {
			mValue[bit_] &= 0xFFFF0000;
		} else {
			mValue[bit_] &= 0xFFFF;
		}
		mIntArray->runDirty();
	}
	
	Int16Count::Int16Count()
	{
	}
	
	Int16Count::~Int16Count()
	{
	}
	
}
