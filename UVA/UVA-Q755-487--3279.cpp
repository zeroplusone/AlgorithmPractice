/******************
Judge   : UVA
Problem : 755-487--3279
Course  : Course2
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

          nn
		  tel0
		  tel1
		  .
		  .
		  telnn-1
Output  : tel0' num0
          tel1' num1
		  .
		  .
Solve   : sort SET MAP
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
	int n,nn,now,num;
	set<int> tel;
	map<int,int> ans;
	telmap();
	scanf("%d",&n);	
	getchar();
	for(int j=0;j<n;++j)
	{
		tel.clear();	ans.clear();
		if(j)	printf("\n");
		getchar();		
		scanf("%d",&nn);
		getchar();
		for(int i=0;i<nn;++i)
		{
			char in[100100];
			scanf("%s",in);
			//gets(in);
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
			
	}	
	return 0;
}

/*-------------TLE-----------
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
using namespace std;
int nummap[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int main()
{
	int i,j;
	int t,n,len,num;
	char in[100100];
	bool flag=false;
	multiset<int> ans;
	map<int,int> appear;
	scanf("%d",&t);	getchar();
	while(t--)
	{
		ans.clear();	appear.clear();
		getchar();
		scanf("%d",&n);
		getchar();
		while(n--)
		{
			scanf("%s",in);
			len=strlen(in);
			num=0;
			for(i=0;i<len;++i)
			{
				if(in[i]=='-')
					continue;
				else if(in[i]>='A' && in[i]<='Z')
					num=num*10+nummap[in[i]-'A'];
				else
					num=num*10+in[i]-'0';
			}
			ans.insert(num);
		}
			flag=false;
			set<int>::iterator itr;
			for(itr=ans.begin();itr!=ans.end();++itr)
			{
				num=ans.count(*itr);
				if(num>1 && appear[*itr]==0)
				{
					printf("%03d-%04d %d\n",(*itr)/10000,(*itr)%10000,num);
					appear[*itr]=1;
					flag=true;
				}
			}
			if(!flag)
				printf("No duplicates.\n");
			if(t!=0)
				printf("\n");
		
	}
	return 0;
}
*/