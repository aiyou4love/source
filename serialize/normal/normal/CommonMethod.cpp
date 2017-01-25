#include "../../Serialize.hpp"

namespace cc {
	
	int32_t strToInt32(const char * nValue)
	{
        return strtol(nValue, nullptr, 0);
	}
	
	string int32ToStr(int32_t nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%d", nValue);
		return result_;
	}
	
	int64_t strToInt64(const char * nValue)
	{
        return strtoll(nValue, nullptr, 0);
	}
	
	string int64ToStr(int64_t nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%lld", nValue);
		return result_;
	}
	
	double strToDouble(const char * nValue)
	{
		return strtod(nValue, nullptr);
	}
	
	string doubleToStr(double nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%f", nValue);
		return result_;
	}
	
	int32_t stringCrc(const char * nValue)
	{
		crc_32_type crc32_;
		crc32_.process_bytes(nValue, strlen(nValue));
		return crc32_();
	}
	
	wstring UTF8ToUTF16(const char * nValue)
	{
		wstring_convert<codecvt_utf8<wchar_t> > convert_;
		return convert_.from_bytes(nValue);
	}
	
	string UTF16ToUTF8(const wchar_t * nValue)
	{
		wstring_convert<codecvt_utf8<wchar_t> > convert_;
		return convert_.to_bytes(nValue);
	}
	
#ifdef __WINDOW__
	string UTF8ToGBK(const char * nValue)
	{
		wstring_convert<codecvt_utf8<wchar_t> > convert_;
		wstring value_ = convert_.from_bytes(nValue);
		using cCodecvt = codecvt_byname<wchar_t, char, mbstate_t>;
		wstring_convert<cCodecvt> convert1_(new cCodecvt(""));
		return convert1_.to_bytes(value_);
	}
	
	string GBKToUTF8(const char * nValue)
	{
		using cCodecvt = codecvt_byname<wchar_t, char, mbstate_t>;
		wstring_convert<cCodecvt> convert0_(new cCodecvt(""));
		wstring value_ = convert0_.from_bytes(nValue);
		wstring_convert<codecvt_utf8<wchar_t> > convert1_;
		return convert1_.to_bytes(value_);
	}
#endif
	
	int64_t linkInt32(int32_t nId0, int32_t nId1)
	{
		int64_t result_ = nId0;
		result_ <<= 32;
		result_ |= nId1;
		return result_;
	}
	
	int32_t linkInt16(int16_t nId0, int16_t nId1)
	{
		int32_t result_ = nId0;
		result_ <<= 16;
		result_ |= nId1;
		return result_;
	}
	
	int16_t linkInt8(int8_t nId0, int8_t nId1)
	{
		int16_t result_ = nId0;
		result_ <<= 8;
		result_ |= nId1;
		return result_;
	}
	
	int32_t linkInt24(int8_t nId0, int32_t nId1)
	{
		int32_t result_ = nId0;
		result_ <<= 24;
		result_ |= nId1;
		return result_;
	}
	
	void zstdcompress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize)
	{
		size_t destSize_ = ZSTD_compressBound(nInsize);
		
		nOutsize = int16_t(ZSTD_compress(nDest + 2, destSize_, nValue, nInsize, 1));
		if (ZSTD_isError(nOutsize)) {
			LOGE("[%s]%s", __METHOD__, ZSTD_getErrorName(nOutsize));
			nOutsize = 0;
		} else {
			(* ((int16_t *)nDest) ) = nOutsize;
			nOutsize += 2;
		}
	}
	
	void zstdecompress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize)
	{
		uint64_t size_ = ZSTD_getDecompressedSize(nValue, nInsize);
		
		nOutsize = int16_t( ZSTD_decompress(nDest, size_, nValue, nInsize) );
		if ( nOutsize != size_ ) {
			LOGE("[%s]nOutsize != size_", __METHOD__);
			nOutsize = 0;
		}
	}
	
	void lz4compress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize)
	{
		int16_t destSize_ = int16_t( LZ4_compressBound(nInsize) );
		
		nOutsize = int16_t( LZ4_compress_default(nValue, nDest + 4, nInsize, destSize_) );
		if ( nOutsize > 0 ) {
			(* ((int16_t *)nDest) ) = nOutsize;
			(* ((int16_t *)(nDest + 2)) ) = nInsize;
			nOutsize += 4;
		}
	}
	
	void lz4decompress(const char * nValue, char * nDest, int16_t& nOutsize)
	{
		nOutsize = (*( (int16_t *)nValue ));
		
		if ( LZ4_decompress_fast(nValue + 2, nDest, nOutsize) < 0 ) {
			nOutsize = 0;
		}
	}
	
	void runEncrypt(char * nValue, int32_t nInsize, int32_t nSeed)
	{
		int32_t block_ = (nInsize / 4);
		int32_t bytes_ = block_ * 4;
		
		for( int32_t i = 0; i < block_; ++i )
		{
			((int32_t *)nValue)[i] ^= nSeed;
			nSeed = ((int32_t *)nValue)[i];
		}
		
		int8_t seed_ = int8_t(nSeed);
		for( int32_t i = bytes_; i < nInsize; ++i )
		{
			nValue[i] ^= seed_;
		}
	}
	
	void runDecrypt(char * nValue, int32_t nInsize, int32_t nSeed)
	{
		int32_t block_ = (nInsize / 4);
		int32_t bytes_ = block_ * 4;
		
		int32_t iSeed_ = 0;
		for( int32_t i = 0; i < block_; ++i )
		{
			iSeed_ = ((int32_t *)nValue)[i];
			((int32_t *)nValue)[i] ^= nSeed;
			nSeed = iSeed_;
		}
		
		int8_t bSeed_ = int8_t(iSeed_);
		for( int32_t i = bytes_; i < nInsize; ++i )
		{
			nValue[i] ^= bSeed_;
		}
	}
	
}
