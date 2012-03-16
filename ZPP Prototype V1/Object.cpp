#include "main.h"

OBJECT::OBJECT()
{
	pic = 0;							//picture used
	pos.x = pos.y = 0;					//pos = 0, 0
	size.x = size.y = 0;				//size = 0, 0
	type = 5;							//collision type = circle
	diag = 0;							//diag = 0 (used for diaganal line collision detection
	imagesize.x = imagesize.y = 20;		//image size
	radius = 10;						//radius
}

OBJECT::~OBJECT()
{
}

void OBJECT::SetType(int t)
{
	type = t;												//collision type
	if(t > 0 && t < 5)	diag = (float)size.x / size.y;		//if diaganal find % of x compared to y
}

void OBJECT::Render(BUFFER &pBuffer, POINT mappos)
{
	if ((pos.x + size.x > mappos.x)							//if object on screen
		&& (pos.x < mappos.x + WIDTH)
		&& (pos.y + size.y > mappos.y)
		&& (pos.y < mappos.y + HEIGHT))
	{														//draw object
		if (size.x > WIDTH || size.y > HEIGHT)
		{
		}
		TransparentStretchBitmap(pBuffer, pic, pos.x - mappos.x, pos.y - mappos.y, size.x, size.y, 0, 0, imagesize.x, imagesize.y);
	}
}