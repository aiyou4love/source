#pragma once

namespace cc {
	
	class IntEntity : public Property
	{
	public:
		void initIntIndex(IntIndexPtr& nIntIndex);
		void clearIntArray(int16_t nType);
		
		IntEntity();
		~IntEntity();
		
	private:
		map<int16_t, IntArrayPtr> mIntArrays;
	};
	typedef SPTR<IntEntity> IntEntityPtr;
	
}
