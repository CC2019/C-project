#include<stdio.h>
#include<string.h>
#include<time.h>
#include"whole.h"
/*1����ǰʱ�䣬1��
2����ǰ���ԣ�1��
3��3�������з���1��
4��3��������״̬�����С�����������ͣ���ȴ����������ͣ����2��
5��3����λ�ã�2��
6�����������״̬�����С���X��ռ�ã���2�֣�
*/
void output(double time,int Aflag,int Bflag,int Cflag,int x1,int y1,int x2,int y2,int x3,int y3,
                       int Astate,int Bstate,int Cstate,int trade1,int trade2,int way,char ch,char*ch1,int ASpeed,int BSpeed,int CSpeed
					   ,int*As1,int As,int*Bs1,int Bs,int*Cs1,int Cs)//,char*ch1
{
	FILE*filePtr; 
	printf("ʱ�䣺%lf\n",time);
	
	if(way==1)
	    printf("����1,������\n");
	else if(way==2)
	    printf("����2����һ������\n"); 
	else if(way==3)
	    printf("����3���˹�����\n") ;
	
	//������� ����� 
	if(trade1==0)
	    printf("�������1����     ");
	else if(trade1==1)
	    printf("�������1��A��ռ��    ");
	else if(trade1==2)
	    printf("�������1��B��ռ��   ");

	if(trade2==0)
	    printf("�������2����\n");
	else if(trade2==1)
	    printf("�������2��B��ռ��\n");
	else if(trade2==2)
	    printf("�������2��C��ռ��\n");
	    
	
	//A������� 
	printf("A����λ�ã���%d��%d��",x1,y1);
	if(Aflag==1&&Astate==1&&ch!='a')
	    printf("A���ķ�������") ;
	else if(Aflag==2&&Astate==1&&ch!='a')
	    printf("A���ķ�������"); 
	else if(Aflag==3&&Astate==1&&ch!='a')
	    printf("A���ķ�������");
	else if(Aflag==0&&Astate==1&&ch!='a')
	    printf("A���ķ�������");
	if(ch=='a')
	    printf("  A������������ͣ\n");                         //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
	else if(Astate==1)
	    printf("  A��������\n");
	else 
	    printf("  A���ȴ����������ͣ\n");
	printf("    A�����ٶȣ�%d\n",ASpeed); 
		 
	//B������� 
	printf("B����λ�ã���%d��%d��",x2,y2);
	if(Bflag==1&&Bstate==1&&ch!='b')
	    printf("B���ķ�������") ;
	else if(Bflag==2&&Bstate==1&&ch!='b')
	    printf("B���ķ�������"); 
	else if(Bflag==3&&Bstate==1&&ch!='b')
	    printf("B���ķ�������");
	else if(Bflag==0&&Bstate==1&&ch!='b')
	    printf("B���ķ�������");
	if(ch=='b')
	    printf("   B������������ͣ\n");
	else if(Bstate==1)
	    printf("  B��������\n");
	else
	    printf(" B���ȴ����������ͣ\n");
	printf("    B�����ٶȣ�%d\n",BSpeed);    
	//c������� 
	printf("C����λ�ã���%d��%d��",x3,y3);
	if(Cflag==1&&Cstate==1&&ch!='c')
	    printf("C���ķ�������") ;
	else if(Cflag==2&&Cstate==1&&ch!='c')
	    printf("C���ķ�������"); 
	else if(Cflag==3&&Cstate==1&&ch!='c')
	    printf("C���ķ�������");
	else if(Cflag==0&&Cstate==1&&ch!='c')
	    printf("C���ķ�������");
	if(ch=='c')
	    printf("  C������������ͣ\n");                         //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
	else if(Astate==1)
	    printf("  C��������\n");
	else
	    printf("  C���ȴ����������ͣ\n");
	printf("    C�����ٶȣ�%d\n",CSpeed);	    
	    printf("����1�����ı�С�𳵵�״̬\n       ����a����A��ͣ������b����B��ͣ������c--c��ͣ\n");
		printf("       ����d--a�𳵼�������,����e--b�𳵼������У�����f--c�𳵼�������)\n") ;
		printf("����2�����ı����\n");
		printf("����3�����ı�С���ٶ�"); 
	    
	    
	    
if((filePtr=fopen("C:\\Users\\���Ӻ�\\Desktop\\42�汾2.rar\\42_�汾1.rar\\Դ����\\outputfile.c","a"))==NULL)           //���ļ� 
	             printf("Open the file error!");
	        else
			{    if(*ch1 !=ch)
	    {
	    	if(ch=='a')
			    fprintf(filePtr,"A��ͣ��\n");
			if(ch=='b')
			    fprintf(filePtr,"B��ͣ��\n");
            if(ch=='c')
			    fprintf(filePtr,"c��ͣ��\n");
			if(ch=='d')
			    fprintf(filePtr,"A�𳵼�������\n");
			if(ch=='e')
			    fprintf(filePtr,"B�𳵼�������\n");    
			if(ch=='f')
			    fprintf(filePtr,"C�𳵼�������\n");
	    }
	        *ch1 =ch;
           
           
            if(*As1!=As||*Bs1!=Bs||*Cs1!=Cs)
	    {
	    	if(As==0)
			    fprintf(filePtr,"A��ͣ��\n");
			if(Bs==0)
			    fprintf(filePtr,"B��ͣ��\n");
            if(Cs==0)
			    fprintf(filePtr,"c��ͣ��\n");
			if(As==1)
			    fprintf(filePtr,"A�𳵼�������\n");
			if(Bs==1)
			    fprintf(filePtr,"B�𳵼�������\n");    
			if(Cs==1)
			    fprintf(filePtr,"C�𳵼�������\n");
	    }
	        *As1 =As;
           *Bs1 =Bs;
           *Cs1 =Cs;
           
	        	fprintf(filePtr,"%lf\n",time);
	
	if(way==1)
	    fprintf(filePtr,"����1,������\n");
	else
	    fprintf(filePtr,"����2����һ������\n"); 
	
	//������� ����� 
	if(trade1==0)
	    fprintf(filePtr,"�������1����     ");
	else if(trade1==1)
	    fprintf(filePtr,"�������1��A��ռ��    ");
	else if(trade1==2)
	    fprintf(filePtr,"�������1��B��ռ��   ");

	if(trade2==0)
	    fprintf(filePtr,"�������2����\n");
	else if(trade2==1)
	    fprintf(filePtr,"�������2��B��ռ��\n");
	else if(trade2==2)
	    fprintf(filePtr,"�������2��C��ռ��\n");
	    
	
	//A������� 
	fprintf(filePtr,"A����λ�ã���%d��%d��",x1,y1);
	if(Aflag==1&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A���ķ�������") ;
	else if(Aflag==2&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A���ķ�������"); 
	else if(Aflag==3&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A���ķ�������");
	else if(Aflag==0&&Astate==1&&ch!='a')
	    fprintf(filePtr,"A���ķ�������");
	if(ch=='a')
	    fprintf(filePtr,"  A������������ͣ\n");                         //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
	else if(Astate==1)
	    fprintf(filePtr,"  A��������\n");
	else 
	    fprintf(filePtr,"  A���ȴ����������ͣ\n");
		 
	//B������� 
	fprintf(filePtr,"B����λ�ã���%d��%d��",x2,y2);
	if(Bflag==1&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B���ķ�������") ;
	else if(Bflag==2&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B���ķ�������"); 
	else if(Bflag==3&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B���ķ�������");
	else if(Bflag==0&&Bstate==1&&ch!='b')
	    fprintf(filePtr,"B���ķ�������");
	if(ch=='b')
	    fprintf(filePtr,"   B������������ͣ\n");
	else if(Bstate==1)
	    fprintf(filePtr,"  B��������\n");
	else
	    fprintf(filePtr," B���ȴ����������ͣ\n");
	    
	//c������� 
	fprintf(filePtr,"C����λ�ã���%d��%d��",x3,y3);
	if(Cflag==1&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C���ķ�������") ;
	else if(Cflag==2&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C���ķ�������"); 
	else if(Cflag==3&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C���ķ�������");
	else if(Cflag==0&&Cstate==1&&ch!='c')
	    fprintf(filePtr,"C���ķ�������");
	if(ch=='c')
	    fprintf(filePtr,"  C������������ͣ\n");                         //���������� Ҫ����һ�� �ж��Ƿ� ��Ϊ����ı��� 
	else if(Astate==1)
	    fprintf(filePtr,"  C��������\n");
	else
	    fprintf(filePtr,"  C���ȴ����������ͣ\n");
	    
	     

	        fclose(filePtr);
	        }
}
