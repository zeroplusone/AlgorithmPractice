/******************
Judge   : POJ
Problem : 2255-Tree_Recovery
Course  : Course6
discribe: give pre and in order tree and output post order tree 
Input   : pre in
		  pre in
		  .
		  .
Output  : post
		  post
		  .
		  .
Solve   : binary tree
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>  //POJ~這個才會過
using namespace std;

string pre,in;

void post(string pre,string in)
{
	int t,size=in.size();
	if(size==1)
	{	
		printf("%c",in[0]);
		return;
	}

	
	for(int i=0;i<size;++i)
		if(in[i]==pre[0])
			t=i;
	if(t!=0)
		post(pre.substr(1,t),in.substr(0,t));
	if(size-t-1!=0)	
		post(pre.substr(t+1,size-t-1),in.substr(t+1,size-t-1));
	printf("%c",in[t]);
	
}

int main()
{	
	while(cin>>pre>>in)
	{
		post(pre,in);
		printf("\n");
	}
	return 0;
}