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
		
		template <class T>
		static void deletePtr(SPTR<T>& nValue)
		{
		}
		
		template <class T>
		static void deletePtr(T *& nValue)
		{
			delete nValue;
			nValue = nullptr;
		}
	};
	
}
