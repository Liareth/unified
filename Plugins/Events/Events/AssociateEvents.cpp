#include "Events/AssociateEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Helpers.hpp"

namespace Events {

using namespace NWNXLib;

static Hooking::FunctionHook* g_AddAssociateHook = nullptr;
static Hooking::FunctionHook* g_RemoveAssociateHook = nullptr;

AssociateEvents::AssociateEvents(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__AddAssociate, void, API::CNWSCreature*, API::Types::ObjectID, uint16_t>(&AddAssociateHook);
    hooker->RequestExclusiveHook<API::Functions::CNWSCreature__RemoveAssociate, void, API::CNWSCreature*, API::Types::ObjectID>(&RemoveAssociateHook);

    g_AddAssociateHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__AddAssociate);
    g_RemoveAssociateHook = hooker->FindHookByAddress(API::Functions::CNWSCreature__RemoveAssociate);
}

void AssociateEvents::AddAssociateHook(API::CNWSCreature* thisPtr, API::Types::ObjectID assocId, uint16_t unused)
{
    std::string assocIdStr = Helpers::ObjectIDToString(assocId);

    Events::PushEventData("ASSOCIATE_OBJECT_ID", assocIdStr);
    if (Events::SignalEvent("NWNX_ON_ADD_ASSOCIATE_BEFORE", thisPtr->m_idSelf))
    {
        g_AddAssociateHook->CallOriginal<void>(thisPtr, assocIdStr, unused);
    }

    Events::PushEventData("ASSOCIATE_OBJECT_ID", assocIdStr);
    Events::SignalEvent("NWNX_ON_ADD_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

void AssociateEvents::RemoveAssociateHook(API::CNWSCreature* thisPtr, API::Types::ObjectID assocId)
{
    std::string assocIdStr = Helpers::ObjectIDToString(assocId);

    Events::PushEventData("ASSOCIATE_OBJECT_ID", assocIdStr);
    if (Events::SignalEvent("NWNX_ON_REMOVE_ASSOCIATE_BEFORE", thisPtr->m_idSelf))
    {
        g_RemoveAssociateHook->CallOriginal<void>(thisPtr, assocIdStr);
    }

    Events::PushEventData("ASSOCIATE_OBJECT_ID", assocIdStr);
    Events::SignalEvent("NWNX_ON_REMOVE_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

}
