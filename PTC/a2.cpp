#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct point
{
	int id,count;
}
point list[101][101];
int row,col;
int step[3]={-1,0,1};
bool check(int &i,int j)
{
	if(j>=col)
		return false;
	else{
		if(i>=row)
			i=0;
		if(list[i][j]==0)
			return false;
		else
			return true;
	}
}
void dfs()
{
	int i,nexti,nextj=0,j,min=0;
	while(++nextj<col){
		for(j=0;j<row;j++){
			for(i=0;i<3;i++){
				nexti=j+step[i];
				if(check(nexti,nextj)){
					tmp=list[j][nextj-1].id+list[nexti][nextj].id;
					if(!list[nexti][nextj].count)
						list[nexti][nextj].count=tmp;
					if(list[nexti][nextj].count>tmp)
						list[nexti][nextj].count=tmp;
				}
			}
		}
	}
}
int main()
{
	int test,i,j;
	while(test--){
		scanf("%d %d",&row,&col);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				scanf("%d",&list[i][j].id);
				list[i][j].count=0;
			}
		}
		dfs();
	}
	return 0;
}