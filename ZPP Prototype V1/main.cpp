#include "main.h"

//create double buffer
BUFFER gBuffer;												

//key presses
bool keys[256];
POINT mousepos, dragpos;
bool Lmousedown, Rmousedown, mousedrag;

//game is running
bool game_running = true;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{	
	long long int GameTime = 0;
	state screen = main_menu;
	// Create the handle to the window.  
	HWND        hwnd;										
	// Create the variable to hold the window messages
	MSG         msg;	

	// Create the structure that holds the attributes of the window.
	// I just crammed them in like this to save space because we know what they do.
	WNDCLASSEX  wndclass = {sizeof (wndclass), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, 
							hInstance, LoadIcon (NULL, IDI_WINLOGO),
							LoadCursor (NULL, IDC_ARROW), 
							(HBRUSH) GetStockObject (WHITE_BRUSH),
							NULL, "Window Class", LoadIcon (NULL, IDI_WINLOGO)};


	// Register the window class with the operating system
	RegisterClassEx (&wndclass);	

	// Now, we actually create the window
	hwnd = CreateWindow ("Window Class",	// window class name 
		"Zombie Penguin Pirates",	  		// window's Title 
		WS_EX_TOPMOST |
		WS_POPUP |							// no boarders
		//WS_SIZEBOX |						//resize
		WS_SYSMENU,							// window style	- This style won't allow the window to resize
		50,									// initial x position
		50,									// initial y position
		WIDTH,								// Here we pass in our desired width 	 
		HEIGHT,								// Here we pass in our desired height 	 
		NULL,								// This is the parent window handle.  
		NULL,								// This is the window menu handle
		hInstance,						    // This is the programs instance handle.
		NULL);								// We don't want to pass any extra data in, so NULL

	// This shows our window. 
	ShowWindow (hwnd, iCmdShow);							

	// This pretty much paints our window to the screen.
	UpdateWindow (hwnd);									
	SwapBackBuffer(gBuffer, FALSE);

	PlaySound("sound//penguin soundtrack.wav", NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);

	initMenu();

	while(game_running)
	{
		// Check if there is a window message and remove it from the queue
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// If the message was to quit, break out of the while loop
			if(msg.message == WM_QUIT) break;

			// This Translates messages so windows understands them.
			TranslateMessage (&msg);					

			// This sends the messages to the WndProc().
			DispatchMessage (&msg);							
		}
		else
		{
			//if (keys[VK_ESCAPE]) game_running = false;

			switch (screen)
			{
			case main_menu:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
						drawMenu(gBuffer);
				break;

			case new_game:
				screen = rungame(keys, dragpos, mousedrag, mousepos, Lmousedown, Rmousedown);
				if (keys[VK_ESCAPE]) 
				{
					screen = in_game_pause;
					pause_options(screen);
				}
				if(AnimateNextFrame(GameFrameRate, GameTime))
				{
					drawgame(gBuffer, mousedrag);
				}
				break;

			case load_game:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
						drawMenu2(gBuffer);
				break;

			case settings:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
						drawMenu3(gBuffer);
				break;

			case tutorials:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
						drawMenu4(gBuffer);
				break;

			case quit:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
						drawMenu5(gBuffer);
				break;

			case quit_for_real:
				game_running = false;
				break;

			case in_game_pause:
				//game_running = false;
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
				drawMenu6(gBuffer);
				break;

			case in_game_pause_quit:
				screen = RunMenu(mousepos, Lmousedown, Rmousedown);
				drawMenu7(gBuffer);
				break;
			}
			SwapBackBuffer(gBuffer, FALSE);
			//run game created in game files
		}
	}
	UnregisterClass("Window Class",hInstance);

	return 0;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Check which message was passed in
	switch (iMsg)											
	{
		// This message is sent when the window is created
	case WM_CREATE:
		//Create the double buffer and load the bitmaps	
		Init(hwnd);										
		break;

	case WM_RBUTTONDOWN:
		Rmousedown = true;
		break;

	case WM_RBUTTONUP:
		Rmousedown = false;
		break;

	case WM_KEYDOWN:
		keys[wParam] = true;
		break;
		// This message is sent when the window is destroyed
	case WM_MOUSEMOVE:
		if (Lmousedown) 
		{
			if (!mousedrag) dragpos = mousepos;
			mousedrag = true;
		}
		mousepos.x = LOWORD (lParam);
		mousepos.y = HIWORD (lParam);
		break;

	case WM_LBUTTONDOWN:
		Lmousedown = true;
		break;

	case WM_LBUTTONUP:
		Lmousedown = false;
		mousedrag = false;
		break;

	case WM_SIZE:
		ResizeBuffers(gBuffer);
		break;

	case WM_DESTROY:									
		// Free all the data and set everything back to normal, then post the quit message
		DeInit();										
		break;

		//key no longer pressed
	case WM_KEYUP:
		keys[wParam] = false;
		break;
	}													
	// Process/handle the default messages
	return DefWindowProc (hwnd, iMsg, wParam, lParam);		
}

void Init(HWND &hwnd)
{	
	// Create our double buffering
	CreateDoubleBuffering(gBuffer, hwnd);

	// Set the backbuffer to white first (This clears the backbuffer)
	ClearScreen(gBuffer.hdcBack, gBuffer.scrnRect, BLACK_BRUSH);			

	SwapBackBuffer(gBuffer, FALSE);

	game_running = true;
	loadtiles();
	initgame();
	//FullScreenDisplay();
}

void FullScreenDisplay()
{
	//change display mode to full screen
	DEVMODE screen;
	memset(&screen, 0, sizeof(screen));
	screen.dmSize = sizeof(screen);
	screen.dmPelsWidth = WIDTH;
	screen.dmPelsHeight = HEIGHT;
	screen.dmBitsPerPel = 32;
	screen.dmFields = DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
	ChangeDisplaySettings(&screen, CDS_FULLSCREEN);
}

void DeInit()
{
	// Free the back buffer
	FreeBuffers(gBuffer);
	
	// Post the QUIT message to the window (0 = WM_QUIT)															
	PostQuitMessage(0);				
}