/*
Sample Input
0 0 4 0 0 1 
7 5 1 0 0 0 
0 0 0 0 0 0 

Sample Output
2 
1 

せ计だ1*1 2*2 ...6*6籷计
絚6*6*6 璸衡惠璶碭絚

*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int pack[6];
int box,one;

int main()
{	
	while(scanf("%d %d %d %d %d %d",&pack[0],&pack[1],&pack[2],&pack[3],&pack[4],&pack[5])!=EOF)
	{
		if(pack[0]==0 &&pack[1]==0 &&pack[2]==0 &&pack[3]==0 &&pack[4]==0 &&pack[5]==0 )
			break;
		box=0;	one=0;
		box=pack[5]+pack[4]+pack[3];           //6 5 4
		one+=11*pack[4];						//5回干碭1
		box+=pack[2]%4==0?pack[2]/4:pack[2]/4+1;//3
																	//printf("3+4+5+6=%d\n",box);
		if(pack[3]*5>=pack[1])				//1 2 干4回
		{
			one+=(pack[3]*5-pack[1])*4;		
			pack[1]=0;
		}
		else		
			pack[1]-=pack[3]*5;
																	//printf("2=%d 1=%d\n",pack[1],one);
		if(pack[2]%4==1)               //1 2 干3回
		{
			if(5>=pack[1])
			{
				one+=7+(5-pack[1])*4;		
				pack[1]=0;
			}
			else
			{			
				pack[1]-=5;
				one+=7;
			}
		}
		else if(pack[2]%4==2)
		{
			if(3>=pack[1])
			{
				one+=6+(3-pack[1])*4;		
				pack[1]=0;
			}
			else
			{
				pack[1]-=3;
				one+=6;
			}	
		}
		else if(pack[2]%4==3)
		{
			if(1>=pack[1])
			{
				one+=7+(1-pack[1])*4;		
				pack[1]=0;
			}
			else
			{	
				pack[1]-=1;
				one+=7;
			}
		}
														//printf("2=%d 1=%d\n",pack[1],one);
		if(pack[1]>0)			//2ㄓ穝舶
		{
			box+=pack[1]%9==0?pack[1]/9:pack[1]/9+1;
			one+=pack[1]%9==0?0:(9-(pack[1]%9))*4;
		}
														//printf("2+3+4+5+6=%d\n",box);
		if(pack[0]>one)			//1ㄓ穝舶
		{
			pack[0]-=one;
			box+=pack[0]%36==0?pack[0]/36:pack[0]/36+1;
		}
																
		printf("%d\n",box);
		
	}
	return 0;
}
