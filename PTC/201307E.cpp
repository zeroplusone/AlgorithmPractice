#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 10000
struct rule
{
	int num[4];
	int bull;
	int cow;
}in[MAX];

int ans,all;
int solution[4]; // a candidate 
bool used[10]; // constraint 

void check(int a,int b,int c,int d)
{
	bool pass=true;
	int test[4];
	test[0]=a;test[1]=b;test[2]=c;test[3]=d;
	int bullt,cowt;
	for(int i=0;i<all;++i)
	{
		bullt=0;	cowt=0;
		for(int j=0;j<4;++j)
			if(test[j]==in[i].num[j])
				bullt++;
		
		for(int j=0;j<4;++j)
		{
			for(int k=0;k<4;++k)
			{
				if(j!=k)
				{
					if(test[j]==in[i].num[k])
						cowt++;
				}
			}
		}
		if(bullt==in[i].bull && cowt==in[i].cow)
			continue;
		else
		{
			pass=false;
			break;
		}
	}
	if(pass)
	{
		/*for(int i=0;i<4;++i)
			printf("%d",test[i]);
		printf("\n");*/
		ans++;
	}
}

void backtracking(int k,int end, int n) //the kth dimension 
{ 
	if (k == end) // it's a solution 		
		check(solution[0],solution[1],solution[2],solution[3]);
		
	else 
	{ 
		for (int i=0; i<n; i++) 
		{
			if (!used[i])
			{ 
				used[i] = true; // set constraint 
				solution[k] = i; // set solution 
				backtracking(k+1,end, n); // recursive 
				used[i] = false; // back up the constraint 
			} 
		}
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	char input[10];
	while(n--)
	{
		all=0;	ans=0;
		while(scanf("%s",input))
		{
			if(input[0]=='-')
				break;	
			for(int i=0;i<4;++i)			
				in[all].num[i]=input[i]-'0';
			in[all].bull=input[4]-'0';
			in[all].cow=input[5]-'0';
			all++;
		}
		memset(used,false,sizeof(used));
		backtracking(0,4,10);
		printf("%d\n",ans);
	}
	return 0;
}