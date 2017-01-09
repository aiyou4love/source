#pragma once

#include "../system/System.hpp"

#include "plugin/Plugin.hpp"

#include "EaspectId.hpp"

#include "lua/LuaCondition.hpp"
#include "lua/LuaReward.hpp"
#include "lua/LuaAspect.hpp"

#include "ui/UiReward.hpp"
#include "ui/UiAspect.hpp"

#include "app/AppReward.hpp"
#include "app/AppAspect.hpp"

#include "account/account/AccountCondition.hpp"
#include "account/account/AccountReward.hpp"
#include "account/account/AccountAspect.hpp"
#include "account/agent/cAccountAspect.hpp"
#include "account/client/cAccountAspect.hpp"

#include "net/net/NetReward.hpp"
#include "net/net/NetAspect.hpp"
#include "net/agent/cNetAspect.hpp"
#include "net/client/cAgentResult.hpp"
#include "net/client/cNetAspect.hpp"
#include "net/game/cNetAspect.hpp"
#include "net/social/cNetAspect.hpp"

#include "role/role/RoleCondition.hpp"
#include "role/role/RoleReward.hpp"
#include "role/role/RoleAspect.hpp"
#include "role/agent/cRoleAspect.hpp"
#include "role/client/cRoleAspect.hpp"
#include "role/game/cRoleAspect.hpp"
#include "role/client/cRoleAspect.hpp"

#include "server/common/ServerCondition.hpp"
#include "server/common/ServerReward.hpp"
#include "server/common/ServerAspect.hpp"
#include "server/server/cServerAspect.hpp"
#include "server/client/cServerAspect.hpp"

extern void aspectInit();
