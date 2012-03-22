#ifndef _BITBLT_H				// If we haven't included this file							
#define _BITBLT_H				// Set a flag saying we included it

void DrawMiniMap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh);
void DrawMenu(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh);
void DrawUI(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh);
void StretchBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh);
void TransparentStretchBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh);
void TransparentBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey);
void PortionOfBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey);
void TransparentPortionOfBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey);
void loadtiles();

#endif