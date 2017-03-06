#include<iostream>
/*
Sample Input:
2  //兩筆樹自
10
10
4    ----
1
2
2
4

Sample Output:
10 2 1     //中位數 多少跟中位數一樣大的樹   中位數的個數(偶樹才會有問題)
2 2 1
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1000010
int num[MAX];

int main()
{
	int n,ans,same,range,mid;
	while(scanf("%d",&n)!=EOF)
	{
		same=0;	range=0;
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
			
		sort(num,num+n);
		
		mid=(n-1)/2;
		ans=num[mid];	
		
		for(int i=mid-1;i>=0;--i)
			if( i>=0 && num[i]==num[mid] )
				same++;			

		if(n%2==0){	mid++; same++;}
		for(int i=mid;i<n;++i)
			if( i<n && num[i]==num[mid])
				same++;
				
		range=n%2==0?num[mid]-num[mid-1]+1:1;
		
		printf("%d %d %d\n",ans,same,range);	
	}
	return 0;
}