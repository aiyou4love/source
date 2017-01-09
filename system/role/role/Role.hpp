#pragma once

namespace cc {
	
	class Role : public Entity
	{
	public:
		virtual int64_t getId() = 0;
		
		Role();
		virtual ~Role();
	};
	
}
