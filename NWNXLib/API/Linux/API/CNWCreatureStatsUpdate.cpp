#include "CNWCreatureStatsUpdate.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CCombatInformation.hpp"

namespace NWNXLib {

namespace API {

CNWCreatureStatsUpdate::CNWCreatureStatsUpdate()
{
    CNWCreatureStatsUpdate__CNWCreatureStatsUpdateCtor(this);
}

CNWCreatureStatsUpdate::~CNWCreatureStatsUpdate()
{
    CNWCreatureStatsUpdate__CNWCreatureStatsUpdateDtor(this);
}

void CNWCreatureStatsUpdate::ClearEffectIcons()
{
    return CNWCreatureStatsUpdate__ClearEffectIcons(this);
}

void CNWCreatureStatsUpdate::SetCombatInformation(CCombatInformation* a0)
{
    return CNWCreatureStatsUpdate__SetCombatInformation(this, a0);
}

void CNWCreatureStatsUpdate__CNWCreatureStatsUpdateCtor(CNWCreatureStatsUpdate* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWCreatureStatsUpdate*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWCreatureStatsUpdate__CNWCreatureStatsUpdateCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWCreatureStatsUpdate__CNWCreatureStatsUpdateDtor(CNWCreatureStatsUpdate* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWCreatureStatsUpdate*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWCreatureStatsUpdate__CNWCreatureStatsUpdateDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWCreatureStatsUpdate__ClearEffectIcons(CNWCreatureStatsUpdate* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWCreatureStatsUpdate*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWCreatureStatsUpdate__ClearEffectIcons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWCreatureStatsUpdate__SetCombatInformation(CNWCreatureStatsUpdate* thisPtr, CCombatInformation* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWCreatureStatsUpdate*, CCombatInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWCreatureStatsUpdate__SetCombatInformation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
