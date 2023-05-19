#pragma once

#include <la.h>

class GTA3 : public ILAModule
{
public:
    virtual const char* GetGameName() { return "GTA 3"; }
    virtual const char* GetLibName() { return "libR1.so"; }
    virtual const char* GetConfigName() { return "AML_LimitAdjuster.GTA3"; }
    virtual eLoadedGame GetGameEnum() { return eLoadedGame::GTA_3; }
};