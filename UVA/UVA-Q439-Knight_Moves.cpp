/*
Sample Input
e2 e4   //開始位置 結束位置
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output      //日字步(馬)最小幾步能走到
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

SOL:BFS
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

int step[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int beg[2]; 
int end[2]; 
bool v[9][9];
queue<int> x,y,l;

int bfs()
{
	int nowx,nowy,nowl;	
	v[beg[0]][beg[1]]=true;	x.push(beg[0]);	y.push(beg[1]); l.push(1);
	while(!x.empty() && !y.empty())
	{		
		nowx=x.front();	nowy=y.front();	nowl=l.front();
		//printf("%d %d %d\n",nowx,nowy,nowl);
		
		if( nowx==end[0] && nowy==end[1])
			return nowl;

		for(int i=0;i<8;++i)
		{
			if( nowx+step[i][0]>0 && nowx+step[i][0]<=8 && nowy+step[i][1]>0 && nowy+step[i][1]<=8)
			{
				if(!v[nowx+step[i][0]][nowy+step[i][1]])
				{
					x.push(nowx+step[i][0]);
					y.push(nowy+step[i][1]);
					l.push(nowl+1);
					v[nowx+step[i][0]][nowy+step[i][1]]=true;
				}
			}
		}
		x.pop();	y.pop();	l.pop();	
	}
}

void clear()
{
	while(!x.empty())
		x.pop();
	while(!y.empty())
		y.pop();
	while(!l.empty())
		l.pop();
}

int main()
{
	char inx[2];
	int iny[2];
	while(scanf("%c%d %c%d",&inx[0],&iny[0],&inx[1],&iny[1])!=EOF)
	{
		clear();	memset(v,false,sizeof(v));
		getchar();		
		beg[0]=inx[0]-'a'+1;	beg[1]=iny[0];
		end[0]=inx[1]-'a'+1;	end[1]=iny[1];
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n",inx[0],iny[0],inx[1],iny[1],bfs()-1);
	}
	return 0;
}