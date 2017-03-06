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
/*WA
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010
int p[MAXN],r[MAXN];
set<int> enemy[MAXN];
int n;
int seven[MAXN],seven2[MAXN];
int num,num2;
void makeset()
{
	for(int i=0;i<=MAXN;++i)
	{	
		p[i]=i;
		r[i]=0;
		enemy[i].clear();
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
	int i,tmp;
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
						for(itr=enemy[x].begin();itr!=enemy[x].end() && ok;++itr)
						{
							if(findset(*itr)==fy)
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
							for(itr=enemy[x].begin();itr!=enemy[x].end();++itr)
							{
								enemy[y].insert(*itr);
								enemy[*itr].insert(y);
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
						for(itr=enemy[x].begin();itr!=enemy[x].end() && ok;++itr)
						{
							if(enemy[y].count(*itr))
							{
								printf("-1\n");
								ok=false;
								break;
							}
						}
						num=0;	num2=0;
						for(i=0;i<n && ok ;++i)
						{
							tmp=findset(i);
							if(tmp==fy)
							{
								if(fx==tmp)
								{
									printf("-1\n");
									ok=false;
									break;
								}
								else
								{
									seven[num]=i;
									++num;
								}
							}
							if(tmp==fx)
							{
								if(fy==tmp)
								{
									printf("-1\n");
									ok=false;
									break;
								}
								else
								{
									seven2[num2]=i;
									++num2;
								}
							}
						}
						
						if(ok)
						{
							enemy[x].insert(y);	//printf("a %d*%d\n",x,y);
							enemy[y].insert(x);
							for(itr=enemy[y].begin();itr!=enemy[y].end();++itr)							
							{	if(x!=*itr)	{uniont(x,*itr);	}}
							for(itr=enemy[x].begin();itr!=enemy[x].end();++itr)							
							{	if(y!=*itr)	{uniont(y,*itr);}}
							for(i=0;i<num;++i)
							{
								enemy[seven[i]].insert(x);	
								enemy[x].insert(seven[i]);
								//printf("c %d*%d\n",seven[i],x);
							}
							for(i=0;i<num2;++i)
							{
								enemy[seven2[i]].insert(y);
								enemy[y].insert(seven2[i]);
								//printf("d %d*%d\n",seven2[i],y);
							}							
						}
					}
					break;
				case 3:				
					printf("%d\n",findset(x)==findset(y)?1:0);
					break;
				case 4:	
					if(!enemy[x].empty())
						printf("%d\n",enemy[x].count(y)?1:0);	
					else
						printf("0\n");
				
					break;
				default:
					break;
			}
		}
	}	
	return 0;
}
*/
//1~n friend   n+1~2n: enemy

#include<bits/stdc++.h>
using namespace std;

#define MAXN 10100
int p[2*MAXN],r[2*MAXN];
int n;

void makeset(int size)
{
	for(int i=0;i<=size;++i)
	{	
		p[i]=i;
		r[i]=0;
	}
}

int findset(int a)
{
	if(a==p[a])	return a;
	else	return p[a]=findset(p[a]);
}

void uniont(int a,int b)
{

		if(r[a]<r[b])
		{
			p[a]=b;
		}
		else
		{
			p[b]=a;
			if(r[a]==r[b])
				r[a]++;
		}
	
}

int main()
{
	int c,x,y;
	int fx,fy;
	int ex,ey;
	while(scanf("%d",&n)!=EOF)
	{
		makeset(2*n+10);	
		while(scanf("%d%d%d",&c,&x,&y)!=EOF)
		{
			if(!c && !x && !y)	break;
			fx=findset(x);	fy=findset(y);
			ex=findset(x+n);	ey=findset(y+n);
			//printf("~~%d %d %d %d\n",fx,fy,ex,ey);
			switch(c)
			{
				case 1:
					if(fx==ey || fy==ex)
						printf("-1\n");
					else
					{
						uniont(fx,fy);
						uniont(ex,ey);
					}		
					break;
				case 2:
					if(x==y)
						printf("0\n");
					else if(fx==fy)
						printf("-1\n");
					else
					{
						uniont(fx,ey);
						uniont(ex,fy);
					}	
					break;
				case 3:					
					printf("%d\n",fx==fy?1:0);
					break;
				case 4:	
					printf("%d\n",fx==findset(y+n) || fy==findset(x+n)?1:0);
				
					break;
				default:
					break;
			}
		}
	}	
	return 0;
}