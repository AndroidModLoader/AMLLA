#include "la_gtasa.h"

// HOOKS DECLARATION
DECL_HOOKv(PoolsInit)
{
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeSingleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeSingle", 70000, "PoolLimits"), 0x8);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeDoubleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeDouble", 3200, "PoolLimits"), 0xC);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools21ms_pEntryInfoNodePoolE")) = 
        AllocatePool(cfg->GetInt("EntryInfoNode", 500, "PoolLimits"), 20);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools11ms_pPedPoolE")) = 
        AllocatePool(cfg->GetInt("Peds", 140, "PoolLimits"), 1996);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools15ms_pVehiclePoolE")) = 
        AllocatePool(cfg->GetInt("Vehicles", 110, "PoolLimits"), 2604);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools16ms_pBuildingPoolE")) = 
        AllocatePool(cfg->GetInt("Buildings", 13000, "PoolLimits"), 0x3C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools14ms_pObjectPoolE")) = 
        AllocatePool(cfg->GetInt("Objects", 350, "PoolLimits"), 420);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools13ms_pDummyPoolE")) = 
        AllocatePool(cfg->GetInt("Dummys", 2500, "PoolLimits"), 0x3C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools16ms_pColModelPoolE")) = 
        AllocatePool(cfg->GetInt("ColModel", 10150, "PoolLimits"), 48);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools12ms_pTaskPoolE")) = 
        AllocatePool(cfg->GetInt("Task", 500, "PoolLimits"), 128);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools13ms_pEventPoolE")) = 
        AllocatePool(cfg->GetInt("Event", 200, "PoolLimits"), 68);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools18ms_pPointRoutePoolE")) = 
        AllocatePool(cfg->GetInt("PointRoute", 64, "PoolLimits"), 100);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools19ms_pPatrolRoutePoolE")) = 
        AllocatePool(cfg->GetInt("PatrolRoute", 32, "PoolLimits"), 420);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools17ms_pNodeRoutePoolE")) = 
        AllocatePool(cfg->GetInt("NodeRoute", 64, "PoolLimits"), 36);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools21ms_pTaskAllocatorPoolE")) = 
        AllocatePool(cfg->GetInt("TaskAllocator", 16, "PoolLimits"), 32);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools23ms_pPedIntelligencePoolE")) = 
        AllocatePool(cfg->GetInt("PedIntelligence", 140, "PoolLimits"), 664);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools20ms_pPedAttractorPoolE")) = 
        AllocatePool(cfg->GetInt("PedAttractors", 64, "PoolLimits"), 236);
        
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN9CColStore11ms_pColPoolE")) = 
        AllocatePool(cfg->GetInt("Collisions", 255, "PoolLimits"), 0x2C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CEntryExitManager17mp_poolEntryExitsE")) = 
        AllocatePool(cfg->GetInt("EntryExits", 455, "PoolLimits"), 0x3C);
}

// GENERIC FUNCTIONS
static void PoolsPatch()
{
    // EntryExits
    aml->PlaceB(pGameAddr + 0x304A1C + 0x1, pGameAddr + 0x304A94 + 0x1);
}

// CLASS DESCRIPTION
class GTASA_2_00 : public GTASA
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x202020) == 0xE8BDB001);
    }
    void GameLoaded();
} GTASA_2_00_Module;
//REG_MODULE(GTASA_2_00);

void GTASA_2_00::GameLoaded()
{
    // Pools
    //PoolsPatch();
    HOOKPLT(PoolsInit, pGameAddr + 0x672468);
}