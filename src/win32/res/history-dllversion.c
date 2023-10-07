/* See: http://msdn.microsoft.com/library/en-us/shellcc/platform/shell/programmersguide/versions.asp */
#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#define READLINE_LIBRARY
#include "../../readline.h"
#ifdef __cplusplus
extern "C" {
#endif
/* __declspec(dllexport) */ HRESULT DllGetVersion (DLLVERSIONINFO2 *pdvi);
#ifdef __cplusplus
}
#endif

HRESULT DllGetVersion (DLLVERSIONINFO2 *pdvi)
{
	if ( !pdvi || (pdvi->info1.cbSize != sizeof (*pdvi)) )
		return (E_INVALIDARG);
	pdvi->info1.dwMajorVersion = RL_VERSION_MAJOR;
	pdvi->info1.dwMinorVersion = RL_VERSION_MINOR;
	pdvi->info1.dwBuildNumber = 1892;
	pdvi->info1.dwPlatformID = DLLVER_PLATFORM_WINDOWS;
	if (pdvi->info1.cbSize == sizeof (DLLVERSIONINFO2))
		pdvi->ullVersion = MAKEDLLVERULL (pdvi->info1.dwMajorVersion, pdvi->info1.dwMinorVersion, 1892, 39233);
	return S_OK;
}
