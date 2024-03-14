int winfoCount, winfoStruct;
char* winfos;


void PatchWeapons()
{
    if(*(uint32_t*)(pGameAddr + 0x678ED0) == (pGameAddr + 0x00A86288))
    {
        winfoCount = cfg->GetInt("WeaponInfos", ADJUSTED_POOL_LIMIT(80), "Weapons");
        winfoStruct = winfoCount * 0x70;

        winfos = new char[winfoStruct];
        aml->WriteAddr(pGameAddr + 0x678ED0, &winfos);
    }
}