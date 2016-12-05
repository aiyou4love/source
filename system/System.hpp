#pragma once

#include "../engine/Engine.hpp"

#include "ui/manager/IUiEngine.hpp"
#include "ui/manager/UiManager.hpp"
#include "ui/console/CommandArgs.hpp"
#include "ui/console/CommandBat.hpp"
#include "ui/console/ConsoleInput.hpp"
#include "ui/console/ConsoleUpdate.hpp"
#include "ui/console/ConsoleInputClone.hpp"
#include "ui/console/ConsoleUpdateClone.hpp"
#include "ui/console/ConsoleItem.hpp"
#include "ui/console/ConsoleUi.hpp"
#include "ui/console/ConsoleEngine.hpp"

#include "server/ServerItem.hpp"
#include "server/ServerEngine.hpp"

#include "time/time/EtimeBegin.hpp"
#include "time/time/EtimeCount.hpp"
#include "time/time/EtimeEnd.hpp"
#include "time/time/EtimeStart.hpp"
#include "time/time/EtimeState.hpp"
#include "time/time/EtimeType.hpp"
#include "time/time/TimeAdjust.hpp"
#include "time/time/TimeBegin.hpp"
#include "time/time/TimeCount.hpp"
#include "time/time/TimeEnd.hpp"
#include "time/time/TimeStart.hpp"
#include "time/time/TimeDuration.hpp"
#include "time/time/ServerTime.hpp"
#include "time/time/TimeEngine.hpp"
#include "time/server/cServerTime.hpp"
#include "time/client/cServerTime.hpp"

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

#include "role/role/RoleItem.hpp"
#include "role/client/cRoleListResult.hpp"
#include "role/client/RoleEngine.hpp"

#include "account/account/Account.hpp"
#include "account/account/AccountEngine.hpp"
#include "account/agent/cAccount.hpp"
#include "account/agent/cAccountEngine.hpp"
#include "account/social/cAccount.hpp"
#include "account/social/cAccountEngine.hpp"
#include "account/client/EaccountId.hpp"
#include "account/client/cRoleResult.hpp"
#include "account/client/cLoginResult.hpp"
#include "account/client/cAccount.hpp"
#include "account/client/cAccountEngine.hpp"

extern void systemInit();
