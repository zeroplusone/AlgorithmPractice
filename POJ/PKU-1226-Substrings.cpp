/******************
Judge   : poj
Problem : 1226-Substrings
Course  : Course17
discribe:   find the largest string X, such that either X, or its inverse can be found as a substring of any of the given strings.
			 string of minimum length 1 and maximum length 100.
Input   :
			2	//case
			3	//n #string 1~10
			ABCD
			BCDFF
			BRCD
			2
			rose
			orchid
Output	:
			2
			2
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 110
int pi[MAXN];
char w[MAXN],t[MAXN],tmp[MAXN];
char in[MAXN][MAXN];
int ans,n,ind,ya;
bool used[MAXN];

void buildPi()
{	
	int i,j,len;
	len=strlen(w+1);
	memset(pi,0,(len+1)*sizeof(int));
	pi[1]=0;	j=0;
	for(i=2;i<=len;++i)
	{
		while(j>0 && w[j+1]!=w[i])
		{
			j=pi[j];
		}

		if(w[j+1]==w[i])
			j++;
		pi[i]=j;

	}
}

void KMP()
{
	int i,j,k;
	int lent;
	int lenw=strlen(w+1);

	for(k=0;k<n;++k)
	{		

		if(k!=ind)
		{			
			strcpy(t+1,in[k]);
			lent=strlen(t+1);
			//printf("~%s\n",t+1);
			j=0;
			for(i=1;i<=lent;++i)
			{
				while(j>0 && t[i]!=w[j+1])
				{
					j=pi[j];
				}
					
				if(t[i]==w[j+1])
					j++;
				//printf("%d %d %d\n",i,j,lenw);
				if(j==lenw)
				{
					if(!used[k])
					{
						//printf("%s\n",t+1);
						used[k]=true;
						ya++;
					}
					j=pi[j];
					
					break;
				}
			}
		}
		else
			continue;
		
	}
}

int main()
{
	int tt,i,j,k,minl,len;
	scanf("%d",&tt);
	while(tt--)
	{
		minl=MAXN;	ind=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			getchar();
			scanf("%s",in[i]);
			len=strlen(in[i]);
			if(minl>len)
			{
				minl=len;
				ind=i;
			}
		}
		ans=-1;
		for(i=minl;i>=1;--i)
		{
			for(j=0;j<=minl-i;++j)
			{
				for(k=0;k<n;++k)	used[k]=false;
				ya=0;
				strncpy(w+1,in[ind]+j,i);
				w[i+1]=0;
				//printf("%d %d %s\n",i,j,w+1);
				buildPi();
				KMP();
				
				strcpy(tmp,w+1);
				for(k=0;k<i;++k)
					w[k+1]=tmp[i-k-1];
				//printf("%d %d %s\n",i,j,w+1);
				buildPi();				
				KMP();

				if(ya==n-1)
				{
					ans=i;
					break;
				}
			}
			if(ans!=-1)	break;
		}
		if(ans==-1)
			ans=0;
		printf("%d\n",ans);
	}
	return 0;
}