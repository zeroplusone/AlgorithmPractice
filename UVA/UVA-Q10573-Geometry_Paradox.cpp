#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

#define PI 2*acos(0)

int ten(int now,int all)
{
	int ans=1;
	for(int i=0;i<all-now-1;++i)
		ans*=10;
	return ans;
}

int main()
{
	int n,ift,i,r1,r2,t;
	string s;
	double ans;
	scanf("%d",&n);
	getchar();
	for(int j=0;j<n;++j)
	{
		ift=0;
		r1=0;
		r2=0;
		t=0;
		getline(cin,s);
		
		for(int i=0;i<s.length();++i)
		{
			if(s[i]!=' ')
				t=t*10+(s[i]-'0');
			else
			{
				r1=t;
				t=0;
				ift=1;
			}
		}

		if(ift==0)		
		{	
			
			if(t<0)
			{
				printf("Impossible.");				
			}
			else
			{
				ans=(float)(t*t)/(float)8*PI;
				printf("%.4lf\n",ans);
			}
		}
		else
		{
			r2=t;
			
			if(r1<0 || r2<0)
			{
				printf("Impossible.");				
			}
			else
			{
				ans=2*r1*r2*PI;
				printf("%.4lf\n",ans);
			}
		}
		
	
	}
	return 0;
}
