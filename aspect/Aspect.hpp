#pragma once

#include "../dispatch/Dispatch.hpp"

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
#include "account/social/cAccountAspect.hpp"

#include "role/role/RoleCondition.hpp"
#include "role/role/RoleReward.hpp"
#include "role/role/RoleAspect.hpp"
#include "role/agent/cRoleAspect.hpp"
#include "role/client/cRoleAspect.hpp"

#include "server/server/ServerCondition.hpp"
#include "server/server/ServerReward.hpp"
#include "server/server/ServerAspect.hpp"
#include "server/agent/cServerAspect.hpp"
#include "server/client/cServerAspect.hpp"

extern void aspectInit();
