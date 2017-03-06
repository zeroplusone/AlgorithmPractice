/******************
Judge   : UVA
Problem : 156-Ananagrams
Course  : Course2
discribe: give a string ,and then parse word to print word that appear once(includeing rerange)
Input   : string (end #)
Output  : word  
Solve   : set+map

*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define MAXS 100
#define MAXW 1100
char in[MAXS],ori[MAXS],small[MAXS];

int main()
{
	multiset<string> dic;
	map<string,string> to;
	int i,j,len;
	string so,ss;
	bool exit=false;
	while(gets(in))
	{
		char* pch;
		for(pch=strtok(in," \n\r");pch;pch=strtok(NULL," \n\r"))
		{
			if(!strcmp("#",pch))
			{
				exit=true;
				break;
			}
			strcpy(ori,pch);	
			strcpy(small,pch);			
			len=strlen(ori);			
			for(j=0;j<len;++j)
			{
				if(ori[j]>='A' && ori[j]<='Z')
					small[j]-='A'-'a';
			}
			sort(small,small+len);
			//printf("%s\n",w[i].small);
			ss=string(small);
			so=string(ori);
			dic.insert(ss);
			to[ss]=so;
			
		}
		if(exit)
			break;
	}
	set<string>::iterator itr;
	string ans[MAXW];
	j=0;
	for(itr=dic.begin();itr!=dic.end();itr++)
	{
		if(dic.count(*itr)<=1)
			//cout<<w[to[*itr]].ori<<endl;
			ans[j++]=to[*itr];
	}
	sort(ans,ans+j);
	for(i=0;i<j;++i)
		cout<<ans[i]<<endl;
	
	return 0;
}