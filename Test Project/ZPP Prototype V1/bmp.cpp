#include "main.h"

HBITMAP LoadABitmap(LPSTR szFileName)
{
	// Load bitmap and return handle to bitmap we loaded
	return (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void DeletePics(HBITMAP &hBitmap)
{
	//clean up
	if(hBitmap)
	{
		DeleteObject(hBitmap);			
	}
}