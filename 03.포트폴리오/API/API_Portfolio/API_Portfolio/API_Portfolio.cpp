// API_Portfolio.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "API_Portfolio.h"
#include "cMainGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HWND g_hwnd;
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_API_PORTFOLIO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 초기함수 실행

	cMainGame MainGame;
	MainGame.Init();

	///////////
	DWORD dwOldTime = GetTickCount();
	DWORD dwCurTime = 0;


	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API_PORTFOLIO));

	MSG msg;

	//33ms, 1 프레임 당 시간
	DWORD dwFrame = 0;
	//1000ms, 1초 당 프레임 계산을 위한 시간
	DWORD dwSecond = 0;

	// 기본 메시지 루프입니다.
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg); // 메시지 번역 함수.
			DispatchMessage(&msg);	// 메시지 처리함수(WndProc)에게 메시지를 전달 역할.
		}

		//dwCurTime = GetTickCount();

		//if (dwCurTime - dwOldTime >= 10) // 0.01초 간격으로 진행.
		//{
		//	MainGame.Update();
		//	MainGame.Draw();

		//	dwOldTime = dwCurTime;
		//}																	// 이쪽은 다시한번 확인...
		dwCurTime = GetTickCount();											// 이쪽은 다시한번 확인...
		dwFrame += dwCurTime - dwOldTime;									// 이쪽은 다시한번 확인...
		dwSecond += dwCurTime - dwOldTime;									// 이쪽은 다시한번 확인...
		dwOldTime = dwCurTime;												// 이쪽은 다시한번 확인...
																			// 이쪽은 다시한번 확인...
		if (dwFrame >= 33) // 1/30 초 간격으로 진행.						// 이쪽은 다시한번 확인...
		{																	// 이쪽은 다시한번 확인...
			MainGame.Update();												// 이쪽은 다시한번 확인...
																			// 이쪽은 다시한번 확인...
			dwFrame -= 33;													// 이쪽은 다시한번 확인...
		}																	// 이쪽은 다시한번 확인...
		MainGame.Draw();													// 이쪽은 다시한번 확인...
		if (dwSecond >= 100) // 0.01초 간격으로 진행.						// 이쪽은 다시한번 확인...
		{																	// 이쪽은 다시한번 확인...
			dwSecond -= 1000;												// 이쪽은 다시한번 확인...
			//fps = 0;														// 이쪽은 다시한번 확인...
		}																	// 이쪽은 다시한번 확인...
																			// 이쪽은 다시한번 확인...
	}																		// 이쪽은 다시한번 확인...
																			// 이쪽은 다시한번 확인...
	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API_PORTFOLIO));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_API_PORTFOLIO);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	RECT rc{ 0,0,WINCX,WINCY };

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE); // 창 사이즈


	HWND hWnd = CreateWindowW
	(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		0, 
		rc.right-rc.left,	// 해상도 변경이 필요함.... 
		rc.bottom-rc.top, 
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (!hWnd)
	{
		return FALSE;
	}

	g_hwnd = hWnd;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	_CrtDumpMemoryLeaks();

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}
		break;
	case WM_DESTROY:	// 윈도우가 파괴될 때 발생하는 메시지		
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}