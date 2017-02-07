#include "../../Engine.hpp"

namespace cc {
	
	void Property::setEntity(Entity * nEntity)
	{
		mEntity = nEntity;
	}
	
	Entity * Property::getEntity()
	{
		return mEntity;
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
