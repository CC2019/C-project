#include"whole.h"
#include<stdio.h>
/*[A Speed]	 //A�����ٶ�
[B Speed]	 //B�����ٶ�
[A width] 	//A���й���Ŀ��
[A hight]	 	//A���й���ĸ߶�
[B width] 	//B���й���Ŀ��
[B hight] 	//B���й���ĸ߶�
[C width] 	//C���й���Ŀ��
[C hight] 	//C���й���ĸ߶�
[FirstStart]   //�����'A'����ʾA�����������'X'����ʾͬʱ����
[Interval]		//�������ʱ�䣬��λ��
[A StartPoint]	 //A����λ�ã����罫A�����Ϊ0-12��̶ȣ�����λ����0�㣩
[B StartPoint]	 //B����λ�ã����罫B�����Ϊ0-12��̶ȣ�����λ����7�㣩*/

void input(int*ASpeed,int*BSpeed,int*CSpeed,int*ALenth,int*AWidth,int*BLenth,int*BWidth,int*CLenth,int*CWidth,
          int*AStartPointX,int*AStartPointY,int*BStartPointX,int*BStartPointY,int*CStartPointX,int*CStartPointY,int*Interval,int*ways,int*timecontrol
		  ,int*way)//char*FirstStart,,
{
	FILE *filePtr;
	printf("���룺��1.�ı�����  2.�������룩") ;
	scanf("%d",ways);

	
	if(*ways==1)
    {
    		if((filePtr=fopen("C:\\Users\\���Ӻ�\\Desktop\\42�汾2.rar\\42_�汾1.rar\\Դ����\\inputfile.c","r"))==NULL)           //���ļ� 
	             printf("Open the file error!");
	        else
			{
			 	//printf("���ԣ�1 ������  2 A��B���C�� 3 �˹�����");
	fscanf(filePtr,"%d",way);

	        	//	printf("���������³�ʼ������\n");
//	printf("A�����ٶ�:");
	fscanf(filePtr,"%d",ASpeed);
//	printf("B�����ٶ�:");
	fscanf(filePtr,"%d",BSpeed);
//	printf("A���й�����ȣ�");
    fscanf(filePtr,"%d",CSpeed);
	fscanf(filePtr,"%d",ALenth);
//	printf("A���й����ȣ�");
	fscanf(filePtr,"%d",AWidth);
//	printf("B���й�����ȣ�");
	fscanf(filePtr,"%d",BLenth);
//	printf("B���й����ȣ�");
	fscanf(filePtr,"%d",BWidth);
//	printf("C���й�����ȣ�");
	fscanf(filePtr,"%d",CLenth);
//	printf("C���й����ȣ�");
	fscanf(filePtr,"%d",CWidth);

//	printf("A����λ��x���꣺");
	fscanf(filePtr,"%d",AStartPointX);
//	printf("A����λ��y���꣺");
	fscanf(filePtr,"%d",AStartPointY);
//	printf("B����λ��x���꣺");
	fscanf(filePtr,"%d",BStartPointX);
//	printf("B����λ��y���꣺");
	fscanf(filePtr,"%d",BStartPointY);
//	printf("C����λ��x���꣺");
	fscanf(filePtr,"%d",CStartPointX);
//	printf("C����λ��y���꣺");
	fscanf(filePtr,"%d",CStartPointY);
	
	
	fscanf(filePtr,"%d",timecontrol);
//	printf("�����������������'A'����ʾA�����������'B'����ʾB�����������'X'����ʾͬʱ������");
//	fscanf(filePtr,"%c",FirstStart);
//	if(*timecontrol==2)
    
    	//printf("�������ʱ��:");
	    fscanf(filePtr,"%d",Interval);
   
	fclose(filePtr);
	        }
    }
 	 
    else
    {
    		printf("���ԣ�1 ������  2 A��B���C�� 3 �˹�����");
	scanf("%d",way);

	printf("���������³�ʼ������\n");
	printf("��ܰ��ʾ���ٶ�����ڴ��ڵ���1С��5\n");
	printf("A�����ٶ�:");
	scanf("%d",ASpeed);
	printf("B�����ٶ�:");
	scanf("%d",BSpeed);
	printf("C�����ٶ�:");
	scanf("%d",CSpeed);	
	printf("��ܰ��ʾ�����������ڴ��ڵ���5С��20  ���ڴ���3С��\n") ; 
	printf("A���й�����ȣ�");
	scanf("%d",ALenth);
	printf("A���й����ȣ�");
	scanf("%d",AWidth);
	printf("B���й�����ȣ�");
	scanf("%d",BLenth);
	printf("B���й����ȣ�");
	scanf("%d",BWidth);

	printf("C���й�����ȣ�");
	scanf("%d",CLenth);
	printf("C���й����ȣ�");
	scanf("%d",CWidth);
//	printf("�����������������'A'����ʾA�����������'B'����ʾB�����������'X'����ʾͬʱ������");
//	scanf("%c",FirstStart);
/*	if(*FirstStart=='A')
    {
    	printf("�������ʱ��:");
	    scanf("%d",Interval);
    }*/
	printf("A����λ��x���꣺");
	scanf("%d",AStartPointX);
	printf("A����λ��y���꣺");
	scanf("%d",AStartPointY);
	printf("B����λ��x���꣺");
	scanf("%d",BStartPointX);
	printf("B����λ��y���꣺");
	scanf("%d",BStartPointY);
	printf("C����λ��x���꣺");
	scanf("%d",CStartPointX);
	printf("C����λ��y���꣺");
	scanf("%d",CStartPointY);
	printf("������������1 ͬʱ���� 2 A������C����)");
    scanf("%d",timecontrol);

//	fscanf(filePtr,"%c",FirstStart);
	if(*timecontrol==2)
    {
    	printf("�������ʱ��:");
	    scanf("%d",Interval);
   }
	printf("���� 1˳ʱ�� 2��ʱ��");
	getchar();getchar(); 
    }
}
