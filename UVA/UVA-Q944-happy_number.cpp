#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int count=0;

int happy(int n)
{
	++count;
	if(count==11)
		return 0;
	if(n==1)
		return 0;
	int next=0;
    while(n!=0)
	{
		next+=(n%10)*(n%10);
		n/=10;
	}
	happy(next);
}

int main()
{
	int l,h;
	int first=0;
	while(scanf("%d %d",&l,&h)!=EOF)
	{
		if(first)
		{
			printf("\n");
		}
		else
		{
			first=1;
		}		
		for(int i=l;i<=h;++i)
		{
			count=0;
			happy(i);
			if(count!=11)
				cout<<i<<" "<<count<<endl;
		}
		
	}
	return 0;
}

/*
int main()
{
	int l,h,count,tmp,next,flag;
	while(scanf("%d %d",&l,&h)!=EOF)
	{
		for(int i=l;i<=h;++i)
		{
			tmp=i;
			count=0;
			next=0;
			flag=0;
			while(tmp!=1)
			{				
				count++;
				while(tmp!=0)
				{
					next+=(tmp%10)*(tmp%10);
					tmp/=10;
				}
				tmp=next;
				if(tmp==i)
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				printf("%d %d\n",i,count);
			}
		}
		printf("\n");
	}
	return 0;
}*/