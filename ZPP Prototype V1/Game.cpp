#include "Game.h"

//will most likely change to a single image for background
int maptiles[xtiles][ytiles];
//position of the top left corner of the screen on the map (caps at edges of the screen, ask if you want an explenation)
POINT mappos = {0, 0};

ZOMBIE icon;
//first set of units
ZOMBIE blue[units];
//2nd set of units
ZOMBIE green[units];
//set of objects
OBJECT scenery[objects];
//used for the drag area, ask if you wanna know how it works
SQUARE DragSize;

bool SceneWon = false;
static int spawnunit = 0;
static bool recentlyplaced = true;

//initialising game
void initgame()
{
	initunits();
	initmap();
	initObjects();
}

//initialising units
void initunits()
{
	spawnunit = 0;
	for (int x = 0; x < units; x++)
	{
		//blue data
		blue[x].SetSize(50, 50);
		blue[x].SetRadius(25);
		blue[x].SetTeam(4);
		blue[x].Revive();
		blue[x].SetMaxHealth(5);
		blue[x].SetHealth(5);
		blue[x].Select(false);
		//picture used according to array
		blue[x].SetPic(0);
		blue[x].SetPos(-blue[x].GetSize().x, (x + 1) * blue[x].GetSize().y + 150);
		//move order set to its current position (cant tell it not to move but can tell it that its target is where it is, bool could change that but adding an if statement isnt needed)
		blue[x].SetMoveOrder(blue[x].GetPos());
		//size of image used
		blue[x].SetImageSize(50, 50);
		blue[x].SetAttackDelay(50);
		blue[x].SetMinDamage(1);
		blue[x].SetMaxDamage(1);
		//green data
		green[x].SetImageSize(50, 50);
		green[x].SetSize(50, 50);
		green[x].SetRadius(10);
		green[x].SetTeam(0);
		green[x].Revive();
		green[x].SetMaxHealth(5);
		green[x].SetHealth(5);
		green[x].Select(false);
		green[x].SetPic(1);
		green[x].SetPos(3 * TilesSize - green[x].GetSize().x, (x + 3) * TilesSize);
		green[x].SetMoveOrder(green[x].GetPos());
		green[x].SetAttackDelay(100);
		green[x].SetMinDamage(1);
		green[x].SetMaxDamage(1);
	}
	icon = blue[0];
	icon.Select(false);
}

//initialising map (wont be needed without scrolling screen)
void initmap()
{
	for (int x = 0; x < xtiles; x++)
	{
		for (int y = 0; y < xtiles; y++)
		{
			//change tile used as it goes along starting with tile 1
			maptiles[x][y] = 1;
		}
	}
}

//initialising objects
void initObjects()
{
	for (int y = 0; y < objects; y++)
	{
		//object data
		scenery[y].SetImageSize(32, 16);
		scenery[y].SetSize(32, 20);
		//pic 2 from array
		scenery[y].SetPic(2);
		scenery[y].SetPos((y + 2) * 20 + 200, (y * 2) * 20 + 300);
		//change collision type (atm 0 for square, 5 for circle, 1-4 triangle which isnt coded, may change to only use circle and square)
		scenery[y].SetType(0);
	}
	//object data
	scenery[0].SetImageSize(1024, 150);
	scenery[0].SetSize(1024, 150);
	//pic 2 from array
	scenery[0].SetPic(3);
	scenery[0].SetPos(0, 0);
	//change collision type (atm 0 for square, 5 for circle, 1-4 triangle which isnt coded, may change to only use circle and square)
	scenery[0].SetType(0);
}

//run the game itself
state rungame(bool keys[256], POINT mousedragpos, bool mousedrag, POINT mousepos, bool Lmousedown, bool Rmousedown)
{
	//do key actions
	keyboard(keys);
	//do mouse actions
	mouse(mousedragpos, mousedrag, mousepos, Lmousedown, Rmousedown);

	icon.SetPos(mappos.x + 200, mappos.y + 400);
	for (int x = 0; x < units; x++)
	{
		//new frame so no collisions yet
		blue[x].ResetCollision();
		green[x].ResetCollision();
	}

	for (int x = 0; x < units; x++)
	{
		for (int y = 0; y < units; y++)
		{
			if (!green[y].GetDead() && !blue[x].GetDead())
			{
				//check for collisions with enemy
				if (blue[x].CollisionCheck(green[y]))
				{
					//get damage will get a number for damage but still needs code to ensure it doesnt hit too fast
					green[y].LoseHealth(blue[x].GetDamage());
					blue[x].LoseHealth(green[y].GetDamage());
				}
			}

			//check for collisions with team, but not itself
			if (x != y && !blue[y].GetDead() && !blue[x].GetDead())	blue[x].CollisionCheck(blue[y]);
			if (x != y && !green[y].GetDead() && !green[x].GetDead()) green[x].CollisionCheck(green[y]);
		}
	}

	for (int x = 0; x < units; x++)
	{
		for (int y = 0; y < objects; y++)
		{
			blue[x].CollisionCheck(scenery[y]);
			green[x].CollisionCheck(scenery[y]);
		}
	}

	for (int x = 0; x < units; x++)
	{
		//if attack order was given before ensure you change move order to its position every time (code will need to be added with the damage so that if it dies attack turns off)
		if (blue[x].GetAttack()) blue[x].SetMoveOrder(green[blue[x].GetUnitNumb()].GetPos());
		//move unit
		blue[x].Move();

		if (green[x].GetAttack()) green[x].SetMoveOrder(blue[green[x].GetUnitNumb()].GetPos());
		green[x].Move();
	}	

	SceneWon = true;
	for (int x = 0; x < units; x++)
	{
		if (!green[x].GetDead()) SceneWon = false;
	}
	if(SceneWon) 
	{
		SetState(main_menu);
		return main_menu;
	}
	else return new_game;
}

//figure out corners for drag area (collision detection is simpler moving from top left to bot right, this changes the co-ords to be that way round)
void DragSpace(POINT mousedragpos, POINT mousepos)
{
	//figure out smallest x
	if (mousedragpos.x > mousepos.x)
	{
		DragSize.x = mousepos.x;
		DragSize.width = mousedragpos.x;
	}
	else
	{
		DragSize.x = mousedragpos.x;
		DragSize.width = mousepos.x;
	}
	//figure out smallest y
	if (mousedragpos.y > mousepos.y)
	{
		DragSize.y = mousepos.y;
		DragSize.height = mousedragpos.y;
	}
	else
	{
		DragSize.y = mousedragpos.y;
		DragSize.height = mousepos.y;
	}
}

//user interaction with mouse
void mouse(POINT mousedragpos, bool mousedrag, POINT mousepos, bool Lmousedown, bool Rmousedown)
{
	//left button
	if (Lmousedown)
	{
		for (int x = 0; x < units; x++)
		{
			//if draging mouse
			if (mousedrag)
			{
				//figure out drag area
				DragSpace(mousedragpos, mousepos);
				
				//select all units in area
				if((DragSize.width + mappos.x > blue[x].GetPos().x && DragSize.x + mappos.x < blue[x].GetPos().x + blue[x].GetSize().x)
					&& (DragSize.height + mappos.y > blue[x].GetPos().y && DragSize.y + mappos.y < blue[x].GetPos().y + blue[x].GetSize().y))
				{
					blue[x].Select(true);
				}
				else blue[x].Select(false);
			}
			//otherwise
			else
			{
				//select individual unit (not truely needed since single pixel should still colide with units but coded it anyway)
				if((mousepos.x + mappos.x > blue[x].GetPos().x && mousepos.x + mappos.x < blue[x].GetPos().x + blue[x].GetSize().x)
					&& (mousepos.y + mappos.y > blue[x].GetPos().y && mousepos.y + mappos.y < blue[x].GetPos().y + blue[x].GetSize().y))
				{
					blue[x].Select(true);
				}
				else blue[x].Select(false);
			}
		}

		if ((mousepos.x + mappos.x > icon.GetPos().x && mousepos.x + mappos.x < icon.GetPos().x + icon.GetSize().x)
			&& (mousepos.y + mappos.y > icon.GetPos().y && mousepos.y + mappos.y < icon.GetPos().y + icon.GetSize().y))
		{
			if(recentlyplaced)
			{
				if (spawnunit < 5)
				{
					blue[spawnunit].SetMoveOrder(0, blue[spawnunit].GetPos().y);
					spawnunit++;
				}
				recentlyplaced = false;
			}
		}
	}

	//if right button pressed
	if (Rmousedown)
	{
		for (int x = 0; x < units; x++)
		{
			//if unit selected
			if(blue[x].GetSelect())
			{
				//if clicking on enemy
				if ((mousepos.x + mappos.x > green[x].GetPos().x && mousepos.x + mappos.x < green[x].GetPos().x + green[x].GetSize().x)
					&& (mousepos.y + mappos.y > green[x].GetPos().y && mousepos.y + mappos.y < green[x].GetPos().y + green[x].GetSize().y))
				{
					//attack that unit
					blue[x].SetAttackOrder(0);
				}
				//otherwise
				else 
				{
					//give move order and stop attacking previous target if any
					blue[x].SetMoveOrder(mousepos.x + mappos.x, mousepos.y + mappos.y);
					blue[x].StopAttack();
				}
			}
		}
	}

	if (!Lmousedown) recentlyplaced = true;
}
//user interaction with keyboard
void keyboard(bool keys[256])
{
	//arrow keys pressed scroll map in that direction (will be removed if map doesnt scroll)
	if (keys[VK_LEFT]) movemap(-1, 0);
	if (keys[VK_UP]) movemap(0, -1);
	if (keys[VK_RIGHT]) movemap(1, 0);
	if (keys[VK_DOWN]) movemap(0, 1);
}
//scrolling map caping co-ords
void movemap(int x, int y)
{
	//x map caped at 0 and map size (will be changed from 100 * xtiles to fixed number if map scrolls but isnt tiled)
	if ((mappos.x + x > 0) && (mappos.x + x + WIDTH < mapsizex)) mappos.x += x;
	if ((mappos.y + y > 0) && (mappos.y + y + HEIGHT < mapsizey + 104)) mappos.y += y;
}
//draw game to back buffer
void drawgame(BUFFER &pBuffer, bool mousedrag)
{
	//as this is 2D things have to be drawn in the correct order or they wont be seen properly
	//3D coding includes a Z-buffer which figures out what goes where as long as nothing is at the same distance and on the same position (can explain more but its explained in 2nd year)

	//draw the map
	drawmap(pBuffer);

	for (int y = 0; y < objects; y++)
	{
		//draw objects
		scenery[y].Render(pBuffer, mappos);
	}

	for (int x = 0; x < units; x++)
	{
		//draw units
		blue[x].Render(pBuffer, mappos);
		green[x].Render(pBuffer, mappos);
	}

	DrawMiniMap(pBuffer, 3, 0, 374, 640, 106, 0, 0, 640, 100);
	DrawMiniMap(pBuffer, 0, 2, 376, 102, 102, 0, 0, 1, 1);// the map BG
	
	for (int i=0;i<units;i++)
	{
		if (!blue[i].GetDead())
		{
			Zombie_and_Human_Positions (pBuffer,blue[i], true);
		}
	}
	
	for (int i=0;i<units;i++)
	{
		if (!green[i].GetDead())
		{
			Zombie_and_Human_Positions (pBuffer,green[i], false);
		}
	}

	icon.Render(pBuffer, mappos);

	//draw mouse drag area
	if (mousedrag) drawselect(pBuffer);
}

void Zombie_and_Human_Positions (BUFFER &pBuffer,OBJECT & object, bool colour)
{
	if (object.GetPos().x > -1 && object.GetPos().y > -1)
	{
		if (colour) DrawMiniMap(pBuffer, 2, 2 + object.GetPos().x/10, 376 + object.GetPos().y/10, object.GetSize().x/10, object.GetSize().y/10, 0, 0, 2, 2);//friendly penguins
		else DrawMiniMap(pBuffer, 1, 2 + object.GetPos().x/10, 376 + object.GetPos().y/10, object.GetSize().x/10, object.GetSize().y/10, 0, 0, 2, 2);	
	}
}

//draw select area
void drawselect(BUFFER &pBuffer)
{
	//stretch single pixel to the drag size 1 line at a time
	StretchBitmap(pBuffer, 0, DragSize.x, DragSize.y, 1, DragSize.height - DragSize.y, 0, 0, 1, 1);
	StretchBitmap(pBuffer, 0, DragSize.x, DragSize.y, DragSize.width - DragSize.x, 1, 0, 0, 1, 1);
	StretchBitmap(pBuffer, 0, DragSize.width, DragSize.y, 1, DragSize.height - DragSize.y, 0, 0, 1, 1);
	StretchBitmap(pBuffer, 0, DragSize.x, DragSize.height, DragSize.width - DragSize.x, 1, 0, 0, 1, 1);
}
//draw map
void drawmap(BUFFER &pBuffer)
{
	int screenx, screeny;
	int sizex, sizey;
	int tilew, tileh;
	for (int x = 0; x < xtiles; x++)
	{
		for (int y = 0; y < ytiles; y++)
		{
			//figure out if tile is on screen
			if ((((x + 1) * TilesSize) - mappos.x > 0 
				&& (x * TilesSize) - mappos.x < WIDTH) &&
				(((y + 1) * TilesSize) - mappos.y > 0 
				&& (y * TilesSize) - mappos.y < HEIGHT))
			{
				//figure how much of the tile is on screen
				screenx = (x * TilesSize) - mappos.x;
				screeny = (y * TilesSize) - mappos.y;
				if (screenx < 0) 
				{
					//if tile starts off screen screen x will currently be a negative number
					//this changes it so that the off screen part isnt drawn (more efficient because every pixel off the screen would need to be drawn otherwise)
					sizex = TilesSize + screenx;
					screenx = 0;
					tilew = TilesSize - sizex;
				}
				//if tile goes passed the screen size change it to stop drawing when it hits the edge
				else if (screenx + TilesSize > WIDTH) 
				{
					sizex = WIDTH - screenx;
					tilew = 0;
				}
				//if tile is fully on screen draw it fully
				else
				{
					sizex = TilesSize;
					tilew = 0;
				}

				if (screeny < 0) 
				{
					sizey = TilesSize + screeny;
					screeny = 0;
					tileh = TilesSize - sizey;
				}
				else if (screeny + TilesSize > HEIGHT) 
				{
					sizey = HEIGHT - screeny;
					tileh = 0;
				}
				else 
				{
					sizey = TilesSize;
					tileh = 0;
				}
				drawtile(pBuffer, maptiles[x][y], screenx, screeny, sizex, sizey, tilew, tileh);
			}
		}
	}
}
//draw a single tile
void drawtile(BUFFER &pBuffer, int tilenum, int x, int y, int w, int h, int tw, int th)
{
	//works fine with these tiles but any tiles that have actual detail would mean this code needed to change slightly
	PortionOfBitmap(pBuffer, tilenum, x, y, w, h, tw, th);
}