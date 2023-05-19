#pragma once

#include <la.h>

struct CSAPool
{
    void*     objects;
    uint8_t*  flags;
    uint32_t  count;
    uint32_t  top;
    uint32_t  initialized;
};
inline CSAPool* AllocatePool(size_t count, size_t size)
{
    CSAPool *p = new CSAPool;
    p->objects = new char[size*count];
    p->flags = new uint8_t[count];
    p->count = count;
    p->top = 0xFFFFFFFF;
    p->initialized = 1;
    for (size_t i = 0; i < count; ++i)
    {
        p->flags[i] |= 0x80;
        p->flags[i] &= 0x80;
    }
    return p;
}

class GTASA : public ILAModule
{
public:
    virtual const char* GetGameName() { return "GTA: San Andreas"; }
    virtual const char* GetLibName() { return "libGTASA.so"; }
    virtual const char* GetConfigName() { return "AML_LimitAdjuster.SA"; }
    virtual eLoadedGame GetGameEnum() { return eLoadedGame::GTA_SA; }
};