#include "../Engine.hpp"

namespace cc {
	
	void Int4Count::setInt(int16_t nId, int8_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 8)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 8;
		int16_t bit_ = (nId - 1) % 8;
		if (0 == bit_) {
			mValue[id_] &= 0xFFFFFFF0;
			mValue[id_] |= nValue;
		} else if (1 == bit_) {
			mValue[id_] &= 0xFFFFFF0F;
			
			int32_t value_ = (nValue << 4);
			mValue[id_] |= value_;
		} else if (2 == bit_) {
			mValue[id_] &= 0xFFFFF0FF;
			
			int32_t value_ = (nValue << 8);
			mValue[id_] |= value_;
		} else if (3 == bit_) {
			mValue[id_] &= 0xFFFF0FFF;
			
			int32_t value_ = (nValue << 12);
			mValue[id_] |= value_;
		} else if (4 == bit_) {
			mValue[id_] &= 0xFFF0FFFF;
			
			int32_t value_ = (nValue << 16);
			mValue[id_] |= value_;
		} else if (5 == bit_) {
			mValue[id_] &= 0xFF0FFFFF;
			
			int32_t value_ = (nValue << 20);
			mValue[id_] |= value_;;
		} else if (6 == bit_) {
			mValue[id_] &= 0xF0FFFFFF;
			
			int32_t value_ = (nValue << 24);
			mValue[id_] |= value_;
		} else if (7 == bit_) {
			mValue[id_] &= 0xFFFFFFF;
			
			int32_t value_ = (nValue << 28);
			mValue[id_] |= value_;
		} else {
		}
		mIntArray->runDirty();
	}
	
	int8_t Int4Count::getInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 8)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return 0;
		}
		int16_t id_ = (nId - 1) / 8;
		int16_t bit_ = (nId - 1) % 8;
		if (0 == bit_) {
			return int8_t(mValue[id_] & 0xF);
		} else if (1 == bit_) {
			int32_t value0_ = mValue[id_] >> 4;
			return int8_t(value0_ & 0xF);
		} else if (2 == bit_) {
			int32_t value0_ = mValue[id_] >> 8;
			return int8_t(value0_ & 0xF);
		} else if (3 == bit_) {
			int32_t value0_ = mValue[id_] >> 12;
			return int8_t(value0_ & 0xF);
		} else if (4 == bit_) {
			int32_t value0_ = mValue[id_] >> 16;
			return int8_t(value0_ & 0xF);
		} else if (5 == bit_) {
			int32_t value0_ = mValue[id_] >> 20;
			return int8_t(value0_ & 0xF);
		} else if (6 == bit_) {
			int32_t value0_ = mValue[id_] >> 24;
			return int8_t(value0_ & 0xF);
		} else if (7 == bit_) {
			int32_t value0_ = mValue[id_] >> 28;
			return int8_t(value0_ & 0xF);
		} else {
			return 0;
		}
	}
	
	void Int4Count::addInt(int16_t nId, int8_t nValue)
	{
		if ( (nId < 1) || (nId > (N * 8)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 8;
		int16_t bit_ = (nId - 1) % 8;
		if (0 == bit_) {
			int8_t value_ = int8_t(mValue[id_] & 0xF);
			value_ += nValue;
			if (value_ > 0xF) {
				value_ = 0xF;
			}
			mValue[id_] &= 0xFFFFFFF0;
			mValue[id_] |= value_;
		} else if (1 == bit_) {
			int32_t value0_ = mValue[id_] >> 4;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFFFF0F;
			
			int32_t value2_ = (value1_ << 4);
			mValue[id_] |= value2_;
		} else if (2 == bit_) {
			int32_t value0_ = mValue[id_] >> 8;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFFF0FF;
			
			int32_t value2_ = (value1_ << 8);
			mValue[id_] |= value2_;
		} else if (3 == bit_) {
			int32_t value0_ = mValue[id_] >> 12;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFF0FFF;
			
			int32_t value2_ = (value1_ << 12);
			mValue[id_] |= value2_;
		} else if (4 == bit_) {
			int32_t value0_ = mValue[id_] >> 16;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFF0FFFF;
			
			int32_t value2_ = (value1_ << 16);
			mValue[id_] |= value2_;
		} else if (5 == bit_) {
			int32_t value0_ = mValue[id_] >> 20;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFF0FFFFF;
			
			int32_t value2_ = (value1_ << 20);
			mValue[id_] |= value2_;
		} else if (6 == bit_) {
			int32_t value0_ = mValue[id_] >> 24;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xF0FFFFFF;
			
			int32_t value2_ = (value1_ << 24);
			mValue[id_] |= value2_;
		} else if (7 == bit_) {
			int32_t value0_ = mValue[id_] >> 28;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += nValue;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xF0FFFFFF;
			
			int32_t value2_ = (value1_ << 28);
			mValue[id_] |= value2_;
		} else {
		}
		mIntArray->runDirty();
	}
	
	void Int4Count::addInt(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 8)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 8;
		int16_t bit_ = (nId - 1) % 8;
		if (0 == bit_) {
			int8_t value_ = int8_t(mValue[id_] & 0xF);
			value_ += 1;
			if (value_ > 0xF) {
				value_ = 0xF;
			}
			mValue[id_] &= 0xFFFFFFF0;
			mValue[id_] |= value_;
		} else if (1 == bit_) {
			int32_t value0_ = mValue[id_] >> 4;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFFFF0F;
			
			int32_t value2_ = (value1_ << 4);
			mValue[id_] |= value2_;
		} else if (2 == bit_) {
			int32_t value0_ = mValue[id_] >> 8;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFFF0FF;
			
			int32_t value2_ = (value1_ << 8);
			mValue[id_] |= value2_;
		} else if (3 == bit_) {
			int32_t value0_ = mValue[id_] >> 12;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFFF0FFF;
			
			int32_t value2_ = (value1_ << 12);
			mValue[id_] |= value2_;
		} else if (4 == bit_) {
			int32_t value0_ = mValue[id_] >> 16;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFFF0FFFF;
			
			int32_t value2_ = (value1_ << 16);
			mValue[id_] |= value2_;
		} else if (5 == bit_) {
			int32_t value0_ = mValue[id_] >> 20;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xFF0FFFFF;
			
			int32_t value2_ = (value1_ << 20);
			mValue[id_] |= value2_;
		} else if (6 == bit_) {
			int32_t value0_ = mValue[id_] >> 24;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xF0FFFFFF;
			
			int32_t value2_ = (value1_ << 24);
			mValue[id_] |= value2_;
		} else if (7 == bit_) {
			int32_t value0_ = mValue[id_] >> 28;
			int8_t value1_ = int8_t(value0_ & 0xF);
			value1_ += 1;
			if (value1_ > 0xF) {
				value1_ = 0xF;
			}
			mValue[id_] &= 0xF0FFFFFF;
			
			int32_t value2_ = (value1_ << 28);
			mValue[id_] |= value2_;
		} else {
		}
		mIntArray->runDirty();
	}
	
	void Int4Count::pushInt(int8_t nValue)
	{
		for (int16_t i = 0; i < (N * 8); ++i) {
			int16_t id_ = i / 8;
			int16_t bit_ = i % 8;
			if (0 == bit_) {
				int8_t value_ = int8_t(mValue[id_] & 0xF);
				if ( 0 != value_ ) {
					continue;
				}
				mValue[id_] |= nValue;
				break;
			} else if (1 == bit_) {
				int32_t value0_ = mValue[id_] >> 4;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 4);
				mValue[id_] |= value2_;
				break;
			} else if (2 == bit_) {
				int32_t value0_ = mValue[id_] >> 8;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 8);
				mValue[id_] |= value2_;
				break;
			} else if (3 == bit_) {
				int32_t value0_ = mValue[id_] >> 12;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 12);
				mValue[id_] |= value2_;
				break;
			} else if (4 == bit_) {
				int32_t value0_ = mValue[id_] >> 16;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 16);
				mValue[id_] |= value2_;
				break;
			} else if (5 == bit_) {
				int32_t value0_ = mValue[id_] >> 20;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 20);
				mValue[id_] |= value2_;
				break;
			} else if (6 == bit_) {
				int32_t value0_ = mValue[id_] >> 24;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 24);
				mValue[id_] |= value2_;
				break;;
			} else if (7 == bit_) {
				int32_t value0_ = mValue[id_] >> 28;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( 0 != value1_ ) {
					continue;
				}
				int32_t value2_ = (nValue << 28);
				mValue[id_] |= value2_;
				break;
			} else {
			}
		}
		mIntArray->runDirty();
	}
	
	void Int4Count::popInt(int8_t nValue)
	{
		for (int16_t i = 0; i < (N * 8); ++i) {
			int16_t id_ = i / 8;
			int16_t bit_ = i % 8;
			if (0 == bit_) {
				int8_t value_ = int8_t(mValue[id_] & 0xF);
				if ( nValue != value_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFFFF0;
				break;
			} else if (1 == bit_) {
				int32_t value0_ = mValue[id_] >> 4;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFFF0F;
				break;
			} else if (2 == bit_) {
				int32_t value0_ = mValue[id_] >> 8;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFF0FF;
				break;
			} else if (3 == bit_) {
				int32_t value0_ = mValue[id_] >> 12;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFF0FFF;
				break;
			} else if (4 == bit_) {
				int32_t value0_ = mValue[id_] >> 16;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFF0FFFF;
				break;
			} else if (5 == bit_) {
				int32_t value0_ = mValue[id_] >> 20;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFF0FFFFF;
				break;
			} else if (6 == bit_) {
				int32_t value0_ = mValue[id_] >> 24;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xF0FFFFFF;
				break;
			} else if (7 == bit_) {
				int32_t value0_ = mValue[id_] >> 28;
				int8_t value1_ = int8_t(value0_ & 0xF);
				if ( nValue != value1_ ) {
					continue;
				}
				mValue[id_] &= 0xFFFFFFF;
				break;
			} else {
			}
		}
		mIntArray->runDirty();
	}
	
	void Int4Count::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 8)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 8;
		int16_t bit_ = (nId - 1) % 8;
		if (0 == bit_) {
			mValue[id_] &= 0xFFFFFFF0;
		} else if (1 == bit_) {
			mValue[id_] &= 0xFFFFFF0F;
		} else if (2 == bit_) {
			mValue[id_] &= 0xFFFFF0FF;
		} else if (3 == bit_) {
			mValue[id_] &= 0xFFFF0FFF;
		} else if (4 == bit_) {
			mValue[id_] &= 0xFFF0FFFF;
		} else if (5 == bit_) {
			mValue[id_] &= 0xFF0FFFFF;
		} else if (6 == bit_) {
			mValue[id_] &= 0xF0FFFFFF;
		} else if (7 == bit_) {
			mValue[id_] &= 0xFFF0FFF;
		} else {
		}
		mIntArray->runDirty();
	}
	
	Int4Count::Int4Count()
	{
	}
	
	Int4Count::~Int4Count()
	{
	}
	
}
