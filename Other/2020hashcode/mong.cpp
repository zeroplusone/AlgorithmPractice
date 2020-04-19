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
	long long int bookNum, signupTime, dailyMax;
	int curScore;
}libraryList[MAX];

int books[MAX][MAX];
bool scaned[MAX];

bool cmp(library A, library B){
	if(A.curScore/(A.signupTime+(A.bookNum/A.dailyMax)) > B.curScore/(B.signupTime+(B.bookNum/B.dailyMax))){
		return true;
	}
	return false;
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
	int B, L, N, libID;
	long long int D, signupNum=0, signupCost=0, shipNum;

	// input
	memset(score, 0, sizeof(score));
	memset(scaned, false, sizeof(scaned));
	scanf("%d %d %lld", &B, &L, &D);
	for(int i=0; i<B; i++){
		scanf("%d", &score[i]);
	}
	for(int i=0; i<L; i++){
		libraryList[i].ID = i;
		scanf("%lld %lld %lld", &libraryList[i].bookNum, &libraryList[i].signupTime, &libraryList[i].dailyMax);
		libraryList[i].curScore = 0;
		for(long long int j=0; j<libraryList[i].bookNum; j++){
			scanf("%d", &books[i][j]);
			libraryList[i].curScore += score[books[i][j]];
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

	printf("%lld\n", signupNum);
	for(long long int i=0; i<signupNum; i++){
		if((D-libraryList[i].signupTime)*libraryList[i].dailyMax > libraryList[i].bookNum){
			shipNum = libraryList[i].bookNum;
		}else{
			shipNum = (D-libraryList[i].signupTime)*libraryList[i].dailyMax;
		}
		D = D-libraryList[i].signupTime;
		libID = libraryList[i].ID;
		printf("%d %lld\n", libraryList[i].ID, shipNum);

		sort(books[libID], books[libID]+libraryList[i].bookNum, cmp_book);
		for(int j=0; j<shipNum; j++){
			printf("%d ",books[libID][j]);
			scaned[books[libID][j]]=true;
		}
		printf("\n");
	}

	return 0;
}