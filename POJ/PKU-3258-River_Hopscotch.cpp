#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 50010
long long int dif[MAX];
int l,n,m;
bool last;

bool canbe(long long int a)
{
	int remove=0;
	for(int i=0;i<n;++i)
	{
		if(dif[i]<a)
		{
			remove++;
			if(i==n-1)
				last=true;
		}
	}
	if(remove>m)
		return false;
	else
		return true;
		
	/*int count=0,remove=0;	
	bool two=false;
	long long int tmp,min=1000000000;
	int i;
	for(i=-1;i<=n-1 && remove!=m;)
	{
		tmp=0;	two=false;	
		while(tmp<a)
		{
			i++;
			if(i==n+1)
				break;
			tmp+=dif[i];
			
			if(two)
				remove++;
			else
				two=true;
		}
		if(min>tmp)
			tmp=min;
		count++;
		printf("$$%lld\n",tmp);
	}
	tmp=0;
	for(int j=i;j<=n;++j)
		tmp+=dif[j];
	if(min>tmp)
			tmp=min;		
		
	printf("$%d\n",count);
	if(min==a)
		return true;
	else
		return false;*/
}
/*
void print()
{
	for(int i=0;i<=n;++i)
		printf("%lld ",dif[i]);
	printf("\n");
}

long long int ans(long long int a,long long int b)
{
	if(a>b)
		return b;
	else
		return a;
}
*/
int main()
{	
	long long int t,tt,min;
	while(scanf("%d %d %d",&l,&n,&m)!=EOF)
	{		
		dif[0]=0;
		for(int i=1;i<=n;++i)		
			scanf("%lld",&dif[i]);		
		sort(dif+1,dif+n+1);
		
		
		t=dif[1];
		dif[1]=dif[1]-dif[0];		
		min=dif[1];
		for(int j=2;j<=n;++j)
		{
			tt=dif[j];
			dif[j]=dif[j]-t;			
			t=tt;
			min=dif[j]<min?dif[j]:min;
		}		
		//sort(dif+1,dif+n+1);
		long long int beg=min,mid,end=(long long int)l;
		
		//print();
		while(beg<end)
		{	
			last=false;
			//printf("@%lld %lld\n",beg,end);
			mid=(beg+end)/2;
			if(canbe(mid))	beg=mid+1;
			else	end=mid-1;
		}
		if(!last)
			beg=beg<(l-t)?beg:(l-t);
		printf("%lld\n",beg);		
	}
	return 0;
}
