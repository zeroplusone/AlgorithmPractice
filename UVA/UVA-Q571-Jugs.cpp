/*
Sample Input 
3 5 4			//A容量 B容量 B要達到的容量
5 7 3

Sample Output  //步驟
fill B
pour B A
empty A
pour B A
fill B
pour B A
success
fill A
pour A B
fill A
pour A B
empty B
pour A B
success

SOL:BFS走每一種可能的倒法
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

#define MAX 1010

int a,b,n;
queue<int> aa,bb,last;
stack<string> ans;
string s[7]={"fill A","fill B","pour A B","pour B A","empty A","empty B","success"};
bool v[MAX][MAX];
struct map
{
	int lx;
	int ly;	
	int show;
}m[MAX][MAX];

void reset()
{
	while(!aa.empty())
		aa.pop();
	while(!bb.empty())
		bb.pop();
	while(!last.empty())
		last.pop();
	while(!ans.empty())
		ans.pop();
	for(int i=0;i<=a;++i)
	{
		for(int j=0;j<=b;++j)
		{
			m[i][j].lx=-1;
			m[i][j].ly=-1;			
			m[i][j].show=-1;
		}		
	}		
	memset(v,false,sizeof(v));
	ans.push(s[6]);
}

void makeans(int x,int y)
{	
	int tx,ty;
	while(x!=0 || y!=0)
	{
		
		tx=x;	ty=y;
		ans.push(s[m[x][y].show]);
		x=m[tx][ty].lx;
		y=m[tx][ty].ly;

	}
}

void bfs()
{
	int nowa,nowb,tmpa,tmpb;	
	aa.push(0);	bb.push(0);
	v[0][0]=true;
	while(1)
	{
		nowa=aa.front();	nowb=bb.front();
		
			if(nowb==n)
			{
				makeans(nowa,nowb);
				break;
			}
		
			if(nowa<a && !v[a][nowb])
			{		
				//printf("fill a\n");
				aa.push(a);
				bb.push(nowb);
				m[a][nowb].lx=nowa;
				m[a][nowb].ly=nowb;
				m[a][nowb].show=0;
				v[a][nowb]=true;
			}
			if(nowb<b && !v[nowa][b])
			{
				//printf("fill b\n");
				aa.push(nowa);
				bb.push(b);
				m[nowa][b].lx=nowa;
				m[nowa][b].ly=nowb;
				m[nowa][b].show=1;
				v[nowa][b]=true;
			}
			if(nowa>0 && nowb<b)
			{
				//printf("pour a b\n");
				tmpa=nowa-(b-nowb)<0?0:nowa-(b-nowb);
				tmpb=nowb+nowa>b?b:nowb+nowa;
				if(!v[tmpa][tmpb])
				{
					aa.push(tmpa);
					bb.push(tmpb);
					m[tmpa][tmpb].lx=nowa;
					m[tmpa][tmpb].ly=nowb;
					m[tmpa][tmpb].show=2;
					v[tmpa][tmpb]=true;
				}
			}
			if(nowb>0 && nowa<a)
			{
				//printf("pour b a\n");
				tmpa=nowb+nowa>a?a:nowb+nowa;
				tmpb=nowb-(a-nowa)<0?0:nowb-(a-nowa);
				if(!v[tmpa][tmpb])
				{
					bb.push(tmpb);
					aa.push(tmpa);
					m[tmpa][tmpb].lx=nowa;
					m[tmpa][tmpb].ly=nowb;
					m[tmpa][tmpb].show=3;
					v[tmpa][tmpb]=true;
				}
			}
			if(nowa>0 && !v[0][nowb])
			{
				//printf("empty a\n");
				aa.push(0);
				bb.push(nowb);
				m[0][nowb].lx=nowa;
				m[0][nowb].ly=nowb;
				m[0][nowb].show=4;
				v[0][nowb]=true;
			}
			if(nowb>0 && !v[nowa][0])
			{
				//printf("empty b\n");
				aa.push(nowa);
				bb.push(0);
				m[nowa][0].lx=nowa;
				m[nowa][0].ly=nowb;
				m[nowa][0].show=5;
				v[nowa][0]=true;
			}
			aa.pop();	bb.pop();	
	}
	return;
}

void print()
{
	while(!ans.empty())
	{
		cout<<ans.top()<<endl;
		ans.pop();
	}
}

int main()
{
	
	while(scanf("%d %d %d",&a,&b,&n)!=EOF)
	{
		reset();		
		bfs();
		print();
	}
	return 0;
}