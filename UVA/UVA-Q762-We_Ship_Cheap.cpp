/*
Sample input 
3       //三條路
JV PT
KA PT
KA HP
JV HP  //起點 鐘點

2
JV PT
KA HP
JV HP

Sample output  //最短路徑
JV PT
PT KA
KA HP

No route  //無法

SOL:BFS
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
using namespace std;

#define MAX 800
int r[MAX][MAX],c;
bool v[MAX];
int last[MAX];
map<string,int> to;
map<int,string> back;
stack<string> ans;
queue<int> b;

string start,end;

void print(int now)
{
	string tmp;
	
	ans.push(back[now]);
	while(last[now]!=-1)
	{
		ans.push(back[last[now]]);
		now=last[now];
	}	
	while(ans.size()!=1)
	{
		tmp=ans.top();	ans.pop();
		cout<<tmp<<" "<<ans.top()<<endl;
			
	}
}

int bfs()
{
	
	int now;
	b.push(to[start]);
	v[to[start]]=true;
	last[to[start]]=-1;
	while(!b.empty())
	{			
		now=b.front();
		if(back[now]==end)
		{
			print(now);
			return 1;
		}
		for(int i=0;i<c;++i)
		{
			if(r[now][i]==1 && !v[i])
			{
				b.push(i);
				v[i]=true;
				last[i]=now;
			}
		}
		b.pop();
	}
	return 0;
}

void reset()
{
	memset(r,0,sizeof(r));
	memset(v,false,sizeof(v));
	memset(last,-1,sizeof(last));
	to.clear();
	back.clear();
	while(!ans.empty())
		ans.pop();
	while(!b.empty())
		b.pop();
	c=0;
}

int main()
{
	int n;
	bool ya=true;

	string s1,s2;
	while(scanf("%d",&n)!=EOF)
	{
		if(ya)
			ya=false;
		else
			printf("\n");		
		
		reset();
		for(int i=0;i<n;++i)
		{	
			cin>>s1>>s2;
			if(!to.count(s1))
			{
				to[s1]=c;
				back[c]=s1;
				c++;
			}
			if(!to.count(s2))
			{
				to[s2]=c;
				back[c]=s2;
				c++;
			}
			r[to[s1]][to[s2]]=r[to[s2]][to[s1]]=1;
		}
		cin>>start>>end;

		if(bfs()==0)
			printf("No route\n");
	}
	return 0;
}