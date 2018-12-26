#include<graphics.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>  
#include <winsock.h>
#include <winbase.h> 
#include"whole.h"
//#include"control.h"
char ch;  //从键盘上读取新的指令 
DWORD WINAPI getInput(LPVOID pPararneter); 
	int ASpeed,BSpeed,CSpeed,speed,speed1;
    int way,ways,Ways;//第几种策略 
  int a=1;
int main(void)                               //  .c文件与.h 文件函数形参要保持一致 
{
	char s[100],s1[100];
	int AWidth,BWidth,ALenth,BLenth,CWidth,CLenth; 
	int Astate,Bstate,Cstate;
	int As,As1,Bs,Bs1,Cs,Cs1; 
	As=As1,Bs=Bs1,Cs=Cs1;    //图形化时火车选择的状态 
	int Interval=0;     //时间间隔 
    char FirstStart;
    int timecontrol;
    char fuck[100];

	 char ch1=ch='q'; 
    int AStartPointX,BStartPointX,AStartPointY,BStartPointY,CStartPointX,CStartPointY;
//车的运动状态 
    int Aflag=1,Bflag=1,Cflag=1; //车的运动方向 
    int x1,y1,x2,y2,x3,y3; 
    int go;
    
    int trade1,trade2;//判断轨道上是否被占用 trade=0时空闲  1时第一辆火车占用   2时第二辆小火车占用 
    
    clock_t start, finish;
    double time=0,time1;
    start = clock();                //别忘写endtime 在循环中 

    input(&ASpeed,&BSpeed,&CSpeed,&ALenth,&AWidth,&BLenth,&BWidth,&CLenth,&CWidth,&AStartPointX,&AStartPointY,&BStartPointX
	,&BStartPointY,&CStartPointX,&CStartPointY,&Interval,&Ways,&timecontrol,&way);//&FirstStart,&Interval,
	x1=AStartPointX;
	y1=AStartPointY;
	x2=BStartPointX;
	y2=BStartPointY;
	x3=CStartPointX;
	y3=CStartPointY;
	
	PIMAGE img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img12;

   initgraph(1200,800);     //打开ege 
   streetDraw(ALenth,AWidth,0);
   streetDraw(BLenth,BWidth,(AWidth-1)*18);    
    streetDraw(CLenth,CWidth,(AWidth+BWidth-2)*18);
    //Carrun(&a,ALenth,AWidth,0);
    //Carrun(&a,BLenth,BWidth,(AWidth-1)*18);
    //Carrun(&a,CLenth,CWidth,(AWidth+BWidth-2)*18);
    
    img1=newimage();
    img2=newimage();
    img3=newimage();
    img4=newimage(); 
    img5=newimage();
    img6=newimage();
    img7=newimage();
    img8=newimage();
    img9=newimage();
    img10=newimage();
    img11=newimage();
    img12=newimage();    
    getimage(img1, "C:\\Users\\杨子航\\Pictures\\train4.png");
	getimage(img2, "C:\\Users\\杨子航\\Pictures\\train2.png");
	getimage(img3, "C:\\Users\\杨子航\\Pictures\\train3.png");
	getimage(img4, "C:\\Users\\杨子航\\Pictures\\train1.png"); 
    getimage(img5, "C:\\Users\\杨子航\\Pictures\\A.png");
	getimage(img6, "C:\\Users\\杨子航\\Pictures\\B.png");
	getimage(img7, "C:\\Users\\杨子航\\Pictures\\C.png");
	getimage(img8, "C:\\Users\\杨子航\\Pictures\\stop.png"); 
	getimage(img9, "C:\\Users\\杨子航\\Pictures\\str1.jpg");
	getimage(img10,"C:\\Users\\杨子航\\Pictures\\str2.jpg");
	getimage(img11, "C:\\Users\\杨子航\\Pictures\\str3.jpg"); 
	getimage(img12, "C:\\Users\\杨子航\\Pictures\\background2.png");     
    
   /*创建线程1：从键盘接收字符写入到全局变量ch中 */ 
   DWORD ThreadID1 = 1;
   HANDLE hRead1 = CreateThread(NULL,0,getInput,NULL,0,&ThreadID1);
   time1=Interval;
;   

	//while(1)
	for(; is_run(); delay_fps(10))
	{
		cleardevice();
	    putimage(0, 0, 1200, 800, img12, 0, 0, 2560,1600);
	    streetDraw(ALenth,AWidth,0);
        streetDraw(BLenth,BWidth,(AWidth-1)*18);    
        streetDraw(CLenth,CWidth,(AWidth+BWidth-2)*18);
		finish = clock();             //结束时间 
     	time = (double)(finish - start)/CLOCKS_PER_SEC;  //计算时间 
     	// ouputfile(ch,&ch1);
        output(time,Aflag,Bflag,Cflag,x1,y1,x2,y2,x3,y3,Astate,Bstate,Cstate,trade1,trade2,way,ch,&ch1,ASpeed,BSpeed,CSpeed,&As1,As,&Bs1,Bs,&Cs1,Cs);
        printf("\n\n");
       if(ways==1)
	    {printf("\n输入命令：");
	    	//	scanf("%c",&ch);
	          // 	printf("%c\n",ch);
	    }
	    else if(ways==2)
	    {
	    	printf("\n你要选择哪一种策略？ 1是快慢车 2 A先B后  3人工策略"); 
	    //	scanf("%d",&way);
	    	
	    }
	    else if(ways==3)
	    {
	    	printf("\n请输入你要改变哪一个小火车的速度：（1是A，2是B，3是C"); 
	    //	scanf("%d",&speed1);
	    	if(speed1==1)
	        {
	        	printf("\n请输入A小火车的速度");
	        //	scanf("%d",&ASpeed);
	        }
	         else if(speed1==2)
	        {
	        	printf("\n请输入B小火车的速度");
	        //	scanf("%d",&BSpeed);
	        }
	        else if(speed1==3)
	        {
	        	printf("\n请输入C小火车的速度");
	        	//scanf("%d",&CSpeed);
	        }
	    }
        
        
        //write(&way);
		Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18, &Astate,&Bstate,ASpeed,BSpeed,&trade1,way);//第一个 
	    Detetor(x2,y2,x3,y3,(BWidth-1)*18,(BLenth-1)*18,(CWidth-1)*18,(CLenth-1)*18, &Bstate,&Cstate,BSpeed,CSpeed,&trade2,way);
	    
        if(Aflag==1)
	       	putimage(y1, x1, 18, 18, img1, 0, 0, 433, 234);
		else if(Aflag==2)
		    putimage(y1, x1, 18, 18, img2, 0, 0, 234,433);
		else if(Aflag==3)
		    putimage(y1, x1, 18, 18, img3, 0, 0, 433, 234);
		else if(Aflag==0)
		    putimage(y1, x1, 18, 18, img4, 0, 0, 234, 433);
		
       if(Bflag==1)
	       	putimage(y2, x2+(AWidth-1)*18, 18, 18, img1, 0, 0, 433, 234);
		else if(Bflag==2)
		    putimage(y2, x2+(AWidth-1)*18, 18, 18, img2, 0, 0,234 , 433);
		else if(Bflag==3)
		    putimage(y2, x2+(AWidth-1)*18, 18, 18, img3, 0, 0, 433, 234);
		else if(Bflag==0)
		    putimage(y2, x2+(AWidth-1)*18, 18, 18, img4, 0, 0, 234, 433);

        if(Cflag==1)
	       	putimage(y3, x3+(AWidth+BWidth-2)*18, 18, 18, img1, 0, 0, 433, 234);
		else if(Cflag==2)
		    putimage(y3, x3+(AWidth+BWidth-2)*18, 18, 18, img2, 0, 0, 234, 433);
		else if(Cflag==3)
		    putimage(y3, x3+(AWidth+BWidth-2)*18, 18, 18, img3, 0, 0, 433, 234);
		else if(Cflag==0)
	        putimage(y3, x3+(AWidth+BWidth-2)*18, 18, 18, img4, 0, 0, 234, 433);
	    
	    //按钮 
         outtextrect(1000,50,200,100,"左键点击停止运行\n 右键恢复运行");
		putimage(1000, 100, 75, 75, img5, 0, 0, 177, 178);
	    putimage(1009, 200, 85, 85, img6, 0, 0, 168, 178);
	    putimage(1000, 300, 75, 75, img7, 0, 0, 175, 188);
	    putimage(1000, 400, 75, 75, img8, 0, 0, 178, 178);
         outtextrect(750,150,200,100,"点击切换策略：");			  
	    putimage(750, 200, 136, 64, img9, 0, 0, 136, 64);
	    putimage(750, 300, 136, 64, img10, 0, 0, 136, 64);
	    putimage(750, 400, 136, 64, img11, 0, 0, 136, 64); 
	    mouseControl(&As,&Bs,&Cs,&way);
		
		//界面输出	
         outtextrect(15,480,200,100,"时间：");
        sprintf(s, "%.2lf", time);
        outtextxy(80, 480, s);
	//	outtextrect(15,380,&time);    
	    if(way==1) 
	     	outtextrect(15,500,200,100,"策略1:快车优先\n"); 
	    else if(way==2)
            outtextrect(15,500,200,100,"策略2:交替策略\n");
		else if(way==3)
		    outtextrect(15,500,200,100,"策略3:人工控制\n");
		

		if(trade1==0)
	        outtextrect(15,580,200,100,"公共轨道1空闲         ");
     	else if(trade1==1)
	        outtextrect(15,580,200,100,"公共轨道1被A车占用    ");
    	else if(trade1==2)
	        outtextrect(15,580,200,100,"公共轨道1被B车占用    ");

        if(trade2==0)
	        outtextrect(200,580,200,100,"公共轨道2空闲     \n");
	    else if(trade2==1)
	        outtextrect(200,580,200,100,"公共轨道2被B车占用\n");
    	else if(trade2==2)
	        outtextrect(200,580,200,100,"公共轨道2被C车占用\n");
	    
	
	//A车的输出
	     outtextrect(15,520,200,100,"A车位置： "); 
	    sprintf(s, "%d", x1);
        outtextxy(80, 520, s);
        sprintf(s, "%d", y1);
        outtextxy(110, 520, s);
       	if(Aflag==1&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A车的方向：向右");
    	else if(Aflag==2&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A车的方向：向下"); 
      	else if(Aflag==3&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A车的方向：向左");
    	else if(Aflag==0&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A车的方向：向上");
		if(ch=='a'||As==0)
	        outtextrect(280,520,200,100,"A车接受命令暂停    ");                        //这里有问题 要传入一个 判断是否 人为输入的变量 
     	else if(Astate==1)
	        outtextrect(280,520,200,100,"A车在运行          ");
    	else 
	        outtextrect(280,520,200,100,"A车等待公共轨道暂停");
	        outtextrect(440,520,200,100,"A车速度：");
	    sprintf(s, "%d", ASpeed);
        outtextxy(500, 520, s);
        
        //B车输出 
	     outtextrect(15,540,200,100,"B车位置： "); 
	    sprintf(s, "%d", x2);
        outtextxy(80, 540, s);
        sprintf(s, "%d", y2);
        outtextxy(110, 540, s);
       	if(Bflag==1&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B车的方向：向右");
    	else if(Bflag==2&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B车的方向：向下"); 
      	else if(Bflag==3&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B车的方向：向左");
    	else if(Bflag==0&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B车的方向：向上");
		if(ch=='b'||Bs==0)
	        outtextrect(280,540,200,100,"B车接受命令暂停    ");                        //这里有问题 要传入一个 判断是否 人为输入的变量 
     	else if(Bstate==1)
	        outtextrect(280,540,200,100,"B车在运行          ");
    	else 
	        outtextrect(280,540,200,100,"B车等待公共轨道暂停");
	        outtextrect(440,540,200,100,"B车速度：");
	    sprintf(s, "%d", BSpeed);
        outtextxy(500, 540, s);
        
         //C车输出 
	     outtextrect(15,560,200,100,"C车位置： "); 
	    sprintf(s, "%d", x3);
        outtextxy(80, 560, s);
        sprintf(s, "%d", y3);
        outtextxy(110, 560, s);
       	if(Cflag==1&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C车的方向：向右");
    	else if(Cflag==2&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C车的方向：向下"); 
      	else if(Cflag==3&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C车的方向：向左");
    	else if(Cflag==0&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C车的方向：向上");
		if(ch=='c'||Cs==0)
	        outtextrect(280,560,200,100,"C车接受命令暂停    ");                        //这里有问题 要传入一个 判断是否 人为输入的变量 
     	else if(Cstate==1)
	        outtextrect(280,560,200,100,"C车在运行          ");
    	else 
	        outtextrect(280,560,200,100,"C车等待公共轨道暂停");
	        outtextrect(440,560,200,100,"C车速度：");
	    sprintf(s, "%d", CSpeed);
        outtextxy(500, 560, s); 
        
         outtextrect(15,620,200,100,"火车运行状态 ： 正常（无撞车现象）");
		
	    for(speed=ASpeed;speed>0;speed--)
		for(go=1;go<=ASpeed||go<=BSpeed||go<=CSpeed;go++)
		{
			if(go<=ASpeed)
			{   if(ch=='d')      //输入d A火车会继续运行 
		             Astate=1;
			    Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18,&Astate,&Bstate,ASpeed,BSpeed,&trade1,way);
	            if(ch=='a')	    //输入a   A火车会停车 
		             Astate=0;   //
                if(As==0)
                   Astate=0;
	            carControl((ALenth-1)*18,(AWidth-1)*18,Astate,&Aflag,&x1,&y1);
			}
			if(go<=BSpeed)		
			{
			    if(ch=='f')         //输入f b火车会继续运行 
		             Bstate=1;
		        Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18, &Astate,&Bstate,ASpeed,BSpeed,&trade1,way);//第一个 
	            Detetor(x2,y2,x3,y3,(BWidth-1)*18,(BLenth-1)*18,(CWidth-1)*18,(CLenth-1)*18, &Bstate,&Cstate,BSpeed,CSpeed,&trade2,way);	
			    if(ch=='b')	   //输入b   b火车会停车 
		             Bstate=0;	
			    if(Interval>0&& time<=Interval)
				 {
				  Bstate=0;
				 } 
                if(Bs==0)
                   Bstate=0;				  
		        carControl((BLenth-1)*18,(BWidth-1)*18,Bstate,&Bflag,&x2,&y2);
			}
			if(go<=CSpeed)
			{   if(ch=='e')         //输入e C火车会继续运行 
		            Cstate=1;
	            Detetor(x2,y2,x3,y3,(BWidth-1)*18,(BLenth-1)*18,(CWidth-1)*18,(CLenth-1)*18, &Bstate,&Cstate,BSpeed,CSpeed,&trade2,way);	
			    if(ch=='c')	  //输入c   c火车会停车 
		            Cstate=0;	
				if(Interval>0&&time<=2*Interval)
				  {Cstate=0;
				  }
                if(Cs==0)
                   Cstate=0; 			
		        carControl((CLenth-1)*18,(CWidth-1)*18,Cstate,&Cflag,&x3,&y3);
			}
		}
	//	api_sleep(100);
		system("cls");
	}   
    return 0; 
} 

DWORD WINAPI getInput(LPVOID pPararneter)
{
	while(1)
	{
		getchar();
		scanf("%d",&ways);
		if(ways==1)
	    {
	    	  printf("输入命令：");
	    		scanf("%c",&ch);
	          // 	printf("%c\n",ch);
	    }
	    else if(ways==2)
	    {
	    	printf("你要选择哪一种策略？ （1是快慢车 2 A先B后  3人工策略"); 
	    	scanf("%d",&way);
	    	
	    }
	    else if(ways==3)
	    {
	    	printf("请输入你要改变哪一个小火车的速度：（1是A，2是B，3是C)"); 
	    	scanf("%d",&speed1);
	    	if(speed1==1)
	        {
	        	printf("请输入A小火车的速度");
	        	scanf("%d",&ASpeed);
	        }
	         else if(speed1==2)
	        {
	        	printf("请输入B小火车的速度");
	        	scanf("%d",&BSpeed);
	        }
	        else if(speed1==3)
	        {
	        	printf("请输入C小火车的速度");
	        	scanf("%d",&CSpeed);
	        }
	    }
	}
} 
