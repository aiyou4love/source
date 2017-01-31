#pragma once

namespace cc {
	
	class BufReader : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			int16_t size_ = int16_t(sizeof(nValue));
			const char * buffer = this->getBuffer(size_);
			if (nullptr == buffer) {
				LOGE("[%s]%s", __METHOD__, nName);
				return;
			}
			nValue = *(T *)(buffer);
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			LOGE("[%s]%s", __METHOD__, nName);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runBuffer(char *& nValue, int16_t nLength);
		
		void runPush(const char * nName);
		bool runChild(const char * nName);
		bool runNext(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void selectStream(const char * nValue);
		
		int8_t pushBuf(char * nBuffer, int16_t nSize);
		int8_t nextBuf(char * nBuffer, int16_t nSize);
		
		void runDecompress(char * nBuffer, int8_t nType);
		void runDecrypt(int32_t nSeed);
		
		const char * getBuffer(int16_t nSize);
		
		void runClear();
		
		bool isText();
		
		BufReader();
		~BufReader();
		
	private:
		char mBuffer[PACKETSIZE];
		int16_t mCount;
		int16_t mLength;
		int16_t mPos;
		
		char mValue[PACKETSIZE];
		int16_t mSize;
		int16_t mPos0;
	};
	
}
