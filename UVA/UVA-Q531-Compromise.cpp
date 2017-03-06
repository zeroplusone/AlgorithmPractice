/******************
Judge   : UVA
Problem : UVA-Q531-Compromise.cpp
Course  : Course9
discribe: LCS
			
Input   : 
//s1		die einkommen der landwirte
			sind fuer die abgeordneten ein buch mit sieben siegeln
			um dem abzuhelfen
			muessen dringend alle subventionsgesetze verbessert werden
			#
//s2		die steuern auf vermoegen und einkommen
			sollten nach meinung der abgeordneten
			nachdruecklich erhoben werden
			dazu muessen die kontrollbefugnisse der finanzbehoerden
			dringend verbessert werden
			#
Output  : 
			die einkommen der abgeordneten muessen dringend verbessert werden
Solve   : LCS
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

#define MAX 120
string s1[MAX];
string s2[MAX];
int lcs[MAX][MAX];
int p[MAX][MAX];
int c1,c2;
char c[50];

int main()
{	
	c1=0;	c2=0;
	while(scanf("%s",c)!=EOF)
	{
		s1[c1]=string(c);
		do
		{
			if(s1[c1]=="#")
				break;
			c1++;
		}while(cin>>s1[c1]);
		cin>>s2[c2];
		do
		{
			if(s2[c2]=="#")
				break;
			c2++;
		}while(cin>>s2[c2]);
		getchar();
		
		for(int i=0;i<=c1;++i)
		{
			for(int j=0;j<=c2;++j)
			{	
				lcs[i][j]=0;
				p[i][j]=0;
			}
		}
		for(int i=0;i<c1;++i)
		{
			for(int j=0;j<c2;++j)
			{
				if(s1[i]==s2[j])
				{
					lcs[i+1][j+1]=lcs[i][j]+1;
					p[i+1][j+1]=0; //  
				}
				else if(s1[i]!=s2[j])
				{
					lcs[i+1][j+1]=lcs[i][j+1]>lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
					p[i+1][j+1]=lcs[i][j+1]>lcs[i+1][j]?1:2; // ¡ô ¡ö
				}

			}
		}
		stack<string> a;
		int i,j;
		for(i=c1-1,j=c2-1;i>=0 && j>=0;)
		{
			
				if(p[i+1][j+1]==0)
				{
					a.push(s1[i]);
					i--;	j--;
				}
				else if(p[i+1][j+1]==1)
				{
					i--;
				}
				else if(p[i+1][j+1]==2)
				{
					j--;
				}
				
			
		}
		bool first=true;
		while(!a.empty())
		{
			if(first)	first=false;
			else	printf(" ");
			cout<<a.top();
			a.pop();
		}
		printf("\n");
		c1=0;	c2=0;
	}
	return 0;
}

