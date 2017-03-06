#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
/*
#define MAX 100010
long long int w[MAX];
long long int ans,tmp,tmp2;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		ans=0;
		for(int i=0;i<n;++i)
			scanf("%lld",&w[i]);
		for(int i=0;i<n;++i)
		{
			if(w[i]>0)
			{
				for(int j=1;j<n;++j)
				{
					if(i-j>=0)
					{
						if(w[i-j]<0)
						{
							tmp=w[i-j]; tmp2=w[i];
							w[i-j]=w[i]>=((-1)*w[i-j])?0:w[i-j]+w[i];
							w[i]=w[i-j]==0?w[i]+tmp:0;							
							ans=w[i]==0?ans+j*tmp2:ans-j*tmp;
							if(!w[i])
								break;
						}	
					}					
					if(i+j<n)
					{
						if(w[i+j]<0)
						{
							tmp=w[i+j]; tmp2=w[i];
							w[i+j]=w[i]>((-1)*w[i+j])?0:w[i+j]+w[i];
							w[i]=w[i+j]==0?w[i]+tmp:0;
							ans=w[i]==0?ans+j*tmp2:ans-j*tmp;
							if(!w[i])
								break;
						}						
					}					
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
*/

//do not calculate negative
//give it to the right (= later send back)
int main()	
{
	int n;
	long long int w,ans,neww;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		ans=0;	neww=0;
		while(n--)
		{
			scanf("%lld",&w);
			neww=neww+w;
			if(neww>=0)
				ans+=neww;
			else
				ans+=(-1)*neww;
		}
		printf("%lld\n",ans);
	}
	return 0;
}