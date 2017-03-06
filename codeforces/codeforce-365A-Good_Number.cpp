#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 12
bool v[MAXN];

int main()
{
	int n,k,in,i;
	int ans=0;
	bool ya=true;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		ans=0;
		
		int tmp=n;
		while(n--)
		{
			
			scanf("%d",&in);
			memset(v,false,sizeof(v));
			ya=true;
			while(in!=0)
			{
				v[in%10]=true;
				in/=10;
			}
			for(i=0;i<=k;++i)
			{	
				if(!v[i])
				{
					ya=false;
					break;
				}
			}
			if(ya)	ans++;
		}

		printf("%d\n",ans);
	}
	return 0;
}