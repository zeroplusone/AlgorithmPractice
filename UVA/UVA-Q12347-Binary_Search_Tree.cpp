/******************
Judge   : UVA
Problem : 12347 - Binary Search Tree
Course  : Course6
discribe:  Given the pre-order traversal of a binary search tree, you task is to find the post-order traversal of this tree.
Input   : 	
			50
			30
			24
			5
			28
			45
			98
			52
			60
Output  : 	
			5
			28
			24
			45
			30
			60
			52
			98
			50
Solve   :	binary search tree
*******************/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10100
int t[MAXN];
int n;
void post(int s,int e)
{
	if(s==e)	return;
	
	int mid=t[s],r=e;
	for(int i=s+1;i<e;++i)
	{
		if(t[i]>mid)
		{	
			r=i;
			break;
		}
	}
	post(s+1,r);	//left
	post(r,e);	//right
	printf("%d\n",mid);	//mid
}

int main()
{
	n=1;
	while(scanf("%d",&t[n])!=EOF)	n++;
	post(1,n);		
	return 0;
}
