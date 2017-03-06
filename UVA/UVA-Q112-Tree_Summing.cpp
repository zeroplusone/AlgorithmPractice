/*
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

#define MAX 10000
/*
int t[MAX];
bool v[MAX],end;*/
/*vector<int> t;
vector<bool> v;
bool end;
int sum,n;

void back(int now)
{
	if(t[now]==-1 )
	{
		if(sum==n && now!=1)
			end=true;
		return;
	}
	
	sum+=t[now];
	//printf("%d %d\n",now,sum);
	back(now*2);
	if(end)		return;
	back(now*2+1);
	if(end)		return;
	sum-=t[now];
	//printf("-%d %d\n",t[now],sum);
	
}

int main()
{
	int now,num;	char c;	bool ya,minus;	
	stack<char> p;
	while(scanf("%d",&n)!=EOF)
	{
		/*memset(t,-1,sizeof(t));
		memset(v,false,sizeof(v));*/
		/*t.assign(MAX,-1);
		v.assign(MAX,false);
		while(!p.empty())
			p.pop();
			
		ya=false;	end=false;	minus=false;
		/*do{scanf("%c",&c);}while(c!='(');	p.push(c);	
		
		do
		{
			if(!ya)
				scanf("%c",&c);
			else
				ya=false;
				
			if(c=='(')
			{
				p.push(c);				
				now*=2;
				now=v[now]?now+1:now;
				v[now]=true;
			}
			else if(c==')')
			{
				p.pop();
				now/=2;
			}
			else if(c=='-')
			{
				minus=true;
			}
			else if(c>='0' && c<='9')
			{
				num=0;
				
				while(c>='0' && c<='9')
				{
					num=num*10+(c-'0');
					scanf("%c",&c);
					ya=true;
				}

				t[now]=minus?(-1)*num:num;				
				v[now]==true;	minus=false;
				//printf("&%d %d %d\n",now,t[now],minus);
				
			}		
		}while(!p.empty());*/
		/*getchar();
		sum=0;
		back(1);
		if(!end)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}*/
/*
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;

#define MAX 1000000
int t[MAX];
bool v[MAX],end;
int sum,n,big;

void back(int now)
{
	if(t[now]==-1 || now>big)
	{
		if(sum==n && now!=1)
			end=true;
		return;
	}
	
	sum+=t[now];
	printf("%d %d\n",now,sum);
	back(now*2);
	if(end)		return;
	back(now*2+1);
	if(end)		return;
	sum-=t[now];
	printf("-%d %d\n",t[now],sum);
	
}

int main()
{
	int now,num;	char c;	bool ya,minus;	
	stack<char> p;
	while(scanf("%d",&n)!=EOF)
	{
		memset(t,-1,sizeof(t));
		memset(v,false,sizeof(v));
		while(!p.empty())
			p.pop();
		big=0;	ya=false;	end=false;	minus=false;
		do{scanf("%c",&c);}while(c!='(');	p.push(c);	now=1;
		do
		{
			big=big<now?now:big;
			if(!ya)
				scanf("%c",&c);
			else
				ya=false;
				
			if(c=='(')
			{
				p.push(c);				
				now*=2;
				now=v[now]?now+1:now;
				v[now]=true;
			}
			else if(c==')')
			{
				p.pop();
				now/=2;
			}
			else if(c=='-')
			{
				minus=true;
			}
			else if(c>='0' && c<='9')
			{
				num=0;
				
				while(c>='0' && c<='9')
				{
					num=num*10+(c-'0');
					cin>>c;
					ya=true;
				}

				t[now]=minus?(-1)*num:num;				
				/*v[now]==true;	*//*minus=false;
				printf("&%d %d\n",now,t[now]);
				
			}		
		}while(!p.empty());
		getchar();
		sum=0;
		back(1);
		if(!end)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}*/
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

int n;
int p,sum,i;
char c;
bool ya,cmp,r;

/*
struct number
{
	int ifpop;
	int ad;
}
typedef struct number number;
stack<number> num;
*/
vector<int> ad,ifpop;


void rightp()
{
	p--;
	ifpop[p]--;
	//printf("@%d %d\n",p,ifpop[p]);
	if(ifpop[p]==0)
	{
		if(sum==n && cmp)	ya=true;
			cmp=false;	
			sum-=ad[p];
			//printf("%d %d pop\n",p,ad[p]);
			
	}
}

void sumtree()
{
	

		if(!r)	cin>>c;
		else	r=false;
	//printf("~%d %c\n",p,c);
	if(c=='(')
	{
		p++;
		/*cin>>i;
		if(!cin)
		{
			cin.clear(); printf("error\n");
		}
		else
		{
			//ad[p]=i;
			ad.push_back(i);
			ifpop.push_back(2);
			sum+=i;
			cmp=true;
			printf("add %d %d\n",p,i);
		}*/
		cin>>c;
		bool minus=false;
		if(c==')')
			rightp();
		else if(c=='-')
		{
			minus=true;
			cin>>i;
			i*=-1;
			if(p>=ad.size())
			{
				ad.push_back(i);
				ifpop.push_back(2);
			}
			else
			{
				ad[p]=i;
				ifpop[p]=2;
			}
			sum+=i;
			cmp=true;
			//printf("add %d %d\n",p,i);
		}
		else
		{
			i=0;
			while(c>='0' && c<='9')
			{
				i=10*i+c-'0';
				cin>>c;
			}
			r=true;
			if(p>=ad.size())
			{
				ad.push_back(i);
				ifpop.push_back(2);
			}
			else
			{
				ad[p]=i;
				ifpop[p]=2;
			}
			sum+=i;
			cmp=true;
			//printf("add %d %d\n",p,i);
		}
	}
	else if(c==')')
	{
		rightp();			
	}
	/*else if(c=='-')
	{
		cin>>i;
		i*=-1;
		ad.push_back(i);
		ifpop.push_back(2);
		sum+=i;
		cmp=true;
		printf("add %d %d\n",p,i);
	}*/
	if(p==0)
		return;
	else
		sumtree();	

}

void reset()
{
	sum=0;
	/*while(!num.empty())
		num.pop();*/
	ad.clear();	ad.push_back(0);
	ifpop.clear(); ifpop.push_back(0);
	p=0;
	ya=false;
	cmp=true;
	r=false;
}

int main()
{
	while(cin>>n)
	{
		reset();
		sumtree();

		if(ya)	printf("yes\n");
		else	printf("no\n");
}
	return 0;
}


/*
二元樹到底的走法加起來是否等於 一開始給的數
Sample Input

22 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
20 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
10 (3 
     (2 (4 () () )
        (8 () () ) )
     (1 (6 () () )
        (4 () () ) ) )
5 ()

			
Sample Output

yes
no
yes
no

*/