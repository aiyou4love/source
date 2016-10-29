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
	
}
