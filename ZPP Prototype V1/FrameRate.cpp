#include "FrameRate.h"

bool AnimateNextFrame(int desiredFrameRate, long long int &lastTime)
{
	long long int elapsedTime = 0;

	//get current time in seconds
    long long int currentTime = GetTickCount(); 

	//get elapsed time
	elapsedTime = currentTime - lastTime;

	//check if time since last checked over
    if( elapsedTime > (1000 / desiredFrameRate) )
    {
		//reset last time
        lastTime = currentTime;	

		//return TRUE, animate next frame
        return true;
    }

	//don't animate yet
	return false;
}
/*
void CalculateFrameRate(HWND hWnd)
{
	static float fFPS      = 0.0f;
    static float fLastTime = 0.0f;
    static DWORD dwFrames  = 0;
	char strFrameRate[55] = {0};

    //keep track of time lapse and frame count
    float fTime = GetTickCount() * 0.001f; //convert time to seconds
    ++dwFrames;

    //if current time minus last recorded time great than 1 second, start over
    if( fTime - fLastTime > 1.0f)
    {
		//store current time to test again
        fLastTime = fTime;

		//store Frames Per Second in a buffer
		sprintf(strFrameRate, "Frames Per Second: %d", dwFrames);

		//display Frames Per Second on window title
		SetWindowText(hWnd, strFrameRate);

		//reset frames
		dwFrames  = 0;
    }
}
*/