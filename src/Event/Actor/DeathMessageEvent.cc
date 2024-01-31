#include "Global.h"
#include <GMLIB/Event/Entity/DeathMessageEvent.h>

namespace GMLIB::Event::EntityEvent {

using DEATH_MESSAGE = std::pair<std::string, std::vector<std::string>>;

ActorDamageSource const& DeathMessageBeforeEvent::getDamageSource() const { return mDamageSource; }

ActorDamageSource const& DeathMessageAfterEvent::getDamageSource() const { return mDamageSource; }
DEATH_MESSAGE const&     DeathMessageAfterEvent::getDeathMessage() const { return mDeathMessage; }

LL_AUTO_TYPE_INSTANCE_HOOK(
    DeathMessageEvent1,
    HookPriority::Normal,
    ActorDamageSource,
    "?getDeathMessage@ActorDamageSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?"
    "$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_"
    "traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@"
    "PEAVActor@@@Z",
    DEATH_MESSAGE,
    std::string a1,
    Actor*      a2
) {
    auto beforeEvent = DeathMessageBeforeEvent(*a2, *this);
    ll::event::EventBus::getInstance().publish(beforeEvent);
    if (beforeEvent.isCancelled()) {
        return DEATH_MESSAGE{};
    }
    auto result     = origin(a1, a2);
    auto afterEvent = DeathMessageAfterEvent(*a2, *this, result);
    ll::event::EventBus::getInstance().publish(afterEvent);
    return result;
}

LL_AUTO_TYPE_INSTANCE_HOOK(
    DeathMessageEvent2,
    HookPriority::Normal,
    ActorDamageByActorSource,
    "?getDeathMessage@ActorDamageByActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@"
    "std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$"
    "char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@"
    "PEAVActor@@@Z",
    DEATH_MESSAGE,
    std::string a1,
    Actor*      a2
) {
    auto beforeEvent = DeathMessageBeforeEvent(*a2, *this);
    ll::event::EventBus::getInstance().publish(beforeEvent);
    if (beforeEvent.isCancelled()) {
        return DEATH_MESSAGE{};
    }
    auto result     = origin(a1, a2);
    auto afterEvent = DeathMessageAfterEvent(*a2, *this, result);
    ll::event::EventBus::getInstance().publish(afterEvent);
    return result;
}

LL_AUTO_TYPE_INSTANCE_HOOK(
    DeathMessageEvent3,
    HookPriority::Normal,
    ActorDamageByBlockSource,
    "?getDeathMessage@ActorDamageByBlockSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@"
    "std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$"
    "char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@"
    "PEAVActor@@@Z",
    DEATH_MESSAGE,
    std::string a1,
    Actor*      a2
) {
    auto beforeEvent = DeathMessageBeforeEvent(*a2, *this);
    ll::event::EventBus::getInstance().publish(beforeEvent);
    if (beforeEvent.isCancelled()) {
        return DEATH_MESSAGE{};
    }
    auto result     = origin(a1, a2);
    auto afterEvent = DeathMessageAfterEvent(*a2, *this, result);
    ll::event::EventBus::getInstance().publish(afterEvent);
    return result;
}

LL_AUTO_TYPE_INSTANCE_HOOK(
    DeathMessageEvent4,
    HookPriority::Normal,
    ActorDamageByChildActorSource,
    "?getDeathMessage@ActorDamageByChildActorSource@@UEBA?AU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@"
    "D@2@@std@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?"
    "$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@std@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@3@"
    "PEAVActor@@@Z",
    DEATH_MESSAGE,
    std::string a1,
    Actor*      a2
) {
    auto beforeEvent = DeathMessageBeforeEvent(*a2, *this);
    ll::event::EventBus::getInstance().publish(beforeEvent);
    if (beforeEvent.isCancelled()) {
        return DEATH_MESSAGE{};
    }
    auto result     = origin(a1, a2);
    auto afterEvent = DeathMessageAfterEvent(*a2, *this, result);
    ll::event::EventBus::getInstance().publish(afterEvent);
    return result;
}


} // namespace GMLIB::Event::EntityEvent