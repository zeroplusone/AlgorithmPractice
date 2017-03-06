/*
Sample Input

-7
10
9
2
3
8
8
1
Sample Output

4
-
-7
2
3
8

SOL:LIS~10萬筆資料-->第二種方法
*/
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

	lis.clear();	poi.clear();	num.clear();
	while(scanf("%d",&seq)!=EOF)
	{
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
	printf("%d\n-\n",ans);
	
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
	return 0;
}

