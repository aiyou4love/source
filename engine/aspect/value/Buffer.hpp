#pragma once

namespace cc {
	
	class Buffer : noncopyable
	{
	public:
		template<class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mLength, "length");
			nSerialize->runBuffer(mValue, mLength);
		}
		
		int16_t getLength();
		char * getValue();
		
		Buffer();
		Buffer(char * nValue, int16_t nLength, bool nIsNew);
		~Buffer();
		
	private:
		char * mValue;
		int16_t mLength;
		bool mIsNew;
	};
	typedef SPTR<Buffer> BufferPtr;
	
}
