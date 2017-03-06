/******************
Judge   : UVA
Problem : 501 - Black Box
Course  : Course6
discribe: ADD(x): put element x into Black Box;
		  GET: increase i by 1 and give an i-minimum out of all integers containing in the Black Box.
Input   : 
			1	//k(case)

			7 4	//n(add) m(get)
			3 1 -4 2 8 -1000 2 //add
			1 2 6 6 //get position
Output  : 
			3
			3
			1
			2
Solve   : binary search
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 30100
int b[MAXN];

int main()
{
	int k,n,m;
	int i,now,get,ii;
	vector<int> box;
	vector<int>::iterator itr;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&m);
		
		box.clear();
		
		for(i=0;i<n;++i)
			scanf("%d",&b[i]);
		now=0;	ii=0;
		
		for(i=0;i<m;++i)
		{
			scanf("%d",&get);
			while(now<get)
			{
				itr=lower_bound(box.begin(),box.end(),b[now]); //find position to add(bst by vector)
				box.insert(itr,b[now]);
				now++;
			}
			printf("%d\n",box[ii++]);
		}
		if(k)
			printf("\n");
	}
	return 0;
}