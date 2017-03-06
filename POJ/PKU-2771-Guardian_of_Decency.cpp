/******************
Judge   : poj
Problem : 2771-Guardian of Decency(=uva 12083)
discribe:  a low probability two persons will become a couple:
			Their height differs by more than 40 cm.
			They are of the same sex.
			Their preferred music style is different.
			Their favourite sport is the same (they are likely to be fans of different teams and that would result in fighting).
			the maximum number of persons he can take, given their vital information. (no couple)
Input   :
			2	//t (case)
			4	//n
			35 M classicism programming
			0 M baroque skiing
			43 M baroque chess
			30 F baroque soccer
			8	//n
			27 M romance programming
			194 F baroque programming
			67 M baroque ping-pong
			51 M classicism programming
			80 M classicism Paintball
			35 M baroque ping-pong
			39 F romance ping-pong
			110 M romance Paintball
Output  :
			3
			7
Solve   : bipartite matching
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 550
struct Person
{
	string gender,music,sport;
	int h;
}per[MAXN];
int mx[MAXN],my[MAXN];
bool used[MAXN];
double edge[MAXN][MAXN];	//left right

bool DFS(int now,int ny)
{
	int i,next;
	for(i=0;i<ny;++i)
	{
		if(edge[now][i] && !used[i])
		{
			used[i]=true;
			if(my[i]==-1 || DFS(my[i],ny))
			{
				mx[now]=i;
				my[i]=now;
				return true;
			}
		}
	}
	return false;
}

int bipartite(int nx,int ny)
{
	int i,ans=0;
	for(i=0;i<nx;++i)
		mx[i]=-1;
	for(i=0;i<ny;++i)
		my[i]=-1;

	for(i=0;i<nx;++i)
	{
		memset(used,false,(ny+1)*sizeof(bool));
		if(DFS(i,ny))	++ans;
	}
	return ans;
}

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		{
			memset(edge,0,sizeof(edge));
			for(i=0;i<n;++i)
			{
				cin>>per[i].h>>per[i].gender>>per[i].music>>per[i].sport;
				for(j=0;j<i;++j)
				{
					if(abs(per[i].h-per[j].h)<=40 && per[i].gender!=per[j].gender && per[i].music==per[j].music && per[i].sport!=per[j].sport)
					{
						if(per[i].gender=="F")
							edge[i][j]=1;
						else
							edge[j][i]=1;
					}
				}
			}

			printf("%d\n",n-bipartite(n,n));
		}
	}

	return 0;
}
