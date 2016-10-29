#pragma once

namespace cc {
	
	template<int16_t N = 128>
	class IntArrayN : public IntArray
	{
	public:
		int32_t * rangeInts(int16_t nBegin, int16_t nEnd)
		{
			if ( (nBegin <= 0) || (nBegin >= N) 
				|| (nEnd > N) || (nBegin >= nEnd) ) {
				LOGE("[%s]%d,%d", __METHOD__, nBegin, nEnd);
				return nullptr;
			}
			return (mValue + nBegin - 1);
		}
		
		void runDirty()
		{
			mIsDirty = true;
		}
		
		bool isDirty()
		{
			return mIsDirty;
		}
		
		IntArrayN()
			: mIsDirty (false)
		{
			memset(mValue, 0, sizeof(mValue));
		}
		
		~IntArrayN()
		{
			memset(mValue, 0, sizeof(mValue));
			mIsDirty = false;
		}
		
	private:
		int32_t mValue[N];
		bool mIsDirty;
	};
	
}
