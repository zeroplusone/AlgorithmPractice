/******************
Judge   : UVA
Problem : 10098 - Generating Fast
Course  : Course2
discribe: print all the possible of permutation
Input   : n
		  s
		  s
		  .
		  . *n
Output  : ans

		  ans
		  
		  ans
		  
Solve   : sort SET MAP
*******************/
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int n,len;
	char in[15],*stl;
	while(scanf("%d\n",&n)!=EOF)
	{
		while(n--)
		{
			gets(in);
			len=strlen(in);
			stl=in+len;
			sort(in,in+len);
			do
			{
				printf("%s\n",in);
			}while(next_permutation(in,stl));
			printf("\n");
		}
		
	}
	return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
 
char in[15],sol[15];
bool used[15];

void per(int k,int n)
{
	int i;
	if(k==n)
	{
		for(i=0;i<n;++i)
			printf("%c",sol[i]);
		printf("\n");
	}
	else
	{
		char last='\0';
		for(i=0;i<n;++i)
		{
			if(!used[i] && last!=in[i])	//because string is sorted
			{                           //do not do the same recursion
				used[i]=true;
				sol[k]=in[i];
				last=in[i];
				per(k+1,n);
				used[i]=false;
			}
		}
	}
}

int main()
{
	int n,len;

	while(scanf("%d\n",&n)!=EOF)
	{
		while(n--)
		{
			gets(in);
			len=strlen(in);
			memset(used,false,sizeof(used));
			sort(in,in+len);
			per(0,len);
			printf("\n");
		}
		
	}
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
 
char in[15],sol[15];
bool used[15];

set<string> ans;
void per(int k,int n)
{
	int i;
	if(k==n)
	{

		ans.insert(string(sol));
	}
	else
	{

		for(i=0;i<n;++i)
		{
			if(!used[i])	
			{                      
				used[i]=true;
				sol[k]=in[i];
				per(k+1,n);
				used[i]=false;
			}
		}
	}
}

int main()
{
	int n,len;
	set<string>::iterator itr;
	while(scanf("%d\n",&n)!=EOF)
	{
		ans.clear();
		while(n--)
		{
			gets(in);
			len=strlen(in);
			memset(used,false,sizeof(used));
			per(0,len);
			
			for(itr=ans.begin();itr!=ans.end();++itr)
				cout<<*itr<<endl;
			printf("\n");	
		}
		
	}
	return 0;
}*/