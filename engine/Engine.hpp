#pragma once

#include "../serialize/Serialize.hpp"

#include "handle/Context.hpp"
#include "handle/IContextClone.hpp"
#include "handle/Handle.hpp"
#include "handle/HandleConfig.hpp"
#include "handle/HandleCount.hpp"
#include "handle/HandleEngine.hpp"

#include "upint/Upint.hpp"
#include "upint/UpintEngine.hpp"

#include "aspect/value/Buffer.hpp"
#include "aspect/value/Value.hpp"
#include "aspect/value/IndexValue.hpp"
#include "aspect/value/PacketMgr.hpp"
#include "aspect/value/ValueMgr.hpp"
#include "aspect/dispatch/IDispatch.hpp"
#include "aspect/dispatch/DispatchEngine.hpp"
#include "aspect/doing/EdoingType.hpp"
#include "aspect/doing/Doing.hpp"
#include "aspect/trigger/EtriggerType.hpp"
#include "aspect/trigger/Trigger.hpp"
#include "aspect/entity/Property.hpp"
#include "aspect/entity/Entity.hpp"
#include "aspect/condition/Condition.hpp"
#include "aspect/condition/ConditionEngine.hpp"
#include "aspect/reward/Reward.hpp"
#include "aspect/reward/RewardEngine.hpp"
#include "aspect/select/Selector.hpp"
#include "aspect/select/IfSelect.hpp"
#include "aspect/select/SelectEngine.hpp"
#include "aspect/aspect/IAspect.hpp"
#include "aspect/aspect/AspectEngine.hpp"

extern void engineInit();
