#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int K[2],Q[2],R[2][2],B[2][2],N[2][2],P[2][8];

void reset()
{
	for(int i=0;i<2;++i)
	{
		K[i]=Q[i]=0;
		for(int j=0;j<2;++j)
			R[i][j]=B[i][j]=N[i][j]=0;
		for(int k=0;k<8;++k)
			P[i][k]=0;
	}
}

void print(int c)
{
	int flag=0;
	if(K[c]!=0){	printf("K%c%d",K[c]/10+'a',K[c]%10);	flag=1;}
	if(Q[c]!=0){	if(flag)printf(",");	else flag=1;	printf("Q%c%d",Q[c]/10+'a',Q[c]%10);}
	for(int i=0;i<2;++i)
	{
		if(R[c][i]!=0)
		{		if(flag)printf(",");	
				else flag=1;	
				printf("R%c%d",R[c][i]/10+'a',R[c][i]%10);
		}
		else
			continue;
	}
	for(int i=0;i<2;++i)
	{
		if(B[c][i]!=0)
		{		if(flag)printf(",");	
				else flag=1;	
				printf("B%c%d",B[c][i]/10+'a',B[c][i]%10);
		}
		else
			continue;
	}
	for(int i=0;i<2;++i)
	{
		if(N[c][i]!=0)
		{		if(flag)printf(",");	
				else flag=1;	
				printf("N%c%d",N[c][i]/10+'a',N[c][i]%10);
		}
		else
			continue;
	}
	for(int i=0;i<8;++i)
	{
		if(P[c][i]!=0)
		{		if(flag)printf(",");	
				else flag=1;	
				printf("%c%d",P[c][i]/10+'a',P[c][i]%10);
		}
		else
			continue;
	}	
	printf("\n");
}

bool white(int a,int b)
{
	return a%10==b%10?a/10<b/10:a%10<b%10;
}

bool black(int a,int b)
{
	return a%10==b%10?a/10<b/10:a%10>b%10;
}

int main()
{
	char chess[35];	
	reset();
	int now0=0,now1=0;
	for(int j=8;j>=1;--j)
	{
		gets(chess);  gets(chess); 
		for(int i=2,k=0;i<=30;i=i+4,++k)
		{			
			if(chess[i]>='B' && chess[i]<='R')
			{
				switch(chess[i])
				{
					case 'K':	K[0]=k*10+j; 
						break;
					case 'Q':	Q[0]=k*10+j;
						break;
					case 'R':	if(R[0][0]==0)	R[0][0]=k*10+j;
								else	    	R[0][1]=k*10+j;
						break;
					case 'B':	if(B[0][0]==0)	B[0][0]=k*10+j;
								else	    	B[0][1]=k*10+j;
						break;
					case 'N':	if(N[0][0]==0)	N[0][0]=k*10+j;
								else	    	N[0][1]=k*10+j;
						break;
					case 'P':	P[0][now0++]=k*10+j;
						break;
				}
			}
			else if(chess[i]>='b' && chess[i]<='r')
			{
				switch(chess[i])
				{
					case 'k':	K[1]=k*10+j;
						break;
					case 'q':	Q[1]=k*10+j;
						break;
					case 'r':	if(R[1][0]==0)	R[1][0]=k*10+j;
								else	    	R[1][1]=k*10+j;
								
						break;
					case 'b':	if(B[1][0]==0)	B[1][0]=k*10+j;
								else	    	B[1][1]=k*10+j;
						break;
					case 'n':	if(N[1][0]==0)	N[1][0]=k*10+j;
								else	    	N[1][1]=k*10+j;
						break;
					case 'p':	P[1][now1++]=k*10+j;
						break;
				}
			}
		}
		
	}
	gets(chess);
	sort(R[0],R[0]+2,white);	sort(B[0],B[0]+2,white);	sort(N[0],N[0]+2,white);	sort(P[0],P[0]+8,white);
	sort(R[1],R[1]+2,black);	sort(B[1],B[1]+2,black);	sort(N[1],N[1]+2,black);	sort(P[1],P[1]+8,black);
	printf("White: "); print(0);
	printf("Black: "); print(1);
	return 0;
}