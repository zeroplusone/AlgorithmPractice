/*
Sample Input 
3 4 5  //高寬長
S....  //S起點 E中點 #障礙 .可走
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

Sample Output    //計算要走幾步
Escaped in 11 minute(s).
Trapped!

SOL:BFS
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 30
bool v[MAXN][MAXN][MAXN];
char road[MAXN];
int x,y,z,sx,sy,sz,ex,ey,ez;
queue<int> xx,yy,zz,level;

int step[6][3]={{0,0,-1},{0,0,1},{0,-1,0},{0,1,0},{1,0,0},{-1,0,0}};

int bfs()
{
	int nowx,nowy,nowz,nowl,mx,my,mz;
	v[sx][sy][sz]=true;
	xx.push(sx);	yy.push(sy);	zz.push(sz);
	level.push(1);
	
	while(!xx.empty() && !yy.empty() && !zz.empty() && !level.empty())
	{
		nowx=xx.front();	nowy=yy.front();
		nowz=zz.front();	nowl=level.front();

		if( nowx==ex && nowy==ey && nowz==ez )
			return nowl;
		for(int i=0;i<6;++i)
		{
			mx=nowx+step[i][0];	my=nowy+step[i][1];	mz=nowz+step[i][2];
			if( mx>=0 && mx<x && my>=0 && my<y && mz>=0 && mz<z )
			{
				if(!v[mx][my][mz])
				{
					v[mx][my][mz]=true;
					xx.push(mx);	yy.push(my);	zz.push(mz);
					level.push(nowl+1);					
				}
			}
		}
		xx.pop();	yy.pop();
		zz.pop();	level.pop();		
	}
	return 0;
}

void reset()
{
	while(!xx.empty())
		xx.pop();
	while(!yy.empty())
		yy.pop();
	while(!zz.empty())
		zz.pop();
	while(!level.empty())
		level.pop();
	memset(v,false,sizeof(v));
}

int main()
{
	int ans;
	while(scanf("%d %d %d",&x,&y,&z))
	{	
		if(!(x||y||z))
			break;
		if((!x)||(!y)||(!z))
		{
			printf("Trapped!\n");
			continue;
		}
		
		reset();
		
		for(int i=0;i<x;++i)
		{
			for(int j=0;j<y;++j)
			{
				scanf("%s",road);
				for(int k=0;k<z;++k)
				{

					if(road[k]=='S'){	sx=i; sy=j; sz=k; }
					if(road[k]=='E'){	ex=i; ey=j; ez=k; }
					if(road[k]=='#'){	v[i][j][k]=true; }
					else{  v[i][j][k]=false;	}
					
				}

			}

		}
		
		ans=bfs();
		if(ans==0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",ans-1);
			
	}
	return 0;
}
