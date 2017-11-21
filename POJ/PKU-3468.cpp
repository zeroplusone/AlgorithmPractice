#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

#define MAXN 50100
#define INF 9999999
int s[MAXN];

struct Node
{
    int valmax,valmin,valsum,tag;
    Node *l,*r;
    
    void update(int v)
    {
        valmin=v;
        valmax=v;
        valsum=0;
        tag=0;
    }
    void pull()
    {
        valmax=max(l->valmax,r->valmax);
        valmin=min(l->valmin,r->valmin);
        valsum=l->valsum+r->valsum;
    }
};

Node* build(int L,int R)
{
    // create new node
    Node* now=new Node();
    // (1) is this node a leaf
    if(L==R)
    {
        now->update(s[L]);
        return now;
    }
    int mid=(L+R)>>1;
    // (2) create left subtree
    now->l=build(L,mid);
    // (3) create right subtree
    now->r=build(mid+1,R);
    // (4) pull
    now->pull();
    return now;
}

void push(Node* node, int L,int R) {
    if (!node->tag) return;
    if (L!=R) {   
        int mid= (L+R) >> 1;
        node->l->tag += node->tag;
        node->r->tag += node->tag;
        node->l->valsum += node->tag * (mid - L +1);   
        node->r->valsum += node->tag * (R - mid);
    }
    node->tag = 0;
}

int query(Node* now,int L,int R,int x,int y)
{
    // (1) There is no overlap between [L, R] and [x, y]
    //     => [x y L R] or [L R x y] 
    if(x>R || y<L)  return 0;
    // (2) [x, y] completely include [L, R]
    //     => [x L R y]
    if(x<=L && y>=R)    return now->valsum;
    // (3) Others (partial overlap)
    push(now, L, R);
    int mid=(L+R)>>1;
    return query(now->l,L,mid,x,y)+query(now->r,mid+1,R,x,y);  
}

void modify(Node* node, int L, int R, int x, int y,int d) {   
    // (1) There is no overlap between [L, R] and [x, y]
    //     => [x y L R] or [L R x y] 
    if (x>R || y<L) return;
    // (2) [x, y] completely include [L, R]
    //     => [x L R y]
    if (x<=L && R<=y) {
        node->tag += d;
        node->valsum += d*(R-L+1);
        return;
    }
    // (3) Others (partial overlap)
    push(node,L,R);
    int mid = (L+R) >> 1;
    modify(node->l, L,mid,x,y,d);
    modify(node->r,mid+1,R,x,y,d);
    node->pull();
}

int main()
{
    int N,Q;
    int i;

    Node* root;
    memset(s,0,sizeof(s));
    scanf("%d%d",&N,&Q);
    for(i=1;i<=N;++i)
        scanf("%d",&s[i]);      
    root=build(1,N);
    char qtype;
    int a, b, c;
    while(Q--)
    {
        char cc= getchar();
        cout<<"!"<<cc<<endl;
        scanf("%c",&qtype);
        cout<<qtype<<endl;
        if(qtype=='C'){
            scanf("%d%d%d",&a,&b,&c);
            modify(root, 1, N, a, b, c);
        }else if(qtype=='Q'){
            cout<<query(root, 1, N, a, b)<<endl;
        }
    }
    return 0;
}


