#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <algorithm>
#define MAX 100005
using namespace std;

int score[MAX];
struct library{
	int ID;
	int bookNum, signupTime, dailyMax;
}libraryList[MAX];

int books[MAX][MAX];
bool scaned[MAX];

bool cmp(library A, library B){
	if(A.signupTime==B.signupTime){
		return ((A.bookNum/A.dailyMax)<(B.bookNum/B.dailyMax));
	}
	return (A.signupTime<B.signupTime);
}

bool cmp_book(int book_A, int book_B){
	if(!scaned[book_A] && !scaned[book_B]){
		if(score[book_A]>score[book_B]){
			return true;
		}else{
			return false;
		}
	}else if(!scaned[book_A]){
		return true;
	}else{
		return false;
	}
}

int main()
{
	int B, L, D, N;
	int signupNum=0, signupCost=0, shipNum, libID;

	// input
	memset(score, 0, sizeof(score));
	memset(scaned, false, sizeof(scaned));
	scanf("%d %d %d", &B, &L, &D);
	for(int i=0; i<B; i++){
		scanf("%d", &score[i]);
	}
	for(int i=0; i<L; i++){
		libraryList[i].ID = i;
		scanf("%d %d %d", &libraryList[i].bookNum, &libraryList[i].signupTime, &libraryList[i].dailyMax);
		for(int j=0; j<libraryList[i].bookNum; j++){
			scanf("%d", &books[i][j]);
		}
	}

	sort(libraryList, libraryList+L, cmp);
	
	for(int i=0; i<L; i++){
		if((signupCost + libraryList[i].signupTime) < D){
			signupCost += libraryList[i].signupTime;
			signupNum++;			
		}else{
			break;
		}
	}

	printf("%d\n", signupNum);
	for(int i=0; i<signupNum; i++){
		if((D-libraryList[i].signupTime)*libraryList[i].dailyMax > libraryList[i].bookNum){
			shipNum = libraryList[i].bookNum;
		}else{
			shipNum = (D-libraryList[i].signupTime)*libraryList[i].dailyMax;
		}
		D = D-libraryList[i].signupTime;
		libID = libraryList[i].ID;
		printf("%d %d\n", libraryList[i].ID, shipNum);

		sort(books[libID], books[libID]+libraryList[i].bookNum, cmp_book);
		for(int j=0; j<shipNum; j++){
			printf("%d ",books[libID][j]);
			scaned[books[libID][j]]=true;
		}
		printf("\n");
	}

	return 0;
}