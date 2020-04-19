#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

struct IDVALUE{
    LL id;
    LL value;

    bool operator<(const IDVALUE &t) const
    {
        return value > t.value;
    }
};

struct IDDOUBLEVALUE
{
    LL id;
    double value;

    bool operator<(const IDDOUBLEVALUE &t) const
    {
        return value > t.value;
    }
};

int main()
{
    int B, L, D; 
    scanf("%d%d%d", &B, &L, &D);
    vector<IDVALUE> bookScore(B);
    vector<IDVALUE> libBookNum(L);
    vector<IDVALUE> libSignDay(L);
    vector<IDVALUE> libShipDay(L);
    vector<IDDOUBLEVALUE> libCp(L);
    vector<vector<IDVALUE> > bookLists(L);

    for (int book = 0; book < B; ++book)
    {
        LL score;
        scanf("%lld", &score);
        struct IDVALUE val;
        val.id=book;
        val.value=score;
        bookScore[book]=val;
    }

    LL bookNum, signDay, shipDay;
    LL scoreSum;
    for (int lib = 0; lib < L; ++lib)
    {
        scanf("%lld%lld%lld", &bookNum, &signDay, &shipDay);
        struct IDVALUE val;
        val.id = lib;

        val.value = bookNum;
        libBookNum[lib] = val;

        val.value = signDay;
        libSignDay[lib] = val;

        val.value = shipDay;
        libShipDay[lib] = val;

        scoreSum = 0;

        vector<IDVALUE> bookList(bookNum);
        LL id;
        for (int book = 0; book < bookNum; ++book)
        {
            struct IDVALUE val;
            scanf("%lld", &id);
            val.id = id;
            val.value=bookScore[id].value;
            bookList[book]=val;
            if(book<=bookNum*0.2){
                scoreSum += val.value;
            }
        }

        sort(bookList.begin(), bookList.end());
        bookLists[lib]=bookList;

        struct IDDOUBLEVALUE dVal;
        dVal.id = lib;
        dVal.value = shipDay*scoreSum / signDay /bookNum;
        libCp[lib] = dVal;
    }

    sort(libCp.begin(), libCp.end());

    set<int> shippedBook;

    int d = 0;
    vector<int> libAns;
    vector<vector<int> > bookAnsList;
    for (int i = 0; i < L; ++i)
    {
        int libId = libCp[i].id;
        d += libSignDay[i].value;
        if(d>=D)
            break;
        
        vector<int> bookAns;
        LL j=0;
        for (int k = 0; j < libShipDay[libId].value * (D - d) && k < bookLists[libId].size(); ++k)
        {
            LL bookId = bookLists[libId][k].id;
            if(!shippedBook.count(bookId)){
                bookAns.push_back(bookId);
                j++;
            }
        }

        if(bookAns.size()==0){
            d -= libSignDay[i].value;
            continue;
        }
        for(int k=0;k<bookAns.size();++k){
            shippedBook.insert(bookAns[k]);
        }
        libAns.push_back(libId);
        bookAnsList.push_back(bookAns);
    }

    cout<<libAns.size() << endl;
    for (int i = 0; i < libAns.size(); ++i)
    {
        cout << libAns[i] << " " << bookAnsList[i].size() << endl;

        for (LL j = 0; j < bookAnsList[i].size(); ++j)
        {
            if (j != 0)
                cout << " ";
            cout << bookAnsList[i][j];
        }
        cout<<endl;
    }
    

    return 0;
}
