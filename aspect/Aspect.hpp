#pragma once

#include "../dispatch/Dispatch.hpp"

#include "plugin/Plugin.hpp"

#include "EaspectId.hpp"

#include "lua/LuaCondition.hpp"
#include "lua/LuaReward.hpp"
#include "lua/LuaAspect.hpp"

#include "ui/UiReward.hpp"
#include "ui/UiAspect.hpp"

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

extern void aspectInit();
