#pragma once

#include <map>

#pragma warning(push)
#pragma warning(disable:4819)
#pragma warning(disable:4003)
#include <boost/log/sources/logger.hpp>
#include <boost/utility.hpp>
#include <boost/format.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/dll/import.hpp>

#include <curl/curl.h>

#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>

#pragma warning(pop) 

using namespace std;
using namespace boost;

#if defined(_WIN32) ||  defined(_WIN64)
#define __WINDOW__
#endif

#ifdef __WINDOW__
#define __METHOD__ __FUNCTION__
#else
#define __METHOD__ __PRETTY_FUNCTION__
#endif

#define SODLLZIP "aspect.zip"
#ifdef __WINDOW__
#define SODLLNAME "aspect.dll"
#else
#define SODLLNAME "aspect.so"
#endif

#include "zip/miniz.h"
#include "zip/zip_file.hpp"

#include "directory/AutoupDirectory.hpp"

#include "log/LogEx.hpp"

#include "curl/AutoupCurl.hpp"

#include "serialize/AutocReader.hpp"
#include "serialize/AutojReader.hpp"
#include "serialize/AutojWriter.hpp"

#include "startup/IPlugin.hpp"
#include "startup/Startup.hpp"

#include "autoup/AutoupItem.hpp"
#include "autoup/AutoupSave.hpp"
#include "autoup/AutoupEngine.hpp"
