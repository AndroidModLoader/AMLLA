void PatchEntityPointers()
{
    
    if(*(uint32_t*)(pGameAddr + 0x6778F4) == 0x00960B80)
    {
        static void** VisibleEntityPtrs;

        int visibleEnts = cfg->GetInt("VisibleEntityPointers", ADJUSTED_POOL_LIMIT(1000), "Entities"); // doing x4 cuz it's good for mods

        VisibleEntityPtrs = new void*[visibleEnts] {0};
        aml->WriteAddr(pGameAddr + 0x6778F4, (uintptr_t)&VisibleEntityPtrs);
    }
}