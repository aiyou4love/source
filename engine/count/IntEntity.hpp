#pragma once

namespace cc {
	
	class IntEntity : public Property
	{
	public:
		
		IntEntity();
		~IntEntity();
		
	private:
		map<int16_t, IntArrayMPtr> mIntArrayMs;
	};
	typedef SPTR<IntEntity> IntEntityPtr;
	
}
