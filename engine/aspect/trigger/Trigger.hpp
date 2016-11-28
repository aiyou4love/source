#pragma once

namespace cc {
	
	class Trigger : noncopyable
	{
	public:
		void setEntity(EntityPtr& nEntity);
		EntityPtr& getEntity();
		void setValue(ValuePtr& nValue);
		ValuePtr& getValue();
		void setActionId(int32_t nActionId);
		
		Trigger();
		~Trigger();
		
	private:
		EntityPtr mEntity;
		ValuePtr mValue;
	};
	
}
