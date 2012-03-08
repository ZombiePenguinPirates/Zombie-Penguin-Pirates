#include "main.h"

void CreateDoubleBuffering(BUFFER &pBuffer, HWND &hwnd)
{
	// Assign window handle to structure
	pBuffer.hwnd = hwnd;									
	
	// Store client rect
	GetClientRect(hwnd, &(pBuffer.scrnRect));

	// Get handle to device context and store as front buffer
	pBuffer.hdcFront = GetDC(pBuffer.hwnd);

	// Create compatible device context for backbuffer
	pBuffer.hdcBack = CreateCompatibleDC(pBuffer.hdcFront);

	// Create another hdc to store bitmap before backbuffer
	pBuffer.hdcBitmap = CreateCompatibleDC(pBuffer.hdcFront);

	// Create dummy bitmap handle to store in front buffer
	pBuffer.hCompBitmap = CreateCompatibleBitmap(pBuffer.hdcFront, pBuffer.scrnRect.right, pBuffer.scrnRect.bottom);

	// Select dummy bitmap handle into back buffer to make it like front hdc
	pBuffer.hOldBitmap = (HBITMAP)SelectObject(pBuffer.hdcBack, pBuffer.hCompBitmap);	
}

void ClearScreen(HDC &hdc, RECT &scrnRect, int color)
{
	//fill backbuffer with white to clear screen
	FillRect(hdc, &scrnRect, (HBRUSH)GetStockObject(color));
}

void SwapBackBuffer(BUFFER &pBuffer, BOOL bClearBackBuffer)
{
	//blit backbuffer to screen
	BitBlt(pBuffer.hdcFront, pBuffer.scrnRect.left, pBuffer.scrnRect.top, 
		   pBuffer.scrnRect.right, pBuffer.scrnRect.bottom, pBuffer.hdcBack, 0, 0, SRCCOPY);
}

void ResizeBuffers(BUFFER &pBuffer)
{
	//get new client rectangle of window
	GetClientRect(pBuffer.hwnd, &(pBuffer.scrnRect));
			
	//select old bitmap into back buffer
	SelectObject(pBuffer.hdcBack, pBuffer.hOldBitmap);

	//delete old bitmap
	DeleteObject(pBuffer.hCompBitmap);

	//create new compatible bitmap with new size of window
	pBuffer.hCompBitmap = CreateCompatibleBitmap(pBuffer.hdcFront, pBuffer.scrnRect.right, pBuffer.scrnRect.bottom);

	//select new compatible bitmap into backbuffer and store old one again
	pBuffer.hOldBitmap = (HBITMAP) SelectObject(pBuffer.hdcBack, pBuffer.hCompBitmap);	
}

void FreeBuffers(BUFFER &pBuffer)
{
	//set backbuffer to original bitmap
	SelectObject(pBuffer.hdcBack, pBuffer.hOldBitmap);

	//free hbitmaps
	DeleteObject(pBuffer.hOldBitmap);
	DeleteObject(pBuffer.hCompBitmap);

	//free all HDC's
	ReleaseDC(pBuffer.hwnd, pBuffer.hdcBack);
	ReleaseDC(pBuffer.hwnd, pBuffer.hdcBitmap);
	ReleaseDC(pBuffer.hwnd, pBuffer.hdcFront);
}