#include "la_gtasa.h"

class GTASA_2_00 : public GTASA
{
public:
    bool IsTheLoadedGameCorrect()
    {
        return (*(uint32_t*)(pGameAddr + 0x202020) == 0xE8BDB001);
    }
    void GamePreloaded();
};
REG_MODULE(GTASA_2_00);

void GTASA_2_00::GamePreloaded()
{
    
}