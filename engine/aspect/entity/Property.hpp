#pragma once

namespace cc {
	
	class Entity;
	typedef SPTR<Entity> EntityPtr;
	class Property : public SinkMgr
	{
	public:
		void setEntity(Entity * nEntity);
		Entity * getEntity();
		
		Property();
		virtual ~Property();
		
	private:
		Entity * mEntity;
	};
	typedef SPTR<Property> PropertyPtr;
	
}
