/******************
Judge   : UVA
Problem : 10420 - List of Conquests
Course  : Course2
discribe: sort and count how many girl in each country 
Input   : n
		  country name
		  country name
		  .
		  .
Output  : country num
		  country num
		  .
		  .
Solve   : multiset
*******************/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

#define MAXN 100
char in[MAXN];
char cut[MAXN];

int main()
{
	int n;
	map<string,int> coun;
	while(scanf("%d\n",&n)!=EOF)
	{
		coun.clear();
		while(n--)
		{
			gets(in);
			sscanf(in,"%s",cut);
			coun[string(cut)]++;
		}
		
		map<string,int>::iterator itr;
		for(itr=coun.begin();itr!=coun.end();++itr)
		{
			cout<<itr->first<<" "<<itr->second<<endl;
		}
	}
}