#include<graphics.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>  
#include <winsock.h>
#include <winbase.h> 
#include"whole.h"
//#include"control.h"
char ch;  //�Ӽ����϶�ȡ�µ�ָ�� 
DWORD WINAPI getInput(LPVOID pPararneter); 
	int ASpeed,BSpeed,CSpeed,speed,speed1;
    int way,ways,Ways;//�ڼ��ֲ��� 
  int a=1;
int main(void)                               //  .c�ļ���.h �ļ������β�Ҫ����һ�� 
{
	char s[100],s1[100];
	int AWidth,BWidth,ALenth,BLenth,CWidth,CLenth; 
	int Astate,Bstate,Cstate;
	int As,As1,Bs,Bs1,Cs,Cs1; 
	As=As1,Bs=Bs1,Cs=Cs1;    //ͼ�λ�ʱ��ѡ���״̬ 
	int Interval=0;     //ʱ���� 
    char FirstStart;
    int timecontrol;
    char fuck[100];

	 char ch1=ch='q'; 
    int AStartPointX,BStartPointX,AStartPointY,BStartPointY,CStartPointX,CStartPointY;
//�����˶�״̬ 
    int Aflag=1,Bflag=1,Cflag=1; //�����˶����� 
    int x1,y1,x2,y2,x3,y3; 
    int go;
    
    int trade1,trade2;//�жϹ�����Ƿ�ռ�� trade=0ʱ����  1ʱ��һ����ռ��   2ʱ�ڶ���С��ռ�� 
    
    clock_t start, finish;
    double time=0,time1;
    start = clock();                //����дendtime ��ѭ���� 

    input(&ASpeed,&BSpeed,&CSpeed,&ALenth,&AWidth,&BLenth,&BWidth,&CLenth,&CWidth,&AStartPointX,&AStartPointY,&BStartPointX
	,&BStartPointY,&CStartPointX,&CStartPointY,&Interval,&Ways,&timecontrol,&way);//&FirstStart,&Interval,
	x1=AStartPointX;
	y1=AStartPointY;
	x2=BStartPointX;
	y2=BStartPointY;
	x3=CStartPointX;
	y3=CStartPointY;
	
	PIMAGE img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img12;

   initgraph(1200,800);     //��ege 
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
    getimage(img1, "C:\\Users\\���Ӻ�\\Pictures\\train4.png");
	getimage(img2, "C:\\Users\\���Ӻ�\\Pictures\\train2.png");
	getimage(img3, "C:\\Users\\���Ӻ�\\Pictures\\train3.png");
	getimage(img4, "C:\\Users\\���Ӻ�\\Pictures\\train1.png"); 
    getimage(img5, "C:\\Users\\���Ӻ�\\Pictures\\A.png");
	getimage(img6, "C:\\Users\\���Ӻ�\\Pictures\\B.png");
	getimage(img7, "C:\\Users\\���Ӻ�\\Pictures\\C.png");
	getimage(img8, "C:\\Users\\���Ӻ�\\Pictures\\stop.png"); 
	getimage(img9, "C:\\Users\\���Ӻ�\\Pictures\\str1.jpg");
	getimage(img10,"C:\\Users\\���Ӻ�\\Pictures\\str2.jpg");
	getimage(img11, "C:\\Users\\���Ӻ�\\Pictures\\str3.jpg"); 
	getimage(img12, "C:\\Users\\���Ӻ�\\Pictures\\background2.png");     
    
   /*�����߳�1���Ӽ��̽����ַ�д�뵽ȫ�ֱ���ch�� */ 
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
		finish = clock();             //����ʱ�� 
     	time = (double)(finish - start)/CLOCKS_PER_SEC;  //����ʱ�� 
     	// ouputfile(ch,&ch1);
        output(time,Aflag,Bflag,Cflag,x1,y1,x2,y2,x3,y3,Astate,Bstate,Cstate,trade1,trade2,way,ch,&ch1,ASpeed,BSpeed,CSpeed,&As1,As,&Bs1,Bs,&Cs1,Cs);
        printf("\n\n");
       if(ways==1)
	    {printf("\n�������");
	    	//	scanf("%c",&ch);
	          // 	printf("%c\n",ch);
	    }
	    else if(ways==2)
	    {
	    	printf("\n��Ҫѡ����һ�ֲ��ԣ� 1�ǿ����� 2 A��B��  3�˹�����"); 
	    //	scanf("%d",&way);
	    	
	    }
	    else if(ways==3)
	    {
	    	printf("\n��������Ҫ�ı���һ��С�𳵵��ٶȣ���1��A��2��B��3��C"); 
	    //	scanf("%d",&speed1);
	    	if(speed1==1)
	        {
	        	printf("\n������AС�𳵵��ٶ�");
	        //	scanf("%d",&ASpeed);
	        }
	         else if(speed1==2)
	        {
	        	printf("\n������BС�𳵵��ٶ�");
	        //	scanf("%d",&BSpeed);
	        }
	        else if(speed1==3)
	        {
	        	printf("\n������CС�𳵵��ٶ�");
	        	//scanf("%d",&CSpeed);
	        }
	    }
        
        
        //write(&way);
		Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18, &Astate,&Bstate,ASpeed,BSpeed,&trade1,way);//��һ�� 
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
	    
	    //��ť 
         outtextrect(1000,50,200,100,"������ֹͣ����\n �Ҽ��ָ�����");
		putimage(1000, 100, 75, 75, img5, 0, 0, 177, 178);
	    putimage(1009, 200, 85, 85, img6, 0, 0, 168, 178);
	    putimage(1000, 300, 75, 75, img7, 0, 0, 175, 188);
	    putimage(1000, 400, 75, 75, img8, 0, 0, 178, 178);
         outtextrect(750,150,200,100,"����л����ԣ�");			  
	    putimage(750, 200, 136, 64, img9, 0, 0, 136, 64);
	    putimage(750, 300, 136, 64, img10, 0, 0, 136, 64);
	    putimage(750, 400, 136, 64, img11, 0, 0, 136, 64); 
	    mouseControl(&As,&Bs,&Cs,&way);
		
		//�������	
         outtextrect(15,480,200,100,"ʱ�䣺");
        sprintf(s, "%.2lf", time);
        outtextxy(80, 480, s);
	//	outtextrect(15,380,&time);    
	    if(way==1) 
	     	outtextrect(15,500,200,100,"����1:�쳵����\n"); 
	    else if(way==2)
            outtextrect(15,500,200,100,"����2:�������\n");
		else if(way==3)
		    outtextrect(15,500,200,100,"����3:�˹�����\n");
		

		if(trade1==0)
	        outtextrect(15,580,200,100,"�������1����         ");
     	else if(trade1==1)
	        outtextrect(15,580,200,100,"�������1��A��ռ��    ");
    	else if(trade1==2)
	        outtextrect(15,580,200,100,"�������1��B��ռ��    ");

        if(trade2==0)
	        outtextrect(200,580,200,100,"�������2����     \n");
	    else if(trade2==1)
	        outtextrect(200,580,200,100,"�������2��B��ռ��\n");
    	else if(trade2==2)
	        outtextrect(200,580,200,100,"�������2��C��ռ��\n");
	    
	
	//A�������
	     outtextrect(15,520,200,100,"A��λ�ã� "); 
	    sprintf(s, "%d", x1);
        outtextxy(80, 520, s);
        sprintf(s, "%d", y1);
        outtextxy(110, 520, s);
       	if(Aflag==1&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A���ķ�������");
    	else if(Aflag==2&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A���ķ�������"); 
      	else if(Aflag==3&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A���ķ�������");
    	else if(Aflag==0&&Astate==1&&ch!='a')
	        outtextrect(140,520,200,100,"A���ķ�������");
		if(ch=='a'||As==0)
	        outtextrect(280,520,200,100,"A������������ͣ    ");                        //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
     	else if(Astate==1)
	        outtextrect(280,520,200,100,"A��������          ");
    	else 
	        outtextrect(280,520,200,100,"A���ȴ����������ͣ");
	        outtextrect(440,520,200,100,"A���ٶȣ�");
	    sprintf(s, "%d", ASpeed);
        outtextxy(500, 520, s);
        
        //B����� 
	     outtextrect(15,540,200,100,"B��λ�ã� "); 
	    sprintf(s, "%d", x2);
        outtextxy(80, 540, s);
        sprintf(s, "%d", y2);
        outtextxy(110, 540, s);
       	if(Bflag==1&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B���ķ�������");
    	else if(Bflag==2&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B���ķ�������"); 
      	else if(Bflag==3&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B���ķ�������");
    	else if(Bflag==0&&Bstate==1&&ch!='b')
	        outtextrect(140,540,200,100,"B���ķ�������");
		if(ch=='b'||Bs==0)
	        outtextrect(280,540,200,100,"B������������ͣ    ");                        //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
     	else if(Bstate==1)
	        outtextrect(280,540,200,100,"B��������          ");
    	else 
	        outtextrect(280,540,200,100,"B���ȴ����������ͣ");
	        outtextrect(440,540,200,100,"B���ٶȣ�");
	    sprintf(s, "%d", BSpeed);
        outtextxy(500, 540, s);
        
         //C����� 
	     outtextrect(15,560,200,100,"C��λ�ã� "); 
	    sprintf(s, "%d", x3);
        outtextxy(80, 560, s);
        sprintf(s, "%d", y3);
        outtextxy(110, 560, s);
       	if(Cflag==1&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C���ķ�������");
    	else if(Cflag==2&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C���ķ�������"); 
      	else if(Cflag==3&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C���ķ�������");
    	else if(Cflag==0&&Cstate==1&&ch!='c')
	        outtextrect(140,560,200,100,"C���ķ�������");
		if(ch=='c'||Cs==0)
	        outtextrect(280,560,200,100,"C������������ͣ    ");                        //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
     	else if(Cstate==1)
	        outtextrect(280,560,200,100,"C��������          ");
    	else 
	        outtextrect(280,560,200,100,"C���ȴ����������ͣ");
	        outtextrect(440,560,200,100,"C���ٶȣ�");
	    sprintf(s, "%d", CSpeed);
        outtextxy(500, 560, s); 
        
         outtextrect(15,620,200,100,"������״̬ �� ��������ײ������");
		
	    for(speed=ASpeed;speed>0;speed--)
		for(go=1;go<=ASpeed||go<=BSpeed||go<=CSpeed;go++)
		{
			if(go<=ASpeed)
			{   if(ch=='d')      //����d A�𳵻�������� 
		             Astate=1;
			    Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18,&Astate,&Bstate,ASpeed,BSpeed,&trade1,way);
	            if(ch=='a')	    //����a   A�𳵻�ͣ�� 
		             Astate=0;   //
                if(As==0)
                   Astate=0;
	            carControl((ALenth-1)*18,(AWidth-1)*18,Astate,&Aflag,&x1,&y1);
			}
			if(go<=BSpeed)		
			{
			    if(ch=='f')         //����f b�𳵻�������� 
		             Bstate=1;
		        Detetor(x1,y1,x2,y2,(AWidth-1)*18,(ALenth-1)*18,(BWidth-1)*18,(BLenth-1)*18, &Astate,&Bstate,ASpeed,BSpeed,&trade1,way);//��һ�� 
	            Detetor(x2,y2,x3,y3,(BWidth-1)*18,(BLenth-1)*18,(CWidth-1)*18,(CLenth-1)*18, &Bstate,&Cstate,BSpeed,CSpeed,&trade2,way);	
			    if(ch=='b')	   //����b   b�𳵻�ͣ�� 
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
			{   if(ch=='e')         //����e C�𳵻�������� 
		            Cstate=1;
	            Detetor(x2,y2,x3,y3,(BWidth-1)*18,(BLenth-1)*18,(CWidth-1)*18,(CLenth-1)*18, &Bstate,&Cstate,BSpeed,CSpeed,&trade2,way);	
			    if(ch=='c')	  //����c   c�𳵻�ͣ�� 
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
	    	  printf("�������");
	    		scanf("%c",&ch);
	          // 	printf("%c\n",ch);
	    }
	    else if(ways==2)
	    {
	    	printf("��Ҫѡ����һ�ֲ��ԣ� ��1�ǿ����� 2 A��B��  3�˹�����"); 
	    	scanf("%d",&way);
	    	
	    }
	    else if(ways==3)
	    {
	    	printf("��������Ҫ�ı���һ��С�𳵵��ٶȣ���1��A��2��B��3��C)"); 
	    	scanf("%d",&speed1);
	    	if(speed1==1)
	        {
	        	printf("������AС�𳵵��ٶ�");
	        	scanf("%d",&ASpeed);
	        }
	         else if(speed1==2)
	        {
	        	printf("������BС�𳵵��ٶ�");
	        	scanf("%d",&BSpeed);
	        }
	        else if(speed1==3)
	        {
	        	printf("������CС�𳵵��ٶ�");
	        	scanf("%d",&CSpeed);
	        }
	    }
	}
} 
