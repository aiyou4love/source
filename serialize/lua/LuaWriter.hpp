#pragma once

namespace cc {
	
	class LuaWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T nValue, const char * nName)
		{
			this->runFirst();
			
			mValue += nName;
			mValue += "=";
			mValue += convertValue<T, string>(nValue);
		}
		void runNumber(string& nValue, const char * nName);
		
		template <typename T0, typename T1>
		void runNumbers(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1 value_ = (*it);
				this->runNumber(value_);
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void runMapNumbers(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1 value_ = it->second;
				this->runNumber(value_);
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void luaNumbers(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1 value_ = (*it);
				this->runNumber(value_);
			}
			luaEnd(nName);
		}
		
		template <typename T0, typename T1>
		void luaMapNumbers(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1 value_ = it->second;
				this->runNumber(value_);
			}
			luaEnd(nName);
		}
		
		template <typename T>
		void runStream(T& nValue, const char * nName)
		{
			tableBegin(nName);
			nValue.luaValue(this, nName);
			tableEnd();
		}
		
		template <typename T>
		void runStreamPtr(T& nValue, const char * nName)
		{
			tableBegin(nName);
			nValue->luaValue(this, nName);
			tableEnd();
		}
	
		template <typename T>
		void luaStream(T& nValue, const char * nName)
		{
			luaBegin(nName);
			nValue.serialize(this, nName, 0);
			luaEnd(nName);
		}
		
		template <typename T>
		void luaStreamPtr(T& nValue, const char * nName)
		{
			luaBegin(nName);
			nValue->serialize(this, nName, 0);
			luaEnd(nName);
		}
		
		template <typename T0, typename T1>
		void runStreams(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = (*it);
				tableBegin();
				value_.serialize(this, nName, 0);
				tableEnd();
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void runMapStreams(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = it->second;
				tableBegin();
				value_.serialize(this, nName, 0);
				tableEnd();
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void runStreamPtrs(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = (*it);
				tableBegin();
				value_->serialize(this, nName, 0);
				tableEnd();
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void runMapStreamPtrs(T0& nValue, const char * nName)
		{
			tableBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = it->second;
				tableBegin();
				value_->serialize(this, nName, 0);
				tableEnd();
			}
			tableEnd();
		}
		
		template <typename T0, typename T1>
		void luaStreams(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = (*it);
				tableBegin();
				value_.serialize(this, nName, 0);
				tableEnd();
			}
			luaEnd(nName);
		}
		
		template <typename T0, typename T1>
		void luaMapStreams(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = it->second;
				tableBegin();
				value_.serialize(this, nName, 0);
				tableEnd();
			}
			luaEnd(nName);
		}
		
		template <typename T0, typename T1>
		void luaStreamPtrs(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = (*it);
				tableBegin();
				value_->serialize(this, nName, 0);
				tableEnd();
			}
			luaEnd(nName);
		}
		
		template <typename T0, typename T1>
		void luaMapStreamPtrs(T0& nValue, const char * nName)
		{
			luaBegin(nName);
			auto it = nValue.begin();
			for ( ; it != nValue.end(); ++it ) {
				T1& value_ = it->second;
				tableBegin();
				value_->serialize(this, nName, 0);
				tableEnd();
			}
			luaEnd(nName);
		}
		
		void luaBegin(const char * nName);
		void luaEnd(const char * nName);
		
		const char * getLuaValue();
		
	private:
		void tableBegin();
		void tableBegin(const char * nName);
		void tableEnd();
		
		void runNumber(string& nValue);
		
		template <typename T>
		void runNumber(T nValue)
		{
			this->runFirst();
			
			mValue += convertValue<T, string>(nValue);
		}
		void runFirst();
		
	public:
		LuaWriter();
		~LuaWriter();
		
	private:
		string mValue;
		bool mFirst;
	};
	typedef SPTR<LuaWriter> LuaWriterPtr;
	typedef WPTR<LuaWriter> LuaWriterWtr;
	
}
