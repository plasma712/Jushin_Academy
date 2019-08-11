// API_Portfolio.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "API_Portfolio.h"
#include "cMainGame.h"

#define MAX_LOADSTRING 100

// ���� ����:
HWND g_hwnd;
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
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

	// TODO: ���⿡ �ڵ带 �Է��մϴ�.

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_API_PORTFOLIO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// �ʱ��Լ� ����

	cMainGame MainGame;
	MainGame.Init();

	///////////
	DWORD dwOldTime = GetTickCount();
	DWORD dwCurTime = 0;


	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API_PORTFOLIO));

	MSG msg;

	//33ms, 1 ������ �� �ð�
	DWORD dwFrame = 0;
	//1000ms, 1�� �� ������ ����� ���� �ð�
	DWORD dwSecond = 0;

	// �⺻ �޽��� �����Դϴ�.
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg); // �޽��� ���� �Լ�.
			DispatchMessage(&msg);	// �޽��� ó���Լ�(WndProc)���� �޽����� ���� ����.
		}

		//dwCurTime = GetTickCount();

		//if (dwCurTime - dwOldTime >= 10) // 0.01�� �������� ����.
		//{
		//	MainGame.Update();
		//	MainGame.Draw();

		//	dwOldTime = dwCurTime;
		//}																	// ������ �ٽ��ѹ� Ȯ��...
		dwCurTime = GetTickCount();											// ������ �ٽ��ѹ� Ȯ��...
		dwFrame += dwCurTime - dwOldTime;									// ������ �ٽ��ѹ� Ȯ��...
		dwSecond += dwCurTime - dwOldTime;									// ������ �ٽ��ѹ� Ȯ��...
		dwOldTime = dwCurTime;												// ������ �ٽ��ѹ� Ȯ��...
																			// ������ �ٽ��ѹ� Ȯ��...
		if (dwFrame >= 33) // 1/30 �� �������� ����.						// ������ �ٽ��ѹ� Ȯ��...
		{																	// ������ �ٽ��ѹ� Ȯ��...
			MainGame.Update();												// ������ �ٽ��ѹ� Ȯ��...
																			// ������ �ٽ��ѹ� Ȯ��...
			dwFrame -= 33;													// ������ �ٽ��ѹ� Ȯ��...
		}																	// ������ �ٽ��ѹ� Ȯ��...
		MainGame.Draw();													// ������ �ٽ��ѹ� Ȯ��...
		if (dwSecond >= 100) // 0.01�� �������� ����.						// ������ �ٽ��ѹ� Ȯ��...
		{																	// ������ �ٽ��ѹ� Ȯ��...
			dwSecond -= 1000;												// ������ �ٽ��ѹ� Ȯ��...
			//fps = 0;														// ������ �ٽ��ѹ� Ȯ��...
		}																	// ������ �ٽ��ѹ� Ȯ��...
																			// ������ �ٽ��ѹ� Ȯ��...
	}																		// ������ �ٽ��ѹ� Ȯ��...
																			// ������ �ٽ��ѹ� Ȯ��...
	return (int)msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
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
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	RECT rc{ 0,0,WINCX,WINCY };

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE); // â ������


	HWND hWnd = CreateWindowW
	(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		0, 
		rc.right-rc.left,	// �ػ� ������ �ʿ���.... 
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
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
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
	case WM_DESTROY:	// �����찡 �ı��� �� �߻��ϴ� �޽���		
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}