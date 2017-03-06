#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	char map[15][15];
	int step[15][15];
	int row,col,enter,nowx,nowy,count,loop;
	while(scanf("%d %d %d",&row,&col,&enter)!=EOF)
	{
		getchar();
		if(row==0 && col==0 && enter==0)
			break;
		for(int i=1;i<=row;++i)
		{
			for(int j=1;j<=col;++j)
				scanf("%c",&map[i][j]);
			getchar();
		}
		nowx=1;		nowy=enter;		count=1;		loop=0;    
		//memset(step,0,sizeof(step));       16ms
		for(int j=0;j<15;++j)         //0ms
			for(int k=0;k<15;++k)
				step[j][k]=0;
		while(nowx>0 && nowx<=row && nowy>0 && nowy<=col)
		{
			if(step[nowx][nowy])
			{				
				loop=count-step[nowx][nowy];
				break;
			}
			else
			{				
				step[nowx][nowy]=count;
				count++;
				switch(map[nowx][nowy])
				{
					case 'N':nowx--;
						break;
					case 'E':nowy++;
						break;
					case 'W':nowy--;
						break;
					case 'S':nowx++;
						break;
					default:
						break;
				}
			}
		}
		if(loop)		
			printf("%d step(s) before a loop of %d step(s)\n",step[nowx][nowy]-1,loop);			
		
		else		
			printf("%d step(s) to exit\n",count-1);		
	}
	return 0;
}