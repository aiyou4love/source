#pragma once

namespace cc {
	
	namespace convert_value {
		
		template<typename T1, typename T2>
		struct ConvertValue
		{
			T2 operator () (T1 nValue) const
			{
				return static_cast<T1>(nValue);
			}
		};
		
		template<typename T1>
		struct ConvertValue<T1, string>
		{
			string operator () (T1 nValue) const
			{
				return int32ToStr(nValue);
			}
		};
		
		template<>
		struct ConvertValue<int64_t, string>
		{
			string operator () (int64_t nValue) const;
		};
		
		template<>
		struct ConvertValue<float, bool>
		{
			bool operator () (float nValue) const;
		};
		
		template<>
		struct ConvertValue<float, string>
		{
			string operator () (float nValue) const;
		};
		
		template<>
		struct ConvertValue<double, bool>
		{
			bool operator () (double nValue) const;
		};
		
		template<>
		struct ConvertValue<double, string>
		{
			string operator () (double nValue) const;
		};
		
		template<typename T2>
		struct ConvertValue<const char *, T2>
		{
			T2 operator () (const char * nValue) const
			{
				int32_t value_ = strToInt32(nValue);
				return static_cast<T2>(value_);
			}
		};
		
		template<>
		struct ConvertValue<const char *, bool>
		{
			bool operator () (const char * nValue) const;
		};
		
		template<>
		struct ConvertValue<const char *, int64_t>
		{
			int64_t operator () (const char * nValue) const;
		};
		
		template<>
		struct ConvertValue<const char *, float>
		{
			float operator () (const char * nValue) const;
		};
		
		template<>
		struct ConvertValue<const char *, double>
		{
			double operator () (const char * nValue) const;
		};
		
		template<>
		struct ConvertValue<const char *, string>
		{
			const char * operator () (const char * nValue) const;
		};
		
		template<typename T2>
		struct ConvertValue<string, T2>
		{
			T2 operator () (string& nValue) const
			{
				int32_t value_ = strToInt32(nValue.c_str());
				return static_cast<T2>(value_);
			}
		};
		
		template<>
		struct ConvertValue<string, bool>
		{
			bool operator () (const string& nValue) const;
		};
		
		template<>
		struct ConvertValue<string, int64_t>
		{
			int64_t operator () (const string& nValue) const;
		};
		
		template<>
		struct ConvertValue<string, float>
		{
			float operator () (const string& nValue) const;
		};
		
		template<>
		struct ConvertValue<string, double>
		{
			double operator () (const string& nValue) const;
		};
		
		template<>
		struct ConvertValue<string, string>
		{
			const char * operator () (const string& nValue) const;
		};
	}
	
	template<typename T1, typename T2>
	T2 convertValue(T1 nValue)
	{
		return convert_value::ConvertValue<T1, T2>()(nValue);
	}
	
}
