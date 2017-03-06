#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int n,f,h,num;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		if(i)
			printf("\n");
		scanf("%d",&h);
		scanf("%d",&f);
		for(int j=0;j<f;++j)
		{
			if(j)
				printf("\n");
			for(int k=1;k<2*h;++k)
			{
				num=h-abs(h-k);
				for(int l=0;l<num;++l)
					printf("%d",num);
				printf("\n");
			}
		}
	}
	return 0;
}