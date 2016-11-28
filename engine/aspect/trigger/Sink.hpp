#pragma once

namespace cc {
	
	class Sink : noncopyable
	{
	public:
		int16_t getSinkId();
		int16_t getSinkType();
		int32_t getSinkValue();
		int32_t getActionId();
		int32_t getDeleteId();
		
		template <class T>
		void serialize(T * nSerialize, const char * nName, int8_t nCount)
		{
			nSerialize->runNumber(mSinkId, "sinkId");
			nSerialize->runNumber(mSinkType, "sinkType");
			nSerialize->runNumber(mSinkValue, "sinkValue");
			nSerialize->runNumber(mActionId, "actionId");
			nSerialize->runNumber(mDeleteId, "deleteId");
		}
		int16_t getKey();
		bool isDefault();
		
		Sink();
		~Sink();
		
	private:
		int16_t mSinkId;
		int16_t mSinkType;
		int32_t mSinkValue;
		int32_t mActionId;
		int32_t mDeleteId;
	};
	typedef SPTR<Sink> SinkPtr;
	
}
