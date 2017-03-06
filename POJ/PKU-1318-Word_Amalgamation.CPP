/******************
Judge   : POJ
Problem : 1318-Word_Amalgamation.CPP
Course  : Course1
discribe: find the same word in dictionary

Solve   : sort every word then compare
*******************/
/*
Sample Input

tarp         字典裡的字
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco		要找的字
nfudre
aptr
sett
oresuc
XXXXXX
--------------------------
Sample Output

score       和要找的字母一樣(順序可不同)
******
refund
******
part
tarp
trap
******
NOT A VALID WORD    //沒找到
******
course
******
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
using namespace std;

#define MAX 110
#define MAX_word 7 // at least one and at most six characters long.->不能開6

char s[MAX][MAX_word];
char save[MAX][MAX_word];
char ans[MAX_word];
set<string>  dic;

int compare(const void* a,const void* b)
{
	return *(char*)a-*(char*)b;
}

int main()
{
	int i=-1,flag;
	string g;
	do
	{
		i++;
		gets(s[i]);		
		strcpy(save[i],s[i]);	
		qsort(s[i],sizeof(char)*strlen(s[i]),sizeof(char),compare);		
	}while(strcmp(save[i],"XXXXXX"));	
	
	do
	{		
		gets(ans);
		if(!strcmp(ans,"XXXXXX"))
			break;
		flag=0;
		qsort(ans,strlen(ans)*sizeof(char),sizeof(char),compare);
		dic.clear();
		for(int j=0;j<i;++j)	
		{
			
			if(!strcmp(ans,s[j]))
			{	
				g=string(save[j]);				
				dic.insert(g);
				flag=1;
			}
		}
		
		if(dic.size()==0)
		{	
			printf("NOT A VALID WORD\n");
		}
		else
		{
			set<string> :: iterator itr;
			for(itr=dic.begin();itr!=dic.end();++itr)
				cout<<*itr<<endl;
		}
		printf("******\n");		
	}while(1);
	
	return 0;
}