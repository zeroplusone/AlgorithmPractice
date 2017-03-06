#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define MAX 5000

struct fraction
{
	double num;
	double d;
	//int k;
	bool operator<(const fraction &p)const
	{
		return d<p.d;
	}
	
}up[MAX],down[MAX];

int main()
{
	int n,tmp1,tmp2,unow,dnow;
	double in;
	//double all;
	while(scanf("%d",&n)!=EOF)
	{
		unow=0;	dnow=0;// all=0;
		for(int i=0;i<2*n;++i)
		{
			scanf("%lf",&in);
			//all+=in;
			tmp1=in;
			tmp2=in+0.5;
			if(tmp1==tmp2)
			{
				down[dnow].num=in;
				down[dnow].d=in-(double)tmp1;
				//down[dnow].k=tmp1;
				dnow++;
			}			
			else
			{
				up[unow].num=in;
				up[unow].d=(double)tmp2-in;
				//up[dnow].k=tmp2;
				unow++;
			}
				
		}
		sort(up,up+unow);
		sort(down,down+dnow);
		double ans=0;
		
		
		if(unow<dnow)
		{
			for(int i=0;i<unow;++i)
			{
			printf("%lf ,",up[i].d);
				ans-=up[i].d;
			}
			for(int i=0;i<(unow+dnow)/2;++i)
			{printf("#%lf %lf ,",down[i].num,down[i].d);
				ans+=down[i].d;
			}
			for(int i=(unow+dnow)/2;i<dnow;++i)
			{printf("%lf ,",down[i].d);
				if(down[i].d!=0)
					ans-=1-down[i].d;
			}
		}
		else if(unow==dnow)
		{
			for(int i=0;i<unow;++i)
				ans-=up[i].d;
			for(int i=0;i<dnow;++i)
				ans+=down[i].d;		
		}
		else
		{
			for(int i=0;i<(unow+dnow)/2;++i)
				ans-=up[i].d;
			for(int i=0;i<dnow;++i)
				ans+=down[i].d;
			for(int i=(unow+dnow)/2;i<unow;++i)
				ans+=1-up[i].d;
		}
		ans=ans<0?(-1)*ans:ans;
		printf("%lf\n",ans);
	}
	return 0;
}