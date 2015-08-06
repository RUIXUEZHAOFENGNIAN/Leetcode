#include<iostream>
#include<windows.h>
using namespace std;

HANDLE hMutex = CreateMutex(NULL, FALSE, (LPCTSTR)"screen");
//eg1:
DWORD WINAPI Fun(LPVOID lpParameter)
{	
	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Fun display!"<<endl;
		Sleep(500);
		ReleaseMutex(hMutex);
	}
}
/*
HANDLE CreateThread(
LPSECURITY_ATTRIBUTES lpThreadAttributes, // SD
SIZE_T dwStackSize,                       // initial stack size
LPTHREAD_START_ROUTINE lpStartAddress,    // thread function
LPVOID lpParameter,                       // thread argument
DWORD dwCreationFlags,                    // creation option
LPDWORD lpThreadId                        // thread identifier
);
����������ֻ�õ��˵������͵��ĸ�����������������������һ�������ĵ�ַ��Ҳ������Ҫָ�����µ��̣߳����ĸ������Ǵ������̵߳Ĳ���ָ��
*/

/*
HANDLE CreateMutex(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,  // SD
	BOOL bInitialOwner,                       // initial owner
	LPCTSTR lpName                            // object name
	);
�ú������ڴ���һ����ռ��Դ����һ����������û��ʹ�ã�������ΪNULL���ڶ�������ָ������Դ��ʼ�Ƿ�����������Ľ��̣�����������ָ����Դ������
*/

int main()
{
	HANDLE hThread = CreateThread(NULL, 0,Fun,NULL,0,NULL);
	CloseHandle(hThread);
	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Main display!"<<endl;
		Sleep(500);
		ReleaseMutex(hMutex);
	}
	system("pause");
	return 0;
}
