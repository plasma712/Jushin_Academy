// 190715.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "190715.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// API (Application Programming Interface)
// Win32 API

// H (Handle) : 대상마다 부여된 고유 식별 번호. 
//				-> 핸들끼리 중복된 값을 가질 수 없다. 정수 형태를 취한다.
//				-> 운영체제(시스템)가 부여.

// Instance	  :	메모리에 등록된 실체. (변수, 객체, 실행중인 프로그램)
// HINSTANCE  : 프로그램의 핸들.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,				// 핸들
                     _In_opt_ HINSTANCE hPrevInstance,		// 앞선 핸들
                     _In_ LPWSTR    lpCmdLine,				// 명령어(char* 이라고 보면 됨. // TMI : LP가 붙으면 char형
                     _In_ int       nCmdShow)				// 
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

	//TCHAR szBuf[] = L"Hello"; // 유니코드
	TCHAR szBuf[] = _T("Hello"); // _T( )는 유니코드, 멀티바이트 모두 대응가능



    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY190715, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))	// 초기화.
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY190715));

    MSG msg; // 메시지 구조체

    // 기본 메시지 루프입니다:

	// GetMessage함수 : 시스템이 갖고 있는 메시지 큐에서 메시지를 얻어오는 함수.
	// WM_QUIT(종료메시지)를 얻어오면 FALSE 반환. 그외 TRUE 반환.
	
	// 만약에 메시지큐에 얻어올 메시지가 없다면,
	// 해당 응용프로그램은 다음 메시지가 발생될 때까지 대기 상태로 진입.

    while (GetMessage(&msg, nullptr, 0, 0))	// 메시지 범위
    {
        //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        //{
            TranslateMessage(&msg);	// 메시지 번역함수
            DispatchMessage(&msg);	// 메시지 처리함수(WndProc)에게 메시지를 전달 역할.
        //}
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
// 순수 절차지형인 API
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;				// 창의 크기가 달라지면 다시 그리겠다.
    wcex.lpfnWndProc    = WndProc;								// 메시지 처리 함수
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY190715));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY190715);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

					  // 윈도우창 고유번호  / 제목  / 가장 보편적인 윈도우창
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	  // 생성위치	  / 윈도우 크기 설정			/ 현재 프로그램 핸들 / 

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	/*
	// 함수 호출 규약.
	// 함수가 종료될 때 Stack이 반환되는데 이 Stack을 누가 정리할 것이냐에 대한 약속.
	// __cdecl , __stdcall, fastcall, thiscall

	// __cdecl : C 언어의 대표적인 호출 규약. 가변인자함수 (printf, scanf 등)
	// - 호출자(Caller) Stack을 정리한다.

	// __stdcall : API의 대표적인 호출 규약. 고정인자함수
	// - 피호출자(Callee)가 Stack을 정리한다.

	// fastcall : 레지스터에 올려서 이용하기에 빠름.

	// thiscall : 멤버함수 호출규약.


	 // void __stdcall A() // 호출자
	 // {		
	 // 	// 피호출자
		 ////	B(a, b, c);  //--> c, b, a순으로 들어감.
		 ////	B함수 stack 정리 코드
		 ////
		 ////	B(a, b, c); // __cdecl
		 ////	B함수 stack 정리 코드
	    
		 ////	B(a, b, c); // __cdecl
		 ////	B함수 stack 정리 코드
	    
		 ////	A함수 stack 정리 코드
	 // }
	*/
	//사각형을 표현하기 위한 구조체
	static RECT rc = { 100,100,200,200 };


    switch (message)
    {
	case WM_CREATE : // 윈도우 생성 시 발생하는 메시지. (초기화 메시지)
		// 타이머 생성하는 함수.
		// 마지막 인자에 nullptr를 전달하게 되면 설정한 주기대로 WM_TIMER 메시지 발생
		SetTimer(hWnd, 0, 100, nullptr);
		break;
	case WM_TIMER :
		// 윈도우 그리기 갱신.
		InvalidateRect(hWnd, nullptr, TRUE);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			rc.left -= 10;
			rc.right -= 10;
			break;
		case VK_RIGHT:
			rc.left += 10;
			rc.right += 10;
			break;
		case VK_UP:
			rc.top -= 10;
			rc.bottom -= 10;
			break;
		case VK_DOWN:
			rc.top += 10;
			rc.bottom += 10;

			break;
		case VK_ESCAPE :
			DestroyWindow(hWnd);
		default:
			break;
		}
        break;
    case WM_PAINT:	// 윈도우를 그릴 때 발생되는 메시지
        {
            PAINTSTRUCT ps;

			// DC (Device Context)
			// 그래픽 출력에 필요한 데이터들을 저장하는 공간. (도화지)
			// HDC : DC의 핸들
			// DC는 GDI(Graphic Device Interface)에서 관리한다.
			// GDI에서는 그리기에 필요한 각종 함수들이나 자료형을 제공한다.

            HDC hdc = BeginPaint(hWnd, &ps);	// ps 그리기 도구

            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

			// 커서 포인트(CP)를 이동시키는 함수.
			//MoveToEx(hdc, 100, 100, nullptr);
			//LineTo(hdc,x,y)
			//현재 CP 위치로부터 x,y지점까지 선을 그리는 함수
			//MoveToEx(hdc, 10, 10, nullptr);
			//LineTo(hdc, 10, 200);
			//LineTo(hdc, 300, 200); // 시작점은 200,200으로 됨.
			//LineTo(hdc, 300, 10);
			//LineTo(hdc, 10, 10);

			//Rectangle(hdc, 100, 100, 200, 200);
			//Ellipse(hdc, 100, 100, 200, 200);
   //         EndPaint(hWnd, &ps);

			//////사각형을 표현하기 위한 구조체
			////RECT rc = { 100,100,200,200 };

			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

        }
        break;
    case WM_DESTROY:
		KillTimer(hWnd,WM_TIMER);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
