#include"whole.h"

extern   void carControl(int file,int row,int state,int *flag,int *i,int *j)       //file==len  row==wid
{
	if(state==1)
	{
	if(*flag==0)
	{
        if((*i)==0)
		    (*flag)++;   //up
	    else
		    {
			    (*i)--;}
    }
	
	if(*flag==1){
	    if((*j)==(file-1))
		    (*flag)++;   //right
	    else
		    {
			    (*j)++;
			}
		}
	if(*flag==2){
	    if((*i)==(row-1))
		    (*flag)++;   //down
	    else
		    {
		    	(*i)++;
			}
		}
	if(*flag==3){
	    if((*j)==0)
		   { 
		       (*flag)=0;
			    (*i)--;
		   }    //left
	    else
		    {
			    (*j)--;
			}
       }		
	}
  
}
