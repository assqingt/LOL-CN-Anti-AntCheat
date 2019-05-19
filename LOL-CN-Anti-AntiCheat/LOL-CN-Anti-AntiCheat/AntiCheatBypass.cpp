#include <AntiCheatBypass.h>

//tcj要处理的
//NtSetInformationThread
//RtlMoveMemory
//NtQueryInformationProcess
//NtOpenProcess
//NtCreateThreadEx

AntiCheatBypass::AntiCheatBypass()
{
}


AntiCheatBypass::~AntiCheatBypass()
= default;

void AntiCheatBypass::EnableDebug()
{
	//RtlDispatchAPC dll注入 ntdll.dll
	//DbgUiRemoteBreakin 调试器中断 ntdll.dll
	//NtTerminateProcess Nt终止进程 ntdll.dll
	//ZwTerminateProcess Zw终止进程 ntdll.dll
	//SetUnhandledExceptionFilter UEF回调清空 Kernel32.dll
}
