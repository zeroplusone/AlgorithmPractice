/******************
Judge   : POJ
Problem : 2371-Questions_and_answers
Course  : Course1
discribe: 3 people fine the money in the middle
Input   : n
		  data0
		  data1
		  .
		  datan-1
		  ###
		  K
		  ele0
		  ele1
		  .
		  elek-1
Output  : data[ele0]
		  data[ele1]
		  .
		  data[elen-1]
Solve   : sort
*******************/
/*
Sample Input
5   (n個)             //data
7
121
123
7
121
###
4   (k個)             //i
3
3
2
5

Sample Output
121                      //sort後印出第i個數字
121
7
123
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 100010
int data[MAX];

int compare(const void* a,const void* b)
{	return *(int*)a-*(int*)b;	}

int main()
{
	int n,k,ele;
	string s;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&data[i]);
	getchar();
	getline(cin,s);	
	qsort(data,n,sizeof(int),compare);
	scanf("%d",&k);
	for(int i=0;i<k;++i)
	{	
		scanf("%d",&ele);
		printf("%d\n",data[ele-1]);
	}	
	return 0;
}