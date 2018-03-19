
#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class CombatEvents
{
public:
    CombatEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t StartCombatRoundHook(NWNXLib::API::CNWSCombatRound*, NWNXLib::API::Types::ObjectID);
};

}
