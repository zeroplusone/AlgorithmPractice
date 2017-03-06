#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 100
bool ya[MAX];

int main()
{
	long long int p,g;
	long long int num,sum,full;
	while(scanf("%lld",&p)!=EOF)
	{
		num=0;	sum=0;
		
		if(p==0)
			break;
			
		for(int i=2;i<p;++i)
		{		
			memset(ya,false,sizeof(ya));
			g=1;	full=0;
			for(int j=1;j<p;++j)
			{
				g*=i;
				if(!ya[g%p])
				{
					//printf("ya\n");
					ya[g%p]=true;
					full++;
				}
				g=g%p;				
			}
			if(full==p-1)
			{
				//printf("yaya\n");
				num+=1;
				sum+=i;
			}
		}
		printf("%lld %lld %lld\n",p,num,sum);
		
	}
	return 0;
}