#include <stdio.h>
#include <windows.h>

int main()
{
	char dllPath[15] = "injectedDLL.dll";
	
	HWND hwnd = FindWindow(0,"TEST");
	int pid;
	
	GetWindowThreadProcessId(hwnd,&pid);
	
	HANDLE phd = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
	
	int* LLA = GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA");
	
	int* dllA = VirtualAllocEx(phd,NULL,15,(0x1000 | 0x2000), 0x40);
	
	printf("LoadLibrary Address : [%p]\npath Address : [%p]\n",LLA,dllA);
	
	WriteProcessMemory(phd,dllA,dllPath,15,0);
	//printf("%d\n",GetLastError());
	CreateRemoteThread(phd, NULL,0,LLA,dllA,0,0);
	system("pause");	
	return 0;
}
