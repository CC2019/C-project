#include<stdio.h>
#include<string.h>
#include<time.h>
#include"whole.h"
/*1）当前时间，1分
2）当前策略，1分
3）3辆火车运行方向，1分
4）3辆火车运行状态（运行、接受命令暂停、等待公共轨道暂停），2分
5）3辆火车位置，2分
6）公共轨道的状态（空闲、被X车占用）（2分）
*/
void output(double time,int Aflag,int Bflag,int Cflag,int x1,int y1,int x2,int y2,int x3,int y3,
                       int Astate,int Bstate,int Cstate,int trade1,int trade2,int way,char ch,char*ch1,int ASpeed,int BSpeed,int CSpeed
					   ,int*As1,int As,int*Bs1,int Bs,int*Cs1,int Cs)//,char*ch1
{
	FILE*filePtr; 
	printf("时间：%lf\n",time);
	
	if(way==1)
	    printf("策略1,快慢车\n");
	else if(way==2)
	    printf("策略2，第一辆优先\n"); 
	else if(way==3)
	    printf("策略3，人工策略\n") ;
	
	//公共轨道 的情况 
	if(trade1==0)
	    printf("公共轨道1空闲     ");
	else if(trade1==1)
	    printf("公共轨道1被A车占用    ");
	else if(trade1==2)
	    printf("公共轨道1被B车占用   ");

	if(trade2==0)
	    printf("公共轨道2空闲\n");
	else if(trade2==1)
	    printf("公共轨道2被B车占用\n");
	else if(trade2==2)
	    printf("公共轨道2被C车占用\n");
	    
	
	//A车的输出 
	printf("A车的位置：（%d，%d）",x1,y1);
	if(Aflag==1&&Astate==1&&ch!='a')
	    printf("A车的方向：向右") ;
	else if(Aflag==2&&Astate==1&&ch!='a')
	    printf("A车的方向：向下"); 
	else if(Aflag==3&&Astate==1&&ch!='a')
	    printf("A车的方向：向左");
	else if(Aflag==0&&Astate==1&&ch!='a')
	    printf("A车的方向：向上");
	if(ch=='a')
	    printf("  A车接受命令暂停\n");                         //这里有问题 要传入一个 判断是否 人为输入的变量 
	else if(Astate==1)
	    printf("  A车在运行\n");
	else 
	    printf("  A车等待公共轨道暂停\n");
	printf("    A车的速度：%d\n",ASpeed); 
		 
	//B车的输出 
	printf("B车的位置：（%d，%d）",x2,y2);
	if(Bflag==1&&Bstate==1&&ch!='b')
	    printf("B车的方向：向右") ;
	else if(Bflag==2&&Bstate==1&&ch!='b')
	    printf("B车的方向：向下"); 
	else if(Bflag==3&&Bstate==1&&ch!='b')
	    printf("B车的方向：向左");
	else if(Bflag==0&&Bstate==1&&ch!='b')
	    printf("B车的方向：向上");
	if(ch=='b')
	    printf("   B车接受命令暂停\n");
	else if(Bstate==1)
	    printf("  B车在运行\n");
	else
	    printf(" B车等待公共轨道暂停\n");
	printf("    B车的速度：%d\n",BSpeed);    
	//c车的输出 
	printf("C车的位置：（%d，%d）",x3,y3);
	if(Cflag==1&&Cstate==1&&ch!='c')
	    printf("C车的方向：向右") ;
	else if(Cflag==2&&Cstate==1&&ch!='c')
	    printf("C车的方向：向下"); 
	else if(Cflag==3&&Cstate==1&&ch!='c')
	    printf("C车的方向：向左");
	else if(Cflag==0&&Cstate==1&&ch!='c')
	    printf("C车的方向：向上");
	if(ch=='c')
	    printf("  C车接受命令暂停\n");                         //这里有问题 要传入一个 判断是否 人为输入的变量 
	else if(Astate==1)
	    printf("  C车在运行\n");
	else
	    printf("  C车等待公共轨道暂停\n");
	printf("    C车的速度：%d\n",CSpeed);	    
	    printf("输入1——改变小火车的状态\n       （输a——A火车停，输入b——B火车停，输入c--c火车停\n");
		printf("       输入d--a火车继续运行,输入e--b火车继续运行，输入f--c火车继续运行)\n") ;
		printf("输入2——改变策略\n");
		printf("输入3——改变小火车速度"); 
	    
	    
	    
if((filePtr=fopen("C:\\Users\\杨子航\\Desktop\\42版本2.rar\\42_版本1.rar\\源代码\\outputfile.c","a"))==NULL)           //打开文件 
	             printf("Open the file error!");
	        else
			{    if(*ch1 !=ch)
	    {
	    	if(ch=='a')
			    fprintf(filePtr,"A火车停下\n");
			if(ch=='b')
			    fprintf(filePtr,"B火车停下\n");
            if(ch=='c')
			    fprintf(filePtr,"c火车停下\n");
			if(ch=='d')
			    fprintf(filePtr,"A火车继续运行\n");
			if(ch=='e')
			    fprintf(filePtr,"B火车继续运行\n");    
			if(ch=='f')
			    fprintf(filePtr,"C火车继续运行\n");
	    }
	        *ch1 =ch;
           
           
            if(*As1!=As||*Bs1!=Bs||*Cs1!=Cs)
	    {
	    	if(As==0)
			    fprintf(filePtr,"A火车停下\n");
			if(Bs==0)
			    fprintf(filePtr,"B火车停下\n");
            if(Cs==0)
			    fprintf(filePtr,"c火车停下\n");
			if(As==1)
			    fprintf(filePtr,"A火车继续运行\n");
			if(Bs==1)
			    fprintf(filePtr,"B火车继续运行\n");    
			if(Cs==1)
			    fprintf(filePtr,"C火车继续运行\n");
	    }
	        *As1 =As;
           *Bs1 =Bs;
           *Cs1 =Cs;
           
	        	fprintf(filePtr,"%lf\n",time);
	
	if(way==1)
	    fprintf(filePtr,"策略1,快慢车\n");
	else
	    fprintf(filePtr,"策略2，第一辆优先\n"); 
	
	//公共轨道 的情况 
	if(trade1==0)
	    fprintf(filePtr,"公共轨道1空闲     ");
	else if(trade1==1)
	    fprintf(filePtr,"公共轨道1被A车占用    ");
	else if(trade1==2)
	    fprintf(filePtr,"公共轨道1被B车占用   ");

	if(trade2==0)
	    fprintf(filePtr,"公共轨道2空闲\n");
	else if(trade2==1)
	    fprintf(filePtr,"公共轨道2被B车占用\n");
	else if(trade2==2)
	    fprintf(filePtr,"公共轨道2被C车占用\n");
	    
	
	//A车的输出 
	fprintf(filePtr,"A车的位置：（%d，%d）",x1,y1);
	if(Aflag==1&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A车的方向：向右") ;
	else if(Aflag==2&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A车的方向：向下"); 
	else if(Aflag==3&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A车的方向：向左");
	else if(Aflag==0&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A车的方向：向上");
	if(ch=='a')
	    fprintf(filePtr,"  A车接受命令暂停\n");                         //这里有问题 要传入一个 判断是否 人为输入的变量 
	else if(Astate==1)
	    fprintf(filePtr,"  A车在运行\n");
	else 
	    fprintf(filePtr,"  A车等待公共轨道暂停\n");
		 
	//B车的输出 
	fprintf(filePtr,"B车的位置：（%d，%d）",x2,y2);
	if(Bflag==1&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B车的方向：向右") ;
	else if(Bflag==2&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B车的方向：向下"); 
	else if(Bflag==3&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B车的方向：向左");
	else if(Bflag==0&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B车的方向：向上");
	if(ch=='b')
	    fprintf(filePtr,"   B车接受命令暂停\n");
	else if(Bstate==1)
	    fprintf(filePtr,"  B车在运行\n");
	else
	    fprintf(filePtr," B车等待公共轨道暂停\n");
	    
	//c车的输出 
	fprintf(filePtr,"C车的位置：（%d，%d）",x3,y3);
	if(Cflag==1&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C车的方向：向右") ;
	else if(Cflag==2&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C车的方向：向下"); 
	else if(Cflag==3&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C车的方向：向左");
	else if(Cflag==0&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C车的方向：向上");
	if(ch=='c')
	    fprintf(filePtr,"  C车接受命令暂停\n");                         //这里有问题 要传入一个 判断是否 人为输入的变量 
	else if(Astate==1)
	    fprintf(filePtr,"  C车在运行\n");
	else
	    fprintf(filePtr,"  C车等待公共轨道暂停\n");
	    
	     

	        fclose(filePtr);
	        }
}
