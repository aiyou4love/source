#include "../../Engine.hpp"

namespace cc {
	
	void Property::setEntity(EntityPtr& nEntity)
	{
		mEntity = (&nEntity);
	}
	
	EntityPtr& Property::getEntity()
	{
		return (*mEntity);
	}
	
	Property::Property()
		: mEntity(nullptr)
	{
	}
	
	Property::~Property()
	{
		mEntity = nullptr;
	}
	
}
