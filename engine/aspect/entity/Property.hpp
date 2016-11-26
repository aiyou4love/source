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
		map<int32_t, SinkPtr *> mSinks;
		
		EntityPtr * mEntity;
	};
	typedef SPTR<Property> PropertyPtr;
	
}
