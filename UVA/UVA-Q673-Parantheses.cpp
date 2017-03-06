/******************
Judge   : UVA
Problem : 673-Parantheses
Course  : Course2
discribe: give a seqence and judge its correct
	correct:
		(a)if it is the empty string
		(b)if A and B are correct, AB is correct,
		(c)if A is correct, (A) and [A] is correct.
Input   : N
          s
		  s
		  s
		  .
		  .
		  s
Output  : yes or no		  
Solve   : stack(push left and then chesk right to pop)

*******************/
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n=0;
	scanf("%d",&n);
	string s;
	int flag=0;
	getchar();
	stack <char> a;    
	for(int j=0;j<n;++j)
	{
		
		flag=0;
		getline(cin,s);
		if(s=="")
		{
			cout<<"Yes"<<endl;
			while(!a.empty())a.pop();
			continue;
		}

		for(int i=0;i<s.length();++i)
		{
			
			if(s[i]=='(' || s[i]=='[')
			{
				a.push(s[i]);				
			}
			else if(!a.empty())
			{
				if(s[i]==')')
				{
					if(a.top()!='(' )
					{							
						flag=1;					
						break;
					}
					else
					{
						a.pop();
						
					}
				}
				else if(s[i]==']' )
				{
					if(a.top()!='[')
					{	
						
						flag=1;					
						break;
					}
					else
					{
						a.pop();
						continue;
					}
				}
				else
				{
					flag=1;
					break;
				}
				
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(!a.empty())
			flag=1;		
		if(flag==0)
			printf("Yes\n");
		else
			printf("No\n");
			
		while(!a.empty())a.pop();
	}
	return 0;
}