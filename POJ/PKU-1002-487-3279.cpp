/******************
Judge   : POJ
Problem : 1002-487-3279
Course  : Course1
discribe: convert tel to all number
          and sort and count
		  A, B, and C map to 2 
	   	  D, E, and F map to 3 
	   	  G, H, and I map to 4 
		  J, K, and L map to 5 
		  M, N, and O map to 6 
		  P, R, and S map to 7 
		  T, U, and V map to 8 
		  W, X, and Y map to 9
		  There is no mapping for Q or Z.
Input   : n
		  tel0
		  tel1
		  .
		  .
		  teln-1
Output  : tel0' num0
          tel1' num1
		  .
		  .
Solve   : sort
*******************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

map <char,int> eng;

void telmap()
{
	for(char i='A';i<='O';++i)
		eng[i]=(i-'A')/3+2;
	eng['P']=eng['R']=eng['S']=7;
	for(char i='T';i<='Y';++i)
		eng[i]=(i-'T')/3+8;
	
}

int main()
{
	int n,now,num;
	set<int> tel;
	map<int,int> ans;
	telmap();
	scanf("%d",&n);	
	getchar();
	for(int i=0;i<n;++i)
	{
		char in[200];
		scanf("%s",in);
		now=0; num=0;	
		
		while(now!=strlen(in))
		{
			
			if(in[now]!='-')
			{
				if(in[now]>='A' && in[now]<='Z')			
					num=num*10+eng[in[now]];
				else
					num=num*10+(in[now]-'0');	
				
			}
			now++;
		}
		
		ans[num]++;
		
		if(tel.count(num)==0)
			{tel.insert(num);}	
	}
	int flag=0;
	set<int>::iterator itr;
	for(itr=tel.begin();itr!=tel.end();++itr)
	{
		if(ans[*itr]>1)
		{
			flag=1;
			printf("%03d-%04d %d\n",(*itr)/10000,(*itr)%10000,ans[*itr]);
		}
	}
	if(flag==0)
		printf("No duplicates.\n");
	
	return 0;
}