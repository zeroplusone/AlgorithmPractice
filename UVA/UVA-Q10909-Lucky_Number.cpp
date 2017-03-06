/******************
Judge   : UVA
Problem : 10909 - Lucky Number
Course  : Course6
discribe:  whether a number can be written as the sum of two lucky numbers.sum of the integers. Your task is to find the k smallest sums among them.
			strike out all even ones
			The second number is 3, next strike out every third number
			The third number is 7, next strike out every seventh number 
			process infinite
Input   : 	n
			n
			.
Output  : 	n is not the sum of two luckies!
			n is the sum of L1 and L2.
Solve   :	binary serach tree
*******************/
#include<bits/c++std.h>
using namespace std;

#define MAXN 2000100
struct NODE
{
	int val,rank;
}bst[MAXN];

int main()
{
	make();
}