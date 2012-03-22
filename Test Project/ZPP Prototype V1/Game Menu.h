#ifndef _GAME_MENU_H				// If we haven't included this file							
#define _GAME_MENU_H

#include "main.h"

void initMenu();
void SetState(state State);
state RunMenu(POINT mousepos, bool Lmousedown, bool Rmousedown);
bool MouseMenu(INTERFACEOBJECT &object, POINT mousepos, bool Lmousedown, bool Rmousedown);
void drawMenu(BUFFER &pBuffer);
void drawMenu2(BUFFER &pBuffer);
void drawMenu3(BUFFER &pBuffer);
void drawMenu4(BUFFER &pBuffer);
void drawMenu5(BUFFER &pBuffer);
void drawMenu6(BUFFER &pBuffer);
void drawMenu7(BUFFER &pBuffer);
void drawMenu8(BUFFER &pBuffer);
void pause_options(state s);

#endif