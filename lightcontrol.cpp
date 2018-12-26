#include"whole.h"

extern void Detetor(int x1, int y1, int x2, int y2, int row1, int col1, int row2, int col2, int *astate, int *bstate, int v1, int v2,int *trade,int way)
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

		//	*trade = 2;                          //B车占用轨道

		}

		if (x2 == 0 && y2 >= 0 && y2 <= c)           //B车占用轨道*
		{
			if (x1 == row1 - 1 && y1 == c + 1)
				*astate = 0;
		}

		if (x1 == row1 - 1 && y1 == c + 1 && x2 == 1 && y2 == 0)      //A,B同时即将进站
		{
			if(way==1) 
            {
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
			}
			
			else if(way==2) 
			{
				*bstate = 0;
			}
			
			else if(way==3)
			{
				*astate = 0;
			 } 

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
			if(way==1) 
            {
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
			}
			
			else if(way==2) 
			{
				*bstate = 0;
			}
			
			else if(way==3)
			{
				*astate = 0;
			 } 

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
			if(way==1) 
            {
			if (v1 > v2)
				*bstate = 0;
			else
				*astate = 0;
			}
			
			else if(way==2) 
			{
				*bstate = 0;
			}
			
			else if(way==3)
			{
				*astate = 0;
			 } 

		}
		
	}

    if (x2==0 && y2 <= c&&y2>=0)
	    (*trade)=2;
else	if (x1==row1-1 && y1 <= c&&y1>=0)
	    (*trade) =1;	else
	    (*trade) =0;
}
