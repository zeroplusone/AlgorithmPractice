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
	scanf("%d",&n);

		lis.clear();
		for(int i=0;i<n;++i)
		{
			lis.clear();
			scanf("%d",&c);
			for(int j=0;j<c;++j)
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

