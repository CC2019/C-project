#include"whole.h"
#include"graphics.h"

void streetDraw(int wid,int len,int b)
{
	PIMAGE img1, img2, img3;
	int i;
	img1 = newimage();
	img2 = newimage();
	img3 = newimage();

	
	int x, y;
	getimage(img1, "C:\\Users\\Ñî×Óº½\\Pictures\\street_raw.png");
	getimage(img2, "C:\\Users\\Ñî×Óº½\\Pictures\\street_col.png");
	//getimage(img3, "C:\\Users\\wyh\\Pictures\\background2.png");
	setfillcolor(BROWN);
	//putimage(0, 0, 1200, 800, img3, 0, 0, 2560, 1600);
	bar(0, b, 18, 18 + b);                                            //upstreet
	for (i = 0, x = 18; i < wid - 1; i++, x += 18)
		putimage(x, b, 18, 18, img1, 0, 0, 103, 131);
	bar((wid - 1) * 18, b, wid * 18, b + 18);                         //rightstreet
	for (i = 0, y = b + 18; i < len - 1; i++, y += 18)
		putimage((wid - 1) * 18, y, 18, 18, img2, 0, 0, 131, 103);
	bar((wid - 1) * 18, (len - 1) * 18 + b, wid * 18, len * 18 + b);      //downstreet
	for (i = 0, x = (wid - 2) * 18; i < wid - 1; i++, x -= 18)
		putimage(x, (len - 1) * 18 + b, 18, 18, img1, 0, 0, 103, 131);
	bar(0, (len - 1) * 18 + b, 18, len * 18 + b);                        //leftstreet
	for (i = 0, y = (len - 2) * 18 + b; i < len - 2; i++, y -= 18)
		putimage(0, y, 18, 18, img2, 0, 0, 131, 103);

	delimage(img1);
	delimage(img2);
	delimage(img3);
}
