#include"whole.h"
#include<stdio.h>
/*[A Speed]	 //A运行速度
[B Speed]	 //B运行速度
[A width] 	//A运行轨道的宽度
[A hight]	 	//A运行轨道的高度
[B width] 	//B运行轨道的宽度
[B hight] 	//B运行轨道的高度
[C width] 	//C运行轨道的宽度
[C hight] 	//C运行轨道的高度
[FirstStart]   //如果是'A'，表示A启动；如果是'X'，表示同时启动
[Interval]		//启动间隔时间，单位秒
[A StartPoint]	 //A启动位置（例如将A轨道分为0-12点刻度，启动位置在0点）
[B StartPoint]	 //B启动位置（例如将B轨道分为0-12点刻度，启动位置在7点）*/

void input(int*ASpeed,int*BSpeed,int*CSpeed,int*ALenth,int*AWidth,int*BLenth,int*BWidth,int*CLenth,int*CWidth,
          int*AStartPointX,int*AStartPointY,int*BStartPointX,int*BStartPointY,int*CStartPointX,int*CStartPointY,int*Interval,int*ways,int*timecontrol
		  ,int*way)//char*FirstStart,,
{
	FILE *filePtr;
	printf("输入：（1.文本输入  2.键盘输入）") ;
	scanf("%d",ways);

	
	if(*ways==1)
    {
    		if((filePtr=fopen("C:\\Users\\杨子航\\Desktop\\42版本2.rar\\42_版本1.rar\\源代码\\inputfile.c","r"))==NULL)           //打开文件 
	             printf("Open the file error!");
	        else
			{
			 	//printf("策略：1 快慢车  2 A先B其次C后 3 人工控制");
	fscanf(filePtr,"%d",way);

	        	//	printf("请输入以下初始参数：\n");
//	printf("A运行速度:");
	fscanf(filePtr,"%d",ASpeed);
//	printf("B运行速度:");
	fscanf(filePtr,"%d",BSpeed);
//	printf("A运行轨道长度：");
    fscanf(filePtr,"%d",CSpeed);
	fscanf(filePtr,"%d",ALenth);
//	printf("A运行轨道宽度：");
	fscanf(filePtr,"%d",AWidth);
//	printf("B运行轨道长度：");
	fscanf(filePtr,"%d",BLenth);
//	printf("B运行轨道宽度：");
	fscanf(filePtr,"%d",BWidth);
//	printf("C运行轨道长度：");
	fscanf(filePtr,"%d",CLenth);
//	printf("C运行轨道宽度：");
	fscanf(filePtr,"%d",CWidth);

//	printf("A启动位置x坐标：");
	fscanf(filePtr,"%d",AStartPointX);
//	printf("A启动位置y坐标：");
	fscanf(filePtr,"%d",AStartPointY);
//	printf("B启动位置x坐标：");
	fscanf(filePtr,"%d",BStartPointX);
//	printf("B启动位置y坐标：");
	fscanf(filePtr,"%d",BStartPointY);
//	printf("C启动位置x坐标：");
	fscanf(filePtr,"%d",CStartPointX);
//	printf("C启动位置y坐标：");
	fscanf(filePtr,"%d",CStartPointY);
	
	
	fscanf(filePtr,"%d",timecontrol);
//	printf("启动方案：（如果是'A'，表示A启动；如果是'B'，表示B启动；如果是'X'，表示同时启动）");
//	fscanf(filePtr,"%c",FirstStart);
//	if(*timecontrol==2)
    
    	//printf("启动间隔时间:");
	    fscanf(filePtr,"%d",Interval);
   
	fclose(filePtr);
	        }
    }
 	 
    else
    {
    		printf("策略：1 快慢车  2 A先B其次C后 3 人工控制");
	scanf("%d",way);

	printf("请输入以下初始参数：\n");
	printf("温馨提示：速度最好在大于等于1小于5\n");
	printf("A运行速度:");
	scanf("%d",ASpeed);
	printf("B运行速度:");
	scanf("%d",BSpeed);
	printf("C运行速度:");
	scanf("%d",CSpeed);	
	printf("温馨提示：轨道长最好在大于等于5小于20  宽在大于3小于\n") ; 
	printf("A运行轨道长度：");
	scanf("%d",ALenth);
	printf("A运行轨道宽度：");
	scanf("%d",AWidth);
	printf("B运行轨道长度：");
	scanf("%d",BLenth);
	printf("B运行轨道宽度：");
	scanf("%d",BWidth);

	printf("C运行轨道长度：");
	scanf("%d",CLenth);
	printf("C运行轨道宽度：");
	scanf("%d",CWidth);
//	printf("启动方案：（如果是'A'，表示A启动；如果是'B'，表示B启动；如果是'X'，表示同时启动）");
//	scanf("%c",FirstStart);
/*	if(*FirstStart=='A')
    {
    	printf("启动间隔时间:");
	    scanf("%d",Interval);
    }*/
	printf("A启动位置x坐标：");
	scanf("%d",AStartPointX);
	printf("A启动位置y坐标：");
	scanf("%d",AStartPointY);
	printf("B启动位置x坐标：");
	scanf("%d",BStartPointX);
	printf("B启动位置y坐标：");
	scanf("%d",BStartPointY);
	printf("C启动位置x坐标：");
	scanf("%d",CStartPointX);
	printf("C启动位置y坐标：");
	scanf("%d",CStartPointY);
	printf("启动方案：（1 同时启动 2 A启动后C启动)");
    scanf("%d",timecontrol);

//	fscanf(filePtr,"%c",FirstStart);
	if(*timecontrol==2)
    {
    	printf("启动间隔时间:");
	    scanf("%d",Interval);
   }
	printf("方向？ 1顺时针 2逆时针");
	getchar();getchar(); 
    }
}
