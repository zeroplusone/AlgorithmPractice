#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

int a[100010];
int far[100010];

int main()
{
	int T,n,m,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		a[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
				far[i]=far[i-1];
			else
				far[i]=i;
		}
		while(m--)
		{
			scanf("%d%d",&l,&r);
			if(far[r]<=l)
				putchar('Y');
			else
				putchar('N');
		}
		puts("");
	}
	return 0;
}
