/******************
Judge   : POJ
Problem : 3481-Double_Queue
Course  : Course6
discribe: find which custom to serve
			0	The system needs to stop serving
			1 K P	Add client K to the waiting list with priority P
			2	Serve the client with the highest priority and drop him or her from the waiting list
			3	Serve the client with the lowest priority and drop him or her from the waiting lis
Input   : «ü¥O
Output  : the id of served custom
Solve   : binary search tree(set map)
*******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int code,k,p;
	set<int> pri;
	map<int,int> toid;
	set<int>::iterator itr;
	map<int,int>::iterator mitr;
	while(scanf("%d",&code)!=EOF)
	{
		if(code==0)	break;
		else if(code==1)
		{
			scanf("%d%d",&k,&p);
			pri.insert(p);
			toid[p]=k;
		}
		else
		{
			if(pri.empty())
				printf("0\n");
			else
			{
				if(code==2)		
				{
					itr=pri.end();
					itr--;
				}
				if(code==3)			
					itr=pri.begin();
				
				cout<<toid[*itr]<<endl;
				mitr=toid.find(*itr);
				pri.erase(itr);			
				toid.erase(mitr);
			}
		}
		
	}
	return 0;
}