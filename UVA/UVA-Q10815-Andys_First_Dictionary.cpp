/******************
Judge   : UVA
Problem : 10815-Andys_First_Dictionary
Course  : Course2
discribe: give lines of string and then parese word and sort by lex(big all turn to small)
Input   : string 
Output  : word0
          word1
		  .
		  .
		  wordn
Solve   : set

*******************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	string get;	
	set<string> dic;
	int count=0;
	while(getline(cin,get))
	{
		for(int i=0;i<get.length();++i)
		{
			string g;
			while((get[i]<='z' && get[i]>='a') || (get[i]<='Z' && get[i]>='A') )
			{
				if(get[i]<='Z' && get[i]>='A')				
					get[i]=get[i]-'A'+'a';	
				g=g+get[i];				
				i++;
			}
			if(g!="")
			{
				dic.insert(g);
			}
		}		
	}
	set<string> :: iterator itr;
	for(itr=dic.begin();itr!=dic.end();++itr)
		cout<<*itr<<endl;
	
	return 0;
}