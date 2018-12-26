
extern void output(double time,int Aflag,int Bflag,int Cflag,int x1,int y1,int x2,int y2,int x3,int y3,
                       int Astate,int Bstate,int Cstate,int trade1,int trade2,int way,char ch,char*ch1,int ASpeed,int BSpeed,int CSpeed
					   ,int*As1,int As,int*Bs1,int Bs,int*Cs1,int Cs);
					   
					    
extern void input(int*ASpeed,int*BSpeed,int*CSpeed,int*ALenth,int*AWidth,int*BLenth,int*BWidth,int*CLenth,int*CWidth,
          int*AStartPointX,int*AStartPointY,int*BStartPointX,int*BStartPointY,int*CStartPointX,int*CStartPointY,int*Interval,int*ways,int*timecontrol,int*way);
          
extern void Detetor(int x1, int y1, int x2, int y2, int row1, int col1, int row2, int col2, int *astate, int *bstate, int v1, int v2,int *trade,int way);
extern void carControl(int file,int row,int state,int *flag,int *i,int *j);

extern void Carrun(int *state, int wid, int len,int b);
extern void streetDraw(int wid,int len,int b);
//extern void (int * Astate,int * Bstate,int * Cstate); 
extern void write(int*way);
extern void mouseControl(int *A,int *B,int *C,int *way);
