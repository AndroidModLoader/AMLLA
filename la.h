#pragma once

#include <mod/amlmod.h>
#include <mod/config.h>
#include <mod/logger.h>

class ILAModule;
extern Config* cfg;
extern uintptr_t pGameAddr;
extern void* hGameHndl;

extern bool RegisterLAModule(ILAModule* module);

enum eLoadedGame
{
    UnknownGame = 0,

    GTA_SA,
    GTA_VC,
    GTA_3,
};

class ILAModule
{
public:
    ILAModule() { RegisterLAModule(this); }

    virtual const char* GetGameName() = 0;
    virtual const char* GetLibName() = 0;
    virtual const char* GetConfigName() = 0;
    virtual eLoadedGame GetGameEnum() = 0;
    virtual bool IsTheLoadedGameCorrect() = 0;
    virtual void GamePreloaded() {}
    virtual void GameLoaded() {}
    virtual void GameModsLoaded() {}
    virtual bool Is64Bit() = 0; // 32 otherwise
};