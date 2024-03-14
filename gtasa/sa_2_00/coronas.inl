char* aNewCoronas;
int coronasCount, coronasStruct;
void (*UpdateRegisteredCorona)(char*);
DECL_HOOKv(CoronasInit)
{
    CoronasInit();
    for(int i = 0; i < coronasStruct; i += 0x3C)
    {
        *(int*)(aNewCoronas + i + 12) = 0;
    }
}
DECL_HOOKv(CoronasUpdate)
{
    CoronasUpdate();
    for(int i = 0; i < coronasStruct; i += 0x3C)
    {
        int registeredCorona = *(int*)(aNewCoronas + i + 12);
        if(registeredCorona) UpdateRegisteredCorona(aNewCoronas + i);
    }
}

uintptr_t Coronas_Render_Continue, Coronas_Render_Break;
extern "C" uintptr_t Coronas_Render_Inject(int val)
{
    return val == coronasCount ? Coronas_Render_Break : Coronas_Render_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_Render_Patch(void)
{
    asm("ADD.W R10, R10, #1");
    asm("MOV R0, R10");
    asm("BL Coronas_Render_Inject");
    asm("BX R0");
}

uintptr_t Coronas_RenderReflections_Continue, Coronas_RenderReflections_Break;
extern "C" uintptr_t Coronas_RenderReflections_Inject(int val)
{
    return val == coronasStruct ? Coronas_RenderReflections_Break : Coronas_RenderReflections_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_RenderReflections_Patch(void)
{
    asm("MOV R0, R8");
    asm("BL Coronas_RenderReflections_Inject");
    asm("BX R0");
}

uintptr_t Coronas_Register1_Continue, Coronas_Register1_Equal, Coronas_Register1_Break;
extern "C" uintptr_t Coronas_Register1_Inject(int val)
{
    if(val < coronasCount) return Coronas_Register1_Continue;
    if(val == coronasCount) return Coronas_Register1_Equal;
    return Coronas_Register1_Break;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_Register1_Patch(void)
{
    asm("UXTH.W R3, LR");
    asm("PUSH {R0-R2,LR}");
    asm("MOV R0, R3");
    asm("BL Coronas_Register1_Inject");
    asm("MOV R12, R0");
    asm("POP {R0-R2,LR}");
    asm("BX R12");
}

uintptr_t Coronas_Register2_Continue, Coronas_Register2_Equal, Coronas_Register2_Break;
extern "C" uintptr_t Coronas_Register2_Inject(int val)
{
    if(val < 64) return Coronas_Register2_Continue;
    if(val == 64) return Coronas_Register2_Equal;
    return Coronas_Register2_Break;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_Register2_Patch(void)
{
    asm("UXTH.W R6, LR");
    asm("PUSH {R0-R3,LR}");
    asm("MOV R0, R6");
    asm("BL Coronas_Register2_Inject");
    asm("MOV R12, R0");
    asm("POP {R0-R3,LR}");
    asm("BX R12");
}

uintptr_t Coronas_UpdateCoors_Continue, Coronas_UpdateCoors_Equal, Coronas_UpdateCoors_Break;
extern "C" uintptr_t Coronas_UpdateCoors_Inject(int val)
{
    if(val < coronasCount) return Coronas_UpdateCoors_Continue;
    if(val == coronasCount) return Coronas_UpdateCoors_Equal;
    return Coronas_UpdateCoors_Break;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_UpdateCoors_Patch(void)
{
    asm("PUSH {R0-R3,LR}");
    asm("MOV R0, R12");
    asm("BL Coronas_UpdateCoors_Inject");
    asm("MOV R12, R0");
    asm("POP {R0-R3,LR}");
    asm("BX R12");
}

uintptr_t Coronas_Entity_Continue, Coronas_Entity_Equal, Coronas_Entity_Break;
extern "C" uintptr_t Coronas_Entity_Inject(int val)
{
    if(val < coronasCount) return Coronas_Entity_Continue;
    if(val == coronasCount) return Coronas_Entity_Equal;
    return Coronas_Entity_Break;
}
__attribute__((optnone)) __attribute__((naked)) void Coronas_Entity_Patch(void)
{
    asm("MOV R12, R0");
    asm("PUSH {R0-R3}");
    asm("MOV R0, R12");
    asm("BL Coronas_Entity_Inject");
    asm("MOV R12, R0");
    asm("POP {R0-R3}");
    asm("BX R12");
}

// func

void PatchCoronas()
{
    if(*(uint32_t*)(pGameAddr + 0x676C44) == (pGameAddr + 0x00A25B44))
    {
        coronasCount = cfg->GetInt("Coronas", ADJUSTED_POOL_LIMIT(4 * 64), "PoolLimits"); // doing x4 cuz it's good for mods
        coronasStruct = coronasCount * 0x3C;
        aNewCoronas = new char[coronasStruct];
        aml->WriteAddr(pGameAddr + 0x676C44, (uintptr_t)aNewCoronas);

        // Init
        aml->PlaceB(pGameAddr + 0x5A3826 + 0x1, pGameAddr + 0x5A3832 + 0x1);
        HOOKBLX(CoronasInit, pGameAddr + 0x472FD8 + 0x1);
        // Update
        aml->PlaceB(pGameAddr + 0x5A2304 + 0x1, pGameAddr + 0x5A231A + 0x1);
        HOOKBLX(CoronasUpdate, pGameAddr + 0x3F426E + 0x1);
        SET_TO(UpdateRegisteredCorona, aml->GetSym(hGameHndl, "_ZN17CRegisteredCorona6UpdateEv"));
        // Render
        Coronas_Render_Continue = pGameAddr + 0x5A24E2 + 0x1;
        Coronas_Render_Break =    pGameAddr + 0x5A2B0E + 0x1;
        aml->Redirect(pGameAddr + 0x5A2B02 + 0x1, (uintptr_t)Coronas_Render_Patch);
        // RenderReflections
        Coronas_RenderReflections_Continue = pGameAddr + 0x5A2CB2 + 0x1;
        Coronas_RenderReflections_Break =    pGameAddr + 0x5A2F2C + 0x1;
        aml->Redirect(pGameAddr + 0x5A2F24 + 0x1, (uintptr_t)Coronas_RenderReflections_Patch);
        // RegisterCorona1
        Coronas_Register1_Continue = pGameAddr + 0x5A3B44 + 0x1;
        Coronas_Register1_Equal =    pGameAddr + 0x5A3B60 + 0x1;
        Coronas_Register1_Break =    pGameAddr + 0x5A3B90 + 0x1;
        aml->Redirect(pGameAddr + 0x5A3B56 + 0x1, (uintptr_t)Coronas_Register1_Patch);
        // RegisterCorona2
        Coronas_Register2_Continue = pGameAddr + 0x5A3B76 + 0x1;
        Coronas_Register2_Equal =    pGameAddr + 0x5A3CE0 + 0x1;
        Coronas_Register2_Break =    pGameAddr + 0x5A3BC8 + 0x1;
        aml->Redirect(pGameAddr + 0x5A3B82 + 0x1, (uintptr_t)Coronas_Register2_Patch);
        // UpdateCoors
        Coronas_UpdateCoors_Continue = pGameAddr + 0x5A3D82 + 0x1;
        Coronas_UpdateCoors_Equal =    pGameAddr + 0x5A3D9C + 0x1;
        Coronas_UpdateCoors_Break =    pGameAddr + 0x5A3DA2 + 0x1;
        aml->Redirect(pGameAddr + 0x5A3D94 + 0x1, (uintptr_t)Coronas_UpdateCoors_Patch);
        // ProcessLightsForEntity
        Coronas_Entity_Continue = pGameAddr + 0x5A4C92 + 0x1;
        Coronas_Entity_Equal =    pGameAddr + 0x5A4CC0 + 0x1;
        Coronas_Entity_Break =    pGameAddr + 0x5A4CA6 + 0x1;
        aml->Redirect(pGameAddr + 0x5A4C9C + 0x1, (uintptr_t)Coronas_Entity_Patch);
    }
}