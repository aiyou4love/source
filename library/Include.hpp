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

#define EXITIME "2017.09.24|00:00:00"

typedef SPTR<std::thread> ThreadPtr;
