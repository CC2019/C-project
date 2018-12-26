//需要轨道数 和每个轨道的长和宽       轨道用字符数组储存 
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void Detetor(int x1, int y1, int x2, int y2, int row1, int col1, int row2, int col2, int *astate, int *bstate, int v1, int v2,int *trade);
int carcontrol(int file,int row,int *rowptr,int *fileptr,int flag,int *i,int *j); //自动机 
struct train{
    int locationrow;
    int locationfile;
    int speed;
	int state; 
};
struct street{
	int row;
	int file;
};
int main(void){
	int trade=0,num=3,flag1=1,flag2=1,flag3=1,*row1ptr,*row2ptr,*row3ptr,*file1ptr,*file2ptr,*file3ptr,a=0,b=0,c=0,d=0,e=0,f=0,*a1,*b1,*c1,*d1,*e1,*f1;    // 与主函数耦合的部分，作为子函数时直接当参量用
	//scanf("%d",&num);   //可删除
        struct train train[3];
	    struct street trainstreet[3];
	row1ptr=&train[0].locationrow;
	row2ptr=&train[1].locationrow;
	row3ptr=&train[2].locationrow;
	file1ptr=&train[0].locationfile;
	file2ptr=&train[1].locationfile;
	file3ptr=&train[2].locationfile;
	a1=&a;
	b1=&b;
	c1=&c;
	d1=&d;
	e1=&e;
	f1=&f;
	train[0].speed=1;
	train[1].speed=2;
	train[2].speed=3;
	train[0].state=1;
	train[1].state=1;
	train[2].state=1;
	
	int i=0,j=0,i1,j1,k=1;          //i、j为画轨道的坐标，i1、j1为前进格数 
	FILE *ptr;              //所有数组填图零 
 	char street[15][50],common[15][50]; 
	for(i=0;i<15;i++)
	    for(j=0;j<50;j++)
		    {
			    street[i][j]='0';
			    common[i][j]='0';
			}
	i=0;
	j=0;
	for(k=0;k<3;k++)
	{
		printf("PlEASE	shuruchangkuan");
		scanf("%d %d",&trainstreet[k].file,&trainstreet[k].row);           //应从input文件中读取，整合时需要修改 
		street[i][j]='*';
		for(j1=1;j1<trainstreet[k].file;j1++)
		{
			j++;
			street[i][j]='*';
		}
		for(i1=1;i1<trainstreet[k].row;i1++)
		{
			i++;
			street[i][j]='*';
		}
		for(j1=1;j1<trainstreet[k].file;j1++)
        {
        	j--;
        	street[i][j]='*';
		}
		for(i1=2;i1<trainstreet[k].row;i1++)
		{
			i--;
			street[i][j]='*';
		}
		i=(i+trainstreet[k].row-2);
			}	    
	if((ptr=fopen("streetdraw.txt","w"))==NULL)             //将火车轨道写入文件 
	    printf("File could not be opened\n");
	else{
		for(i=0;i<15;i++){
		    for(j=0;j<50;j++){
		        fprintf(ptr,"%c",street[i][j]);
	        }
		fprintf(ptr,"\n");
	}
	train[0].locationfile=0;
	train[0].locationrow=0;
	train[1].locationfile=0;
	train[2].locationfile=0;
	train[1].locationrow=(trainstreet[0].row-1);
	train[2].locationrow=(trainstreet[0].row+trainstreet[1].row-2);
	
	    for(int time=0;1;time++)
		{
		//	Detetor(int x1, int y1, int x2, int y2, int row1, int col1, int row2, int col2, int *astate, int *bstate, int v1, int v2,int *trade)
		    Detetor(a,b,c,d,trainstreet[0].row,trainstreet[0].file,trainstreet[1].row,trainstreet[1].file,&train[0].state,&train[1].state,train[0].speed,train[1].speed,&trade);
		    Detetor(c,d,e,f,trainstreet[1].row,trainstreet[1].file,trainstreet[2].row,trainstreet[2].file,&train[1].state,&train[2].state,train[1].speed,train[2].speed,&trade);
			street[train[0].locationrow][train[0].locationfile]='O';
		    street[train[1].locationrow][train[1].locationfile]='@';
		    street[train[2].locationrow][train[2].locationfile]='B';
	        for(i=0;i<15;i++)
	        {
	            printf("\n");
	            for(j=0;j<50;j++)
		            printf("%c",street[i][j]);}
		            printf("%d %d %d %d %d %d",a,b,c,d,e,f); 
			
			street[train[0].locationrow][train[0].locationfile]='*';
		    street[train[1].locationrow][train[1].locationfile]='*';
		    street[train[2].locationrow][train[2].locationfile]='*';
			if(time%train[0].speed==0&&train[0].state==1)
				flag1=carcontrol(trainstreet[0].file,trainstreet[0].row,row1ptr,file1ptr,flag1,a1,b1);
			if(time%train[1].speed==0&&train[1].state==1)
			    flag2=carcontrol(trainstreet[1].file,trainstreet[1].row,row2ptr,file2ptr,flag2,c1,d1);
			if(time%train[2].speed==0&&train[2].state==1)
			    flag3=carcontrol(trainstreet[2].file,trainstreet[2].row,row3ptr,file3ptr,flag3,e1,f1);
	        Sleep(500);
	        system("cls"); 
        }
    }  
}
//需要外部定义一个flag来确定小火车的运动方向 



 int carcontrol(int file,int row,int *rowptr,int *fileptr,int flag,int *i,int *j)
{
	if(flag%4==0)
	{
        if((*i)==0)
		    flag++;   //up
	    else
		    {
			    (*rowptr)--;
			    (*i)--;}
    }
	
	if(flag%4==1){
	    if((*j)==(file-1))
		    flag++;   //right
	    else
		    {
			    (*fileptr)++;
			    (*j)++;
			}
		}
	if(flag%4==2){
	    if((*i)==(row-1))
		    flag++;   //down
	    else
		    {
		    	(*rowptr)++;
		    	(*i)++;
			}
		}
	if(flag%4==3){
	    if((*j)==0)
		    flag++;    //left
	    else
		    {
			    (*fileptr)--;
			    (*j)--;
			}
       }
    return flag;
}
void Detetor(int x1, int y1, int x2, int y2, int row1, int col1, int row2, int col2, int *astate, int *bstate, int v1, int v2,int *trade)
{
	int a, b,c;
	c = col1 > col2 ? col2 : col1;   //定义探测点位置
	c--; 

	*astate = 1;
	*bstate = 1;
	
	if (col1 > col2)
	{
		if (x1 == row1 - 1 && y1 == c)           //A车到达探测点
		{
			if (x2 == 1 && y2 == 0)              //B车即将进站
				*bstate = 0;

			*trade = 1;                        //A车占用轨道
		}

		if (x1 == row1 - 1 && y1 >= 0 && y1 <= c) //A车占用轨道*
		{
			if (x2 == 1 && y2 == 0)
				*bstate = 0;
		}


		if (x2 == 0 && y2 == 0)                 //B车到达探测点
		{
			if (x1 == row1 - 1 && y1 == c + 1)  //A车即将进站
				*astate = 0;

			*trade = 2;                          //B车占用轨道

		}

		if (x2 == 0 && y2 >= 0 && y2 <= c)           //B车占用轨道*
		{
			if (x1 == row1 - 1 && y1 == c + 1)
				*astate = 0;
		}

		if (x1 == row1 - 1 && y1 == c + 1 && x2 == 1 && y2 == 0)      //A,B同时即将进站
		{
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
		}
	}

	if (col1 < col2)
	{
		if (x1 == row1 - 1 && y1 == c)           //A车到达探测点
		{
			if (x2 == 1 && y2 == 0)              //B车即将进站
				*bstate = 0;

			*trade = 1;                        //A车占用轨道
		}

		if (x1 == row1 - 1 && y1 >= 0 && y1 <= c) //A车占用轨道*
		{
			if (x2 == 1 && y2 == 0)
				*bstate = 0;
		}


		if (x2 == 0 && y2 == 0)                 //B车到达探测点
		{
			if (x1 == row1 - 2 && y1 == c)  //A车即将进站
				*astate = 0;

			*trade = 2;                          //B车占用轨道

		}

		if (x2 == 0 && y2 >= 0 && y2 <= c)           //B车占用轨道*
		{
			if (x1 == row1 - 2 && y1 == c)
				*astate = 0;
		}

		if (x1 == row1 - 2 && y1 == c && x2 == 1 && y2 == 0)      //A,B同时即将进站
		{
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
		}
	}

	if (col1 == col2)
	{
		if (x1 == row1 - 1 && y1 == col1-1)           //A车到达探测点
		{
			if (x2 == 1 && y2 == 0)              //B车即将进站
				*bstate = 0;

			*trade = 1;                        //A车占用轨道
		}

		if (x1 == row1 - 1 && y1 >= 0 && y1 <= col1 - 1) //A车占用轨道*
		{
			if (x2 == 1 && y2 == 0)
				*bstate = 0;
		}


		if (x2 == 0 && y2 == 0)                 //B车到达探测点
		{
			if (x1 == row1 - 2 && y1 == col1 - 1)  //A车即将进站
				*astate = 0;

			*trade = 2;                          //B车占用轨道

		}

		if (x2 == 0 && y2 >= 0 && y2 <= col2 - 1)           //B车占用轨道*
		{
			if (x1 == row1 - 2 && y1 == col1 - 1)
				*astate = 0;
		}

		if (x1 == row1 - 2 && y1 == col1 - 1 && x2 == 1 && y2 == 0)      //A,B同时即将进站
		{
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
		}
	}
}
