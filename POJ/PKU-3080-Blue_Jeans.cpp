/******************
Judge   : poj
Problem : 3080-Blue Jeans
Course  : Course17
discribe:   Given a set of DNA base sequences, determine the longest series of bases that occurs in all of the sequences.
Input   :
			3
			2
			GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
			AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
			3
			GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
			GATACTAGATACTAGATACTAGATACTAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
			GATACCAGATACCAGATACCAGATACCAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
			3
			CATCATCATCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
			ACATCATCATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
			AACATCATCATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
Output	:
			
			no significant commonalities
			AGATAC
			CATCATCAT
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXN 80
int pi[MAXN];
char w[MAXN],t[MAXN],tmp[MAXN];
char in[MAXN][MAXN];
int ans,n,ya;
bool used[MAXN];
set<string> answer;
vector<string> aa;
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
	
	for(k=1;k<n;++k)
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
						//printf("%s\n",t+1);
					ya++;
					j=pi[j];
					
					break;
				}
			}
		
	}
}

int main()
{
	int tt,i,j,k,len;
	string s;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			getchar();
			scanf("%s",in[i]);
			len=strlen(in[i]);
		}
		ans=-1;
		for(i=60;i>=1;--i)
		{
			answer.clear();
			aa.clear();
			for(j=0;j<=60-i;++j)
			{
				for(k=0;k<n;++k)	used[k]=false;
				ya=0;
				strncpy(w+1,in[0]+j,i);
				w[i+1]=0;
				//printf("%d %d %s\n",i,j,w+1);
				buildPi();
				KMP();

				if(ya==n-1)
				{
					s=string(w+1);
					answer.insert(s);
					aa.push_back(s);
					
				}
			}
			sort(aa.begin(),aa.end());
			if(aa.size()!=0)
			{	
				if(i<3)
					printf("no significant commonalities\n");
				else
				{
					cout<<aa[aa.size()-1]<<endl;	
					//cout<<*(answer.end()-1)<<endl;
				}
				break;
			}
		}
	}
	return 0;
}