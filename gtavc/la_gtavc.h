#pragma once

#include <la.h>

class GTAVC : public ILAModule
{
public:
    virtual const char* GetGameName() { return "GTA: Vice City"; }
    virtual const char* GetLibName() { return "libGTAVC.so"; }
    virtual const char* GetConfigName() { return "AML_LimitAdjuster.VC"; }
    virtual eLoadedGame GetGameEnum() { return eLoadedGame::GTA_VC; }
};