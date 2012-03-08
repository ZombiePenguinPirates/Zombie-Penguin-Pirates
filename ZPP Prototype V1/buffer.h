#ifndef _BUFFER_H				// If we haven't included this file							
#define _BUFFER_H				// Set a flag saying we included it

void CreateDoubleBuffering(BUFFER &pBuffer, HWND &hwnd);
void ClearScreen(HDC &hdc, RECT &scrnRect, int color);
void SwapBackBuffer(BUFFER &pBuffer, BOOL bClearBackBuffer);
void ResizeBuffers(BUFFER &pBuffer);
void FreeBuffers(BUFFER &pBuffer);

#endif