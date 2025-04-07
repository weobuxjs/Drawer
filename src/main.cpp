//<--------------------START OF FILE-------------------->
#include "Core/Instance.h"
int main(int argc, char *argv[])
{
    Instance* mainInstance = new Instance();
    SDL_Init(SDL_INIT_EVERYTHING);
    mainInstance->run();
    mainInstance->cleanup();
    return 0;
}
//<--------------------END OF FILE-------------------->