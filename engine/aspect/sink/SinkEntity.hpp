#pragma once

namespace cc {
	
	class SinkEntity : public Property
	{
	public:
		void initSink(EntityPtr& nEntity);
		void runInit(EntityPtr& nEntity);
		const char * countName();
		
		SinkEntity();
		~SinkEntity();
		
	private:
		Int32Count mInt32Count;
	};
	typedef SPTR<SinkEntity> SinkEntityPtr;
	
}
