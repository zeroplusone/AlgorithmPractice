/******************
Judge   : UVA
Problem : 10954-Add_All
Course  : Course6
discribe: add numbers one by one
		  the cost of every step is the sum now
		  find the minimum cost
Input   : n
          num1 num2 num3
		  n
          num1 num2 num3
		  .
		  .
		  0
Output  : ans(minimum cost)
		  ans
		  ans
Solve   : every time add the min number now
          min-heap(priority queue)
*******************/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<queue>
using namespace std;

struct NODE
{
	int v;
	bool operator < (const NODE& in) const
	{
		return v>in.v; 
	}
};


int main()
{
	int n,t,ans;
	priority_queue<NODE> pq;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		ans=0;
		
		for(int i=0;i<n;++i)
		{
			NODE tmp;
			scanf("%d",&tmp.v);
			pq.push(tmp);	
		}
		while(1)
		{
			t=pq.top().v;
			pq.pop();
			//printf("(1)%d",t);
			if(!pq.empty())
			{
				t+=pq.top().v;
				//printf("(2)%d",t);
				pq.pop();
				NODE tmp2;
				tmp2.v=t;
				ans+=t;
				pq.push(tmp2);
			}
			else
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
