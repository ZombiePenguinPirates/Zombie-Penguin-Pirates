#ifndef _UI_H				// If we haven't included this file							
#define _UI_H				// Set a flag saying we included it

#include "main.h"

enum state {main_menu, new_game, load_game, settings, tutorials, quit, quit_for_real, in_game_pause_quit, in_game_pause, GameOver};

class INTERFACEOBJECT
{
public:
	INTERFACEOBJECT();
	~INTERFACEOBJECT();

	void SetPos(int x, int y) {pos.x = x; pos.y = y;};
	void SetSize(int w, int h) {size.x = w; size.y = h;};
	void SetImageSize(int x, int y) {imagesize.x = x; imagesize.y = y;};
	void SetImageSize(POINT xy) {imagesize = xy;};
	void SetPic(int p) {pic = p;};
	void SetState(state s){menu_state = s;};
	void Render(BUFFER &pBuffer);

	POINT GetPos() {return pos;};
	POINT GetSize() {return size;};
	int GetPic() {return pic;};
	state Getstate() {return menu_state;};

protected:
	int pic;
	POINT pos;
	POINT size;
	POINT imagesize;
	state menu_state;
};

#endif