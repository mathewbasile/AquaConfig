// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the AQUACONFIG_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// AQUACONFIG_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef AQUACONFIG_EXPORTS
#define AQUACONFIG_API __declspec(dllexport)
#else
#define AQUACONFIG_API __declspec(dllimport)
#endif

#include "aquaconf.h"

// This class is exported from the dll
class AQUACONFIG_API CAquaConfig {
public:
	CAquaConfig(void);
	// TODO: add your methods here.
};

extern AQUACONFIG_API int nAquaConfig;

AQUACONFIG_API int fnAquaConfig(void);

extern "C"
{
	int AquaConfig(int argc, char* argv[]);
}
