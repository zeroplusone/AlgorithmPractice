/******************
Judge   : codeforeces
Problem : 462B-Appleman and Card Game
Course  : 2015-Course5
discribe: give a string and then print "hello string"
Input   : 
	15 10 				//n[#card] k[#choose]
	DZFDFZDFDDDDDDF		//card type
Output  : 
	82					//9*9[D]+any*1	= 82  
Solve   : greedy

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXN 100100
char in[MAXN];
int num[27];

int main()
{
	int n,k,i,use;
	long long int ans;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		getchar();
		scanf("%s",in);
		memset(num,0,sizeof(num));
		for(i=0;i<n;++i)		
			num[in[i]-'A']++;
		sort(num,num+26);

		ans=0;	use=k;
		for(i=25;i>=0 && use!=0;--i)
		{
			if(num[i]>=use)
			{
				ans+=(long long int)use*(long long int)use;
				break;
			}
			else
			{
				ans+=(long long int)num[i]*(long long int)num[i];
				use-=num[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}