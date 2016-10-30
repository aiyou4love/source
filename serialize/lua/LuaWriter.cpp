#include "../Serialize.hpp"

namespace cc {
	
	void LuaWriter::runNumber(string& nValue, const char * nName)
	{
		this->runFirst();
		mValue += nName;
		mValue += "=[=[";
		mValue += nValue;
		mValue += "]=]";
	}
	
	void LuaWriter::runNumber(string& nValue)
	{
		this->runFirst();
		mValue += "=[=[";
		mValue += nValue;
		mValue += "]=]";
	}
	
	void LuaWriter::runFirst()
	{
		if (!mFirst) {
			mValue += ",";
		}
		if (mFirst) {
			mFirst = false;
		}
	}
	
	void LuaWriter::tableBegin(const char * nName)
	{
		this->runFirst();
		mValue += nName;
		mValue += "={";
		mFirst = true;
	}
	
	void LuaWriter::tableBegin()
	{
		this->runFirst();
		mValue += "{";
		mFirst = true;
	}
	
	void LuaWriter::tableEnd()
	{
		mValue += "}";
		mFirst = false;
	}
	
	void LuaWriter::luaBegin(const char * nName)
	{
		mValue += "local ";
		mValue += nName;
		mValue += "={";
		mFirst = true;
	}
	
	void LuaWriter::luaEnd(const char * nName)
	{
		mValue += "}return ";
		mValue += nName;
	}
	
	const char * LuaWriter::getLuaValue()
	{
		return mValue.c_str();
	}

	LuaWriter::LuaWriter()
		: mValue ("")
		, mFirst (true)
	{
	}
	
	LuaWriter::~LuaWriter()
	{
		mFirst = true;
		mValue = "";
	}
	
}
