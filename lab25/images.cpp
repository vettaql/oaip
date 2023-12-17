#include "images.h"

void Image1(HDC hdc, int cx, int cy, int size) {
		HPEN hPen;
		hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		SelectObject(hdc, hPen);

		MoveToEx(hdc, cx, cy + size, NULL);
		LineTo(hdc, cx + size, cy - size);
		LineTo(hdc, cx - size, cy - size);
		LineTo(hdc, cx, cy + size);

		DeleteObject(hPen);
	}

void Image2(HDC hdc, int cx, int cy, int size) {
	int x1 = cx - size / 2;
	int y1 = cy - size;
	int x2 = cx + size / 2;
	int y2 = cy - size;
	int x3 = cx - size;
	int y3 = cy + size;
	int x4 = cx + size;
	int y4 = cy + size;

	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, int size) {
	int x1 = cx;
	int y1 = cy - size;
	int x2 = cx + size;
	int y2 = cy;
	int x3 = cx;
	int y3 = cy + size;
	int x4 = cx - size;
	int y4 = cy;

	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}

void Image4(HDC hdc, int cx, int cy, int size) {
	int x1 = cx;
	int y1 = cy - size;
	int x2 = cx + size / 4;
	int y2 = cy - size / 4;
	int x3 = cx + size;
	int y3 = cy;
	int x4 = cx + size / 4;
	int y4 = cy + size / 4;
	int x5 = cx;
	int y5 = cy + size;
	int x6 = cx - size / 4;
	int y6 = cy + size / 4;
	int x7 = cx - size;
	int y7 = cy;
	int x8 = cx - size / 4;
	int y8 = cy - size / 4;


	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);
	LineTo(hdc, x6, y6);
	LineTo(hdc, x7, y7);
	LineTo(hdc, x8, y8);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}