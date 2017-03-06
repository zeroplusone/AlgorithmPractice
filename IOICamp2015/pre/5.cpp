#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

stack<int> sta;
queue<int> que;
priority_queue<int> pque;

int main()
{
	int T,n;
	int t,x;
	bool isSta,isQue,isPq;
	scanf("%d",&T);
	while(T--)
	{
		isSta=true;	
		isQue=true;
		isPq=true;
		
		while(!sta.empty())	sta.pop();
		while(!que.empty())	que.pop();
		while(!pque.empty())	pque.pop();

		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&t,&x);
			if(isSta)
			{
				if(t==1)
					sta.push(x);
				else if(t==2 && !sta.empty())
				{
					if(sta.top()!=x)
						isSta=false;
					else
						sta.pop();
				}
				else
					isSta=false;
			}
			if(isQue)
			{
				if(t==1)
					que.push(x);
				else if(t==2 && !que.empty())
				{
					if(que.front()!=x)
						isQue=false;
					else
						que.pop();
				}
				else
					isQue=false;
			}
			if(isPq)
			{
				if(t==1)
					pque.push(x);
				else if(t==2 && !pque.empty())
				{
					if(pque.top()!=x)
						isPq=false;
					else
						pque.pop();
				}
				else
					isPq=false;
			}			
		}
			if(!isSta && !isQue && !isPq)
				printf("impossible\n");
			else if(isSta && !isQue && !isPq)
				printf("stack\n");
			else if(!isSta && isQue && !isPq)
				printf("queue\n");
			else if(!isSta && !isQue && isPq)
				printf("priority queue\n");
			else
				printf("not sure\n");
	
	}
	return 0;
}
