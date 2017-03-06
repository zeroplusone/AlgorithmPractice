#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1000100

long long int ans;

struct roadway
{
	int e,w;
	bool operator<(const roadway& a)const
	{
		return e==a.e?w<a.w:e<a.e;
	}
}road[MAX],tmp[MAX];


void Combine(int l,int mid,int r)
{
	int i,j,cnt;
	
	i=l;	j=mid+1;	cnt=0;
	while(i<=mid && j<=r)
	{
		if(road[j].w<road[i].w && road[j].e>road[i].e){	tmp[cnt++]=road[j++]; ans+=mid-i+1;}
		else	tmp[cnt++]=road[i++];
	}
	
	while(i<=mid)	tmp[cnt++]=road[i++];
	while(j<=r)	tmp[cnt++]=road[j++];
	
	for(i=l;i<=r;++i)
		road[i]=tmp[i-l];
}

void MergeSort(int l,int r)
{
	if(l==r)	return;
	
	int mid=(l+r)/2;
	MergeSort(l,mid);
	MergeSort(mid+1,r);
	Combine(l,mid,r);
}

int main()
{
	int t,m,n,k;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(int j=0;j<k;++j)
		{
			scanf("%d %d",&road[j].e,&road[j].w);
		}
		ans=0;
		sort(road,road+k);
		MergeSort(0,k-1);
		
		printf("Test case %d: %lld\n",i,ans);
	}
	return 0;
}
