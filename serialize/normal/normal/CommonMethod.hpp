#pragma once

namespace cc {
	
	extern int32_t strToInt32(const char * nValue);
	extern string int32ToStr(int32_t nValue);
	extern int64_t strToInt64(const char * nValue);
	extern string int64ToStr(int64_t nValue);
	extern double strToDouble(const char * nValue);
	extern string doubleToStr(double nValue);
	extern int32_t stringCrc(const char * nValue);
	extern wstring UTF8ToUTF16(const char * nValue);
	extern string UTF16ToUTF8(const wchar_t * nValue);
#ifdef __WINDOW__
	extern string UTF8ToGBK(const char * nValue);
	extern string GBKToUTF8(const char * nValue);
#endif
	extern int64_t linkInt32(int32_t nId0, int32_t nId1);
	extern int32_t linkInt16(int16_t nId0, int16_t nId1);
	extern int16_t linkInt8(int8_t nId0, int8_t nId1);
	extern int32_t linkInt24(int8_t nId1, int32_t nId0);
	
	extern void zstdecompress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize);
	extern void zstdcompress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize);
	
	extern void lz4compress(const char * nValue, int16_t nInsize, char * nDest, int16_t& nOutsize);
	extern void lz4decompress(const char * nValue, char * nDest, int16_t& nOutsize);
	
	extern void runEncrypt(char * nValue, int32_t nInsize, int32_t nSeed);
	extern void runDecrypt(char * nValue, int32_t nInsize, int32_t nSeed);
	
}
