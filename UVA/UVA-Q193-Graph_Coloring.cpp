/******************
Judge   : UVA
Problem : 193-Graph_Coloring.cpp
Course  : Course7
discribe: give you a graph and find the max of black number(can not adj)
Input   : 	1  //case數
			6 8  //6個頂點8個邊
			1 2   //邊~~
			1 3
			2 4
			2 5
			3 4
			3 6
			4 6
			5 6
Output  : 	3     黑色不能相臨~最多能途幾個頂點
			1 4 5
		  
Solve   : backtrack如果相鄰都是白的圖黑色繼續~回來變白色
			如果相鄰有黑色~圖白色
			紀錄最大數時的黑色頂點
*******************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

#define MAX 110
int m[MAX][MAX];
bool color[MAX];
int save[MAX];
int ans,mx,n;
//queue<int> w;

void reset()
{
	mx=-1;	ans=0;
	memset(color,false,sizeof(color));
	/*while(!w.empty())
		w.pop();*/
}

void print()
{
	sort(save,save+mx);
	printf("%d\n%d",mx,save[0]);
	//printf("%d\n%d",mx,color[1]);
	for(int i=1;i<mx;++i)
		//printf(" %d",color[i]);
		printf(" %d",save[i]);
	printf("\n");
}

void backtrack(int f)
{
	/*int now;
	w.push(f);
	v[f]=true;
	color[f]=true;
	while(!q.empty())
	{
		now=w.front();*/
	
	if(ans>mx)
	{
		int c=0;
		mx=ans;
		memset(save,0,sizeof(save));
		for(int j=1;j<=n;++j)
			if(color[j])
				save[c++]=j;
	}
	if(f==n+1)
		return;
//	printf("@%d\n",f);print();
	//v[f]=true;
	bool ya=false;
	for(int i=1;i<=n;++i)
	{
		if(m[f][i]==1 && color[i])
		{
			ya=true;
			break;
			/*v[i]=true;
			if(color[f])
			{
				color[i]=false;
				backtrack(i);
			}
			else
			{
				color[i]=true;
				ans++;
				backtrack(i);
				ans--;
				color[i]=false;
				backtrack(i);
			}*/
		}
	}
	if(ya)
	{
		color[f]=false;
		backtrack(f+1);
	}	
	else
	{
		color[f]=true;
		ans++;
		backtrack(f+1);
		ans--;
		color[f]=false;
		backtrack(f+1);
	}	
	//}
}



int main()
{
	int mm,k,t1,t2;
	scanf("%d",&mm);
	for(int i=0;i<mm;++i)
	{
		memset(m,0,sizeof(m));
		reset();
		scanf("%d %d",&n,&k);
		for(int j=0;j<k;++j)
		{
			scanf("%d %d",&t1,&t2);
			m[t1][t2]=m[t2][t1]=1;
		}
		
	
		backtrack(1);
		/*reset();	ans=1;
		color[1]=true;
		backtrack(1);
		
		reset();	ans=0;
		color[1]=false;
		backtrack(1);*/
		print();
	}
	return 0;
}