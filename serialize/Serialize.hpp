#pragma once

#include "../library/Include.hpp"

#include "normal/normal/Instance.hpp"
#include "normal/normal/DefaultValue.hpp"
#include "normal/normal/CommonMethod.hpp"
#include "normal/class/ClassMethod.hpp"
#include "normal/convert/ConvertValue.hpp"
#include "normal/string/StringMethod.hpp"
#include "normal/string/StringTable.hpp"
#include "normal/count/IntArray.hpp"
#include "normal/count/IntArrayN.hpp"
#include "normal/count/BitCount.hpp"
#include "normal/count/Int32Count.hpp"
#include "normal/count/IntCount.hpp"
#include "normal/value/Buffer.hpp"
#include "normal/value/Value.hpp"
#include "normal/value/IndexValue.hpp"
#include "normal/value/PacketMgr.hpp"
#include "normal/value/ValueMgr.hpp"

#include "log/LogEngine.hpp"

#include "lua/LuaWriter.hpp"
#include "lua/LuaThread.hpp"
#include "lua/LuaEngine.hpp"

#include "workDirectory/EappType.hpp"
#include "workDirectory/WorkDirectory.hpp"

#include "lifecycle/LifeCycle.hpp"

#include "time/LocalTime.hpp"
#include "time/EtimeBegin.hpp"
#include "time/EtimeCount.hpp"
#include "time/EtimeEnd.hpp"
#include "time/EtimeStart.hpp"
#include "time/EtimeState.hpp"
#include "time/EtimeType.hpp"
#include "time/TimeAdjust.hpp"
#include "time/TimeBegin.hpp"
#include "time/TimeCount.hpp"
#include "time/TimeEnd.hpp"
#include "time/TimeStart.hpp"
#include "time/TimeDuration.hpp"

#include "serialize/serialize/BinReader.hpp"
#include "serialize/serialize/BinWriter.hpp"
#include "serialize/serialize/BufReader.hpp"
#include "serialize/serialize/BufWriter.hpp"
#include "serialize/serialize/JsonReader.hpp"
#include "serialize/serialize/JsonWriter.hpp"
#include "serialize/serialize/TableReader.hpp"
#include "serialize/serialize/XmlReader.hpp"
#include "serialize/serialize/XmlWriter.hpp"
#include "serialize/serialize/IoReader.hpp"
#include "serialize/serialize/IoWriter.hpp"

#include "serialize/config/ConfigEngine.hpp"
#include "serialize/table/TableEngine.hpp"
#include "serialize/userDefault/UserDefault.hpp"

#include "handle/Context.hpp"
#include "handle/IContextClone.hpp"
#include "handle/Handle.hpp"
#include "handle/HandleConfig.hpp"
#include "handle/HandleCount.hpp"
#include "handle/HandleEngine.hpp"

extern void serializeInit();
extern void serializeStart();

