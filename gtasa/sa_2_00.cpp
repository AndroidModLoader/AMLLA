#include "la_gtasa.h"

#define ADJUSTED_POOL_LIMIT(__var) (int)(2 * __var)
#define SIZEOF_CARGEN 32

// HOOKS DECLARATION
DECL_HOOKv(PoolsInit)
{
    CSAPool* tmpPool;

    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeSingleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeSingle", ADJUSTED_POOL_LIMIT(70000), "PoolLimits"), 0x8);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools25ms_pPtrNodeDoubleLinkPoolE")) = 
        AllocatePool(cfg->GetInt("PtrNodeDouble", ADJUSTED_POOL_LIMIT(3200), "PoolLimits"), 0xC);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools21ms_pEntryInfoNodePoolE")) = 
        AllocatePool(cfg->GetInt("EntryInfoNode", ADJUSTED_POOL_LIMIT(500), "PoolLimits"), 20);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools11ms_pPedPoolE")) = 
        AllocatePool(cfg->GetInt("Peds", ADJUSTED_POOL_LIMIT(140), "PoolLimits"), 1996);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools15ms_pVehiclePoolE")) = 
        AllocatePool(cfg->GetInt("Vehicles", ADJUSTED_POOL_LIMIT(110), "PoolLimits"), 2604);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools16ms_pBuildingPoolE")) = 
        AllocatePool(cfg->GetInt("Buildings", ADJUSTED_POOL_LIMIT(13000), "PoolLimits"), 0x3C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools14ms_pObjectPoolE")) = 
        AllocatePool(cfg->GetInt("Objects", ADJUSTED_POOL_LIMIT(350), "PoolLimits"), 420);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN6CPools13ms_pDummyPoolE")) = 
        AllocatePool(cfg->GetInt("Dummys", ADJUSTED_POOL_LIMIT(2500), "PoolLimits"), 0x3C);
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
        
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN9CColStore11ms_pColPoolE")) = 
        AllocatePool(cfg->GetInt("Collisions", ADJUSTED_POOL_LIMIT(255), "PoolLimits"), 0x2C);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CEntryExitManager17mp_poolEntryExitsE")) = 
        (tmpPool=AllocatePool(cfg->GetInt("EntryExits", ADJUSTED_POOL_LIMIT(455), "PoolLimits"), 0x3C));
        ((char*)tmpPool)[17] = 1; // m_bIsLocked = true
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN9CIplStore8ms_pPoolE")) = 
        AllocatePool(cfg->GetInt("IplStore", ADJUSTED_POOL_LIMIT(256), "PoolLimits"), 0x34);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN13CQuadTreeNode20ms_pQuadTreeNodePoolE")) = 
        AllocatePool(cfg->GetInt("QuadTreeNodes", ADJUSTED_POOL_LIMIT(400), "PoolLimits"), 0x28);
    *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CStuntJumpManager17mp_poolStuntJumpsE")) = 
        AllocatePool(cfg->GetInt("StuntJumps", ADJUSTED_POOL_LIMIT(256), "PoolLimits"), 0x44);
}

int PickUpsCount, PickUpsAlloced;
uintptr_t PickUpsInit_BackTo;
__attribute__((optnone)) __attribute__((naked)) void PickUpsInit_Patch(void)
{
    // Original
    asm("ADDS R3, #0x20");
    asm("STRH.W R12, [R2,#0x1A]");

    asm("PUSH {R0}");
    asm volatile("CMP R3, %0\n" :: "r"(PickUpsAlloced));
    asm volatile("MOV R4, %0\n" :: "r"(PickUpsInit_BackTo));
    asm("POP {R0}\nBX R4");
}

// GENERIC FUNCTIONS
static void* __return_0(...) { return NULL; }
static void PatchPools()
{
    // Quad nodes
    aml->Redirect(aml->GetSym(hGameHndl, "_ZN13CQuadTreeNode8InitPoolEv"), (uintptr_t)__return_0);
    // EntryExits
    //aml->PlaceB(pGameAddr + 0x304A1C + 0x1, pGameAddr + 0x304A8C + 0x1);
    //aml->PlaceNOP(pGameAddr + 0x304A8E + 0x1, 3);
    // Stunt jumps
    aml->PlaceB(pGameAddr + 0x361514 + 0x1, pGameAddr + 0x361574 + 0x1);
    aml->PlaceNOP(pGameAddr + 0x361584 + 0x1, 1);
}

void PatchPickUpsPools()
{
    PickUpsCount = cfg->GetInt("PickUps", 620, "PoolLimits");
    PickUpsAlloced = 0x20 * PickUpsCount;
    void* pickupsPool = new char[PickUpsAlloced] {0};
    aml->Unprot(pGameAddr + 0x678BF8, sizeof(void*));
    *(void**)(pGameAddr + 0x678BF8) = pickupsPool;

    PickUpsInit_BackTo = pGameAddr + 0x31CFA2 + 0x1;
    aml->Redirect(pGameAddr + 0x31CF98 + 0x1, (uintptr_t)PickUpsInit_Patch);
}

// Matrices
void* (*InitMatrixLinkList)(uintptr_t, int);
DECL_HOOKv(InitMatrixArray)
{
    InitMatrixLinkList(aml->GetSym(hGameHndl, "gMatrixList"), cfg->GetInt("MatrixCount", 900, "Matrices"));
}

// Scripts
char* ScriptSearchLights;
int PatchSearchLightsCount;
uintptr_t SearchLights_BackTo1, SearchLights_BackTo2;
extern "C" uintptr_t SearchLights_Inject(int val)
{
    if(val == PatchSearchLightsCount) return SearchLights_BackTo1;
    return SearchLights_BackTo2;
}
__attribute__((optnone)) __attribute__((naked)) void SearchLights_Patch(void)
{
    // Original
    //asm("ADDS R4, #1");

    asm("MOV R0, R8");
    asm("BL SearchLights_Inject");

    asm("BX R0");
}
void PatchScripts()
{
    int SearchLightsCount = cfg->GetInt("SearchLights", 8, "Scripts"); PatchSearchLightsCount = 992 * SearchLightsCount;
    ScriptSearchLights = new char[SearchLightsCount * 0x7C] {0};
    char** ScriptSearchLights_ptr = &ScriptSearchLights;
    aml->Write(pGameAddr + 0x6797B4, (uintptr_t)ScriptSearchLights_ptr, sizeof(void*));
    SearchLights_BackTo1 = pGameAddr + 0x358908 + 0x1;
    SearchLights_BackTo2 = pGameAddr + 0x358812 + 0x1;
    aml->Redirect(pGameAddr + 0x358900 + 0x1, (uintptr_t)SearchLights_Patch);
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

void GTASA_2_00::GameLoaded()
{
    // Pools
    PatchPools();
    //PatchPickUpsPools();
    HOOKPLT(PoolsInit, pGameAddr + 0x672468);

    // Matrices
    HOOK(InitMatrixArray, aml->GetSym(hGameHndl, "_ZN10CPlaceable15InitMatrixArrayEv"));
    SET_TO(InitMatrixLinkList, aml->GetSym(hGameHndl, "_ZN15CMatrixLinkList4InitEi"));

    // Scripts
    PatchScripts();
}
