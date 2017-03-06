/******************
Judge   : uva
Problem : 259 - Software Allocation
Course  : Course13
discribe:  the computers are not multi-tasking, so each computer must handle at most one application in total. (An application takes a day to complete, so that sequencing i.e. one application after another on the same machine is not possible.)

			A job description consists of

			1.one upper case letter A...Z, indicating the application.
			2.one digit 1...9, indicating the number of users who brought in the application.
			3.a blank (space character.)
			4.one or more different digits 0...9, indicating the computers on which the application can run.
			5.a terminating semicolon `;'.
			6.an end-of-line.
Input   :
			A4 01234;
			Q1 5;
			P4 56789;

			A4 01234;
			Q1 5;
			P5 56789;
Output  :
			AAAA_QPPPP
			!
Solve   : bipartite matching
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 110

int mx[MAXN],my[MAXN];
bool used[MAXN];
int edge[MAXN][MAXN];	//left right

char xChar[100];
int n,all;

bool DFS(int now,int ny)
{
	int i,next;
	for(i=0;i<ny;++i)
	{
		if(edge[now][i] && !used[i])
		{
			used[i]=true;
			if(my[i]==-1 || DFS(my[i],ny))
			{
				mx[now]=i;
				my[i]=now;
				return true;
			}
		}
	}
	return false;
}

int bipartite(int nx,int ny)
{
	int i,ans=0;
	for(i=0;i<nx;++i)
		mx[i]=-1;
	for(i=0;i<ny;++i)
		my[i]=-1;

	for(i=0;i<nx;++i)
	{
		memset(used,false,(ny+1)*sizeof(bool));
		if(DFS(i,ny))	++ans;
	}
	return ans;
}
void answer()
{
	int i;
	if(bipartite(n,10)==all)
			{
				for(i=0;i<10;++i)
				{
					if(my[i]==-1)
						printf("_");
					else
						printf("%c",xChar[my[i]]);
				}
				printf("\n");
			}
			else
				printf("!\n");
}

int main()
{
	char in[100],*com,*tmpc;

	char now,*ptr,token[]=" ;";
	int i,j,tmp,tmpl;
	memset(edge,0,sizeof(edge));
	n=0;	all=0;
	while(gets(in))
	{
		if(!strcmp(in,""))
		{
			answer();
			memset(edge,0,sizeof(edge));
			n=0;	all=0;
			continue;
		}
		tmpc=strtok(in,token);
		now=tmpc[0];
		tmp=0;	tmpl=strlen(tmpc);
		for(i=1;i<tmpl;++i)
			tmp=tmp*10+tmpc[i]-'0';
		all+=tmp;
		com=strtok(NULL,token);
		tmpl=strlen(com);
		for(i=0;i<tmp;++i)
		{
			xChar[n]=now;
			for(j=0;j<tmpl;++j)
				edge[n][com[j]-'0']=1;


			n++;
		}
	}
	answer();
	return 0;
}
