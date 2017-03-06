/******************
Judge   : UVA
Problem : UVA-Q341-Non-Stop_Travel.cpp
Course  : Course10
discribe: 找出最短的距離和路徑

Sample Input

5      //5個頂點
2  3 3   4 6    //地1個頂點有2條邊 (頂點 距離)
3  1 2   3 7   5 6
1  4 5
0
1  4 7
2 4             //起點 終點

2
1   2 5
1   1 6
1 2

7
4   2 5   3 13   4 8   5 18
2   3 7   6 14
1   6 6
2   3 5   5 9
3   6 2   7 9    4 6
1   7 2
0
1 7

0   //END
Sample Output

Case 1: Path = 2 1 4; 8 second delay
Case 2: Path = 1 2; 5 second delay
Case 3: Path = 1 2 3 6 7; 20 second delay

SOL:
Bellman Ford
[direction ]
*******************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

#define MAX 15
#define INF 9999999
struct road
{
	int from;
	int to;
	int dis;
}r[MAX*MAX];

int d[MAX];
int p[MAX];
int n;

void reset()
{
	for(int i=0;i<=n;++i)
	{
		d[i]=INF;
		p[i]=0;
	}

}

int main()
{
	int tmp,v,l,start,end,count,a,b,c,ans;
	bool change;
	c=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
			
		reset();
		count=0;		
		for(int i=1;i<=n;++i)
		{			
			scanf("%d",&tmp);
				for(int j=0;j<tmp;++j)
				{
					scanf("%d",&v);
					scanf("%d",&l);
					r[count].from=i;
					r[count].to=v;
					r[count].dis=l;
					count++;
				}		
		}
		scanf("%d %d",&start,&end);	
		d[start]=0;
		for(int i=0;i<n;++i)
		{
			change=false;
			for(int j=0;j<count;++j)
			{
				a=r[j].from;
				b=r[j].to;
				if(d[a]+r[j].dis<d[b])
				{
					d[b]=d[a]+r[j].dis;
					p[b]=a;
					change=true;
				}
			}
			/*for(int k=1;k<=n;++k)
				printf("%d ",d[k]);
			printf("\n");*/
			if(!change)
				break;
		}
		printf("Case %d: Path =",c);
		stack<int> path;
		ans=d[end];
		path.push(end);
		while(end!=start)
		{
			path.push(p[end]);
			end=p[end];
		}
		while(!path.empty())
		{
			printf(" %d",path.top());
			path.pop();
		}
		printf("; %d second delay\n",ans);
		c++;
	}
	return 0;
}
