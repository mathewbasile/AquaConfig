// AquaConfig.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "AquaDllConfig.h"


// This is an example of an exported variable
AQUACONFIG_API int nAquaConfig=0;

// This is an example of an exported function.
AQUACONFIG_API int fnAquaConfig(void)
{
    return 0;
}


// This is the constructor of a class that has been exported.
CAquaConfig::CAquaConfig()
{
    return;
}


int AquaConfig(int argc, char* argv[])
{
    return main(argc, argv);
}
