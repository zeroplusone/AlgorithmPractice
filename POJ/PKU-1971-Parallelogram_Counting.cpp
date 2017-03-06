/******************
Judge   : PKU
Problem : 1971-Parallelogram_Counting.cpp
Course  : Course1
discribe: find out how many Parallelogram are there in these point
Input   : t
          (n
		   x0 y0
		   x1 y1
		   .
		   .
		   xn-1 yn-1
		   )x t
		  
Output  : num		  
Solve   : greedy+sort
          first send bigest d/t
*******************/
/*
Sample Input
2        //case
6        //幾個座標
0 0
2 0
4 0
1 1
3 1
5 1
7         //case2
-2 -1
8 9
5 7
1 1
4 8
2 0
9 8

Sample Output 
5       //有幾個平行四邊形
6

//sol:算出中點排序
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1010
#define pairMAX 5000000
int x[MAX];
int y[MAX];
typedef struct ppair ppair;   
struct ppair
{
	int mx;
	int my;
	bool operator<(const ppair& p)const      
	{	return mx==p.mx?my<p.my:mx<p.mx;}
	
}mid[pairMAX];

bool com(ppair a,ppair b)
{
	if( a.mx==b.mx && a.my==b.my)
		return true;
	else
		return false;
}

int main()
{
	int t,n,count,num;	
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{		
		scanf("%d",&n);
		for(int j=0;j<n;++j)
			scanf("%d %d",&x[j],&y[j]);
		num=0; count=0;
		for(int k=0;k<n-1;++k)
		{
			for(int l=k+1;l<n;++l)
			{			
				mid[count].mx=x[k]+x[l];
				mid[count].my=y[k]+y[l];				
				count++;
			}
		}
		sort(mid,mid+count);
		int now=1;
		for(int m=0;m<count-1;++m)
		{
			while(com(mid[m],mid[m+1]) && m!=count-1)         //有幾個一樣
			{
				m++;
				now++;
				num+=now-1;      //C(n 取 2)-C(n-1 取 2)=n(n-1)/2-(n-1)(n-2)/2=n-1
			}
			now=1;			
		}		
		printf("%d\n",num);
	}
	return 0;
}
/*TLE
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

#define MAX 1010

int x[MAX];
int y[MAX];
typedef struct ppair ppair;    //不能取名為pair
struct ppair
{
	int mx;
	int my;
	bool operator<(const ppair& p)const       //用map也要有這個
	{	return mx==p.mx?my<p.my:mx<p.mx;}
	
}mid;

int main()
{
	int t,n,num;
	map<ppair,int> ans;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		ans.clear();
		scanf("%d",&n);
		for(int j=0;j<n;++j)
			scanf("%d %d",&x[j],&y[j]);
		num=0;
		for(int k=0;k<n-1;++k)
		{
			for(int l=k+1;l<n;++l)
			{			
				mid.mx=x[k]+x[l];
				mid.my=y[k]+y[l];				
				if(ans[mid]!=0)
				{
					ans[mid]++;
					num+=ans[mid]-1;
				}
				else				
					ans[mid]++;
			}
		}				
		printf("%d\n",num);
	}
	return 0;
}
*/