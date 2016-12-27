#pragma once

#include "../system/System.hpp"

#include "EdispatchId.hpp"

#include "application/Application.hpp"
#include "application/ApplicationUpdate.hpp"
#include "application/ApplicationUpdateClone.hpp"
#include "application/ApplicationEngine.hpp"

#include "account/account/AccountUpdate.hpp"
#include "account/account/AccountUpdateClone.hpp"
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

extern void dispatchInit();
