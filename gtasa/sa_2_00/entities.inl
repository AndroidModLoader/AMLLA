struct LinkListSA
{
    struct LinkSA
    {
        LinkSA *data;
        LinkSA *prev;
        LinkSA *next;

        void insert(LinkSA* item)
        {
            this->next = item->next;
            next->prev = this;

            this->prev = item;
            prev->next = this;
        }
    };
    LinkSA usedhead;
    LinkSA usedtail;
    LinkSA freehead;
    LinkSA freetail;
    LinkSA *data;
};

int streamingInstances;
uintptr_t StreamingObjectsInstances_BackTo;
LinkListSA *ms_rwObjectInstances;
extern "C" uintptr_t StreamingObjectsInstances_Inject()
{
    LinkListSA::LinkSA* data = new LinkListSA::LinkSA[streamingInstances];
    ms_rwObjectInstances->usedhead.next = &ms_rwObjectInstances->usedtail;
    ms_rwObjectInstances->usedtail.next = &ms_rwObjectInstances->usedhead;
    ms_rwObjectInstances->freehead.next = &ms_rwObjectInstances->freetail;
    ms_rwObjectInstances->freetail.next = &ms_rwObjectInstances->freehead;
    ms_rwObjectInstances->data =          data;
    for(int i = streamingInstances - 1; i >= 0; --i)
    {
        ms_rwObjectInstances->data[i].insert(&ms_rwObjectInstances->freehead);
    }
    return StreamingObjectsInstances_BackTo;
}
__attribute__((optnone)) __attribute__((naked)) void StreamingObjectsInstances_Patch(void)
{
    asm("BL StreamingObjectsInstances_Inject");
    asm("BX R0");
}

int alphaentities;
uintptr_t AlphaEntityList_BackTo;
LinkListSA *m_alphaEntityList;
extern "C" uintptr_t AlphaEntityList_Inject()
{
    LinkListSA::LinkSA* data = new LinkListSA::LinkSA[alphaentities];
    m_alphaEntityList->usedhead.next = &m_alphaEntityList->usedtail;
    m_alphaEntityList->usedtail.next = &m_alphaEntityList->usedhead;
    m_alphaEntityList->freehead.next = &m_alphaEntityList->freetail;
    m_alphaEntityList->freetail.next = &m_alphaEntityList->freehead;
    m_alphaEntityList->data =          data;
    for(int i = alphaentities - 1; i >= 0; --i)
    {
        m_alphaEntityList->data[i].insert(&m_alphaEntityList->freehead);
    }
    return AlphaEntityList_BackTo;
}
__attribute__((optnone)) __attribute__((naked)) void AlphaEntityList_Patch(void)
{
    asm("BL AlphaEntityList_Inject");
    asm("BX R0");
}

void PatchEntityPointers()
{
    // VisibleEntityPtrs
    if(*(uint32_t*)(pGameAddr + 0x6778F4) == (pGameAddr + 0x00960B80))
    {
        static void** VisibleEntityPtrs;

        int visibleEnts = cfg->GetInt("VisibleEntityPointers", ADJUSTED_POOL_LIMIT(1000), "Entities");

        VisibleEntityPtrs = new void*[visibleEnts] {0};
        aml->WriteAddr(pGameAddr + 0x6778F4, VisibleEntityPtrs);
    }

    // StreamingObjectsInstances
    if(*(uint32_t*)(pGameAddr + 0x46BE20) == 0x6050F244)
    {
        SET_TO(ms_rwObjectInstances, aml->GetSym(hGameHndl, "_ZN10CStreaming20ms_rwObjectInstancesE"));
        streamingInstances = cfg->GetInt("StreamingObjectsInstances", ADJUSTED_POOL_LIMIT(1500), "Entities");
        StreamingObjectsInstances_BackTo = pGameAddr + 0x46BEA0 + 0x1;
        aml->Redirect(pGameAddr + 0x46BE20 + 0x1, (uintptr_t)StreamingObjectsInstances_Patch);
    }

    // AlphaEntityList (needs additional work here)
    /*if(*(uint32_t*)(pGameAddr + 0x5D452E) == 0x607AF44F)
    {
        SET_TO(m_alphaEntityList, aml->GetSym(hGameHndl, "_ZN18CVisibilityPlugins17m_alphaEntityListE"));
        alphaentities = cfg->GetInt("AlphaEntityList", ADJUSTED_POOL_LIMIT(200), "Entities");
        AlphaEntityList_BackTo = pGameAddr + 0x5D45AC + 0x1;
        aml->Redirect(pGameAddr + 0x5D452E + 0x1, (uintptr_t)AlphaEntityList_Patch);
    }*/
}