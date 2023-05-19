#include <mod/amlmod.h>
#include <la.h>

#include <vector>

MYMOD(net.rusjj.la, AMLs Limit Adjuster, 1.0, RusJJ)
BEGIN_DEPLIST()
    ADD_DEPENDENCY_VER(net.rusjj.aml, 1.0.2.1)
END_DEPLIST()

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Saves     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////
Config* cfg = NULL;
uintptr_t pGameAddr; void* hGameHndl;
std::vector<ILAModule*> aModules;
ILAModule* pActiveModule = NULL;
eLoadedGame nCurrentGame = eLoadedGame::UnknownGame;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////     Funcs Exts     ////////////////////////////
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Funcs     ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////
bool RegisterLAModule(ILAModule* module)
{
    if(module)
    {
        aModules.push_back(module);
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////     Main     ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern "C" void OnModPreLoad()
{
    logger->SetTag("LimitAdjuster");
    
    ILAModule* pWorkingModule;
    int count = aModules.size();
    for(int i = 0; i < count; ++i)
    {
        pWorkingModule = aModules[i];
        if(pWorkingModule)
        {
            pGameAddr = aml->GetLib(pWorkingModule->GetLibName());
            if(pGameAddr != 0 && pWorkingModule->IsTheLoadedGameCorrect())
            {
                cfg = new Config(pWorkingModule->GetConfigName());
                hGameHndl = aml->GetLibHandle(pWorkingModule->GetLibName());
                nCurrentGame = pWorkingModule->GetGameEnum();
                pActiveModule = pWorkingModule;

                logger->Info("Got the module loaded!\nGame: %s\nConfig: %s.ini\nLibrary: %s (base: 0x%X)", pWorkingModule->GetGameName(), pWorkingModule->GetConfigName(), pWorkingModule->GetLibName(), pGameAddr);

                break;
            }
        }
    }

    if(pActiveModule) pActiveModule->GamePreloaded();
    else
    {
        logger->Error("LA is not loaded! Is this game supported, btw..?");
    }
}
extern "C" void OnModLoad()
{
    if(pActiveModule) pActiveModule->GameLoaded();
}
extern "C" void OnAllModsLoaded()
{
    if(pActiveModule) pActiveModule->GameModsLoaded();
}