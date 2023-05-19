#include "la_gtasa.h"

/* Class */
class GTASA_2_10 : public GTASA
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x202020) == 0x61766E49);
    }
} GTASA_2_10_Module;