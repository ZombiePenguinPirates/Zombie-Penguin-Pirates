#ifndef _OBJECT_H				// If we haven't included this file							
#define _OBJECT_H				// Set a flag saying we included it

#include "main.h"

class OBJECT
{
public:
	OBJECT();
	~OBJECT();

	void SetPos(int x, int y) {pos.x = x; pos.y = y;};
	void SetSize(int w, int h) {size.x = w; size.y = h;};
	void SetType(int t);
	void SetImageSize(int x, int y) {imagesize.x = x; imagesize.y = y;};
	void SetImageSize(POINT xy) {imagesize = xy;};
	void SetPic(int p) {pic = p;};
	void SetRadius(int r) {radius = r;};

	int GetPic() {return pic;};

	POINT GetPos() {return pos;};
	POINT GetSize() {return size;};
	int GetType() {return type;};
	int GetRadius() {return radius;};
	float GetDiag() {return diag;};

	virtual void Render(BUFFER &pBuffer, POINT mappos);

protected:
	int pic;
	int radius;		//only needed for circle collision detection
	POINT pos;
	POINT size;
	int type;		//affects collision detection, 0 = square, 1 = /|, 2 = |\, 3 = |/, 4 = \|, 5 = O
	float diag;		//used for type 1-4 to work out possition of diag
	POINT imagesize;
};

#endif