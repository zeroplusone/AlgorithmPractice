/******************
Judge   : POJ
Problem : PKU-1724_ROADS.cpp
Course  : Course10
discribe: find the shortest path from the city 1 to the city N that he can afford with the amount of money he has.
			If such path does not exist, only number -1 should be written to the output. 
Sample Input

5	//money
6	//#city
7	//#road
1 2 2 3	//source destination len toll
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 0
5 4 3 2

Sample Output

11	// total length 

SOL:
Bellman Ford
[direction ]
*******************/
/*#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 110
#define INF 1000000000

struct road
{
	int len,toll;
	
}edge[MAX][MAX];

struct release
{
	int v,l,t;
	bool operator<(const release& p)const
	{
		return l==p.l?t>p.t:l>p.l;
	}
}tmp;

priority_queue<struct release> pque;
int dis[MAX];
int money,maxv,rnum;
vector<int> rr[MAX];

int Dijkstra(int start)
{
	int nowv,nowl,nowt,nextv;
	tmp.v=start;	tmp.l=0;	tmp.t=0;
	pque.push(tmp);
	dis[start]=0;
	while(!pque.empty())
	{
		tmp=pque.top();
		pque.pop();
		nowv=tmp.v;	nowl=tmp.l;	nowt=tmp.t;
		dis[nowv]=nowl;
		if(nowv==maxv)	return dis[maxv];
		for(int i=0;i<rr[nowv].size();++i)
		{
			nextv=rr[nowv][i];
			if(nowt+edge[nowv][nextv].toll<=money)
			{
				tmp.v=nextv;	
				tmp.l=nowl+edge[nowv][nextv].len;	
				tmp.t=nowt+edge[nowv][nextv].toll;
				pque.push(tmp);
			}
		}
	}
	if(dis[maxv]==INF)	return -1;
	else	return dis[maxv];
}


void reset()
{
	for(int i=0;i<MAX;++i)
	{
		dis[i]=INF;		
		rr[i].clear();
	}
}

int main()
{
	int fromr,tor,lenr,tollr;
	scanf("%d%d%d",&money,&maxv,&rnum);
	//maxv--;
	reset();
	for(int i=0;i<rnum;++i)
	{
		scanf("%d %d %d %d",&fromr,&tor,&lenr,&tollr);
		//fromr--;	tor--;
		edge[fromr][tor].len=lenr;
		edge[fromr][tor].toll=tollr;
		rr[fromr].push_back(tor);
	}
	printf("%d\n",Dijkstra(1));
	return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 110
#define INF 1000000000

struct road
{
	int des,len,toll;
	
};
vector<struct road> edge[MAX];
struct road tmp2;

struct release
{
	int v,l,t;
	bool operator<(const release& p)const
	{
		return l==p.l?t>p.t:l>p.l;
	}
}tmp;

priority_queue<struct release> pque;
int dis[MAX];
int money,maxv,rnum;
//vector<int> rr[MAX];

int Dijkstra(int start)
{
	int nowv,nowl,nowt,nextv;
	tmp.v=start;	tmp.l=0;	tmp.t=0;
	pque.push(tmp);
	dis[start]=0;
	while(!pque.empty())
	{
		tmp=pque.top();
		pque.pop();
		nowv=tmp.v;	nowl=tmp.l;	nowt=tmp.t;
		dis[nowv]=nowl;
		if(nowv==maxv)	return dis[maxv];
		for(int i=0;i<edge[nowv].size();++i)
		{
			nextv=edge[nowv][i].des;
			if(nowt+edge[nowv][i].toll<=money)
			{
				tmp.v=nextv;	
				tmp.l=nowl+edge[nowv][i].len;	
				tmp.t=nowt+edge[nowv][i].toll;
				pque.push(tmp);
			}
		}
	}
	if(dis[maxv]==INF)	return -1;
	else	return dis[maxv];
}


void reset()
{
	for(int i=0;i<MAX;++i)
	{
		dis[i]=INF;		
		//rr[i].clear();
	}
}

int main()
{
	int fromr,tor,lenr,tollr;
	scanf("%d%d%d",&money,&maxv,&rnum);
	//maxv--;
	reset();
	for(int i=0;i<rnum;++i)
	{
		scanf("%d %d %d %d",&fromr,&tor,&lenr,&tollr);
		//fromr--;	tor--;
		tmp2.des=tor;
		tmp2.len=lenr;
		tmp2.toll=tollr;

		edge[fromr].push_back(tmp2);
	}
	printf("%d\n",Dijkstra(1));
	return 0;
}