/******************
Judge   : uva
Problem : 10364 - Square
Course  : Course15
discribe: give yon n stick with its length , ask you if they can combine to a square 
Input   :
		3	//case
		4 1 1 1 1	//#stick len..
		5 10 20 30 40 50
		8 1 7 2 6 4 4 3 5

Output	:
		yes
		no
		yes
solve:
		bitwise
*******************/

 /*//WA
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 25
int len[MAXN];
int ans[MAXN];
int n,sum,coun;
bool flag;

void DP(int s,int num)
{
	if(num>4)	return;
	if(s==(1<<n)-1 && num==4)
	{		
		flag=true;
		return;
	}
	for(int i=0;i<coun && !flag;++i)
	{
		//printf("%d %d \n",s,ans[i]);
		if((s&ans[i])==0)
			DP((s|ans[i]),num+1);
	}
}

void build(int s,int now,int end)
{
	int i;
	//printf("%d %d\n",s,now);
	if(now==sum/4)
	{
		ans[coun++]=s;
		return;
	}
	
	for(i=end;i<n;++i)
	{
		if(now+len[i]<=sum/4)
		{
			build((s|(1<<i)),now+len[i],i+1);
		}
	}
}

int main()
{
	int T,i,maxl,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;	maxl=0;
		for(i=0;i<n;++i)
		{	
			scanf("%d",&len[i]);
			sum+=len[i];
			maxl=maxl<len[i]?len[i]:maxl;
		}
		if(sum%4!=0 || maxl>sum/4)
			printf("no\n");
		else
		{
			coun=0;
			build(0,0,0);
			flag=false;
			DP(0,0);
			if(flag)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 25
int len[MAXN];
int n,sum;

bool cmp(int a,int b)
{
	return a>b;
}

bool DP(int s,int num,int all,int end)
{
	if(num==3)	return true;
	if(all==sum/4)
		if(DP(s,num+1,0,0))	return true;
		
	for(int i=end;i<n;++i)
	{
		if( ((s&(1<<i))==0) && (all+len[i]<=sum/4))
		{
			if(DP((s|(1<<i)),num,all+len[i],i+1))
				return true;
		}
	}
	return false;
}



int main()
{
	int T,i,maxl,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;	maxl=0;
		for(i=0;i<n;++i)
		{	
			scanf("%d",&len[i]);
			sum+=len[i];
			maxl=maxl<len[i]?len[i]:maxl;
		}
		if(sum%4!=0 || maxl>sum/4)
			printf("no\n");
		else
		{
			sort(len,len+n,cmp);
			
			if(DP(0,0,0,0))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
