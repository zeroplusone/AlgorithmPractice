/******************
Judge   : UVA
Problem : 11085 - Back to the 8-Queens
Course  : Course7
discribe:  give you which row of ith col queen
			then calculate mun times move to acheive 8 queen
Input   : 
			1 2 3 4 5 6 7 8
			1 1 1 1 1 1 1 1
			
Output  : 	
			Case 1: 7
			Case 2: 7
Solve   :	backtracking
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int d;
int ans[8];
int q[8];
int chan;
bool usex[8];
bool slide1[15];// /
bool slide2[15];// \

void queen(int y,int fit)
{
	if(y==8)
	{
		int sum=0;
		for(int j=0;j<8;++j)
		{
			if(q[j]!=ans[j])
				sum++;
		}
		chan=sum<chan?sum:chan;	
		return;
	}
	if(y==fit)
	{
		ans[y]=q[fit];
		queen(y+1,fit);
	}
	else
	{
		for(int x=0;x<8;++x)
		{		
			if( !usex[x] && !slide1[x+y] && !slide2[7-y+x])
			{
				usex[x]=true;
				slide1[x+y]=true;
				slide2[7-y+x]=true;
				ans[y]=x;
				queen(y+1,fit);
				usex[x]=false;
				slide1[x+y]=false;
				slide2[7-y+x]=false;
			}
		}
	}
}

int main()
{
	int i,num=1;
	while(scanf("%d%d%d%d%d%d%d%d",&q[0],&q[1],&q[2],&q[3],&q[4],&q[5],&q[6],&q[7])!=EOF)
	{
		chan=7;
		for(i=0;i<8;++i)	q[i]--;
		for(i=0;i<8;++i)
		{
			memset(usex,false,sizeof(usex));
			memset(slide1,false,sizeof(slide1));
			memset(slide2,false,sizeof(slide2));
			usex[q[i]]=true;
			slide1[i+q[i]]=true;
			slide2[7-i+q[i]]=true;
			queen(0,i);
		}
		printf("Case %d: %d\n",num++,chan);
	}
	return 0;
}