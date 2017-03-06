#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 800
double r[MAX][2];
double w[MAX][MAX];
double d[MAX];
bool v[MAX];
int n;
 
void reset()
{
	memset(v,false,sizeof(v));
	for(int i=0;i<=n;++i)	d[i]=20001;
	memset(w,0,sizeof(w));
}
 
int main()
{
	int t,c,vv;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		reset();	vv=0;
		scanf("%d",&n);
		for(int j=1;j<=n;++j)
		{
			sacnf("%lf %lf",&r[j][0],&r[j][1]);
			for(int k=j-1;k>0;--k)
			{
				w[j][k]=w[k][j]=sqrt((r[j][0]-r[k][0])*(r[j][0]-r[k][0])+(r[j][1]-r[k][1])*(r[j][1]-r[k][1]));
			}
		}
		scanf("%d",&c);
		int aa,bb;
		for(int j=0;j<c;++j)
		{
			sacnf("%d %d",&aa,&bb);
			if(!v[aa]){	v[aa]=true;	vv++;	}
			if(!v[bb]){	v[bb]=true;	vv++;	}
		}
		
		for(;i<e;++i)
	    {
			int a=-1;		double min=20000;
			for(int j=0;j<e;++j)
			{
				if(!v[j] && d[j]<min)
				{				
					a=j;
					min=d[j];
					
				}			
			}
			ans+=min; 
		
			if(a==-1)	break;
			v[a]=true;
			
			for(int j=0;j<e;++j)
			{
				
				if(!v[j] && l[a][j] < d[j])
				{
					d[j]=l[a][j];
						
				}
			}
		}
		
	}
	return 0;
}