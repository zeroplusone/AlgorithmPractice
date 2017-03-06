#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> lis;
vector<int> poi;
vector<int> num;


int main()
{	
	int seq;
	vector<int>::iterator low,i;
	int c;
	string s;
	scanf("%d",&c);	getchar();getchar();
	for(int ii=0;ii<c;++ii)
	{
		if(ii!=0)
			printf("\n");
		lis.clear();	poi.clear();	num.clear();
		while(getline(cin,s))
		{
			if(s=="")
				break;
			seq=0;
			for(int i=0;i<s.size();++i)
				seq=seq*10+(s[i]-'0');
				
			num.push_back(seq);
			if(lis.empty())
			{
				lis.push_back(seq);
				poi.push_back(1);
			}
			else
			{
				if(lis.back()<seq)
				{
					lis.push_back(seq);
					poi.push_back(lis.size());
				}
				else if(lis.back()>=seq)
				{	
					low=lower_bound(lis.begin(),lis.end(),seq);
					*low=seq;
					poi.push_back(low-lis.begin()+1);
					//比n大一點的位置->by binary search tree							
				}
			}
		}
		int ans=lis.size();
		printf("Max hits: %d\n",ans);
		
		int j=ans;
		stack<int> a;

		for(i=poi.end();i>=poi.begin() && j>0;--i)
		{
			if(*i==j)
			{
				a.push(num[i-poi.begin()]);
				j--;
			}

		}
		while(!a.empty())
		{
			printf("%d\n",a.top());
			a.pop();
		}
	}
	return 0;
}

