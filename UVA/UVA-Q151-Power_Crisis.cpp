#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;


#define MAX 110

int main()
{
	int n,j;
	int id[MAX];
	id[1]=0;	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(j=1;;++j)
		{
			for(int k=2;k<=n;++k)
				id[k]=(id[k-1]+j)%k;
			if(id[n]==12)
				break;
		}
		printf("%d\n",j);
	}
	return 0;
}