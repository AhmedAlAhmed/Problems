#include <bits/stdc++.h>
#define lp(i,n) for(int i=0;i<(n);++i)
#define rep(i,s,n) for(int i=(s);i<=(n);i++)
#define repr(i,s,n) for(int i=(n);i>=(s);--i)
#define F first
#define S second
#define MP make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long>
#define ll long long int
#define llu unsigned long long
#define vll vector<ll>
#define vllu vector<llu>
#define clr(m,v) memset(m, v, sizeof m)
#define pb push_back
#define clrv(v) v.clear()
#define all(v) v.begin(), v.end()
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
using namespace std;

int setsCount = 0;
const int MAX = 100000 + 1;

int parent[MAX];
int rnk[MAX];

int countSet[MAX];
set<int> st;

// https://w...content-available-to-author-only...k.com/challenges/journey-to-the-moon/problem

void init(int N)
{
    lp(i, N) 
    {
        parent[i] = i;
        rnk[i] = 0;
        countSet[i] = 1;
    }
}

int findParent(int x)
{
    if(x != parent[x])
         parent[x]=findParent(parent[x]);

    return parent[x];
}

void merge1(int u, int v)
{
    int xu = findParent(u), yv = findParent(v);
    
    if(xu == yv) return;
    

    
    
    
    if(rnk[xu] < rnk[yv])
    {
        parent[xu] = yv; // yv is the parent.
        countSet[yv]+= countSet[xu];
    }
        
    else if (rnk[xu] > rnk[yv])
    {
        parent[yv] = xu;
        countSet[xu]+=countSet[yv];
    }
        
    else
    {
        parent[yv] = xu;
    
        rnk[xu]++;
        countSet[xu]+=countSet[yv];
    
    }
    
}


int main() {

    //rfile("input.txt");
    int N, M;
    si(N); si(M);
    init(N);
    int x, y;
    while(M--)
    {
        si(x); si(y);
        merge1(x, y);
    }
    llu ans = 0;
    lp(i, N)
    {
        if(i == findParent(i))
        {
            
            ans += 1LL * countSet[i] * (N - countSet[i]);
        }
            
    }
    
    cout << ans/2 << endl;
    
            
    return 0;
}


