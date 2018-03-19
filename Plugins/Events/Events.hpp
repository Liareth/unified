#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace Events {

class AssociateEvents;
class ClientEvents;
class CombatEvents;
class DMActionEvents;
class ExamineEvents;
class FeatEvents;
class ItemEvents;
class StealthEvents;
class SpellEvents;

class Events : public NWNXLib::Plugin
{
public: // Structures
    struct EventParams
    {
        // The name of the event
        std::string m_EventName;

        // This maps between event data key -> event data value.
        std::unordered_map<std::string, std::string> m_EventData;

        // This is true if SkipEvent() has been called on this event during its execution.
        bool m_Skipped;
    };

public:
    Events(const Plugin::CreateParams& params);
    virtual ~Events();

    // Should be called before any event data is pushed - prepare the event.
    static void StartEvent(const std::string& eventName);

    // Should be called at the very end of an event's execution.
    static void EndEvent(const std::string& eventName);

    // Pushes event data to the stack - won't do anything until SignalEvent is called.
    static void PushEventData(const std::string tag, const std::string data);

    // Returns true if the event can proceed, or false if the event has been skipped.
    static bool SignalEvent(const std::string& eventName, const NWNXLib::API::Types::ObjectID target);

private: // Structures
    using EventMapType = std::unordered_map<std::string, std::vector<std::string>>;

private:
    NWNXLib::Services::Events::ArgumentStack OnSubscribeEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnPushEventData(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSignalEvent(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnGetEventData(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnSkipEvent(NWNXLib::Services::Events::ArgumentStack&& args);

    EventMapType m_eventMap; // Event name -> subscribers.
    std::stack<EventParams> m_eventData; // Data tag -> data for currently executing event.
    uint8_t m_eventDepth;

    std::unique_ptr<AssociateEvents> m_associateEvents;
    std::unique_ptr<ClientEvents> m_clientEvents;
    std::unique_ptr<CombatEvents> m_combatEvents;
    std::unique_ptr<DMActionEvents> m_dmActionEvents;
    std::unique_ptr<ExamineEvents> m_examineEvents;
    std::unique_ptr<FeatEvents> m_featEvents;
    std::unique_ptr<ItemEvents> m_itemEvents;
    std::unique_ptr<StealthEvents> m_stealthEvents;
    std::unique_ptr<SpellEvents> m_spellEvents;
};

}
