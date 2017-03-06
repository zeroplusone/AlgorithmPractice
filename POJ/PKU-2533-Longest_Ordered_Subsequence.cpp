/******************
Judge   : POJ
Problem : PKU-2533-Longest_Ordered_Subsequence.cpp
Course  : Course9
discribe: lis size
			
Input   : 
			7	//n
			1 7 3 5 9 4 8 //array
Output  : 
			4
Solve   : LIS
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> lis;


int main()
{	
	int n,c;
	int seq,now,flag;
	while(scanf("%d",&n)!=EOF)
	{
		lis.clear();
		for(int i=0;i<n;++i)
		{
			
				scanf("%d",&seq);
				if(lis.empty())
					lis.push_back(seq);
				else
				{
					if(lis.back()<seq)
						lis.push_back(seq);
					else if(lis.back()>seq)				
						*lower_bound(lis.begin(),lis.end(),seq)=seq;
					//比n大一點的位置->by binary search tree
								
				}	
			
		}
		printf("%d\n",lis.size());
	}
		

	return 0;
}

