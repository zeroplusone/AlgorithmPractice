/******************
Judge   : UVA
Problem : 750-8Queens_Chess_Problem.cpp
Course  : Course7
discribe:  give start position and show all possible of 8 queen problem
Input   : 	1		//t(case)

		==========
			1 1		/start position
			
Output  : 	SOLN       COLUMN
			 #      1 2 3 4 5 6 7 8

			 1      1 5 8 6 3 7 2 4      //y position
			 2      1 6 8 3 7 4 2 5
			 3      1 7 4 6 8 2 5 3
			 4      1 7 5 8 2 4 6 3
Solve   :	backtracking
*******************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int d,firstx,firsty;
int ans[8];
int num;
bool usex[8];
bool slide1[15];// /
bool slide2[15];// \

void queen(int y)
{
	//printf("#%d\n",y);
	if(y==8)
	{
		printf("%2d      %d",num,ans[0]);
		for(int j=1;j<8;++j)
			printf(" %d",ans[j]);
		printf("\n");
		num++;
		return;
	}
	if(y==firsty)
	{
		//printf("@\n");
		ans[y]=firstx+1;
		queen(y+1);
	}
	else
	{
		for(int x=0;x<8;++x)
		{		
			if( !usex[x] && !slide1[x+y] && !slide2[7-y+x])
			{
				printf("t %d  %d\n",y,x);
				usex[x]=true;
				slide1[x+y]=true;
				slide2[7-y+x]=true;
				ans[y]=x+1;
				queen(y+1);
				printf("f %d  %d\n",y,x);
				usex[x]=false;
				slide1[x+y]=false;
				slide2[7-y+x]=false;
			}
		}
	}
}

int main()
{
	
	scanf("%d",&d);
	
	for(int i=0;i<d;++i)
	{
		if(i)
			printf("\n");
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		
		num=1;
		scanf("%d %d",&firstx,&firsty);
		firstx--; firsty--;
		memset(usex,false,sizeof(usex));
		memset(slide1,false,sizeof(slide1));
		memset(slide2,false,sizeof(slide2));
		usex[firstx]=true;
		slide1[firstx+firsty]=true;
		slide2[7-firsty+firstx]=true;
		queen(0);
	}
	return 0;
}