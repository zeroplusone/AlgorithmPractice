#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int ans;

#define MAX 25010 
typedef struct wash wash;
struct wash
{
	int beg;
	int end;
	bool operator<(const wash& p)const
	{
		return beg==p.beg?end<p.end:beg<p.beg;
	}
}cow[MAX],tmp;
	
wash w(wash a,wash b)
{
	
}	
	
int main()
{
	int n,t;
	while(scanf("%d %d",&n,&t)!=EOF)
	{
		ans=0;
		for(int i=0;i<n;++i)		
			scanf("%d %d",&cow[i].beg,&cow[i].end);
		sort(cow,cow+n);
		tmp=cow[0];
		for(int j=1;j<n;++j)
		{
			tmp=w(cow[j],tmp);	
		}
	}
	return 0;
}