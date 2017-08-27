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
const int MAX = 1000 + 9;
int p[MAX];
int r[MAX];

void init(int N)
{
    rep(i, 0, N)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int findp(int u)
{
    if(u != p[u]) p[u] = findp(p[u]);
    return p[u];
}
void uni(int x, int y)
{
    x = findp(x); y = findp(y);
    if(x == y) return ;

    if(r[x] > r[y])
    {
        p[y] = x;
        r[x]++;
    }else
    {
        p[x] = y;
        r[y]++;
    }
}

int MST(pair<int, pii > adj[], int M)
{
    int minc = 0;
    lp(i, M)
    {
        auto P = adj[i];
        int x = P.S.F, y = P.S.S;
        int px = findp(x), py = findp(y);
        if(px != py)
        {
            uni(x,y);
            minc += P.F;

        }
    }
    return minc;
}

int main()
{
   // rfile("in");
    int t,p,n,m;
    int x,y,w;
    si(t);
    cntr(t)
    {
        si(p);
        si(n);
        si(m);
        init(n+1);
        pair<int, pii > adj[m];
        lp(i, m)
        {
            si(x); si(y); si(w);
            adj[i] = MP(w, MP(x,y));

        }
        sort(adj, adj+m);
        pll(1LL * MST(adj, m) * p);
        pln();
    }
    return 0;
}

