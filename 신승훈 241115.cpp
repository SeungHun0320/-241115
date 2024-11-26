// 신승훈 241115.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "신승훈 241115.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY241115, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY241115));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY241115));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY241115);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

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
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// 레프트 탑 / 라이트 바텀

RECT rc{ 350, 300, 375, 200 };

list<RECT> BulletList[3];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:

        SetTimer(hWnd, 0, 0, 0);

        break;
    case WM_TIMER:

        InvalidateRect(hWnd, 0, TRUE);

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            MoveToEx(hdc, 100, 100, nullptr);
            
            MoveToEx(hdc, rc.left, rc.top, nullptr);
            //MoveToEx(hdc, 350, 300, nullptr);
            LineTo(hdc, rc.right, rc.bottom);
            //LineTo(hdc, 375, 200);
            LineTo(hdc, rc.right + 25, rc.bottom + 100);
            //LineTo(hdc, 400, 300);
            LineTo(hdc, rc.right + 50, rc.bottom + 130);
            //LineTo(hdc, 425, 330);
            LineTo(hdc, rc.right + 50, rc.bottom + 150);
            //LineTo(hdc, 425, 350);
            LineTo(hdc, rc.right + 175, rc.bottom + 220);
            //LineTo(hdc, 550, 420);
            LineTo(hdc, rc.right + 175, rc.bottom + 250);
            //LineTo(hdc, 550, 450);
            LineTo(hdc, rc.right + 35, rc.bottom + 250);
            //LineTo(hdc, 410, 450);

            MoveToEx(hdc, rc.left, rc.top, nullptr);
            //MoveToEx(hdc, 350, 300, nullptr);
            LineTo(hdc, rc.right - 50, rc.bottom + 130);
            //LineTo(hdc, 325, 330);
            LineTo(hdc, rc.right - 50, rc.bottom + 150);
            //LineTo(hdc, 325, 350);
            LineTo(hdc, rc.right - 155, rc.bottom + 220);
            //LineTo(hdc, 220, 420);
            LineTo(hdc, rc.right - 155, rc.bottom + 250);
            //LineTo(hdc, 220, 450);
            LineTo(hdc, rc.right - 35, rc.bottom + 250);
            //LineTo(hdc, 340, 450);

            MoveToEx(hdc, rc.left + 75, rc.top + 150, nullptr);
            //MoveToEx(hdc, 425, 450, nullptr);
            LineTo(hdc, rc.right + 75, rc.bottom + 300);
            //LineTo(hdc, 450, 500);
            LineTo(hdc, rc.right + 25, rc.bottom + 300);
            //LineTo(hdc, 400, 500);
            LineTo(hdc, rc.right + 10, rc.bottom + 290);
            //LineTo(hdc, 385, 490);
            LineTo(hdc, rc.right, rc.bottom + 300);
            //LineTo(hdc, 375, 500);
            LineTo(hdc, rc.right - 10, rc.bottom + 290);
            //LineTo(hdc, 365, 490);
            LineTo(hdc, rc.right - 25, rc.bottom + 300);
            //LineTo(hdc, 350, 500);
            LineTo(hdc, rc.right - 75, rc.bottom + 300);
            //LineTo(hdc, 300, 500);
            LineTo(hdc, rc.right - 50, rc.bottom + 250);
            //LineTo(hdc, 325, 450);
            /// ㅁㄴㅇ 220줄 ㅎㅇ
            Ellipse(hdc, rc.left + 10, rc.top - 50, rc.right + 15, rc.bottom + 130);
            //Ellipse(hdc, 360, 250, 390, 330);


            for (auto& iter : BulletList[0])
            {
                //  350, 300, 375, 200 
                Ellipse(hdc, iter.left + 20, iter.top - 110, iter.right + 5, iter.bottom + 30);
                Rectangle(hdc, iter.left + 20, iter.top - 95, iter.right + 5, iter.bottom + 30);

                iter.top -= 10;
                iter.bottom -= 10;
            }

            for (auto& iter : BulletList[1])
            {
                Ellipse(hdc, iter.left + 20, iter.top - 110, iter.right + 5, iter.bottom + 30);
                Rectangle(hdc, iter.left + 20, iter.top - 95, iter.right + 5, iter.bottom + 30);

                iter.top -= 10;
                iter.bottom -= 10;
                iter.left -= 10;
                iter.right -= 10;
            }

            for (auto& iter : BulletList[2])
            {
                Ellipse(hdc, iter.left + 20, iter.top - 110, iter.right + 5, iter.bottom + 30);
                Rectangle(hdc, iter.left + 20, iter.top - 95, iter.right + 5, iter.bottom + 30);

                iter.top -= 10;
                iter.bottom -= 10;
                iter.left += 10;
                iter.right += 10;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        case VK_RIGHT:
            rc.left += 10;
            rc.right += 10;
            break;
        case VK_LEFT:
            rc.left -= 10;
            rc.right -= 10;
            break;
        case VK_UP:
            rc.top -= 10;
            rc.bottom -= 10;
            break;
        case VK_DOWN:
            rc.top += 10;
            rc.bottom += 10;
            break;

        case VK_SPACE:
            for (int i = 0; i < 3; i++)
            {
                BulletList[i].push_back(rc);
            }

            break;
        }
        break;
    case WM_DESTROY:
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
