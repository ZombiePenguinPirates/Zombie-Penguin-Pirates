#include "main.h"

#define totaltiles		5
#define totalpics		5
#define uipics			22
#define minimap			6

HBITMAP MiniMap[minimap];
HBITMAP UIPics[uipics];
HBITMAP tiles[totaltiles];
HBITMAP BMPW[totalpics];
HBITMAP BMPB[totalpics];

void loadtiles()
{
	tiles[0] = LoadABitmap("graphics//tiles//tile grass.bmp");
	tiles[1] = LoadABitmap("graphics//tiles//metal_texture_3.bmp");//tile dirt.bmp");
	tiles[2] = LoadABitmap("graphics//tiles//tile road.bmp");
	tiles[3] = LoadABitmap("graphics//tiles//tile sand.bmp");
	tiles[4] = LoadABitmap("graphics//tiles//tile water.bmp");

	BMPW[0] = LoadABitmap("graphics//zombies//zombie w.bmp");
	BMPW[1] = LoadABitmap("graphics//humans//human w.bmp");
	BMPW[2] = LoadABitmap("graphics//bench w.bmp");
	BMPW[3] = LoadABitmap("graphics//background_wall w.bmp");
	BMPW[4] = LoadABitmap("graphics//blood_guts w.bmp");

	BMPB[0] = LoadABitmap("graphics//zombies//zombie b.bmp");
	BMPB[1] = LoadABitmap("graphics//humans//human b.bmp");
	BMPB[2] = LoadABitmap("graphics//bench b.bmp");
	BMPB[3] = LoadABitmap("graphics//background_wall b.bmp");
	BMPB[4] = LoadABitmap("graphics//blood_guts b.bmp");

	UIPics[0] = LoadABitmap("graphics//menu//level_done.bmp");
	UIPics[1] = LoadABitmap("graphics//menu//main_menu.bmp");		//Greig_Main menu pics		
	UIPics[2] = LoadABitmap("graphics//menu//new_game.bmp");
	UIPics[3] = LoadABitmap("graphics//menu//settings.bmp");
	UIPics[4] = LoadABitmap("graphics//menu//tutorials.bmp");
	UIPics[5] = LoadABitmap("graphics//menu//quit_game.bmp");
	UIPics[6] = LoadABitmap("graphics//menu//load_game.bmp");		
	UIPics[7] = LoadABitmap("graphics//menu//load_game1.bmp");
	UIPics[8] = LoadABitmap("graphics//menu//load_game2.bmp");
	UIPics[9] = LoadABitmap("graphics//menu//load_game3.bmp");
	UIPics[10] = LoadABitmap("graphics//menu//key_bindings.bmp");
	UIPics[11] = LoadABitmap("graphics//menu//full_screen.bmp");	
	UIPics[12] = LoadABitmap("graphics//menu//tutorials1.bmp");
	UIPics[13] = LoadABitmap("graphics//menu//tutorials2.bmp");
	UIPics[14] = LoadABitmap("graphics//menu//tutorials3.bmp");
	UIPics[15] = LoadABitmap("graphics//menu//back.bmp");
	UIPics[16] = LoadABitmap("graphics//menu//yes.bmp");
	UIPics[17] = LoadABitmap("graphics//menu//no.bmp");
	UIPics[18] = LoadABitmap("graphics//menu//audio.bmp");
	UIPics[19] = LoadABitmap("graphics//menu//game_menu.bmp");
	UIPics[20] = LoadABitmap("graphics//menu//credits.bmp");
	UIPics[21] = LoadABitmap("graphics//menu//RETRY.bmp");

	MiniMap[0] = LoadABitmap("graphics//UI//Temp_Mini.bmp");
	MiniMap[1] = LoadABitmap("graphics//UI//enemy.bmp");
	MiniMap[2] = LoadABitmap("graphics//UI//player.bmp");
	MiniMap[3] = LoadABitmap("graphics//UI//overlay.bmp");

	for (int x = 0; x < 4; x++)
	{
		if (!MiniMap[x])
		{
			MessageBox(NULL, "failed to load", (LPCSTR) x, MB_OK); 
		}
	}
	MiniMap[4] = LoadABitmap("graphics//decking.bmp");
	MiniMap[5] = LoadABitmap("graphics//bench b.bmp");
}

void DrawMiniMap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, MiniMap[pic]);

	//blit bitmap into backbuffer
	StretchBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, imagew, imageh, SRCCOPY);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void DrawUI(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, UIPics[pic]);

	//blit bitmap into backbuffer
	StretchBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, imagew, imageh, SRCCOPY);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void StretchBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, tiles[pic]);

	//blit bitmap into backbuffer
	StretchBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, imagew, imageh, SRCCOPY);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void TransparentStretchBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPW[pic]);

	//blit bitmap into backbuffer
	StretchBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, imagew, imageh, SRCAND);

	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPB[pic]);

	//blit bitmap into backbuffer
	StretchBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, imagew, imageh, SRCPAINT);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void TransparentBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPW[pic]);
	//blit 1st part of image (white transparrent)
	BitBlt(pBuffer.hdcBack, screenx, screeny, width, height, pBuffer.hdcBitmap, imagex, imagey, SRCAND);

	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPB[pic]);
	//blit 2st part of image (black transparrent)
	BitBlt(pBuffer.hdcBack, screenx, screeny, width, height, pBuffer.hdcBitmap, imagex, imagey, SRCPAINT);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void PortionOfBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, tiles[pic]);

	//blit bitmap into backbuffer
	BitBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, SRCCOPY);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}

void TransparentPortionOfBitmap(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey)
{
	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPW[pic]);

	//blit bitmap into backbuffer
	BitBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, SRCAND);

	//select bitmap handle
	SelectObject(pBuffer.hdcBitmap, BMPB[pic]);

	//blit bitmap into backbuffer
	BitBlt(pBuffer.hdcBack, screenx, screeny, width, height, 
				   pBuffer.hdcBitmap, imagex, imagey, SRCPAINT);

	//select old handle to clean up
	SelectObject(pBuffer.hdcBitmap, pBuffer.hOldBitmap);
}