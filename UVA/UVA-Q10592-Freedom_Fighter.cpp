#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 60
int n,f,e;
char m[MAX][MAX];
bool v[MAX][MAX];
queue<int> x1,y1,x2,y2;

int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void reset()
{
	memset(m,'.',sizeof(m));
	memset(v,false,sizeof(v));
}

void bfs2(int x,int y,char c)
{
	if(c=='B')
		f++;
	if(c=='P')
		e++;
	int nowx,nowy,mx,my;
	while(!x2.empty())
		x2.pop();
	while(!y2.empty())
		y2.pop();
	x2.push(x);
	y2.push(y);
	while(!x2.empty() && !y2.empty())
	{
		nowx=x2.front();	nowy=y2.front();
		for(int i=0;i<4;++i)
		{
			mx=nowx+step[i][0];	my=nowy+step[i][1];
			if(mx>=0 && mx<n && my>=0 && my<n)
			{
				if(!v[mx][my] && m[mx][my]==c)
				{
					v[mx][my]=true;
					x2.push(mx);
					y2.push(my);					
				}
			}
		}
		x2.pop();	y2.pop();
	}
}

void bfs(int x,int y)
{
	int nowx,nowy,mx,my;
	while(!x1.empty())
		x1.pop();
	while(!y1.empty())
		y1.pop();
	x1.push(x);
	y1.push(y);
	while(!x1.empty() && !y1.empty())
	{
		nowx=x1.front();	nowy=y1.front();
		for(int i=0;i<4;++i)
		{
			mx=nowx+step[i][0];	my=nowy+step[i][1];
			if(mx>=0 && mx<n && my>=0 && my<n)
			{
				if(!v[mx][my])
				{
					v[mx][my]=true;
					if(m[mx][my]=='*')
					{
						x1.push(mx);
						y1.push(my);
					}
					else if(m[mx][my]=='B' || m[mx][my]=='P')
					{
						bfs2(mx,my,m[mx][my]);
					}
					
					
				}
			}
		}
		x1.pop();	y1.pop();
	}
}

int main()
{
	int total,count;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		reset();	count=1;	total=0;
		getchar();
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%c",&m[i][j]);
				if(m[i][j]=='.')
					v[i][j]=true;
			}
			getchar();
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(m[i][j]!='.' && !v[i][j])
				{
					f=0;	e=0;
					bfs(i,j);
					printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n",count,f,e);
					count++;
					if(f==e)
						total++;
				}
			}
		}
		printf("Total %d group(s) are in fighting position.\n",total);
	}
	return 0;
}