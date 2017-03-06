#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
	int n,f,money;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		money=0;
		scanf("%d",&f);
		int farm[f][3];
		for(int j=0;j<f;++j)
		{
			scanf("%d %d %d",&farm[j][0],&farm[j][1],&farm[j][2]);
			money+=farm[j][0]*farm[j][2];
		}
		printf("%d\n",money);
	}
	return 0;
}