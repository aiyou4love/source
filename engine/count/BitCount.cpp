#include "../Engine.hpp"

namespace cc {
	
	void BitCount::runReset(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 32)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 32;
		int16_t bit_ = (nId - 1) % 32;
		int32_t value_ = (~(0x1 << bit_));
		mValue[id_] &= value_;
		(*mIntArray)->runDirty();
	}
	
	void BitCount::runTrue(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 32)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return;
		}
		int16_t id_ = (nId - 1) / 32;
		int16_t bit_ = (nId - 1) % 32;
		mValue[id_] |= (0x1 << bit_);
		(*mIntArray)->runDirty();
	}
	
	bool BitCount::isTrue(int16_t nId)
	{
		if ( (nId < 1) || (nId > (N * 32)) ) {
			LOGE("[%s]%d,%d", __METHOD__, N, nId);
			return false;
		}
		int16_t id_ = (nId - 1) / 32;
		int16_t bit_ = (nId - 1) % 32;
		return (((mValue[id_] >> bit_) & 0x1) > 0);
	}
	
	BitCount::BitCount()
	{
	}
	
	BitCount::~BitCount()
	{
	}
	
}
