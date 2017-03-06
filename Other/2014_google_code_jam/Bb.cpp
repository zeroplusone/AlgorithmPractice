#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;


int main()
{
	//freopen("Bb.in","r",stdin);
	freopen("Bb.out","w",stdout);
	int t,tt;
	int i,j,tmp;
	int a,b,k;
	int ans;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d%d%d",&a,&b,&k);

		ans=0;
		for(i=0;i<a;++i)
		{
			for(j=0;j<b;++j)
			{
				//printf("%d\n",i&j);
				tmp=i&j;
				if(tmp<k)
					ans++;
			}
		}
		printf("Case #%d: ",tt);
		printf("%d\n",ans);
	}
	return 0;
}
