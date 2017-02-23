#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <random>
#include <typeinfo>
#include <cstdlib>
#include <thread>
#include <atomic>
#include <mutex>
#include <memory>
#include <codecvt>
#include <locale>
#include <chrono>
#include <iostream>

#include <zstd.h>

#include <lz4/lz4hc.h>
#include <lz4/lz4.h>

#pragma warning(push)
#pragma warning(disable:4819)
#pragma warning(disable:4003)
#include <boost/log/sources/logger.hpp>
#include <boost/asio.hpp>
#include <boost/crc.hpp>
#include <boost/utility.hpp>
#include <boost/format.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/signals2.hpp>
#include <boost/dll/import.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>

#include <curl/curl.h>

#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml.hpp"

#include "lua/lua_tinker.h"
#pragma warning(pop)

using namespace std;
using namespace std::chrono;
using namespace boost;
using namespace rapidxml;

#ifdef APIEXPORT
#define __api __declspec(dllexport)
#else
#define __api
#endif

#if defined(_WIN32) ||  defined(_WIN64)
#define __WINDOW__
#endif

#ifdef __WINDOW__
#define __METHOD__ __FUNCTION__
#else
#define __METHOD__ __PRETTY_FUNCTION__
#endif

#define STD_SIGNAL boost::signals2::signal

#define SPTR std::shared_ptr
#define WPTR std::weak_ptr
#define PTR_SCST std::static_pointer_cast
#define PTR_DCST std::dynamic_pointer_cast
#define SPTR_THIS std::enable_shared_from_this
#define SED_THIS shared_from_this
#define LKGUD std::lock_guard

#define PACKETSIZE 8192


#define SEEDDEF  924

#define EXITIME "2017.09.24|00:00:00"

#define __CLIENTB64__ "Y2xpZW50"
#define __GMCLIENTB64__ "Z21jbGllbnQ="
#define __DECLIENTB64__ "ZGVjbGllbnQ="
#define __AGENTB64__ "YWdlbnQ="
#define __SOCIALB64__ "c29jaWFs"
#define __GAMEB64__ "Z2FtZQ=="

#ifdef __GAMEGM__
#define __CLIENTB64EX__ __GMCLIENTB64__
#elif defined __GAMEDE__
#define __CLIENTB64EX__ __DECLIENTB64__
#else
#define __CLIENTB64EX__ __CLIENTB64__
#endif

#ifdef __CLIENT__
	#define __EXEBASE64__ __CLIENTB64EX__
	#define APPNAME "client"
#elif defined __AGENT__
	#define __EXEBASE64__ __AGENTB64__
	#define APPNAME "agent"
#elif defined __SOCIAL__
	#define __EXEBASE64__ __SOCIALB64__
	#define APPNAME "social"
#elif defined __GAME__
	#define __EXEBASE64__ __GAMEB64__
	#define APPNAME "game"
#else
	#define __EXEBASE64__ __CLIENTB64EX__
	#define APPNAME "client"
#endif

typedef SPTR<std::thread> ThreadPtr;
