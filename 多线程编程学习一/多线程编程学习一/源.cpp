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
在这里我们只用到了第三个和第四个参数，第三个参数传递了一个函数的地址，也是我们要指定的新的线程，第四个参数是传给新线程的参数指针
*/

/*
HANDLE CreateMutex(
	LPSECURITY_ATTRIBUTES lpMutexAttributes,  // SD
	BOOL bInitialOwner,                       // initial owner
	LPCTSTR lpName                            // object name
	);
该函数用于创造一个独占资源，第一个参数我们没有使用，可以设为NULL，第二个参数指定该资源初始是否归属创建它的进程，第三个参数指定资源的名称
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
