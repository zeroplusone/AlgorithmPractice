/******************
Judge   : PKU
Problem : 1007-DNA_Sorting
Course  : Course1
discribe: m strings of n words
          every word larger than its right
		  sort string (from big to small)
Input   : n m
          d[0](string)
		  d[1]
		  .
		  .
		  d[m-1]
Output  : d[0](big)
          d[1]
          .
		  d[m-1](small)
Solve   : use setnum to count(violent)
          then use algorithm sort 
*******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,m,coun;

struct dna
{
	char data[60];
	int num;
	int rank;
	bool operator<(const dna& p)const
	{	
		return num==p.num ? rank<p.rank : num<p.num;
	}
}d[110];

int setnum(int i)
{
	coun=0;
	for(int j=0;j<n;++j)	
		for(int k=j+1;k<n;++k)		
			if(d[i].data[j]>d[i].data[k])
				coun++;
				
	return coun;
}

int main()
{
	
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=0;i<m;++i)
	{
		gets(d[i].data);
		d[i].num=setnum(i);
		d[i].rank=i;
	}
	sort(d,d+m);
	for(int i=0;i<m;++i)
		printf("%s\n",d[i].data);
	return 0;
}