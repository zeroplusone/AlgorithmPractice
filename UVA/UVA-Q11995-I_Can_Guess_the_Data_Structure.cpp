/******************
Judge   : UVA
Problem : 11995 - I Can Guess the Data Structure!
Course  : Course6
discribe:  
			1 x
			Throw an element x into the bag.
			2
			Take out an element from the bag.
			 guess the data structure(stack (Last-In, First-Out), a queue (First-In, First-Out), a priority-queue (Always take out larger elements first))
Input   : 	
			6	//n
			1 1
			1 2
			1 3
			2 1
			2 2
			2 3
			6
			1 1
			1 2
			1 3
			2 3
			2 2
			2 1
			2
			1 1
			2 2
			4
			1 2
			1 1
			2 1
			2 2
			7
			1 2
			1 5
			1 1
			1 3
			2 5
			1 4
			2 4
Output  : 	
			queue
			not sure
			impossible
			stack
			priority queue
Solve   :	stl
*******************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	int a,b;
	stack<int> s;
	queue<int> q;
	priority_queue<int> p;
	bool ans[3];
	int num;
	while(scanf("%d",&n)!=EOF)
	{
		while(!s.empty())	s.pop();
		while(!q.empty())	q.pop();
		while(!p.empty())	p.pop();
		memset(ans,true,sizeof(ans));

		while(n--)
		{
			scanf("%d%d",&a,&b);
			if(a==1)
			{	
				s.push(b);
				p.push(b);
				q.push(b);
			}
			else
			{
				if(ans[0] && !s.empty())
				{
					if(s.top()!=b)	ans[0]=false;
					else	s.pop();
				}
				else	ans[0]=false;	
				if(ans[1] && !q.empty())
				{
					if(q.front()!=b)	ans[1]=false;
					else	q.pop();
				}
				else	ans[1]=false;
				if(ans[2] && !p.empty())
				{
					if(p.top()!=b)	ans[2]=false;	
					else	p.pop();
				}
				else	ans[2]=false;
			}			
		}
		for(i=0,num=0;i<3;++i)	if(ans[i])	num++;
		if(num==0)	printf("impossible\n");
			else if(num>1)	printf("not sure\n");
			else
			{
				if(ans[0])	printf("stack\n");
				else if(ans[1])	printf("queue\n");
				else if(ans[2])	printf("priority queue\n");
			}
	}
	return 0;
}