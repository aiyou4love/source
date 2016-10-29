#include "../../Serialize.hpp"

namespace cc {
	
	namespace convert_value {
		
		string ConvertValue<int64_t, string>::operator () (int64_t nValue) const
		{
			return int64ToStr(nValue);
		}
		
		bool ConvertValue<float, bool>::operator () (float nValue) const
		{
			return ( (0.001f > nValue) && (-0.001f < nValue) );
		}
		
		string ConvertValue<float, string>::operator () (float nValue) const
		{
			return doubleToStr(nValue);
		}
		
		bool ConvertValue<double, bool>::operator () (double nValue) const
		{
			return ((0.001 > nValue) && (-0.001 < nValue));
		}
		
		string ConvertValue<double, string>::operator () (double nValue) const
		{
			return doubleToStr(nValue);
		}
		
		bool ConvertValue<const char *, bool>::operator () (const char * nValue) const
		{
			int32_t value_ = strToInt32(nValue);
			return (1 == value_);
		}
		
		int64_t ConvertValue<const char *, int64_t>::operator () (const char * nValue) const
		{
			return strToInt64(nValue);
		}
		
		float ConvertValue<const char *, float>::operator () (const char * nValue) const
		{
			double value_ = strToDouble(nValue);
			return static_cast<float>(value_);
		}
		
		double ConvertValue<const char *, double>::operator () (const char * nValue) const
		{
			return strToDouble(nValue);
		}
		
		const char * ConvertValue<const char *, string>::operator () (const char * nValue) const
		{
			return nValue;
		}
		
		bool ConvertValue<string, bool>::operator () (const string& nValue) const
		{
			int32_t value_ = strToInt32(nValue.c_str());
			return (1 == value_);
		}
		
		int64_t ConvertValue<string, int64_t>::operator () (const string& nValue) const
		{
			return strToInt64(nValue.c_str());
		}
		
		float ConvertValue<string, float>::operator () (const string& nValue) const
		{
			double value_ = strToDouble(nValue.c_str());
			return static_cast<float>(value_);
		}
		
		double ConvertValue<string, double>::operator () (const string& nValue) const
		{
			return strToDouble(nValue.c_str());
		}
		
		const char * ConvertValue<string, string>::operator () (const string& nValue) const
		{
			return nValue.c_str();
		}
	}
	
}
