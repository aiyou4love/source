#pragma once

namespace cc {
	
	class Entity;
	typedef SPTR<Entity> EntityPtr;
	class Property : noncopyable
	{
	public:
		void setEntity(EntityPtr& nEntity);
		EntityPtr& getEntity();
		
		Property();
		virtual ~Property();
		
	protected:
		EntityPtr * mEntity;
	};
	typedef SPTR<Property> PropertyPtr;
	
}
