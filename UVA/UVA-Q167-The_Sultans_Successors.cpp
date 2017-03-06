/******************
Judge   : UVA
Problem : UVA-Q167-The_Sultans_Successors.cpp
Course  : Course7
discribe:  give the value of every place , find the max sum of 8queen placing
Input   : 	1		//t(case)
			 1  2  3  4  5  6  7  8
			 9 10 11 12 13 14 15 16
			17 18 19 20 21 22 23 24
			25 26 27 28 29 30 31 32
			33 34 35 36 37 38 39 40
			41 42 43 44 45 46 47 48
			48 50 51 52 53 54 55 56
			57 58 59 60 61 62 63 64
			
Output  : 	260 (max sum)
Solve   :	backtracking
*******************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

#define QNUM 8

int ans;
int sum;
int val[QNUM][QNUM];
bool usex[8];
bool slide1[15];// /
bool slide2[15];// \


void queen(int y)
{
	//printf("#%d\n",y);
	if(y==8)
	{
		ans=sum>ans?sum:ans;
		return;
	}
	

	for(int x=0;x<8;++x)
	{		
		if( !usex[x] && !slide1[x+y] && !slide2[7-y+x])
		{
			//printf("t %d  %d\n",y,x);
			usex[x]=true;
			slide1[x+y]=true;
			slide2[7-y+x]=true;
			sum+=val[x][y];
			//ans[y]=x+1;
			queen(y+1);
			//printf("f %d  %d\n",y,x);
			usex[x]=false;
			slide1[x+y]=false;
			slide2[7-y+x]=false;
			sum-=val[x][y];
		}
	}
	
}

int main()
{
	int d;
	int i,j;
	scanf("%d",&d);
	while(d--)
	{	
		for(i=0;i<QNUM;++i)
			for(j=0;j<QNUM;++j)
				scanf("%d",&val[i][j]);
		sum=0;	ans=0;
		memset(usex,false,sizeof(usex));
		memset(slide1,false,sizeof(slide1));
		memset(slide2,false,sizeof(slide2));

		queen(0);
		printf("%5d\n",ans);
	}
	return 0;
}