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
	
	char * zstdcompress(const char * nValue, size_t nInsize, int nLevel, size_t& nOutsize)
	{
		size_t destSize_ = ZSTD_compressBound(nInsize);
		char * result_ = new char[destSize_];
		
		nOutsize = ZSTD_compress(result_, destSize_, nValue, nInsize, nLevel);
		if (ZSTD_isError(nOutsize)) {
			LOGE("[%s]%s", __METHOD__, ZSTD_getErrorName(nOutsize));
			delete [] result_;
			result_ = nullptr;
			nOutsize = 0;
		}
		return result_;
	}
	
	char * zstdecompress(const char * nValue, size_t nInsize, size_t& nOutsize)
	{
		uint64_t size_ = ZSTD_getDecompressedSize(nValue, nInsize);
		if ( 0 == size_ ) {
			LOGE("[%s]0 == size_", __METHOD__);
			nOutsize = 0;
			return nullptr;
		}
		char * result_ = new char[size_];
		
		nOutsize = ZSTD_decompress(result_, size_, nValue, nInsize);
		if ( nOutsize != size_ ) {
			LOGE("[%s]nOutsize != size_)", __METHOD__);
			delete [] result_;
			nOutsize = 0;
			return nullptr;
		}
		return result_;
	}
	
	char * lz4compress(const char * nValue, size_t nInsize, int nLevel, size_t& nOutsize)
	{
		size_t headSize_ = sizeof(int32_t);
		
		int destSize_ = LZ4_compressBound((int)nInsize);
		size_t maxSize_ = headSize_ + size_t(destSize_);
		char * result_ = new char[maxSize_];
		
		*( (uint32_t *)result_ ) = uint32_t(nInsize);
		
		int size_ = 0;
		if (nLevel > 8) {
			size_ = LZ4_compress_HC(nValue, result_ + headSize_, int(nInsize), destSize_, 0);
		} else {
			size_ = LZ4_compress_default(nValue, result_ + headSize_, int(nInsize), destSize_);
		}
		if (size_ <= 0) {
			delete[] result_;
			return nullptr;
		}
		
		if ( (double(maxSize_) / double(size_ + headSize_)) >= 1.2 ) {
			char * bytes_ = new char[size_ + headSize_];
			memcpy(bytes_, result_, size_ + headSize_);
			delete[] result_;
			result_ = bytes_;
		}
		
		nOutsize = size_t(size_) + headSize_;
		return result_;
	}
	
	char * lz4decompress(const char * nValue, size_t nInsize, size_t& nOutsize)
	{
		size_t headSize_ = sizeof(int32_t);
		
		uint32_t size_ = *( (uint32_t *)nValue );
		char * result_ = new char[size_];
		
		if ( (nOutsize > 0) && (nOutsize == size_t(size_)) ) {
			int length_ = LZ4_decompress_fast(nValue + headSize_,
				result_, int(nOutsize));
				
			if ( length_ < 0 ) {
				delete[] result_;
				result_ = nullptr;
			}
		} else {
			int length_ = LZ4_decompress_safe(nValue + headSize_, 
				result_, int(nInsize - headSize_), size_);
				
			if ( length_ > 0 ) {
				nOutsize = size_t(length_);
			} else {
				delete[] result_;
				result_ = nullptr;
			}
		}
		
		return result_;
	}
	
}
