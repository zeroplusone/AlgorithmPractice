#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
using namespace std;

#define MAX 110 
int coor[MAX][MAX];
char rdic[MAX];
int k,a,b,n,m;
int flag;

void reset()
{
	for(int i=0;i<=a+1;++i)
		for(int j=0;j<=b+1;++j)
			coor[i][j]=0;
			
	for(int i=0;i<=n;++i)
		rdic[i]='\0';
	flag=0;
}

void change(int robot,char ch,int time)
{	
	map<char,int> direc;        //不能全域變數
	direc['N']=0; direc['E']=1; direc['S']=2; direc['W']=3;
	char d[4]={'N','E','S','W'};
	if(ch=='L')	
	{	
		for(int i=0;i<time;++i)
			rdic[robot]=d[(direc[rdic[robot]]+3)%4];	
	}
	else if(ch=='R')
	{
		for(int i=0;i<time;++i)
			rdic[robot]=d[(direc[rdic[robot]]+1)%4];
	}	
	//printf("!!%c\n",rdic[robot]);
}

void move(int robot,int time)
{
	int x,y;
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;++j){
			if(coor[i][j]==robot)
			{	x=i;	y=j;	}}}
	
	if(rdic[robot]=='N')
	{
		for(int step=1;step<=time;++step)
		{
			if(y+1>b)
			{	printf("Robot %d crashes into the wall\n",robot);	flag=1;return;}
			else if(coor[x][y+1]!=0)
			{	printf("Robot %d crashes into robot %d\n",robot,coor[x][y+1]);	flag=1; return;}
			else
			{	coor[x][y]=0;	coor[x][y+1]=robot; y=y+1;}
		}
	}	
	else if(rdic[robot]=='E')
	{
		for(int step=1;step<=time;++step)
		{
			if(x+1>a)
			{	printf("Robot %d crashes into the wall\n",robot);	flag=1;return;}
			else if(coor[x+1][y]!=0)
			{	printf("Robot %d crashes into robot %d\n",robot,coor[x+1][y]);	flag=1;return;}
			else
			{	coor[x][y]=0;	coor[x+1][y]=robot; x+=1;}
		}
	}
	else if(rdic[robot]=='S')
	{
		for(int step=1;step<=time;++step)
		{
			if(y-1<=0)
			{	printf("Robot %d crashes into the wall\n",robot);	flag=1;return;}
			else if(coor[x][y-1]!=0)
			{	printf("Robot %d crashes into robot %d\n",robot,coor[x][y-1]);	flag=1;return;}
			else
			{	coor[x][y]=0;	coor[x][y-1]=robot; y-=1;}	
		}
	}
	else if(rdic[robot]=='W')
	{
		for(int step=1;step<=time;++step)
		{
			if(x-1<=0)
			{	printf("Robot %d crashes into the wall\n",robot);	flag=1;return;}
			else if(coor[x-1][y]!=0)
			{	printf("Robot %d crashes into robot %d\n",robot,coor[x-1][y]);	flag=1;return;}
			else
			{	coor[x][y]=0;	coor[x-1][y]=robot; x-=1;}	
		}
	}
}

void print()
{
	for(int i=1;i<=a;++i)
	{	for(int j=1;j<=b;++j)
			printf("%d ",coor[i][j]);
		printf("\n");
	}		
}

int main()
{	
	int x,y;
	char in3;
	scanf("%d",&k);
	for(int i=0;i<k;++i)
	{		
		scanf("%d %d",&a,&b);
		scanf("%d %d",&n,&m);
		//printf("@%d %d %d %d\n",a,b,n,m);
		reset();		
		for(int j=1;j<=n;++j)
		{
			scanf("%d %d %c",&x,&y,&rdic[j]);
			//printf("!%d %d %c\n",x,y,rdic[j]);
			coor[x][y]=j;
		}
		for(int l=0;l<m;++l)
		{
			if(!flag)
			{
				scanf("%d %c %d",&x,&in3,&y);
				//printf("#%d %c %d\n",x,in3,y);					
				if(in3=='F')
					move(x,y);
				else
					change(x,in3,y);
				//print();
			}
			else
				scanf("%d %c %d",&x,&in3,&y);
				
		}
		if(!flag)
			printf("OK\n");
		
	}
	return 0;
}