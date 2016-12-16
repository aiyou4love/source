#pragma once

namespace cc {
	
#ifdef __CLIENT__
	class CommandBat : noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize, const char * nName)
		{
			nSerialize.template runNumbers<list<string>, string>(mCommands, "commands", "command");
		}
		
		const char * streamName();
		
		list<string>& getCommands();
		
		CommandBat();
		~CommandBat();
		
	private:
		list<string> mCommands;
	};
#endif
	
}
