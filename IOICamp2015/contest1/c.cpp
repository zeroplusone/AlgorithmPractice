#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAXN 220
string in1[MAXN],in2[MAXN];
int dp[MAXN][MAXN];

bool same(string a,string b)
{
	int len=a.length();
	if(len!=b.length())
		return false;
	for(int i=0;i<len;++i)
	{
		if(a[i]==b[i])
			continue;
		else
			return false;
	}
	return true;
}

int finddp(int a,int b)
{
	if(a==b)
		return 1;
	printf("!! %d %d\n",a,b);

//	if(a>b)	return 0;
	int l=a,r=b;
	string ch=in2[a];
	while(same(in2[l],ch))	l++;
	while(same(in2[r],ch))	r--;
	
//	for(int i=l;i<=r;++i)
//		in1[i]=ch;
	if(l>r)	return 0;
	while(same(in1[a],in2[a]))	a++;
	while(same(in1[b],in2[b]))	b--;

	printf("%d %d : %d %d\n",a,b,l,r);
	if(l==a && r==b)	
		return finddp(l,r)+1;
	else
		return finddp(l,r)+2;
}

int main()
{
	int T,n;
	int i;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(i=0;i<n;++i)
			cin>>in1[i];
		for(i=0;i<n;++i)
			cin>>in2[i];
		for(i=0;i<n;++i)
			if(in1[i]!=in2[i])
				dp[i][i]=1;
		int a=0,b=n-1;		
		while(same(in1[a],in2[a]))	a++;
		while(same(in1[b],in2[b]))	b--;
		printf("%d\n",finddp(a,b));	
	}
	return 0;
}
