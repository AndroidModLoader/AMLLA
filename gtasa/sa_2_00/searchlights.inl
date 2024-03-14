int slightsCount, slightsStruct;
char* ScriptSearchLights;

uintptr_t SLights_Add_Continue, SLights_Add_Break;
extern "C" uintptr_t SLights_Add_Inject(int val)
{
    return val > slightsCount ? SLights_Add_Break : SLights_Add_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void SLights_Add_Patch(void)
{
    asm("ADD.W R4, R0, #0x7C");
    asm("ADDS R6, R1, #1");
    asm("PUSH {R0-R5}");
    asm("MOV R0, R6");
    asm("BL SLights_Add_Inject");
    asm("MOV R12, R0");
    asm("POP {R0-R5}");
    asm("BX R12");
}

uintptr_t SLights_Process_Continue, SLights_Process_Break;
extern "C" uintptr_t SLights_Process_Inject(int val)
{
    logger->Info("SLights_Process_Inject");
    return val >= slightsStruct ? SLights_Process_Break : SLights_Process_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void SLights_Process_Patch(void)
{
    asm("MOV R0, R8");
    asm("PUSH {LR}");
    asm("BL SLights_Process_Inject");
    asm("POP {LR}");
    asm("BX R0");
}

uintptr_t SLights_Render_Continue, SLights_Render_Break;
extern "C" uintptr_t SLights_Render_Inject(int val)
{
    return val == slightsStruct ? SLights_Render_Break : SLights_Render_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void SLights_Render_Patch(void)
{
    asm("MOV R0, R8");
    asm("BL SLights_Render_Inject");
    asm("BX R0");
}

void PatchSearchlights()
{
    if(*(uint32_t*)(pGameAddr + 0x6797B4) == (pGameAddr + 0x0081A118))
    {
        slightsCount = cfg->GetInt("SearchLights", ADJUSTED_POOL_LIMIT(8), "Scripts");
        slightsStruct = 0x7C * slightsStruct;

        ScriptSearchLights = new char[slightsStruct];
        aml->WriteAddr(pGameAddr + 0x6797B4, ScriptSearchLights);

        // AddScriptSearchLight
        SLights_Add_Continue = pGameAddr + 0x357B38 + 0x1;
        SLights_Add_Break =    pGameAddr + 0x357B44 + 0x1;
        aml->Redirect(pGameAddr + 0x357B2E + 0x1, (uintptr_t)SLights_Add_Patch);
        // ProcessAllSearchLights
        SLights_Process_Continue = pGameAddr + 0x3582FE + 0x1;
        SLights_Process_Break =    pGameAddr + 0x35871C + 0x1;
        aml->Redirect(pGameAddr + 0x358714 + 0x1, (uintptr_t)SLights_Process_Patch); // crash
        // Render
        SLights_Render_Continue = pGameAddr + 0x358812 + 0x1;
        SLights_Render_Break =    pGameAddr + 0x358908 + 0x1;
        aml->Redirect(pGameAddr + 0x358900 + 0x1, (uintptr_t)SLights_Render_Patch);
    }
}