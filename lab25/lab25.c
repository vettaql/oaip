// WindowsProject4.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject4.h"
#include "images.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
    Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    //рисунок 1.1
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);

    //рисунок 1.2
    //RecursiveImage1_1(hdc, cx - size, cy, size / 2);

    //рисунок 1.3
    //RecursiveImage1_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.4
    //RecursiveImage1_1(hdc, cx, cy + size, size / 2);

    //рисунок 1.5
    //RecursiveImage1_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage1_1(hdc, cx, cy + size, size / 2);


    //рисунок 1.6
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);

    //рисунок 1.7
    //RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size / 50, cy + size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);

    //рисунок 1.8
    //RecursiveImage1_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage1_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage1_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    //рисунок 1.1
    //RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);

    //рисунок 1.2
    //RecursiveImage2_1(hdc, cx - size, cy, size / 2); 

    //рисунок 1.3
    //RecursiveImage2_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.4
    //RecursiveImage2_1(hdc, cx - size, cy - size, size / 2);

    //рисунок 1.5
    //RecursiveImage2_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.6
    //RecursiveImage2_1(hdc, cx - size/2, cy - size, size / 2);
    //RecursiveImage2_1(hdc, cx + size/2, cy - size, size / 2);

    //рисунок 1.7
    //RecursiveImage2_1(hdc, cx - size / 2, cy - size, size / 2);
    //RecursiveImage2_1(hdc, cx + size / 2, cy - size, size / 2);
    //RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy + size, size / 2);

    //рисунок 1.8
    //RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy + size, size / 2);
      
}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    //рисунок 1.1
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.2
    //RecursiveImage2_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage2_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.3
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.4
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);

    //рисунок 1.5
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);


    //рисунок 1.6
    //RecursiveImage3_1(hdc, cx - size/2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size/2, cy - size, size / 2);

    //рисунок 1.7
    //RecursiveImage3_1(hdc, cx - size / 2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size / 2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx - size / 2, cy - size, size / 2);
    //RecursiveImage3_1(hdc, cx + size, cy, size / 2);
    //RecursiveImage3_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage3_1(hdc, cx - size, cy, size / 2);

}
void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    //рисунок 1.6
    //RecursiveImage4_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.2
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage4_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.3
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);

    //рисунок 1.4
    //RecursiveImage4_1(hdc, cx , cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);

    //рисунок 1.5
    //RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx - size, cy, size / 2);
    //RecursiveImage4_1(hdc, cx, cy - size, size / 2);
    //RecursiveImage4_1(hdc, cx + size, cy, size / 2);

    //рисунок 1.6
    //RecursiveImage4_1(hdc, cx - size/2, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx + size/2, cy - size, size / 2);

    //рисунок 1.7
    /*RecursiveImage4_1(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage4_1(hdc, cx + size / 2, cy - size, size / 2);
    RecursiveImage4_1(hdc, cx - size / 2, cy - size, size / 2);
    RecursiveImage4_1(hdc, cx + size, cy, size / 2);
    RecursiveImage4_1(hdc, cx, cy + size, size / 2);
    RecursiveImage4_1(hdc, cx - size, cy, size / 2);*/

    //рисунок 1.8
    //RecursiveImage4_1(hdc, cx - size, cy + size, size / 2);
    //RecursiveImage4_1(hdc, cx + size, cy + size, size / 2);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
           
            //RecursiveImage1_1(hdc, 200, 160, 80);
            //RecursiveImage2_1(hdc, 200, 200, 100);
            //RecursiveImage3_1(hdc, 200, 200, 100);
            RecursiveImage4_1(hdc, 200, 200, 100);
            EndPaint(hWnd, &ps);
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

// Обработчик сообщений для окна "О программе".
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
