#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 100100
int num[MAX];

int main()
{
	int n,a,b;
	bool pass=false;
	int ans;
	
	while(scanf("%d",&n)!=EOF)
	{
		pass=false;
		ans=0;
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		scanf("%d %d",&a,&b);
		
		while(!pass && a>=0)
		{
			ans++;
			a--;
			for(int i=0;i<n;++i)
			{
				printf("%d ",num[i]);
				if(b==a-(a%num[i]))
				{
					pass=true;
					break;
				}
				/*else
					num[i]=a-(a%num[i]);*/

			}
			printf("\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}