#pragma once

namespace cc {
	
	namespace default_namespace {
		
		template<typename T>
		struct DefaultValue
		{
			T operator () () const
			{
				return 0;
			}
		};
		
		template<>
		struct DefaultValue<bool>
		{
			bool operator () () const
			{
				return false;
			}
		};
		
		template<>
		struct DefaultValue<float>
		{
			float operator () () const
			{
				return 0.f;
			}
		};
		
		template<>
		struct DefaultValue<double>
		{
			double operator () () const
			{
				return 0.;
			}
		};
		
		template<>
		struct DefaultValue<const char *>
		{
			const char * operator () () const
			{
				return "";
			}
		};
		
		template<>
		struct DefaultValue<string>
		{
			const char * operator () () const
			{
				return "";
			}
		};
		
		template<typename T>
		struct DefaultValue<SPTR<T> >
		{
			SPTR<T> operator () () const
			{
				static SPTR<T> t_;
				return t_;
			}
		};
		
	}
	
	template<typename T>
	T defaultValue()
	{
		return default_namespace::DefaultValue<T>()();
	}
	
	template<typename T>
	SPTR<T>& defaultPtr()
	{
		static SPTR<T> t_;
		return t_;
	}
	
}
