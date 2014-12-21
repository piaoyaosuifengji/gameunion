// dllmain.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxwin.h>
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static AFX_EXTENSION_MODULE HookDllDLL = { NULL, NULL };
// The following symbol used to force inclusion of this module for _USRDLL
#ifdef _X86_
extern "C" { int _afxForceUSRDLL; }
#else
extern "C" { int __afxForceUSRDLL; }
#endif




extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("HookDll.DLL Initializing!\n");

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(HookDllDLL, hInstance))
		{
			AfxMessageBox(_T("AfxInitExtensionModule  false"));
			return 0;
		}

		new CDynLinkLibrary(HookDllDLL);
		//glhInstance=hInstance;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("HookDll.DLL Terminating!\n");

		// Terminate the library before destructors are called
		AfxTermExtensionModule(HookDllDLL);
	}
	return 1;   // ok
}
