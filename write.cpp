#include"whole.h"
#include<graphics.h>

void write(int*way)
{
		switch (*way)
	{
		case 1:{
			getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str1on.jpg");
            putimage(15,115,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str2.jpg");
            putimage(15,185,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str3.jpg");
            putimage(15,255,img); 
			break;
		}
		case 2:{
			getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str1.jpg");
            putimage(15,115,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str2on.jpg");
            putimage(15,185,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str3.jpg");
            putimage(15,255,img); 
			break;
		}
		case 3:{
			getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str1.jpg");
            putimage(15,115,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str2.jpg");
            putimage(15,185,img); 
            getimage(img,"C:\\Users\\Ñî×Óº½\\Pictures\\str3on.jpg");
            putimage(15,255,img); 
			break;
		}
		default:break;
}}
