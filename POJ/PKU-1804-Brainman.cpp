/*

Sample Input
4           //case
4 2 8 0 3              //碭计->块
10 0 1 2 3 4 5 6 7 8 9
6 -42 23 6 28 -100 65537
5 0 0 0 0 0

Sample Output  //籔綟ユ传 程ユ传Ω计->bubble sort
Scenario #1:
3

Scenario #2:
0

Scenario #3:
5

Scenario #4:
0
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1010
int num[MAX];

int main()
{
	int c,n,ans;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		ans=0;
		scanf("%d",&n);
		for(int j=0;j<n;++j)
			scanf("%d",&num[j]);
		for(int k=0;k<n;++k)
		{
			for(int l=0;l<n-k-1;++l)
			{
				if(num[l]>num[l+1])
				{
					swap(num[l+1],num[l]);
					ans++;
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n",i,ans);
	}
	return 0;
}