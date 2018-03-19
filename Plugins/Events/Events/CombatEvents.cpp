#include "Events/CombatEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Events.hpp"
#include "Helpers.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Hooking::FunctionHook* g_StartCombatRoundHook;

CombatEvents::CombatEvents(ViewPtr<HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSCombatRound__StartCombatRound,
        int32_t, API::CNWSCombatRound*, uint32_t>(&StartCombatRoundHook);

    g_StartCombatRoundHook = hooker->FindHookByAddress(API::Functions::CNWSCombatRound__StartCombatRound);
}

int32_t CombatEvents::StartCombatRoundHook(API::CNWSCombatRound* thisPtr, Types::ObjectID oidTarget)
{
    Events::StartEvent("NWNX_ON_START_COMBAT_ROUND_BEFORE");
    Events::PushEventData("TARGET_OBJECT_ID", Helpers::ObjectIDToString(oidTarget));
    bool proceed = Events::SignalEvent(thisPtr->m_pBaseCreature->m_idSelf);
    Events::EndEvent();

    int32_t ret = 0;
    if (proceed)
    {
        ret = g_StartCombatRoundHook->CallOriginal<int32_t>(thisPtr, oidTarget);
    }

    Events::StartEvent("NWNX_ON_START_COMBAT_ROUND_AFTER);
    Events::PushEventData("TARGET_OBJECT_ID", Helpers::ObjectIDToString(oidTarget));
    Events::SignalEvent(thisPtr->m_pBaseCreature->m_idSelf);
    Events::EndEvent();

    return ret;
}

}
