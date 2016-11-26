#pragma once

namespace cc {
	
	class Trigger : noncopyable
	{
	public:
		void setEntity(EntityPtr& nEntity);
		EntityPtr& getEntity();
		void setValue(ValuePtr& nValue);
		ValuePtr& getValue();
		
		Trigger();
		~Trigger();
		
	private:
		EntityPtr mEntity;
		ValuePtr mValue;
	};
	typedef SPTR<Trigger> TriggerPtr;
	
}
