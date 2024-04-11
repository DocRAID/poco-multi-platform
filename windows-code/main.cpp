#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>
#define LOOP_CNT 5


UINT count = 0;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    int num = *((int*)(&lpParam));
    // int num = (int)lpParam;
	for (UINT i = 0; i < 10; ++i)
	{
        printf("%d's loop : %d\n",num,i);
		// std::cout <<num<<"'s loop :" <<i<< std::endl;
        count++;
	}
	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadId[LOOP_CNT];
	HANDLE hThread[LOOP_CNT];

	for(UINT i = 0; i < LOOP_CNT; ++i)
	{
		hThread[i] = CreateThread(
                    nullptr,		// 기본 보안 속성
                    0,				// 기본 스택 사이즈 (1MB : 최소 사이즈)
                    ThreadProc,		// 쓰레드 함수
                    (void*)i,		// 쓰레드 함수의 매개변수를 위한 인자
                    0,				// 디폴트 생성 flag
                    &dwThreadId[i]  // 쓰레드 ID를 전달받기 위한 인자
                    );
			
	}

	// 모든 쓰레드 실행이 완료될 때까지 대기한다.
	WaitForMultipleObjects(LOOP_CNT, hThread, TRUE, INFINITE);

	_tprintf(_T("Count : %d\n"), count);

	for (UINT i = 0; i < LOOP_CNT; ++i)
	{
		CloseHandle(hThread[i]);
	}
	return 0;
}