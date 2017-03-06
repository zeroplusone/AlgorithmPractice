#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 55
#define HOLE 2600
char m[MAX][MAX];
bool v[MAX][MAX];
queue<int> xx,yy;
int x,y;
int step[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

struct hole
{
	int num;
	char c;
	bool operator<(const hole& t)const
	{
		return num==t.num?c>t.c:num<t.num;
	}
}h[HOLE];

void reset()
{
	memset(m,'.',sizeof(m));
	memset(v,false,sizeof(v));
}

int bfs(int a,int b,char cc)
{
	int big=1,tx,ty,mx,my;
	while(!xx.empty())
		xx.pop();
	while(!yy.empty())
		yy.pop();
	xx.push(a);
	yy.push(b);
	v[a][b]=true;
	while(!xx.empty() && !yy.empty())
	{
		tx=xx.front();	ty=yy.front();
		for(int i=0;i<4;++i)
		{
			mx=tx+step[i][0];	my=ty+step[i][1];
			if(mx>=0 && mx<x && my>=0 && my<y)
			{
				if(!v[mx][my] && m[mx][my]==cc)
				{
					xx.push(mx);
					yy.push(my);
					v[mx][my]=true;
					big++;
				}				
			}
		}
		xx.pop();	yy.pop();
	}
	return big;
}

int main()
{
	
	int count,p=1;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		if(x==0 && y==0)
			break;
		reset();	count=0;
		getchar();
		for(int i=0;i<x;++i)
		{
			for(int j=0;j<y;++j)
				scanf("%c",&m[i][j]);
			getchar();
		}
		for(int i=0;i<x;++i)
		{
			for(int j=0;j<y;++j)
			{
				if(m[i][j]!='.' && !v[i][j])
				{					
					h[count].c=m[i][j];
					h[count].num=bfs(i,j,m[i][j]);					
					count++;
					
				}
			}
		}
		sort(h,h+count);
		printf("Problem %d:\n",p);
		p++;
		for(int i=count-1;i>=0;--i)
			printf("%c %d\n",h[i].c,h[i].num);
	}
	return 0;
}