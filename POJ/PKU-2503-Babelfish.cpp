/******************
Judge   : POJ
Problem : Babelfish
Course  : Course2
discribe: translate foreign to english
Input   : fore eng
		  fore eng
		  .
		  .
		  fore eng
		  /n
		  fore
		  fore
		  fore
		  .
		  .
Output  : eng
		  eng
		  .
		  .
		  ans
Solve   : map
*******************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;

#define MAXW 15
char f[MAXW],e[MAXW];
char in[3*MAXW]; 

int main()
{
	map<string,string> to;
	string ee,ff;
	while(gets(in))
	{
		if(!strcmp(in,""))	break;
		sscanf(in,"%s %s",e,f);
		ee=string(e);	ff=string(f);
		to[ff]=ee;
	}
	while(gets(f))
	{
		ff=string(f);
		if(to.count(ff))
			printf("%s\n",to[ff].c_str());
		else
			printf("eh\n");
	}
	
	return 0;
}
