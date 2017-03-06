/******************
Judge   : UVA
Problem : UVA-Q437-The_Tower_of_Babylon.cpp
Course  : Course9
discribe: 底下的面的兩邊要大於上面的兩邊 求最高的高度

Sample Input

1    //幾個tower
10 20 30   //一個tower的xyz
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0   //end
Sample Output

Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342

SOL:按 X再來Y排序
用LIS的想法 找能夠排起來的最大高度

*******************/
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 100
struct tower
{
	int x,y,z;
	bool operator<(const tower& p)const
	{
		return x==p.x?y<p.y:x<p.x;
	}
}t[MAX],tmp;
int dp[MAX];

int main()
{
	int n,d[3],count,ans,tt,now;
	tt=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		count=0;
		for(int i=0;i<=n;++i)
			dp[i]=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %d",&d[0],&d[1],&d[2]);
			sort(d,d+3);
			t[count].x=d[0];	t[count].y=d[1];	t[count].z=d[2];			
			count++;
			t[count].x=d[0];	t[count].y=d[2];	t[count].z=d[1];
			count++;
			t[count].x=d[1];	t[count].y=d[2];	t[count].z=d[0];
			count++;
		}
		sort(t,t+count);
		/*for(int i=0;i<count;++i)
			printf("%d %d %d\n",t[i].x,t[i].y,t[i].z);*/
		
		ans=0; 
		for(int i=0;i<count;++i)
		{
			now=t[i].z;
			for(int j=i-1;j>=0;--j)
			{
				if(j>=0)
				{
					if(t[i].x>t[j].x && t[i].y>t[j].y)
					{
						if(now<dp[j]+t[i].z)
						{
							now=dp[j]+t[i].z;
							//printf("%d %d %d ya\n",i,j);
						}
					}
				}			
			}
			dp[i]=now;
			ans=dp[i]>ans?dp[i]:ans;
		}
		/*printf("\n");
		for(int i=0;i<count;++i)
			printf("%d ",dp[i]);
		printf("\n");*/
		/*ans=0;	tmp.x=t[0].x;	tmp.y=t[0].y;	tmp.z=t[0].z;
		for(int i=1;i<count;++i)
		{
			if(tmp.x==t[i].x)
			{
				if(tmp.z<t[i].z)
				{	
					tmp.x=t[i].x;	tmp.y=t[i].y;	tmp.z=t[i].z;
				}
			}
			else if(tmp.x<t[i].x)
			{
				if(tmp.y>=t[i].y)
				{
					if(tmp.z<t[i].z)
					{	
						tmp.x=t[i].x;	tmp.y=t[i].y;	tmp.z=t[i].z;
					}
				}
				else if(tmp.y<t[i].y)
				{
					ans+=tmp.z;
					printf("%d %d %d\n",tmp.x,tmp.y,tmp.z);
					tmp.x=t[i].x;	tmp.y=t[i].y;	tmp.z=t[i].z;
				}
			}
		}
		ans+=tmp.z;
		printf("%d %d %d\n",tmp.x,tmp.y,tmp.z);
		*/
		printf("Case %d: maximum height = %d\n",tt,ans);
		tt++;
	}
	return 0;
}