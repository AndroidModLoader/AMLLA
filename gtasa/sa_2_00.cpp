#include "la_gtasa.h"

#define ADJUSTED_POOL_LIMIT(__var) (int)(4 * __var)
#define SIZEOF_CARGEN 32

// HOOKS DECLARATION
DECL_HOOKv(PoolsInit)
{
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeSingleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeSingle", ADJUSTED_POOL_LIMIT(75000), "PoolLimits"), 0x8);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeDoubleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeDouble", ADJUSTED_POOL_LIMIT(6000), "PoolLimits"), 0xC);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools21ms_pEntryInfoNodePoolE")) = 
        AllocatePool(cfg->GetInt("EntryInfoNode", ADJUSTED_POOL_LIMIT(500), "PoolLimits"), 20);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools11ms_pPedPoolE")) = 
        AllocatePool(cfg->GetInt("Peds", ADJUSTED_POOL_LIMIT(140), "PoolLimits"), 1996);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools15ms_pVehiclePoolE")) = 
        AllocatePool(cfg->GetInt("Vehicles", ADJUSTED_POOL_LIMIT(110), "PoolLimits"), 2604);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools16ms_pBuildingPoolE")) = 
        AllocatePool(cfg->GetInt("Buildings", ADJUSTED_POOL_LIMIT(14000), "PoolLimits"), 0x3C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools14ms_pObjectPoolE")) = 
        AllocatePool(cfg->GetInt("Objects", ADJUSTED_POOL_LIMIT(350), "PoolLimits"), 420);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools13ms_pDummyPoolE")) = 
        AllocatePool(cfg->GetInt("Dummies", ADJUSTED_POOL_LIMIT(3500), "PoolLimits"), 0x3C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools16ms_pColModelPoolE")) = 
        AllocatePool(cfg->GetInt("ColModel", ADJUSTED_POOL_LIMIT(10150), "PoolLimits"), 48);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools12ms_pTaskPoolE")) = 
        AllocatePool(cfg->GetInt("Task", ADJUSTED_POOL_LIMIT(500), "PoolLimits"), 128);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools13ms_pEventPoolE")) = 
        AllocatePool(cfg->GetInt("Event", ADJUSTED_POOL_LIMIT(200), "PoolLimits"), 68);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools18ms_pPointRoutePoolE")) = 
        AllocatePool(cfg->GetInt("PointRoute", ADJUSTED_POOL_LIMIT(64), "PoolLimits"), 100);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools19ms_pPatrolRoutePoolE")) = 
        AllocatePool(cfg->GetInt("PatrolRoute", ADJUSTED_POOL_LIMIT(32), "PoolLimits"), 420);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools17ms_pNodeRoutePoolE")) = 
        AllocatePool(cfg->GetInt("NodeRoute", ADJUSTED_POOL_LIMIT(64), "PoolLimits"), 36);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools21ms_pTaskAllocatorPoolE")) = 
        AllocatePool(cfg->GetInt("TaskAllocator", ADJUSTED_POOL_LIMIT(16), "PoolLimits"), 32);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools23ms_pPedIntelligencePoolE")) = 
        AllocatePool(cfg->GetInt("PedIntelligence", ADJUSTED_POOL_LIMIT(140), "PoolLimits"), 664);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools20ms_pPedAttractorPoolE")) = 
        AllocatePool(cfg->GetInt("PedAttractors", ADJUSTED_POOL_LIMIT(64), "PoolLimits"), 236);
}
DECL_HOOKv(InitQuadTreePool)
{
    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN13CQuadTreeNode20ms_pQuadTreeNodePoolE"));
    if(!pool) pool = AllocatePool(cfg->GetInt("QuadTreeNodes", ADJUSTED_POOL_LIMIT(400), "PoolLimits"), 0x28);
}
DECL_HOOKv(IplStoreInit)
{
    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN9CIplStore8ms_pPoolE"));
    if(!pool) pool = AllocatePool(cfg->GetInt("IplStore", ADJUSTED_POOL_LIMIT(256), "PoolLimits"), 0x34);
    IplStoreInit();
}
DECL_HOOKv(ColStoreInit)
{
    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN9CColStore11ms_pColPoolE"));
    if(!pool) pool = AllocatePool(cfg->GetInt("Collisions", ADJUSTED_POOL_LIMIT(255), "PoolLimits"), 0x2C);
    ColStoreInit();
}
DECL_HOOKv(EntryExitManInit)
{
    EntryExitManInit();
    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CEntryExitManager17mp_poolEntryExitsE"));
    pool = AllocatePool(cfg->GetInt("EntryExits", ADJUSTED_POOL_LIMIT(455), "PoolLimits"), 0x3C);
    pool->locked = true;
}
DECL_HOOKv(StuntJumpsInit)
{
    // StuntJumpsInit(); // reversed

    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CStuntJumpManager17mp_poolStuntJumpsE"));
    pool = AllocatePool(cfg->GetInt("StuntJumps", ADJUSTED_POOL_LIMIT(256), "PoolLimits"), 0x44);
    aml->Write8(pGameAddr + 0x820000, 0x01); // CStuntJumpManager::m_bActive
}

int fxmempoolsize;
DECL_HOOKb(FxMemPoolInit, int self)
{
    void* data = malloc(fxmempoolsize);

    *(int*)(self + 0) = (int)data;
    *(int*)(self + 4) = fxmempoolsize;
    *(int*)(self + 8) = 0;

    if(data)
    {
        memset(data, 0, fxmempoolsize);
        return true;
    }
    return false;
}

#include "sa_2_00/coronas.inl"
#include "sa_2_00/searchlights.inl"
#include "sa_2_00/weapons.inl"
#include "sa_2_00/vehicles.inl"
#include "sa_2_00/entities.inl"
#include "sa_2_00/occluders.inl"

// GENERIC FUNCTIONS
static void PatchPools()
{
    // Quad nodes
    HOOKBLX(InitQuadTreePool, pGameAddr + 0x471D82 + 0x1);

    // IPLStore
    HOOKB(IplStoreInit, pGameAddr + 0x422E46 + 0x1);

    // COLStore
    HOOKB(ColStoreInit, pGameAddr + 0x2D973E + 0x1);

    // EntryExits
    HOOKBLX(EntryExitManInit, pGameAddr + 0x471DC0 + 0x1);
    aml->PlaceB(pGameAddr + 0x304A1C + 0x1, pGameAddr + 0x304A90 + 0x1);

    // Stunt jumps
    HOOKBLX(StuntJumpsInit, pGameAddr + 0x471DC4 + 0x1);

    // EntityIPL limit
    if(*(uint32_t*)(pGameAddr + 0x28208C) == 0x0045DD2E)
    {
        static void** entityIplPool; // default is 40

        int entitiesIpl = cfg->GetInt("EntityIPL", ADJUSTED_POOL_LIMIT(40), "PoolLimits");
        entityIplPool = new void*[entitiesIpl] {0};

        // IplEntityIndexArrays
        aml->WriteAddr(pGameAddr + 0x2805E0, (uintptr_t)entityIplPool - pGameAddr - 0x280578);
        aml->WriteAddr(pGameAddr + 0x280C78, (uintptr_t)entityIplPool - pGameAddr - 0x2809F0);
        aml->WriteAddr(pGameAddr + 0x281080, (uintptr_t)entityIplPool - pGameAddr - 0x280CEA);
        aml->WriteAddr(pGameAddr + 0x2810C8, (uintptr_t)entityIplPool - pGameAddr - 0x2810C2);
        aml->WriteAddr(pGameAddr + 0x28208C, (uintptr_t)entityIplPool - pGameAddr - 0x28207A);
    }

    // EntityPerIPL limit
    if(*(uint32_t*)(pGameAddr + 0x4692D0) == 0x005451B0)
    {
        static void** entityPerIplPool; // default is 4096

        int entitiesPerIpl = cfg->GetInt("EntityPerIPL", ADJUSTED_POOL_LIMIT(4096), "PoolLimits");
        entityPerIplPool = new void*[entitiesPerIpl] {0};
        
        // gCurrIplInstances / gpLoadedBuildings (v2.10, original name)
        aml->WriteAddr(pGameAddr + 0x4692D0, (uintptr_t)entityPerIplPool - pGameAddr - 0x4690D0);
        aml->WriteAddr(pGameAddr + 0x4692D4, (uintptr_t)entityPerIplPool - pGameAddr - 0x4690E2);
        aml->WriteAddr(pGameAddr + 0x4692D8, (uintptr_t)entityPerIplPool - pGameAddr - 0x4692A8);
        aml->WriteAddr(pGameAddr + 0x4692DC, (uintptr_t)entityPerIplPool - pGameAddr - 0x4690EE);
        aml->WriteAddr(pGameAddr + 0x4692E0, (uintptr_t)entityPerIplPool - pGameAddr - 0x469106);
        aml->WriteAddr(pGameAddr + 0x4692E8, (uintptr_t)entityPerIplPool - pGameAddr - 0x46912A);
        aml->WriteAddr(pGameAddr + 0x4692EC, (uintptr_t)entityPerIplPool - pGameAddr - 0x46912C);
        aml->WriteAddr(pGameAddr + 0x469304, (uintptr_t)entityPerIplPool - pGameAddr - 0x469250);
        aml->WriteAddr(pGameAddr + 0x46930C, (uintptr_t)entityPerIplPool - pGameAddr - 0x469266);
        aml->WriteAddr(pGameAddr + 0x46931C, (uintptr_t)entityPerIplPool - pGameAddr - 0x468D6A);
        aml->WriteAddr(pGameAddr + 0x469330, (uintptr_t)entityPerIplPool - pGameAddr - 0x4691A2);
        aml->WriteAddr(pGameAddr + 0x469334, (uintptr_t)entityPerIplPool - pGameAddr - 0x46919A);
    }

    // Coronas
    PatchCoronas();

    // FX Memory Pool
    // 1 MB on PC, 0.5 MB on Mobile <_<
    fxmempoolsize = 1024 * cfg->GetInt("FXMemoryPoolKB", ADJUSTED_POOL_LIMIT(2 * 512), "PoolLimits");
    HOOKBLX(FxMemPoolInit, pGameAddr + 0x36D074 + 0x1);
    
    // Other pools
    HOOKPLT(PoolsInit, pGameAddr + 0x672468);
}

// Matrices
void* (*InitMatrixLinkList)(uintptr_t, int);
DECL_HOOKv(InitMatrixArray)
{
    InitMatrixLinkList(aml->GetSym(hGameHndl, "gMatrixList"), cfg->GetInt("MatrixCount", ADJUSTED_POOL_LIMIT(900), "Matrices"));
}

// Scripts
void PatchScripts()
{
    // Searchlights are crashing because of a CLEO..?
    //PatchSearchlights();
}

// Misc
DECL_HOOK(void*, ExtraObjectsDir_New, void* self, int count)
{
    return ExtraObjectsDir_New(self, cfg->GetInt("ExtraObjectsDir", ADJUSTED_POOL_LIMIT(550), "Misc"));
}
void PatchMisc()
{
    // ExtraObjectsDir
    HOOKBLX(ExtraObjectsDir_New, pGameAddr + 0x46BCE4 + 0x1);

    // Occluders
    PatchOccluders();

    // Minimum number of iterations in LoadAllRequestedModels
    int iters = cfg->GetInt("LoadModelsIterations", ADJUSTED_POOL_LIMIT(10), "Misc");
    if(iters > 255) iters = 255;
    else if(iters < 10) iters = 10;
    aml->Write8(pGameAddr + 0x2D4662, (uint8_t)iters);
    aml->Write8(pGameAddr + 0x2D466E, (uint8_t)iters);

    // Tracks.dat max filesize is 46384 bytes
    // 57C84A
}

// CLASS DESCRIPTION
class GTASA_2_00 : public GTASA
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x202020) == 0xE8BDB001);
    }
    bool Is64Bit()
    {
        return false;
    }
    void GameLoaded();
} GTASA_2_00_Module;

void GTASA_2_00::GameLoaded()
{
    // Pools
    PatchPools();

    // Matrices
    HOOKBLX(InitMatrixArray, pGameAddr + 0x471D1A + 0x1);
    SET_TO(InitMatrixLinkList, aml->GetSym(hGameHndl, "_ZN15CMatrixLinkList4InitEi"));

    // Scripts
    PatchScripts();

    // Weapons
    //PatchWeapons();

    // Vehicles
    PatchVehicles();

    // Entity pointers
    PatchEntityPointers();

    // Misc
    PatchMisc();
}