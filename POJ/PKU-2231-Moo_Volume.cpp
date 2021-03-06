/*
Sample Input
5
1
5
3
2
4

Sample Output
40

每一個數和其他數的差距加起來
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 10010
long long int cow[MAX];    //要用long long int 不然會WA
long long int ans,odd;
long long int n;

void getans(int a,int b){
	ans+=(cow[b]-cow[a])*2*(b-a);} //差距有(b-a+1)*2-2=2*(b-a)
/*
long long int compare(const void* a,const void* b)
{	return *(long long int*)a-*(long long int*)b;	}	*/
int compare(const void* a,const void* b)
{	return *(int*)a-*(int*)b;	}
	
int main()
{	
	ans=0;	odd=0;
	scanf("%lld",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",&cow[i]);
	qsort(cow,n,sizeof(long long int),compare);
	for(int j=0;j<n/2;++j)
		getans(j,n-1-j);    //前後和中間的數加起來會是兩數的差距

	printf("%lld\n",ans);
	return 0;
}