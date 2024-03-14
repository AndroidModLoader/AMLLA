char* CarGroups;
int groupsCount, groupsStruct, groupsAccess;

#define CARGRP_PATCH(__num, __addr, __exitat)   CarGroupInjection_BackTo##__num = pGameAddr + 0x##__exitat + 0x1; \
                                                aml->Redirect(pGameAddr + 0x##__addr + 0x1, (uintptr_t)CarGroupInjection_Patch##__num);

uintptr_t CarGroupInjection_BackTo1, CarGroupInjection_BackTo2, CarGroupInjection_BackTo3, CarGroupInjection_BackTo4, CarGroupInjection_BackTo5, CarGroupInjection_BackTo6, CarGroupInjection_BackTo7,
          CarGroupInjection_BackTo8, CarGroupInjection_BackTo9, CarGroupInjection_BackTo10, CarGroupInjection_BackTo11, CarGroupInjection_BackTo12, CarGroupInjection_BackTo13, CarGroupInjection_BackTo14,
          CarGroupInjection_BackTo15, CarGroupInjection_BackTo16, CarGroupInjection_BackTo17;
extern "C" int CarGroupInjection_Inject1()
{
    return (int)CarGroups + groupsAccess * 18;
}
extern "C" uint16_t CarGroupInjection_Inject2(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 33);
}
extern "C" uint16_t CarGroupInjection_Inject3(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 32);
}
extern "C" uint16_t CarGroupInjection_Inject4(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 31);
}
extern "C" uint16_t CarGroupInjection_Inject5(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 30);
}
extern "C" uint16_t CarGroupInjection_Inject6(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 3);
}
extern "C" uint16_t CarGroupInjection_Inject7(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 4);
}
extern "C" int CarGroupInjection_Inject8()
{
    return (int)CarGroups + groupsAccess * 18;
}
extern "C" uint16_t CarGroupInjection_Inject9(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 29);
}
extern "C" int CarGroupInjection_Inject10_1(int cargrpoffset)
{
    return cargrpoffset + groupsAccess * 18 + 2 * 0;
}
extern "C" int CarGroupInjection_Inject10_2(int cargrpoffset)
{
    return cargrpoffset + groupsAccess * 18 + 2 * 8;
}
extern "C" uint16_t CarGroupInjection_Inject11(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 16);
}
extern "C" uint16_t CarGroupInjection_Inject12(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 17);
}
extern "C" uint16_t CarGroupInjection_Inject13(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 18);
}
extern "C" uint16_t CarGroupInjection_Inject14(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 19);
}
extern "C" uint16_t CarGroupInjection_Inject15(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 20);
}
extern "C" uint16_t CarGroupInjection_Inject16(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 21);
}
extern "C" uint16_t CarGroupInjection_Inject17(int cargrpoffset)
{
    return *(uint16_t*)(cargrpoffset + groupsAccess * 18 + 2 * 22);
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch1(void)
{
    asm("MOVS R4, #0");
    asm("PUSH {R0-R2}");
    asm("BL CarGroupInjection_Inject1");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo1));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch2(void)
{
    asm("ADD.W R1, R5, R3, LSL#1");
    asm("PUSH {R0,R2}");
    asm("MOV R0, R1");
    asm("BL CarGroupInjection_Inject2");
    asm("MOV R1, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo2));
    asm("POP {R0,R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch3(void)
{
    asm("ADD.W R1, R5, R3, LSL#1");
    asm("PUSH {R0,R2}");
    asm("MOV R0, R1");
    asm("BL CarGroupInjection_Inject3");
    asm("MOV R1, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo3));
    asm("POP {R0,R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch4(void)
{
    asm("ADD.W R1, R5, R3, LSL#1");
    asm("PUSH {R0,R2}");
    asm("MOV R0, R1");
    asm("BL CarGroupInjection_Inject4");
    asm("MOV R1, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo4));
    asm("POP {R0,R2}");
    asm("CMP R1, R0");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch5(void)
{
    asm("ADD.W R1, R5, R3, LSL#1");
    asm("PUSH {R0,R2}");
    asm("MOV R0, R1");
    asm("BL CarGroupInjection_Inject5");
    asm("MOV R1, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo5));
    asm("POP {R0,R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch6(void)
{
    asm("ADD.W R6, R3, R2, LSL#1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R6");
    asm("BL CarGroupInjection_Inject6");
    asm("MOV R6, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo6));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch7(void)
{
    asm("ADD.W R6, R3, R2, LSL#1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R6");
    asm("BL CarGroupInjection_Inject7");
    asm("MOV R6, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo7));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch8(void)
{
    asm("PUSH {R0-R2}");
    asm("BL CarGroupInjection_Inject8");
    asm("MOV R5, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo8));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch9(void)
{
    asm("ADD.W R3, R2, R1, LSL#1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject9");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo9));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch10(void)
{
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject10_1");
    asm("MOV R5, R0");
    asm("VLD1.16 {D18-D19}, [R5]");
    asm("BL CarGroupInjection_Inject10_2");
    asm("MOV R5, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo10));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch11(void)
{
    asm("VSHL.I8 D23, D23, #7");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject11");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo11));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch12(void)
{
    asm("LDR R3, [SP, #0x9C]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject12");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo12));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch13(void)
{
    asm("LDR R3, [SP, #0x98]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject13");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo13));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch14(void)
{
    asm("LDR R3, [SP, #0x94]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject14");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo14));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch15(void)
{
    asm("LDR R3, [SP, #0x90]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject15");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo15));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch16(void)
{
    asm("LDR R3, [SP, #0x8C]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject16");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo16));
    asm("POP {R0-R2}");
    asm("BX R12");
}
__attribute__((optnone)) __attribute__((naked)) void CarGroupInjection_Patch17(void)
{
    asm("LDR R3, [SP, #0x88]");
    asm("ADD R3, R1");
    asm("PUSH {R0-R2}");
    asm("MOV R0, R3");
    asm("BL CarGroupInjection_Inject17");
    asm("MOV R3, R0");
    asm volatile("MOV R12, %0\n" :: "r"(CarGroupInjection_BackTo17));
    asm("POP {R0-R2}");
    asm("BX R12");
}

uintptr_t StreamZoneModels_Continue, StreamZoneModels_Break;
extern "C" uintptr_t StreamZoneModels_Inject1(int val)
{
    return val == (10 * groupsAccess) ? StreamZoneModels_Break : StreamZoneModels_Continue;
}
__attribute__((optnone)) __attribute__((naked)) void StreamZoneModels_Patch1(void)
{
    asm("PUSH {R0-R4}");
    asm("LDR R0, [SP, #0x4]"); // R1
    asm("BL StreamZoneModels_Inject1");
    asm("MOV R12, R0");
    asm("POP {R0-R4}");
    asm("BX R12");
}

DECL_HOOKv(InitVehicleMI)
{
    auto& pool = *(CSAPool**)(aml->GetSym(hGameHndl, "_ZN17CVehicleModelInfo17CVehicleStructure11m_pInfoPoolE"));
    pool = AllocatePool(cfg->GetInt("VehicleStructs", ADJUSTED_POOL_LIMIT(50), "Vehicles"), 812);
    InitVehicleMI();
}

void PatchVehicles()
{
    // Car Groups (cargrp.dat)
    if(*(uint32_t*)(pGameAddr + 0x677364) == (pGameAddr + 0x009F4262))
    {
        groupsCount = cfg->GetInt("CarGroups", ADJUSTED_POOL_LIMIT(23), "Vehicles");
        if(groupsCount > 127) groupsCount = 127;
        groupsAccess = 2 * groupsCount;
        groupsStruct = groupsCount * 0x44;

        CarGroups = new char[groupsStruct] {0};
        aml->WriteAddr(pGameAddr + 0x677364, CarGroups);

        // LoadCarGroups
        aml->Write8(pGameAddr + 0x47500E + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x4750A8 + 0x0, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x4750C4 + 0x2, (uint8_t)groupsCount - 1);
        aml->Write8(pGameAddr + 0x4750E0 + 0x2, (uint8_t)groupsCount - 1);
        aml->Write8(pGameAddr + 0x4750EE + 0x2, (uint8_t)groupsCount);
        aml->Write8(pGameAddr + 0x475124 + 0x0, (uint8_t)groupsCount - 1);
        // ChooseCarModelToLoad
        aml->Write8(pGameAddr + 0x2EC430 + 0x0, (uint8_t)groupsAccess);
        // ChooseModel
        aml->Write8(pGameAddr + 0x2EA5F6 + 0x0, (uint8_t)groupsAccess);
        // IsCarModelNeededInCurrentZone
        aml->Write8(pGameAddr + 0x2D822E + 0x0, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D826E + 0x0, (uint8_t)groupsAccess);
        CARGRP_PATCH(1, 2D8236, 2D8242);
        CARGRP_PATCH(2, 2D81B0, 2D81B8);
        CARGRP_PATCH(3, 2D8178, 2D8180);
        CARGRP_PATCH(4, 2D813E, 2D8148);
        CARGRP_PATCH(5, 2D8104, 2D810C);
        CARGRP_PATCH(6, 2D80CC, 2D80D4);
        CARGRP_PATCH(7, 2D8104, 2D810C);
        // AddToLoadedVehiclesList  
        aml->Write8(pGameAddr + 0x2D34AC + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D34F2 + 0x0, (uint8_t)groupsAccess);
        aml->Write(pGameAddr + 0x2D34A8, "\x00\x26\x4F\xF0\x2E\x09", 6);
        aml->Write8(pGameAddr + 0x2D34A8 + 0x4, (uint8_t)groupsAccess);
        CARGRP_PATCH(8, 2D34AE, 2D34B8);
        CARGRP_PATCH(9, 2D3474, 2D347C);
        // StreamZoneModels_Gangs
        aml->Write8(pGameAddr + 0x2D7880 + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D79EE + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D7A62 + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D7B58 + 0x2, (uint8_t)groupsAccess);
        aml->Write8(pGameAddr + 0x2D7DD8 + 0x0, (uint8_t)groupsAccess);
        CARGRP_PATCH(10, 2D7C74, 2D7C80);
        CARGRP_PATCH(11, 2D7CCC, 2D7CD4);
        CARGRP_PATCH(12, 2D7D30, 2D7D38);
        CARGRP_PATCH(13, 2D7D4C, 2D7D58);
        CARGRP_PATCH(14, 2D7D68, 2D7D70);
        CARGRP_PATCH(15, 2D7D84, 2D7D8C);
        CARGRP_PATCH(16, 2D7DA0, 2D7DA8);
        CARGRP_PATCH(17, 2D7DBC, 2D7DC4);
        aml->Write8(pGameAddr + 0x2D7DD8 + 0x0, (uint8_t)groupsAccess);
        StreamZoneModels_Continue = pGameAddr + 0x2D7C62 + 0x1;
        StreamZoneModels_Break =    pGameAddr + 0x2D7DE4 + 0x1;
        aml->Redirect(pGameAddr + 0x2D7DDC + 0x1, (uintptr_t)StreamZoneModels_Patch1);
    }

    // Vehicle Structs
    HOOKBLX(InitVehicleMI, pGameAddr + 0x466AD2 + 0x1);
    aml->PlaceB(pGameAddr + 0x468B76 + 0x1, pGameAddr + 0x468BD8 + 0x1);

    // DesiredNumberOfVehiclesLoaded

    // Car generators
}