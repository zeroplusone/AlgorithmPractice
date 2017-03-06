#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 100100
int a[MAX];
int to[MAX];

int main()
{
	int n,ans;
	bool plus=false;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			to[i]=-1;
		ans=0;	plus=false;
		
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==i)
				ans++;
			else if(!plus)
			{
				if(to[i]==a[i])
					plus=true;
				else
					to[a[i]]=i;
			}
			else
				continue;
		}
		if(ans!=n)
			ans=plus?ans+2:ans+1;
		printf("%d\n",ans);
		
	}
	return 0;
}