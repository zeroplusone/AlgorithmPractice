/******************
Judge   : UVA
Problem : 604 - The Boggle Game
Course  : Course7
discribe:  each word contains exactly two vowels (y is consider a vowel in PigEwu)
			 reads a pair of Boggle boards and lists all PigEwu words that are common to both boards.
Input   : 	
			T U G I    B R E T
			O K J M    Y A P Q
			K M B E    L O Y R

			Z W A V    G S F U
			U N C O    A H F T
			Y T G I    G N A L
			H G P M    B O O B

			#
			
Output  : 	
			There are no common words for this pair of boggle boards.

			ANGO
			AOGN
			GNAO
			GOAN
			NAOG
			NGOA
			OANG
			OGNA
Solve   :	backtracking+set
*******************/
#include<bits/stdc++.h>
using namespace std;

#define SIZEN 4
char a[SIZEN][SIZEN],b[SIZEN][SIZEN];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool v[SIZEN][SIZEN];
char sol[SIZEN];
set<string> aset,ans;

bool isvow(char c)
{
	if(c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U'|| c=='Y')
		return true;
	else 
		return false;
}

void DFS(int now,int x,int y,int vow,int isb)
{
	if(now==4)
	{
		if(vow==2)
		{
			string s=string(sol);
			if(isb)
			{
				if(aset.count(s))
					ans.insert(s);
			}
			else
			{
				aset.insert(s);
			}
		}
		return;
	}
	
	int tx,ty;
	for(int i=0;i<8;++i)
	{
		tx=x+dir[i][0];	ty=y+dir[i][1];
		if( tx>=0 && tx <4 && ty >=0 && ty <4)
		{
			if(!v[tx][ty])
			{
				v[x][y]=true;
				sol[now]=isb==0?a[tx][ty]:b[tx][ty];
				if(isvow(sol[now]))
					DFS(now+1,tx,ty,vow+1,isb);
				else
					DFS(now+1,tx,ty,vow,isb);
				v[x][y]=false;
			}
		}
	}
	
}

int main()
{
	int i,j;
	char in;	
	bool blank=false;
	set<string>::iterator itr;
	while(scanf("%c",&a[0][0])!=EOF)
	{
		if(a[0][0]=='#')	break;
		getchar();
		
		aset.clear();	ans.clear();
		
		if(blank)	printf("\n");
		else	blank=true;
		
		for(i=0;i<SIZEN;++i)
		{
			for(j=0;j<SIZEN;++j)
			{
				if(i!=0 || j!=0)
				{
					scanf("%c",&a[i][j]);
					getchar();
				}
			}
			getchar();getchar();getchar();
			for(j=0;j<SIZEN;++j)
			{
				scanf("%c",&b[i][j]);
				getchar();
			}
		}
		getchar();
		memset(v,false,sizeof(v));
		for(i=0;i<SIZEN;++i)
		{
			for(j=0;j<SIZEN;++j)
			{
				v[i][j]=true;
				sol[0]=a[i][j];
				if(isvow(a[i][j]))
					DFS(1,i,j,1,0);				
				else
					DFS(1,i,j,0,0);
				v[i][j]=false;
			}
		}
		memset(v,false,sizeof(v));		
		for(i=0;i<SIZEN;++i)
		{
			for(j=0;j<SIZEN;++j)
			{
				v[i][j]=true;
				sol[0]=b[i][j];
				if(isvow(b[i][j]))
					DFS(1,i,j,1,1);				
				else
					DFS(1,i,j,0,1);
				v[i][j]=false;
			}
		}
		if(ans.empty())
			printf("There are no common words for this pair of boggle boards.\n");
		else
		{
			for(itr=ans.begin();itr!=ans.end();itr++)
				cout<<*itr<<endl;
		}
	}
	return 0;
}