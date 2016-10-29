#pragma once

namespace cc {
	
	class BufWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			if ((mLength + sizeof(int16_t)+sizeof(T)) > PACKETSIZE) {
				LOGE("[%s]%s", __METHOD__, nName);
				return;
			}
			memcpy((mBuffer + mLength + sizeof(int16_t)), &nValue, sizeof(T));
			mLength += sizeof(T);
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
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void pushChild(const char * nName);
		void popChild(const char * nName);
		
		void selectStream(const char * nValue);
		
		int16_t getSize();
		char * getValue();
		void runClear();
		void runEnd();
		
		bool isText();
		
		BufWriter();
		~BufWriter();
		
	private:
		char mBuffer[PACKETSIZE];
		int16_t mLength;
	};
	
}
