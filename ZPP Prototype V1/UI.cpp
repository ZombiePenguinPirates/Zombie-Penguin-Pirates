#include "main.h"

INTERFACEOBJECT::INTERFACEOBJECT()
{
	pic = 0;							//picture used
	pos.x = pos.y = 0;					//pos = 0, 0
	size.x = size.y = 0;				//size = 0, 0
	imagesize.x = imagesize.y = 20;		//image size
}

INTERFACEOBJECT::~INTERFACEOBJECT()
{
}

void INTERFACEOBJECT::Render(BUFFER &pBuffer)
{
	//draw object
	DrawUI(pBuffer, pic, pos.x, pos.y, size.x, size.y, 0, 0, imagesize.x, imagesize.y);
}