// WindowsProject13.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject13.h"

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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT13, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT13));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT13));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT13);
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
void drawCar(HDC hdc) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(121, 0, 121));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 50, 200, 300, 250);

    MoveToEx(hdc, 100, 200, NULL);
    LineTo(hdc, 150, 150);
    LineTo(hdc, 250, 150);
    LineTo(hdc, 300, 200);

    hPen = CreatePen(PS_SOLID, 7, RGB(64, 0, 64));
    SelectObject(hdc, hPen);

    hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(64, 0, 64));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 75, 225, 125, 275);
    Ellipse(hdc, 225, 225, 275, 275);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}
void drawSnowman(HDC hdc) {
    HPEN hPen;
    HBRUSH hBrush;
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(225, 255, 225));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 480, 270, 610, 370);
    Ellipse(hdc, 500, 200, 585, 270);
    Ellipse(hdc, 520, 150, 570, 200);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(121, 0, 121));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 520, 100, 570, 140);

    hBrush = CreateSolidBrush(RGB(255, 140, 175));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 497, 140, 590, 160);

    hPen = CreatePen(PS_SOLID, 3, RGB(255, 128, 64));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 540, 175, NULL);
    LineTo(hdc, 500, 180);
    LineTo(hdc, 540, 185);

    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    hBrush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 530, 170, 535, 175);
    Ellipse(hdc, 550, 170, 555, 175);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, 500, 235, NULL);
    LineTo(hdc, 465, 205);
    MoveToEx(hdc, 478, 215, NULL);
    LineTo(hdc, 460, 220);
    MoveToEx(hdc, 478, 215, NULL);
    LineTo(hdc, 480, 200);

    MoveToEx(hdc, 580, 230, NULL);
    LineTo(hdc, 625, 205);
    MoveToEx(hdc, 608, 215, NULL);
    LineTo(hdc, 610, 195);
    MoveToEx(hdc, 608, 215, NULL);
    LineTo(hdc, 626, 220);
}
void drawTruck(HDC hdc) {
    HPEN hPen;
    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(255, 140, 175));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 260, 465, 520, 620);

    MoveToEx(hdc, 260, 515, NULL);
    LineTo(hdc, 140, 565);
    LineTo(hdc, 140, 620);
    LineTo(hdc, 260, 620);

    hBrush = CreateSolidBrush(RGB(168, 168, 168));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, 190, 600, 255, 660);
    Ellipse(hdc, 305, 600, 370, 660);
    Ellipse(hdc, 455, 600, 520, 660);
}
void drawFlower(HDC hdc) {
    HPEN hPen;
    HBRUSH hBrush;
    hBrush = CreateSolidBrush(RGB(128, 64, 64));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 835, 265, 960, 375);

    hBrush = CreateSolidBrush(RGB(0, 128, 0));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_SOLID, 3, RGB(0, 128, 0));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 890, 80, 900, 265);

    hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 128, 0));
    SelectObject(hdc, hBrush);

    Rectangle(hdc, 765, 150, 890, 265);
    Rectangle(hdc, 900, 150, 1020, 265);

    hBrush = CreateSolidBrush(RGB(255, 255, 0));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_DASHDOTDOT, 1, RGB(255, 255, 0));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 880, 40, 910, 80);

    hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(200, 291, 131));
    SelectObject(hdc, hBrush);

    hPen = CreatePen(PS_DASH, 1, RGB(200, 291, 131));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 850, 15, 880, 45);
    Rectangle(hdc, 910, 15, 940, 45);
    Rectangle(hdc, 850, 75, 880, 105);
    Rectangle(hdc, 910, 75, 940, 105);
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
   
            drawCar(hdc);
            drawSnowman(hdc);
            drawTruck(hdc);
            drawFlower(hdc);

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

