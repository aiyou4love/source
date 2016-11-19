#include "../Engine.hpp"

namespace cc {
	
	void Int8Count::setInt(int16_t nId, int8_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 4)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 4;
		int16_t bit_ = (nId - 1) % 4;
		if (0 == bit_) {
			mValue[id_] &= 0xFFFFFF00;
			mValue[id_] |= nValue;
		} else if (1 == bit_)) {
			mValue[id_] &= 0xFFFF00FF;
			
			int32_t value_ = (nValue << 8);
			mValue[id_] |= value_;
		} else if (2 == bit_)) {
			mValue[id_] &= 0xFF00FFFF;
			
			int32_t value_ = (nValue << 16);
			mValue[id_] |= value_;
		} else if (3 == bit_)) {
			mValue[id_] &= 0xFFFFFF;
			
			int32_t value_ = (nValue << 24);
			mValue[id_] |= value_;
		} else {
		}
		(*mIntArray)->runDirty();
	}
	
	int8_t Int8Count::getInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 4)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return 0;
		}
		int16_t id_ = (nId - 1) / 4;
		int16_t bit_ = (nId - 1) % 4;
		if (0 == bit_) {
			return int8_t(mValue[id_] & 0xFF);
		} else if (1 == bit_)) {
			int32_t value0_ = mValue[id_] >> 8;
			return int8_t(value0_ & 0xFF);
		} else if (2 == bit_)) {
			int32_t value0_ = mValue[id_] >> 16;
			return int8_t(value0_ & 0xFF);
		} else if (3 == bit_)) {
			int32_t value0_ = mValue[id_] >> 24;
			return int8_t(value0_ & 0xFF);
		} else {
			return 0;
		}
	}
	
	void Int8Count::addInt(int16_t nId, int8_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 4)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 4;
		int16_t bit_ = (nId - 1) % 4;
		if (0 == bit_) {
			int8_t value_ = int8_t(mValue[id_] & 0xFF);
			value_ += nValue;
			
			mValue[id_] &= 0xFFFFFF00;
			mValue[id_] |= value_;
		} else if (1 == bit_)) {
			int32_t value0_ = mValue[id_] >> 8;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += nValue;
			
			mValue[id_] &= 0xFFFF00FF;
			
			int32_t value2_ = (value1_ << 8);
			mValue[id_] |= value2_;
		} else if (2 == bit_)) {
			int32_t value0_ = mValue[id_] >> 16;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += nValue;
			
			mValue[id_] &= 0xFF00FFFF;
			
			int32_t value2_ = (value1_ << 16);
			mValue[id_] |= value2_;
		} else if (3 == bit_)) {
			int32_t value0_ = mValue[id_] >> 24;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += nValue;
			
			mValue[id_] &= 0xFFFFFF;
			
			int32_t value2_ = (value1_ << 24);
			mValue[id_] |= value2_;
		} else {
		}
		(*mIntArray)->runDirty();
	}
	
	void Int8Count::addInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 4)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 4;
		int16_t bit_ = (nId - 1) % 4;
		if (0 == bit_) {
			int8_t value_ = int8_t(mValue[id_] & 0xFF);
			value_ += 1;
			
			mValue[id_] &= 0xFFFFFF00;
			mValue[id_] |= value_;
		} else if (1 == bit_)) {
			int32_t value0_ = mValue[id_] >> 8;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += 1;
			
			mValue[id_] &= 0xFFFF00FF;
			
			int32_t value2_ = (value1_ << 8);
			mValue[id_] |= value2_;
		} else if (2 == bit_)) {
			int32_t value0_ = mValue[id_] >> 16;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += 1;
			
			mValue[id_] &= 0xFF00FFFF;
			
			int32_t value2_ = (value1_ << 16);
			mValue[id_] |= value2_;
		} else if (3 == bit_)) {
			int32_t value0_ = mValue[id_] >> 24;
			int8_t value1_ = int8_t(value0_ & 0xFF);
			value1_ += 1;
			
			mValue[id_] &= 0xFFFFFF;
			
			int32_t value2_ = (value1_ << 24);
			mValue[id_] |= value2_;
		} else {
		}
		(*mIntArray)->runDirty();
	}
	
	void Int8Count::pushInt(int8_t nValue)
	{
		for (int16_t i = 0; i < (N * 4); ++i) {
			int16_t id_ = (nId - 1) / 4;
			int16_t bit_ = (nId - 1) % 4;
			if (0 == bit_) {
				int8_t value_ = int8_t(mValue[id_] & 0xFF);
				if ( 0 != value_ ) {
					continue;
				}
				mValue[id_] |= nValue;
				break;
			} else if (1 == bit_)) {
				int32_t value0_ = mValue[id_] >> 8;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 8);
				mValue[id_] |= value2_;
				break;
			} else if (2 == bit_)) {
				int32_t value0_ = mValue[id_] >> 16;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 16);
				mValue[id_] |= value2_;
				break;
			} else if (3 == bit_)) {
				int32_t value0_ = mValue[id_] >> 24;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 24);
				mValue[id_] |= value2_;
				break;
			} else {
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void Int8Count::popInt(int8_t nValue)
	{
		for (int16_t i = 0; i < (N * 4); ++i) {
			int16_t id_ = i / 4;
			int16_t bit_ = i % 4;
			if (0 == bit_) {
				int8_t value_ = int8_t(mValue[id_] & 0xFF);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFFF00;
				break;
			} else if (1 == bit_)) {
				int32_t value0_ = mValue[id_] >> 8;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFF00FF;
				break;
			} else if (2 == bit_)) {
				int32_t value0_ = mValue[id_] >> 16;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFF00FFFF;
				break;
			} else if (3 == bit_)) {
				int32_t value0_ = mValue[id_] >> 24;
				int8_t value1_ = int8_t(value0_ & 0xFF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFFF;
				break;
			} else {
			}
		}
		(*mIntArray)->runDirty();
	}
	
	void Int8Count::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 4)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 4;
		int16_t bit_ = (nId - 1) % 4;
		if (0 == bit_) {
			mValue[id_] &= 0xFFFFFF00;
		} else if (1 == bit_)) {
			mValue[id_] &= 0xFFFF00FF;
		} else if (2 == bit_)) {
			mValue[id_] &= 0xFF00FFFF;
		} else if (3 == bit_)) {
			mValue[id_] &= 0xFFFFFF;
		} else {
		}
		(*mIntArray)->runDirty();
	}
	
	Int8Count::Int8Count()
	{
	}
	
	Int8Count::~Int8Count()
	{
	}
	
}
