/******************
Judge   : NOJ
Problem : 1-Hello_World
Course  : Course0
discribe: give a string and then print "hello string"
Input   : s
Output  : Hello s	  
Solve   : IO

*******************/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
/*
int main()
{
	string s;
	while(cin>>s)
	{
		cout<<"Hello "<<s<<endl;
	}
	return 0;
}*/
#define MAX 99999
char s[MAX];
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		printf("Hello %s\n",s);
	}
	return 0;
}