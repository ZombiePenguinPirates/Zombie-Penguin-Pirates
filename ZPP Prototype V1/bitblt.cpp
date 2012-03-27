#include "main.h"
#include <stdlib.h>

#define totaltiles		5
#define totalpics		7
#define uipics			22
#define minimap			6
//change this number for the amount of frames
#define menuanimation	91

static int frames = 0;
static int frames2 = 0;

HBITMAP MenuFrames[menuanimation];
HBITMAP MiniMap[minimap];
HBITMAP UIPics[uipics];
HBITMAP tiles[totaltiles];
HBITMAP BMPW[totalpics];
HBITMAP BMPB[totalpics];

void loadtiles()
{
	//data inputing for you, every frame needs one
	
	MenuFrames[1] = LoadABitmap("graphics//bg//bg ani0001.bmp");
	MenuFrames[2] = LoadABitmap("graphics//bg//bg ani0002.bmp");
	MenuFrames[3] = LoadABitmap("graphics//bg//bg ani0003.bmp");
	MenuFrames[4] = LoadABitmap("graphics//bg//bg ani0004.bmp");
	MenuFrames[5] = LoadABitmap("graphics//bg//bg ani0005.bmp");
	MenuFrames[6] = LoadABitmap("graphics//bg//bg ani0006.bmp");
	MenuFrames[7] = LoadABitmap("graphics//bg//bg ani0007.bmp");
	MenuFrames[8] = LoadABitmap("graphics//bg//bg ani0008.bmp");
	MenuFrames[9] = LoadABitmap("graphics//bg//bg ani0009.bmp");
	MenuFrames[10] = LoadABitmap("graphics//bg//bg ani0010.bmp");
	MenuFrames[11] = LoadABitmap("graphics//bg//bg ani0011.bmp");
	MenuFrames[12] = LoadABitmap("graphics//bg//bg ani0012.bmp");
	MenuFrames[13] = LoadABitmap("graphics//bg//bg ani0013.bmp");
	MenuFrames[14] = LoadABitmap("graphics//bg//bg ani0014.bmp");
	MenuFrames[15] = LoadABitmap("graphics//bg//bg ani0015.bmp");
	MenuFrames[16] = LoadABitmap("graphics//bg//bg ani0016.bmp");
	MenuFrames[17] = LoadABitmap("graphics//bg//bg ani0017.bmp");
	MenuFrames[18] = LoadABitmap("graphics//bg//bg ani0018.bmp");
	MenuFrames[19] = LoadABitmap("graphics//bg//bg ani0019.bmp");
	MenuFrames[20] = LoadABitmap("graphics//bg//bg ani0020.bmp");
	MenuFrames[21] = LoadABitmap("graphics//bg//bg ani0021.bmp");
	MenuFrames[22] = LoadABitmap("graphics//bg//bg ani0022.bmp");
	MenuFrames[23] = LoadABitmap("graphics//bg//bg ani0023.bmp");
	MenuFrames[24] = LoadABitmap("graphics//bg//bg ani0024.bmp");
	MenuFrames[25] = LoadABitmap("graphics//bg//bg ani0025.bmp");
	MenuFrames[26] = LoadABitmap("graphics//bg//bg ani0026.bmp");
	MenuFrames[27] = LoadABitmap("graphics//bg//bg ani0027.bmp");
	MenuFrames[28] = LoadABitmap("graphics//bg//bg ani0028.bmp");
	MenuFrames[29] = LoadABitmap("graphics//bg//bg ani0029.bmp");
	MenuFrames[30] = LoadABitmap("graphics//bg//bg ani0030.bmp");
	MenuFrames[31] = LoadABitmap("graphics//bg//bg ani0031.bmp");
	MenuFrames[32] = LoadABitmap("graphics//bg//bg ani0032.bmp");
	MenuFrames[33] = LoadABitmap("graphics//bg//bg ani0033.bmp");
	MenuFrames[34] = LoadABitmap("graphics//bg//bg ani0034.bmp");
	MenuFrames[35] = LoadABitmap("graphics//bg//bg ani0035.bmp");
	MenuFrames[36] = LoadABitmap("graphics//bg//bg ani0036.bmp");
	MenuFrames[37] = LoadABitmap("graphics//bg//bg ani0037.bmp");
	MenuFrames[38] = LoadABitmap("graphics//bg//bg ani0038.bmp");
	MenuFrames[39] = LoadABitmap("graphics//bg//bg ani0039.bmp");
	MenuFrames[40] = LoadABitmap("graphics//bg//bg ani0040.bmp");
	MenuFrames[41] = LoadABitmap("graphics//bg//bg ani0041.bmp");
	MenuFrames[42] = LoadABitmap("graphics//bg//bg ani0042.bmp");
	MenuFrames[43] = LoadABitmap("graphics//bg//bg ani0043.bmp");
	MenuFrames[44] = LoadABitmap("graphics//bg//bg ani0044.bmp");
	MenuFrames[45] = LoadABitmap("graphics//bg//bg ani0045.bmp");
	MenuFrames[46] = LoadABitmap("graphics//bg//bg ani0046.bmp");
	MenuFrames[47] = LoadABitmap("graphics//bg//bg ani0047.bmp");
	MenuFrames[48] = LoadABitmap("graphics//bg//bg ani0048.bmp");
	MenuFrames[49] = LoadABitmap("graphics//bg//bg ani0049.bmp");
	MenuFrames[50] = LoadABitmap("graphics//bg//bg ani0050.bmp");
	MenuFrames[51] = LoadABitmap("graphics//bg//bg ani0051.bmp");
	MenuFrames[52] = LoadABitmap("graphics//bg//bg ani0052.bmp");
	MenuFrames[53] = LoadABitmap("graphics//bg//bg ani0053.bmp");
	MenuFrames[54] = LoadABitmap("graphics//bg//bg ani0054.bmp");
	MenuFrames[55] = LoadABitmap("graphics//bg//bg ani0055.bmp");
	MenuFrames[56] = LoadABitmap("graphics//bg//bg ani0056.bmp");
	MenuFrames[57] = LoadABitmap("graphics//bg//bg ani0057.bmp");
	MenuFrames[57] = LoadABitmap("graphics//bg//bg ani0058.bmp");
	MenuFrames[58] = LoadABitmap("graphics//bg//bg ani0059.bmp");
	MenuFrames[60] = LoadABitmap("graphics//bg//bg ani0060.bmp");
	MenuFrames[61] = LoadABitmap("graphics//bg//bg ani0061.bmp");
	MenuFrames[62] = LoadABitmap("graphics//bg//bg ani0062.bmp");
	MenuFrames[63] = LoadABitmap("graphics//bg//bg ani0063.bmp");
	MenuFrames[64] = LoadABitmap("graphics//bg//bg ani0064.bmp");
	MenuFrames[65] = LoadABitmap("graphics//bg//bg ani0065.bmp");
	MenuFrames[66] = LoadABitmap("graphics//bg//bg ani0066.bmp");
	MenuFrames[67] = LoadABitmap("graphics//bg//bg ani0067.bmp");
	MenuFrames[68] = LoadABitmap("graphics//bg//bg ani0068.bmp");
	MenuFrames[69] = LoadABitmap("graphics//bg//bg ani0069.bmp");
	MenuFrames[70] = LoadABitmap("graphics//bg//bg ani0070.bmp");
	MenuFrames[71] = LoadABitmap("graphics//bg//bg ani0071.bmp");
	MenuFrames[72] = LoadABitmap("graphics//bg//bg ani0072.bmp");
	MenuFrames[73] = LoadABitmap("graphics//bg//bg ani0073.bmp");
	MenuFrames[74] = LoadABitmap("graphics//bg//bg ani0074.bmp");
	MenuFrames[75] = LoadABitmap("graphics//bg//bg ani0075.bmp");
	MenuFrames[76] = LoadABitmap("graphics//bg//bg ani0076.bmp");
	MenuFrames[77] = LoadABitmap("graphics//bg//bg ani0077.bmp");
	MenuFrames[78] = LoadABitmap("graphics//bg//bg ani0078.bmp");
	MenuFrames[79] = LoadABitmap("graphics//bg//bg ani0079.bmp");
	MenuFrames[80] = LoadABitmap("graphics//bg//bg ani0080.bmp");
	MenuFrames[81] = LoadABitmap("graphics//bg//bg ani0081.bmp");
	MenuFrames[82] = LoadABitmap("graphics//bg//bg ani0082.bmp");
	MenuFrames[83] = LoadABitmap("graphics//bg//bg ani0083.bmp");
	MenuFrames[84] = LoadABitmap("graphics//bg//bg ani0084.bmp");
	MenuFrames[85] = LoadABitmap("graphics//bg//bg ani0085.bmp");
	MenuFrames[86] = LoadABitmap("graphics//bg//bg ani0086.bmp");
	MenuFrames[87] = LoadABitmap("graphics//bg//bg ani0087.bmp");
	MenuFrames[88] = LoadABitmap("graphics//bg//bg ani0088.bmp");
	MenuFrames[89] = LoadABitmap("graphics//bg//bg ani0089.bmp");
	MenuFrames[90] = LoadABitmap("graphics//bg//bg ani0090.bmp");
	MenuFrames[91] = LoadABitmap("graphics//bg//bg ani0091.bmp");


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
	BMPW[5] = LoadABitmap("graphics//zombies//brute w.bmp");
	BMPW[6] = LoadABitmap("graphics//zombies//ranged_penguin w.bmp");

	BMPB[0] = LoadABitmap("graphics//zombies//zombie b.bmp");
	BMPB[1] = LoadABitmap("graphics//humans//human b.bmp");
	BMPB[2] = LoadABitmap("graphics//bench b.bmp");
	BMPB[3] = LoadABitmap("graphics//background_wall b.bmp");
	BMPB[4] = LoadABitmap("graphics//blood_guts b.bmp");
	BMPB[5] = LoadABitmap("graphics//zombies//brute b.bmp");
	BMPB[6] = LoadABitmap("graphics//zombies//ranged_penguin b.bmp");

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

void DrawMenu(BUFFER &pBuffer, int pic, int screenx, int screeny, int width, int height, int imagex, int imagey, int imagew, int imageh)
{
	//select bitmap handle
	//if(frames % 20 == 0)
	{
			SelectObject(pBuffer.hdcBitmap, MenuFrames[pic]);
	}
	
	++frames;

	if(frames > 99999)
	{
		frames = 0;
	}

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