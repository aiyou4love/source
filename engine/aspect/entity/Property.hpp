#pragma once

namespace cc {
	
	class Entity;
	class Property : public SinkMgr
	{
	public:
		void setEntity(Entity * nEntity);
		Entity * getEntity();
		
		Property();
		virtual ~Property();
	};
	typedef SPTR<Property> PropertyPtr;
	
}
