#include "la_gtasa.h"

/* Class */
class GTASA_2_10 : public GTASA
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x200000) == 0x00841928);
    }
    bool Is64Bit()
    {
        return true;
    }
} GTASA_2_10_64_Module;