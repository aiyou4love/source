#pragma once

namespace cc {
	
	class Instance : noncopyable
	{
	public:
		template <class T>
		static void instance(SPTR<T>& nValue)
		{
			nValue.reset(new T());
		}
		
		template <class T>
		static void instance(T *& nValue)
		{
			nValue = new T();
		}
	};
	
}
