#pragma once

#include "../engine/Engine.hpp"

#include "ui/manager/EuiEngine.hpp"
#include "ui/manager/EuiScene.hpp"
#include "ui/manager/UiName.hpp"
#include "ui/manager/IUiEngine.hpp"
#include "ui/manager/UiManager.hpp"
#include "ui/console/CommandArgs.hpp"
#include "ui/console/CommandBat.hpp"
#include "ui/console/ConsoleInput.hpp"
#include "ui/console/ConsoleUiUpdate.hpp"
#include "ui/console/ConsoleGameUpdate.hpp"
#include "ui/console/ConsoleInputClone.hpp"
#include "ui/console/ConsoleUiUpdateClone.hpp"
#include "ui/console/ConsoleGameUpdateClone.hpp"
#include "ui/console/ConsoleItem.hpp"
#include "ui/console/ConsoleUi.hpp"
#include "ui/console/ConsoleScene.hpp"
#include "ui/console/ConsoleEngine.hpp"

#include "task/engine/EtaskType.hpp"
#include "task/engine/EopenType.hpp"
#include "task/engine/TaskConfig.hpp"
#include "task/entity/DailyTask.hpp"
#include "task/entity/TaskAccept.hpp"
#include "task/entity/TaskFinish.hpp"
#include "task/entity/SingleTask.hpp"
#include "task/entity/EntityTask.hpp"
#include "task/client/cTaskConfig.hpp"
#include "task/server/cTaskConfig.hpp"
#include "task/engine/TaskEngine.hpp"

#include "activity/ActivityConfig.hpp"
#include "activity/ActivityEngine.hpp"

#include "server/info/ServerItem.hpp"
#include "server/info/ServerInfo.hpp"
#include "server/client/ServerEngine.hpp"
#include "server/server/ServerEngine.hpp"

#include "role/role/Role.hpp"
#include "role/role/RoleEngine.hpp"
#include "role/role/RoleUpdate.hpp"
#include "role/role/RoleUpdateClone.hpp"

#include "role/client/EroleId.hpp"
#include "role/client/RoleItem.hpp"
#include "role/client/cRoleList.hpp"
#include "role/client/cRoleListResult.hpp"
#include "role/client/cRole.hpp"
#include "role/client/cRoleEngine.hpp"

#include "role/agent/cRole.hpp"
#include "role/agent/cRoleEngine.hpp"

#include "role/game/cRole.hpp"
#include "role/game/cRoleEngine.hpp"

#include "role/social/cRole.hpp"
#include "role/social/cRoleEngine.hpp"

#include "EdispatchId.hpp"

#include "application/Application.hpp"
#include "application/ApplicationUpdate.hpp"
#include "application/ApplicationUpdateClone.hpp"
#include "application/ApplicationEngine.hpp"

#include "account/account/Account.hpp"
#include "account/account/AccountEngine.hpp"
#include "account/agent/cAccount.hpp"
#include "account/agent/cAccountEngine.hpp"
#include "account/client/cLoginResult.hpp"
#include "account/client/cRoleResult.hpp"
#include "account/client/cAccount.hpp"
#include "account/client/cAccountEngine.hpp"

extern void systemInit();
