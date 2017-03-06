/******************
Judge   : UVA
Problem : 10158 - War
Course  : Course8
discribe: 
            c = 1, setFriends
            c = 2, setEnemies
            c = 3, areFriends
            c = 4, areEnemies
			~ is an equivalence relation, i.e.
				1.If x ~ y and y ~ z then x ~ z  (The friends of my friends are my friends as well.)
				2.If x ~ y then y ~ x                  (Friendship is mutual.)
				3.x ~ x                                       (Everyone is a friend of himself.)
            * is symmetric and irreflexive
				4.If x * y then y * x                  (Hatred is mutual.)
				5.Not x * x                                (Nobody is an enemy of himself.)
							  Also
				6.If x * y and y * z then x ~ z   (A common enemy makes two people friends.)
				7.If x ~ y and y * z then x * z   (An enemy of a friend is an enemy.)
			
			write 0 (meaning no) or 1 (meaning yes) 
			ontradicts with previous knowledge, output a ¡V1		
Input   : 
			10      //n people
            1 0 1   //c x y
            1 1 2
            2 0 5
            3 0 2
            3 8 9
            4 1 5
            4 1 2
            4 8 9
            1 8 9
            1 5 2
            3 5 2
            0 0 0  //end
Output  : 
			1
            0
            1
            0
            0
            -1
            0
Solve   : disjoint set
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010
int p[MAXN],r[MAXN];
int p2[MAXN],r2[MAXN]
int n;

void makeset()
{
	for(int i=0;i<=MAXN;++i)
	{	
		p[i]=i;	p2[i]=i;
		r[i]=0;	r2[i]=0;
	}
}

int findset(int a)
{
	if(a==p[a])	return a;
	else	return p[a]=findset(p[a]);
}

void uniont(int a,int b)
{
	int pa=findset(a);
	int pb=findset(b);
	if(pa!=pb)
	{
		if(r[pa]<r[pb])
		{
			p[pa]=pb;
		}
		else
		{
			p[pb]=pa;
			if(r[pa]==r[pb])
				r[pa]++;
		}
	}
}

int main()
{
	int c,x,y;
	int fx,fy;
	set<int>::iterator itr;
	bool ok=true;
	while(scanf("%d",&n)!=EOF)
	{
		makeset();	ok=true;
		while(scanf("%d%d%d",&c,&x,&y)!=EOF)
		{
			if(!c && !x && !y)	break;
			fx=findset(x);	fy=findset(y);
			switch(c)
			{
				case 1:
					if(enemy[x].count(y))					
							printf("-1\n");								
					else
					{						
						for(itr=enemy[y].begin();itr!=enemy[y].end();++itr)
						{
							if(findset(*itr)==fx)
							{
								printf("-1\n");
								ok=false;
								break;
							}
						}
						if(ok)
						{
							uniont(x,y);
							for(itr=enemy[y].begin();itr!=enemy[y].end();++itr)
							{
								enemy[x].insert(*itr);
								enemy[*itr].insert(x);
							}
						}
					}						
					break;
				case 2:
					if(findset(x)==findset(y))
						printf("-1\n");
					else
					{						
						for(itr=enemy[y].begin();itr!=enemy[y].end();++itr)
						{
							if(enemy[x].count(*itr))
							{
								printf("-1\n");
								ok=false;
								break;
							}
						}
						if(ok)
						{
							enemy[x].insert(y);
							enemy[y].insert(x);
							for(itr=enemy[y].begin();itr!=enemy[y].end();++itr)
							{
								uniont(x,*itr);
							}
						}
					}
					break;
				case 3:				
					printf("%d\n",findset(x)==findset(y)?1:0);
					break;
				case 4:	
					printf("%d\n",enemy[x].count(y)?1:0);				
				
					break;
				default:
					break;
			}
		}
	}	
	return 0;
}