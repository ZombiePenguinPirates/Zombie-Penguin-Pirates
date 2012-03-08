#ifndef _MAIN_H				// If we haven't included this file							
#define _MAIN_H				// Set a flag saying we included it

#include <windows.h>
//#include <iostream>
//#include <stdio.h>
#include <MMSystem.h>
//#include <fstream>
//#include <string> 
//#include <sstream>
#include <math.h>
#include "FrameRate.h"
#include "struct.h"
#include "bitblt.h"
#include "bmp.h"
#include "buffer.h"
#include "Object.h"
#include "zombie.h"
#include "Game.h"
#include "UI.h"
#include "Game Menu.h"

#pragma comment(lib,"winmm.lib")

// Create a define for our window height
#define HEIGHT			480			
// Create a define for our window width
#define WIDTH			640



LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
void FullScreenDisplay();
void Init(HWND &hwnd);
void DeInit();

#endif