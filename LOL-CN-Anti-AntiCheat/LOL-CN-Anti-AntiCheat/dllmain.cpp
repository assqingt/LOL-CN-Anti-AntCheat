// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "framework.h"
#include <dll_module.h>

dll_module g_dMod;

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{
	//去掉一些警告
	UNREFERENCED_PARAMETER(lpReserved);
	//关闭线程载入通知
	DisableThreadLibraryCalls(hModule);
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//Init
		g_dMod.attach();
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		//Clear
		g_dMod.detach();
	}

	return TRUE;
}

