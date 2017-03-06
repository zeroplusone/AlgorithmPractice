/******************
Judge   : UVA
Problem : 1872-Ordering
Course  : Course7
discribe: print all the possible of permutation with these constraints
Input   : 	1		//t(case)

			A B F G // alph
			A<B B<F //constraints
Output  : 	A B F G
			A B G F
			A G B F
			G A B F
(If no ordering is possible,output NO.)		  
Solve   : backtracking
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 30
int order[MAX];
int to[MAX];
int r[MAX][MAX];
int ans[MAX];
bool used[MAX];
char in[50];
int ya;

void find(int k,int num)
{
	if(k==num)
	{		
		printf("%c",'A'+order[ans[0]]);
		for(int i=1;i<num;++i)
			printf(" %c",'A'+order[ans[i]]);
		printf("\n");
		ya=1;
	}
	else
	{
		for(int i=0;i<num;++i)
		{
			if(!used[i])
			{
				bool ok=true;
				for(int j=0;j<k;++j)
				{
					if(r[ans[j]][i]==1)
					{
						ok=false;
						break;
					}
				}
				if(ok)
				{
					used[i]=true;
					ans[k]=i;
					find(k+1,num);
					used[i]=false;
				}
			}	
		}
	}
}

int main()
{
	int n,number,t1,t2;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();	
		for(int ii=0;ii<n;++ii)
		{
				
			getchar();
			
			if(ii!=0)
				printf("\n");
			
			memset(r,0,sizeof(r));
			memset(order,0,sizeof(order));
			memset(to,0,sizeof(to));
			memset(ans,0,sizeof(ans));
			memset(used,false,sizeof(used));
			ya=0;
			
			gets(in);
			number=0;
			for(int i=0;i<strlen(in);i=i+2)
			{	
				order[number]=in[i]-'A';
				number++;
			}
			sort(order,order+number);
			
			for(int i=0;i<number;++i)
			{
				to[order[i]]=i;				
			}
			for(int i=0;i<number;++i)
				r[i][i]=1;
			
			gets(in);
			for(int i=0;i<strlen(in);i=i+4)
			{	
				t1=to[in[i+2]-'A'];
				t2=to[in[i]-'A'];

				r[t1][t2]=1;

			}

			find(0,number);
			if(ya==0)
				printf("NO\n");
		}
	}
	return 0;
}