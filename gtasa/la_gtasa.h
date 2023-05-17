#pragma once

#include <la.h>

class GTASA : public ILAModule
{
public:
    virtual const char* GetGameName() { return "GTA: San Andreas"; }
    virtual const char* GetLibName() { return "libGTASA.so"; }
    virtual const char* GetConfigName() { return "AML_LimitAdjuster.SA"; }
    virtual eLoadedGame GetGameEnum() { return eLoadedGame::GTA_SA; }
};