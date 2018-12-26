#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>    //需要的参数 Astate Bstate Cstate   每个按钮都是75*75
#include"whole.h"                        //图片放 A停（1000，100） B停 （1000，200）    C停（1000，300）   全停（1000，400） 
void mouseControl(int *A,int *B,int *C,int *way)
{
	mouse_msg msg = {0};
	{
		//获取鼠标消息，这个函数会等待，等待到有消息为止
		//类似地，有和kbhit功能相近的函数MouseHit，用于检测有没有鼠标消息
		while (mousemsg())
		{
			msg = getmouse();
		}

		//格式化输出为字符串，用于后面输出
		//msg和flag常数请参考文档或者mouse_msg_e, mouse_flag_e的声明

		if(msg.x>1000&&msg.x<1075&&msg.y>100&&msg.y<175&&(int)msg.is_left()==1)
		    *A=0;
		if(msg.x>1000&&msg.x<1075&&msg.y>200&&msg.y<275&&(int)msg.is_left()==1)
		    *B=0;
		if(msg.x>1000&&msg.x<1075&&msg.y>300&&msg.y<375&&(int)msg.is_left()==1)
		    *C=0;				 
		if(msg.x>1000&&msg.x<1075&&msg.y>400&&msg.y<475&&(int)msg.is_left()==1)
		{
			*A=0;
			*B=0;
			*C=0;
					}	
		if(msg.x>1000&&msg.x<1075&&msg.y>100&&msg.y<175&&(int)msg.is_right()==1)
		    *A=1;
		if(msg.x>1000&&msg.x<1075&&msg.y>200&&msg.y<275&&(int)msg.is_right()==1)
		    *B=1;
		if(msg.x>1000&&msg.x<1075&&msg.y>300&&msg.y<375&&(int)msg.is_right()==1)
		    *C=1;				 
		if(msg.x>1000&&msg.x<1075&&msg.y>400&&msg.y<475&&(int)msg.is_right()==1)
		{
			*A=1;
			*B=1;
			*C=1;
					}				    
	}
	if(msg.x>750&&msg.x<886&&msg.y>200&&msg.y<264&&(int)msg.is_left()==1)
	    *way=1;
	if(msg.x>750&&msg.x<886&&msg.y>300&&msg.y<364&&(int)msg.is_left()==1)
	    *way=2;
	if(msg.x>750&&msg.x<886&&msg.y>400&&msg.y<464&&(int)msg.is_left()==1)
	    *way=3;

}
