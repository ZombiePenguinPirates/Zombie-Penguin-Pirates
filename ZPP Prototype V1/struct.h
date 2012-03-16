#ifndef _STRUCTS_H				// If we haven't included this file							
#define _STRUCTS_H				// Set a flag saying we included it

struct BUFFER					// This is our back buffering structure
{
	HWND hwnd;					// This holds the current window's handle
	RECT scrnRect;				// This holds the client rectangle of the window
	HANDLE hCompBitmap;			// This holds the compatible bitmap for the backbuffer
	HANDLE hOldBitmap;			// This is used for storage to free when the program quits
	HDC hdcFront;				// This is the front buffer (The part we see)
	HDC hdcBack;				// This is the back buffer (the part we draw to, then flip)
	HDC hdcBitmap;				// This is a temp buffer to swap the bitmap back and forth from
};

struct SQUARE
{
	int x;
	int y;
	int width;
	int height;
};

struct BOOLSQUARE
{
	bool left;
	bool top;
	bool right;
	bool bot;
};

#define TilesSize		64
#define xtiles			16
#define ytiles			16

#define mapsizex (TilesSize * xtiles)			//+ boarder - 1
#define mapsizey (TilesSize * ytiles)			//+ boarder - 1

#endif