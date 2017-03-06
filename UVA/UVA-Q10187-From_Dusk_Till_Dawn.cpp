/******************
Judge   : UVA
Problem : 10187 - From Dusk Till Dawn
Course  : Course10
discribe: find the shortest route between two given cities
			First, he can only travel by train because he has to take his coffin with him. (On the up side he can always travel first class because he has invested a lot of money in long term stocks.)
			Second, he can only travel from dusk till dawn, namely from 6 pm to 6 am. During the day he has to stay inside a train station.
			Third, he has to take something to eat with him. He needs one litre of blood per day, which he drinks at noon (12:00) inside his coffin.
Input	:
			2	//c(case)
			3	//#edge(<1000) city(<100)
			Ulm Muenchen 17 2	//from to starttime last time
			Ulm Muenchen 19 12
			Ulm Muenchen 5 2
			Ulm Muenchen		//start end
			10
			Lugoj Sibiu 12 6
			Lugoj Sibiu 18 6
			Lugoj Sibiu 24 5
			Lugoj Medias 22 8
			Lugoj Medias 18 8
			Lugoj Reghin 17 4
			Sibiu Reghin 19 9
			Sibiu Medias 20 3
			Reghin Medias 20 4
			Reghin Bacau 24 6
			Lugoj Bacau

Output	:
			Test Case 1.
			There is no route Vladimir can take.
			Test Case 2.
			Vladimir needs 2 litre(s) of blood.

solve:
		coordinate->dijkstra
[direction ,no cycle]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

#define MAXE 1500
#define MAXN 150
#define INF 999999

struct change
{
	int blood,endtime;
}r[MAXN];	//blood

struct EDGE
{
	int from,to;
	int ts,te;
}e[MAXE];

int main()
{
	int c,cc;
	int i,j,now,m;
	int x,y;
	bool ch=false;
	string c1,c2;
	map<string,int> city;
	scanf("%d",&c);
	for(cc=1;cc<=c;++cc)
	{
		printf("Test Case %d.\n",cc);
		
		city.clear();
		now=0;
		scanf("%d",&m);
		for(i=0,j=0;i<m;++i)
		{
			cin>>c1;	cin>>c2;
			if(!city.count(c1))
				city[c1]=now++;
			if(!city.count(c2))
				city[c2]=now++;
			scanf("%d %d",&e[j].ts,&e[j].te);
			x=e[j].ts;	y=e[j].te;
			if(((x>=18 && x<=24) || (x<=6 && x>0)) && (((x+y-1)%24>=17 && (x+y-1)%24<24) || ((x+y-1)%24<6 && (x+y-1)%24>=0)))
			{			
				if(x==6 && y==12)	break;	
				e[j].from=city[c1];
				e[j].to=city[c2];
				j++;
			}	
		}
		m=j;
		for(i=0;i<=now;++i)	
		{	
			r[i].blood=INF;
			r[i].endtime=-999;
		}
		cin>>c1;		
		cin>>c2;	
		r[city[c1]].blood=0;
		r[city[c1]].endtime=12;
		for(i=0;i<now-1;++i)	//bellman-ford
		{
			ch=false;
			for(j=0;j<m;++j)
			{
				x=r[e[j].from].endtime;
				y=e[j].ts;
				x=x<=6?x+24:x;
				y=y<=6?y+24:y;
				//printf("!%d %d %d %d\n",x,y,r[e[j].to].blood,r[e[j].from].blood);
				if(y<x)
				{
					if(r[e[j].to].blood>r[e[j].from].blood+1)
					{
						r[e[j].to].blood=r[e[j].from].blood+1;
						r[e[j].to].endtime=(y+e[j].te-1)%24+1;
						ch=true;
					}					
				}
				else
				{
					if(r[e[j].to].blood>r[e[j].from].blood)
					{
						r[e[j].to].blood=r[e[j].from].blood;
						r[e[j].to].endtime=(y+e[j].te-1)%24+1;
						ch=true;
					}
				
				}
			}
			/*for(int tmp=0;tmp<now;++tmp)
				printf("%d %d %d\n",tmp,r[tmp].blood,r[tmp].endtime);*/
			if(!ch)	break;
		}
		//cout<<city.count(c2)<<endl;
		if( !city.count(c2) || r[city[c2]].blood==INF || m==0)
			printf("There is no route Vladimir can take.\n");
		else
			printf("Vladimir needs %d litre(s) of blood.\n",r[city[c2]].blood);
	}
	return 0;
}