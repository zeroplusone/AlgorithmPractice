#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int hashvalue(vector<vector<int> > snow[])
{
	int t1,t2,t3;
	t1=snow[0] & snow[3];
	t2=snow[1] & snow[4];
	t3=snow[2] & snow[5];
	
	return t1^t2^t3;
}

int com(vector<vector<int> > a,vector<int> b[])
{
	int same;
	for(int i=0;i<6;++i)
		if(b[i]==a[0])
			same=i;
	int check=0;
	for(int j=1;j<6;++j)
	{
		if(a[j]!=b[(same+j)%6])
		{
			check=1;
			break;
		}
	}
	if(!check)
		return 1;
	else
		check=0;
	for(int j=1;j<6;++j)
	{
		if(a[j]!=b[(6+same-j)%6])
		{
			check=1;
			break;
		}
	}
	if(check)
		return 0;
	else
		return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	vector<vector<int> > snow(6, vector<int>(n));
	vector<int> hash(n,0);
	
	for(int i=0;i<n;++i)	
		for(int j=0;j<6;++j)
			scanf("%d",&snow[i][j]);
	
	for(int k=0;k<n;++k)
		hash[k]=hashvalue(snow);

	int flag=0;	
	sort(hash,hash+n);
	int num=hash[0];
	int start=0;
	int end;
	for(int l=1;l<n;++l)
	{
		while(hash[l]==num && l!=n)
			l++;
		end=l-1;
		//printf("%d %d\n",start,end);
		for(int m=start;m<=end;++m)
		{
			for(int n=m+1;n<=end;++n)
			{
				flag=com(snow[m],snow[n]);
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			break;
		start=l;
		num=hash[start];
	}
	if(flag==1)
		printf("Twin snowflakes found.");
	else
		printf("No two snowflakes are alike.");
	return 0;
}