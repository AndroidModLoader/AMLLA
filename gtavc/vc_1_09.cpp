#include "la_gtavc.h"

// HOOKS DECLARATION



// GENERIC FUNCTIONS



// CLASS DESCRIPTION
class GTAVC_1_09 : public GTAVC
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x202020) == 0x81D3F340);
    }
    bool Is64Bit()
    {
        return false;
    }
    void GameLoaded();
} GTAVC_1_09_Module;

void GTAVC_1_09::GameLoaded()
{
    
}