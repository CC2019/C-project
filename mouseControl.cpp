#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>    //��Ҫ�Ĳ��� Astate Bstate Cstate   ÿ����ť����75*75
#include"whole.h"                        //ͼƬ�� Aͣ��1000��100�� Bͣ ��1000��200��    Cͣ��1000��300��   ȫͣ��1000��400�� 
void mouseControl(int *A,int *B,int *C,int *way)
{
	mouse_msg msg = {0};
	{
		//��ȡ�����Ϣ�����������ȴ����ȴ�������ϢΪֹ
		//���Ƶأ��к�kbhit��������ĺ���MouseHit�����ڼ����û�������Ϣ
		while (mousemsg())
		{
			msg = getmouse();
		}

		//��ʽ�����Ϊ�ַ��������ں������
		//msg��flag������ο��ĵ�����mouse_msg_e, mouse_flag_e������

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
