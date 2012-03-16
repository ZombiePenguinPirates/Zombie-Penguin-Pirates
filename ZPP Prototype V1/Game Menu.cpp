#include "Game Menu.h"

INTERFACEOBJECT UserInterface[31];

static state option = main_menu;
static bool click_press = true;

void SetState(state State)
{
	option = State;
}

void initMenu()
{
	//added these 3 lines in initgame
	UserInterface[0].SetPic(1);								//main screen
	UserInterface[0].SetImageSize(800, 600);
	UserInterface[0].SetSize(640, 480);
	UserInterface[0].SetPos(0, 0);
	//and added the render function to end of drawgame
	UserInterface[0].SetState(main_menu);

	//added these 3 lines in initgame
	UserInterface[1].SetPic(2);								//new game
	UserInterface[1].SetImageSize(200, 55);
	UserInterface[1].SetSize(200, 55);
	UserInterface[1].SetPos(40, 140);
	//and added the render function to end of drawgame
	UserInterface[1].SetState(new_game);

	//added these 3 lines in initgame
	UserInterface[2].SetPic(6);								//load game
	UserInterface[2].SetImageSize(200, 55);
	UserInterface[2].SetSize(200, 55);
	UserInterface[2].SetPos(40, 185);
	//and added the render function to end of drawgame
	UserInterface[2].SetState(load_game);

	//added these 3 lines in initgame
	UserInterface[3].SetPic(3);								//settings
	UserInterface[3].SetImageSize(200, 80);
	UserInterface[3].SetSize(200, 80);
	UserInterface[3].SetPos(50, 300);
	//and added the render function to end of drawgame
	UserInterface[3].SetState(settings);

	//added these 3 lines in initgame
	UserInterface[4].SetPic(4);								//tutorials
	UserInterface[4].SetImageSize(200, 55);
	UserInterface[4].SetSize(200, 55);
	UserInterface[4].SetPos(50, 240);
	//and added the render function to end of drawgame
		UserInterface[4].SetState(tutorials);
	
	//added these 3 lines in initgame
	UserInterface[5].SetPic(5);								//quit_game
	UserInterface[5].SetImageSize(100, 55);
	UserInterface[5].SetSize(100, 55);
	UserInterface[5].SetPos(60, 360);
	//and added the render function to end of drawgame
		UserInterface[5].SetState(quit);

	//added these 3 lines in initgame	
	UserInterface[6].SetPic(7);								//load_game1
	UserInterface[6].SetImageSize(370, 99);
	UserInterface[6].SetSize(210, 50);
	UserInterface[6].SetPos(50, 210);
	//and added the render function to end of drawgame
		UserInterface[6].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[7].SetPic(8);								//load_game2
	UserInterface[7].SetImageSize(376, 99);
	UserInterface[7].SetSize(210, 50);
	UserInterface[7].SetPos(50, 260);
	//and added the render function to end of drawgame
		UserInterface[7].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[8].SetPic(9);								//load_game3
	UserInterface[8].SetImageSize(379, 99);
	UserInterface[8].SetSize(210, 50);
	UserInterface[8].SetPos(50, 310);
	//and added the render function to end of drawgame
		UserInterface[8].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[9].SetPic(10);							//key_bindings
	UserInterface[9].SetImageSize(400, 110);
	UserInterface[9].SetSize(210, 55);
	UserInterface[9].SetPos(50, 310);
	//and added the render function to end of drawgame
		UserInterface[9].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[10].SetPic(11);							//full_screen
	UserInterface[10].SetImageSize(400, 110);
	UserInterface[10].SetSize(210, 50);
	UserInterface[10].SetPos(50, 260);
	//and added the render function to end of drawgame
		UserInterface[10].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[11].SetPic(12);							//tutorials1
	UserInterface[11].SetImageSize(355, 114);
	UserInterface[11].SetSize(210, 50);
	UserInterface[11].SetPos(50, 210);
	//and added the render function to end of drawgame
		UserInterface[11].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[12].SetPic(13);							//tutorials2
	UserInterface[12].SetImageSize(354, 112);
	UserInterface[12].SetSize(210, 50);
	UserInterface[12].SetPos(50, 260);
	//and added the render function to end of drawgame
		UserInterface[12].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[13].SetPic(14);							//tutorials3
	UserInterface[13].SetImageSize(360, 106);
	UserInterface[13].SetSize(210, 50);
	UserInterface[13].SetPos(50, 310);
	//and added the render function to end of drawgame
		UserInterface[13].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[14].SetPic(15);							//back
	UserInterface[14].SetImageSize(150, 55);
	UserInterface[14].SetSize(150, 55);
	UserInterface[14].SetPos(50, 380);
	//and added the render function to end of drawgame
	UserInterface[14].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[15].SetPic(16);							//yes
	UserInterface[15].SetImageSize(150, 55);
	UserInterface[15].SetSize(150, 55);
	UserInterface[15].SetPos(50, 240);
	//and added the render function to end of drawgame
	UserInterface[15].SetState(quit_for_real);

		//added these 3 lines in initgame
	UserInterface[16].SetPic(17);							//no
	UserInterface[16].SetImageSize(150, 55);
	UserInterface[16].SetSize(150, 55);
	UserInterface[16].SetPos(50, 310);
	//and added the render function to end of drawgame
	UserInterface[16].SetState(main_menu);

		//added these 3 lines in initgame
	UserInterface[17].SetPic(18);							//audio
	UserInterface[17].SetImageSize(400, 110);
	UserInterface[17].SetSize(210, 50);
	UserInterface[17].SetPos(50, 210);
	//and added the render function to end of drawgame 
	UserInterface[17].SetState(main_menu);

	//added these 3 lines in initgame
	UserInterface[18].SetPic(6);							//load_menu
	UserInterface[18].SetImageSize(200, 55);
	UserInterface[18].SetSize(200, 55);
	UserInterface[18].SetPos(50, 160);
	//and added the render function to end of drawgame
	UserInterface[18].SetState(load_game);

	//added these 3 lines in initgame
	UserInterface[19].SetPic(3);							//settings_menu
	UserInterface[19].SetImageSize(200, 80);
	UserInterface[19].SetSize(200, 80);
	UserInterface[19].SetPos(50, 160);
	//and added the render function to end of drawgame
	UserInterface[19].SetState(settings);


	//added these 3 lines in initgame
	UserInterface[20].SetPic(4);							//tutorials_menu
	UserInterface[20].SetImageSize(200, 55);
	UserInterface[20].SetSize(200, 55);
	UserInterface[20].SetPos(50, 160);
	//and added the render function to end of drawgame
	UserInterface[20].SetState(tutorials);

	//added these 3 lines in initgame
	UserInterface[21].SetPic(5);							//quit_menu
	UserInterface[21].SetImageSize(100, 55);
	UserInterface[21].SetSize(100, 55);
	UserInterface[21].SetPos(50, 160);
	//and added the render function to end of drawgame
	UserInterface[21].SetState(quit);

	UserInterface[22].SetPic(19);							//pause screen
	UserInterface[22].SetImageSize(500, 700);
	UserInterface[22].SetSize(210, 300);
	UserInterface[22].SetPos(250, 100);
	//and added the render function to end of drawgame
	UserInterface[22].SetState(new_game);

	UserInterface[23].SetPic(5);							//pause screen quit
	UserInterface[23].SetImageSize(150, 55);
	UserInterface[23].SetSize(150, 55);
	UserInterface[23].SetPos(270, 150);
	//and added the render function to end of drawgame
	UserInterface[23].SetState(in_game_pause_quit);

	UserInterface[24].SetPic(15);							//pause screen back
	UserInterface[24].SetImageSize(150, 55);
	UserInterface[24].SetSize(140, 55);
	UserInterface[24].SetPos(270, 250);
	//and added the render function to end of drawgame
	UserInterface[24].SetState(new_game);

	UserInterface[25].SetPic(5);							//pause screen quit propper
	UserInterface[25].SetImageSize(150, 55);
	UserInterface[25].SetSize(150, 55);
	UserInterface[25].SetPos(270, 120);
	//and added the render function to end of drawgame
	UserInterface[25].SetState(in_game_pause_quit);
	
	UserInterface[26].SetPic(16);							//pause screen quit propper yes
	UserInterface[26].SetImageSize(150, 55);
	UserInterface[26].SetSize(150, 55);
	UserInterface[26].SetPos(270, 200);
	//and added the render function to end of drawgame
	UserInterface[26].SetState(main_menu);

	UserInterface[27].SetPic(17);							//pause screen quit propper no
	UserInterface[27].SetImageSize(150, 55);
	UserInterface[27].SetSize(150, 55);
	UserInterface[27].SetPos(270, 250);
	//and added the render function to end of drawgame
	UserInterface[27].SetState(in_game_pause);

	UserInterface[28].SetPic(20);							//main menu credits option
	UserInterface[28].SetImageSize(150, 55);
	UserInterface[28].SetSize(150, 55);
	UserInterface[28].SetPos(50, 410);
	//and added the render function to end of drawgame
	UserInterface[28].SetState(main_menu);

	UserInterface[30].SetPic(21);							//pause screen quit propper no
	UserInterface[30].SetImageSize(400, 110);
	UserInterface[30].SetSize(160, 50);
	UserInterface[30].SetPos(270, 250);
	//and added the render function to end of drawgame
	UserInterface[30].SetState(new_game);

	UserInterface[29].SetPic(0);							//pause screen quit propper no
	UserInterface[29].SetImageSize(640, 480);
	UserInterface[29].SetSize(640, 480);
	UserInterface[29].SetPos(0, 0);
	//and added the render function to end of drawgame
	UserInterface[29].SetState(new_game);
}

state RunMenu(POINT mousepos, bool Lmousedown, bool Rmousedown)
{
	switch (option)
	{
	case main_menu:
		for(int button = 1; button < 7; button++)
		{
			if(MouseMenu(UserInterface[button], mousepos, Lmousedown, Rmousedown)&&click_press)
			{
				option = UserInterface[button].Getstate();
				click_press=false;
				//return option
				return option; 
			}
		}
		break;

	case load_game:
		if(MouseMenu(UserInterface[14], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[14].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[18], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[18].Getstate();
				click_press=false;
				//return option
				return option;
		}
			for(int button = 6; button < 9; button++)
		{
			if(MouseMenu(UserInterface[button], mousepos, Lmousedown, Rmousedown)&&click_press)
			{
				option = UserInterface[button].Getstate();
				click_press=false;
				//return option
				return option;
			}
		}
		break;

	case settings:
		if(MouseMenu(UserInterface[14], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
			option = UserInterface[14].Getstate();
			click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[19], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[19].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[17], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[17].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[9], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[9].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[10], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[10].Getstate();
				click_press=false;
				//return option
				return option;
		}
		break;

	case tutorials:
		for(int button = 11; button < 15; button++)
		{
			if(MouseMenu(UserInterface[button], mousepos, Lmousedown, Rmousedown)&&click_press)
			{
				option = UserInterface[button].Getstate();
				click_press=false;
				//return option
				return option;
			}
		}
		if(MouseMenu(UserInterface[20], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[20].Getstate();
				click_press=false;
				//return option
				return option;
		}
		break;

	case quit:
		if(MouseMenu(UserInterface[21], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[21].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[15], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[15].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[16], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[16].Getstate();
				click_press=false;
				//return option
				return option;
		}
		break;

	case in_game_pause:
		if(MouseMenu(UserInterface[23], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[23].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[24], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[24].Getstate();
				click_press=false;
				//return option
				return option;
		}
		break;

	case in_game_pause_quit:
		
		if(MouseMenu(UserInterface[25], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[25].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[26], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[26].Getstate();
				click_press=false;
				//return option
				return option;
		}
		if(MouseMenu(UserInterface[27], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[27].Getstate();
				click_press=false;
				//return option
				return option;
		}
		break;
	case GameOver:
		if(MouseMenu(UserInterface[28], mousepos, Lmousedown, Rmousedown)&&click_press)
		{
				option = UserInterface[28].Getstate();
				click_press = false;
				//return option
				return option;
		}
		break;
	}
	if (!Lmousedown && !Rmousedown)
	{click_press = true;}
	
	return option;
}

void pause_options(state s)
{
	option = s;
}

bool MouseMenu(INTERFACEOBJECT &object, POINT mousepos, bool Lmousedown, bool Rmousedown)
{
	if(Lmousedown || Rmousedown)
	{
		//if theres a collision return true (ask if you wanna know how this works)
		if ((mousepos.x > object.GetPos().x) && (mousepos.x < object.GetPos().x + object.GetSize().x)
			&& (mousepos.y > object.GetPos().y) && (mousepos.y < object.GetPos().y + object.GetSize().y)) 
		{
			return true;
		}else{}
	}
	return false;
}

void drawMenu(BUFFER &pBuffer)
{
	UserInterface[0].Render(pBuffer);
	UserInterface[1].Render(pBuffer);			//main menu
	UserInterface[2].Render(pBuffer);
	UserInterface[3].Render(pBuffer);
	UserInterface[4].Render(pBuffer);
	UserInterface[5].Render(pBuffer);
	UserInterface[28].Render(pBuffer);
}

void drawMenu2(BUFFER &pBuffer)
{
	UserInterface[0].Render(pBuffer);			//load game menu
	UserInterface[18].Render(pBuffer);
	UserInterface[14].Render(pBuffer);
	UserInterface[6].Render(pBuffer);
	UserInterface[7].Render(pBuffer);
	UserInterface[8].Render(pBuffer);

}
void drawMenu3(BUFFER &pBuffer)
{
	UserInterface[0].Render(pBuffer);			//setting menu
	UserInterface[19].Render(pBuffer);
	UserInterface[14].Render(pBuffer);
	UserInterface[17].Render(pBuffer);
	UserInterface[9].Render(pBuffer);
	UserInterface[10].Render(pBuffer);

}
void drawMenu4(BUFFER &pBuffer)
{
	UserInterface[0].Render(pBuffer);			//tutorials menu
	UserInterface[20].Render(pBuffer);
	UserInterface[11].Render(pBuffer);
	UserInterface[12].Render(pBuffer);
	UserInterface[13].Render(pBuffer);
	UserInterface[14].Render(pBuffer);

}

void drawMenu5(BUFFER &pBuffer)
{
	UserInterface[0].Render(pBuffer);			//quit menu
	UserInterface[21].Render(pBuffer);
	UserInterface[15].Render(pBuffer);
	UserInterface[16].Render(pBuffer);
}

void drawMenu6(BUFFER &pBuffer)
{
	UserInterface[22].Render(pBuffer);			//in game menu screen
	UserInterface[23].Render(pBuffer);			//in game menu quit
	UserInterface[24].Render(pBuffer);			//in game menu back
}

void drawMenu7(BUFFER &pBuffer)
{
	UserInterface[22].Render(pBuffer);			//in game menu screen
	UserInterface[25].Render(pBuffer);			//in game pause quit
	UserInterface[26].Render(pBuffer);			//in game pause quit yes
	UserInterface[27].Render(pBuffer);			//in game pause quit no
}
void drawMenu8(BUFFER &pBuffer)
{
	UserInterface[29].Render(pBuffer);
	UserInterface[30].Render(pBuffer);			//in game pause quit no
}