#include "Core/Instance.h"
int main(int argc, char *argv[])
{
    Instance* mainInstance = new Instance();
    mainInstance->Run();
    mainInstance->CleanUp();
    return 0;
}
