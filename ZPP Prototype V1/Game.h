#ifndef _GAME_H				// If we haven't included this file							
#define _GAME_H				// Set a flag saying we included it

#include "main.h"
#include "UI.h"

#define units 5
#define objects 5

//prototypes
void loadtiles();
void initgame();
void initunits();
void initmap();
void initObjects();
state rungame(bool keys[256], POINT mousedragpos, bool mousedrag, POINT mousepos, bool Lmousedown, bool Rmousedown);
void keyboard(bool keys[256]);
void mouse(POINT mousedragpos, bool mousedrag, POINT mousepos, bool Lmousedown, bool Rmousedown);
void movemap(int x, int y);
void drawselect(BUFFER &pBuffer);
void drawgame(BUFFER &pBuffer, bool mousedrag);
void drawmap(BUFFER &pBuffer);
void drawtile(BUFFER &pBuffer, int tilenum, int x, int y, int w, int h, int tw, int th);
void Zombie_and_Human_Positions (BUFFER &pBuffer,OBJECT & object, bool colour);

#endif