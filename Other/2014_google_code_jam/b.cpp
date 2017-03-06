#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int t,tt;
	double c,f,x;
	double last,rate,ans,now;
	int i,j;
	scanf("%d",&t);
	freopen("b.out","w",stdout);
	for(tt=1;tt<=t;++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%lf%lf%lf",&c,&f,&x);
		last=0;	rate=2;	ans=0;	now=x/rate;
		while(now>c/rate+x/(rate+f))
		{
			ans+=c/rate;	
			rate+=f;
			last=x/(rate+f);
			now=x/rate;
		}
		ans+=x/rate;	
		printf("%.7lf\n",ans);
	}
	return 0;
}