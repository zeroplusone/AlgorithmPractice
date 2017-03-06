/******************
Judge   : UVA
Problem : 291 - The House Of Santa Claus
Course  : Course7
discribe:  all the possibilities when starting in the lower left corner( increasing order)
Input	: 	no
			graph:    
				house[1][2] = house[2][1] = 1;
				house[1][3] = house[3][1] = 1;
				house[1][5] = house[5][1] = 1;
				house[2][3] = house[3][2] = 1;
				house[2][5] = house[5][2] = 1;
				house[3][4] = house[4][3] = 1;
				house[3][5] = house[5][3] = 1;
				house[4][5] = house[5][4] = 1;
			
Output  : 	
				123153452
				123154352
				123451352
				123453152
				123513452
				123543152
				125134532
				125135432
				125315432
				125345132
				125431532
				125435132
				132153452
				132154352
				132534512
				132543512
				134512352
				134512532
				134521532
				134523512
				134532152
				134532512
				135123452
				135125432
				135215432
				135234512
				135432152
				135432512
				152134532
				152135432
				152345312
				152354312
				153123452
				153125432
				153213452
				153254312
				153452132
				153452312
				154312352
				154312532
				154321352
				154325312
				154352132
				154352312
Solve   :	backtracking
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 7
#define EDGE 10
bool r[MAXN][MAXN];
bool v[MAXN][MAXN];
int ans[EDGE];

void back(int now,int at)
{
	if(now==9)
	{
		for(int i=0;i<now;++i)
			printf("%d",ans[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=5;++i)
	{
		if(r[at][i] && !v[at][i])
		{
			v[at][i]=v[i][at]=true;
			ans[now]=i;
			back(now+1,i);
			v[at][i]=v[i][at]=false;
		}
	}
}
int main()
{
	memset(r,false,sizeof(r));
	memset(v,false,sizeof(v));
	r[1][2]=r[2][1]=true;
	r[1][3]=r[3][1]=true;
	r[1][5]=r[5][1]=true;
	r[2][3]=r[3][2]=true;
	r[2][5]=r[5][2]=true;
	r[3][4]=r[4][3]=true;
	r[3][5]=r[5][3]=true;
	r[4][5]=r[5][4]=true;
	ans[0]=1;
	back(1,1);
}