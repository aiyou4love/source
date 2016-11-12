#pragma once

namespace cc {
	
	class IntEntity : public Property
	{
	public:
		IntEntity();
		~IntEntity();
		
	private:
		map<int16_t, IntArrayPtr> mIntArrays;
	};
	typedef SPTR<IntEntity> IntEntityPtr;
	
}
 