#pragma once

namespace cc {
	
	class Value : noncopyable
	{
	public:
		int8_t getInt8(int8_t nIndex);
		void pushInt8(int8_t nValue);
		
		int16_t getInt16(int8_t nIndex);
		void pushInt16(int16_t nValue);
		
		void setSelectId(int32_t nValue);
		
		int32_t getInt32(int8_t nIndex);
		void pushInt32(int32_t nValue);
		
		int64_t getInt64(int8_t nIndex);
		void pushInt64(int64_t nValue);
		
		float getFloat(int8_t nIndex);
		void pushFloat(float nValue);
		
		double getDouble(int8_t nIndex);
		void pushDouble(double nValue);
		
		const char * getString(int8_t nIndex);
		void pushString(const char * nValue);
		
		Buffer * getBuffer(int8_t nIndex);
		void pushBuffer(BufferPtr& nValue);
		
		intptr_t getIntptr(int8_t nIndex);
		void pushIntptr(intptr_t nValue);
		
		void setIndex(int32_t nIndex);
		int32_t getIndex();
		
		int8_t checkVersion(bool nHigh); 
		void initVersion();
		
		void printType(int8_t nIndex);
		int8_t getType(int8_t nIndex);
		int8_t getCount();
		
		void setSeed(int32_t nSeed);
		int32_t getSeed();
		
		int32_t getTime();
		void beginTime();
		void endTime();
		
		bool checkValue(vector<int16_t>& nIndexs);
		
		string getTextTime(int8_t nIndex);
		
		void runClear();
		
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runNumbers<vector<int16_t>, int16_t>(mIndexs, "indexs", "index");
			nSerialize.template runNumbers<vector<int8_t>, int8_t>(mInt8s, "int8s", "int8");
			nSerialize.template runNumbers<vector<int16_t>, int16_t>(mInt16s, "int16s", "int16");
			nSerialize.template runNumbers<vector<int32_t>, int32_t>(mInt32s, "int32s", "int32");
			nSerialize.template runNumbers<vector<int64_t>, int64_t>(mInt64s, "int64s", "int64");
			nSerialize.template runNumbers<vector<float>, float>(mFloats, "floats", "float");
			nSerialize.template runNumbers<vector<double>, double>(mDoubles, "doubles", "double");
			nSerialize.template runNumbers<vector<string>, string>(mStrings, "strings", "string");
			nSerialize.template runStreamPtrs<vector<BufferPtr>, BufferPtr>(mBuffers, "buffers", "buffer");
			
			nSerialize.runNumber(mVerMax, "verMax");
			nSerialize.runNumber(mVerMin, "verMin");
		}
		
		const char * streamName();
		const char * streamUrl();
		
		static void runLuaApi();
		
		Value();
		~Value();
		
	private:
		vector<int16_t> mIndexs;
		vector<int8_t> mInt8s;
		vector<int16_t> mInt16s;
		vector<int32_t> mInt32s;
		vector<int64_t> mInt64s;
		vector<float> mFloats;
		vector<double> mDoubles;
		vector<string> mStrings;
		vector<BufferPtr> mBuffers;
		vector<intptr_t> mIntptrs;
		
		int16_t mVerMax;
		int16_t mVerMin;
		
		int32_t mTime;
		
		int32_t mSeed;
		
		int32_t mIndex;
	};
	typedef SPTR<Value> ValuePtr;
	
}
