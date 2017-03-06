/******************
Judge   : POJ
Problem : 1182-food_chain
Course  : Course8
discribe: 
		"1 X Y"，表示X和Y是同類。 
		是"2 X Y"，表示X吃Y。 
		此人對N個動物，用上述兩种說法，一句接一句地說出K句話，這K句話有的是真的，有的是假的。
		假話條件
		1）	?前的?与前面的某些真的??突，就是假?； 
		2）	?前的?中X或Y比N大，就是假?； 
		3）	?前的?表示X吃X，就是假?。
Input   : 
			100 7
			1 101 1 
			2 1 2
			2 2 3 
			2 3 3 
			1 1 3 
			2 3 1 
			1 5 5
Output  : 
			3 //#假話
Solve   : disjoint set
*******************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int in,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0 )	break;
		while(m--)
		{
			scanf("%d%d%d",&in,&a,&b);
		}
	}
	return 0;
}