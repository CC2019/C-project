#include "whole.h"
#include "graphics.h" 

void Carrun(int *state, int wid, int len,int b)         //b为轨道起始点的y坐标
{
	PIMAGE img1, img2, img3, img4, img5;

	int x = 0, y = b;

	img1 = newimage();
	img2 = newimage();
	img3 = newimage();
	img4 = newimage();
	img5 = newimage();

	getimage(img1, "C:\\Users\\杨子航\\Pictures\\train4.png");
	getimage(img2, "C:\\Users\\杨子航\\Pictures\\train2.png");
	getimage(img3, "C:\\Users\\杨子航\\Pictures\\train3.png");
	getimage(img4, "C:\\Users\\杨子航\\Pictures\\train1.png");



	for (; is_run(); delay_fps(300))
	{

		if (x != (wid - 1) * 18 && y == b)                //up
		{
			for (; is_run(), x<(wid - 1) * 18; delay_fps(300))
			{
				cleardevice();
				streetDraw(wid,len,b);

				putimage(x, y, 18, 18, img1, 0, 0, 433, 234);
				if (*state)
					x++;
			}
		}

		if (x == (wid - 1) * 18 && y != (len - 1) * 18 + b)             //right 
		{

			for (; is_run(), y<(len - 1) * 18 + b; delay_fps(300))
			{
				cleardevice();
				streetDraw(wid,len,b);

				putimage(x, y, 18, 18, img2, 0, 0, 234, 433);
				if (*state)
					y++;
			}

		}

		if (y == (len - 1) * 18 + b && x != 0)               //down 
		{
			for (; is_run(), x>0; delay_fps(300))
			{
				cleardevice();
				streetDraw(wid,len,b);

				putimage(x, y, 18, 18, img3, 0, 0, 433, 234);
				if (*state)
					x--;
			}
		}

		if (x == 0 && y != b)                //left 
		{
			for (; is_run(), y>b; delay_fps(300))
			{
				cleardevice();
				streetDraw(wid,len,b);

				putimage(x, y, 18, 18, img4, 0, 0, 234, 433);
				if (*state)
					y--;
			}

		}

	}
	delimage(img1);
	delimage(img2);
	delimage(img3);
	delimage(img4);
}
