#pragma once

namespace cc {
	
	class Sink : noncopyable
	{
	public:
		int32_t getSinkId();
		int8_t getSinkType();
		int32_t getSinkValue();
		int32_t getActionId();
		int32_t getDeleteId();
		
		Sink();
		~Sink();
		
	private:
		int32_t mSinkId;
		int8_t mSinkType;
		int32_t mSinkValue;
		int32_t mActionId;
		int32_t mDeleteId;
	};
	typedef SPTR<Sink> SinkPtr;
	
}
