#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 10001
bool prime[MAX];
int n,ans;
vector<int> p;

void setprime()
{
	prime[0]=false; prime[1]=false;
	for(int i=2;i<MAX;++i)
		prime[i]=true;
	for(int j=2;j<int(sqrt(float(MAX)));++j)
		if(prime[j])
			for(int k=j*j;k<MAX;k+=j)
				prime[k]=false;	
}
/*                              //若可以不連續的做法~題目要看清楚0.0
void find(int left,int now)
{
	printf("%d %d\n",left,now);
	left=left-p[now];
	
	if(left<0 || now<0)
		return;
	else if(left==0)
	{
		printf("PLUS\n");
		ans++;
		//find(n,now-1);
	}
	else
	{
		find(n,now-1);
		for(int i=1;i<=now;i++)
			find(left,now-i);
		find(left+p[now],now-1);
	}
}*/

int main()
{
	setprime();
	while(scanf("%d",&n))
	{		
		if(n==0)
			break;
		ans=0;
		p.clear();
		for(int i=2;i<=n;++i)
		{				
			if(prime[i])
				p.push_back(i);
		}
		int left;
		for(int j=p.size()-1;j>=0;--j)
		{
			left=n;
			for(int k=j;k>=0;--k)
			{
				left=left-p[k];
				if(left>0)
					continue;
				else if(left==0)
					ans++;
				else
					break;
			}
		}
		
		//find(n,p.size()-1);
		printf("!!%d\n",ans);
	}
	return 0;
}