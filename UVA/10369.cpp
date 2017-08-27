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
#define Point pair<float, float>
#define X F
#define Y S
#define EPS 1e18
using namespace std;

const int MAX = 500 + 1;
float dis(int a, int b, int c, int d)
{
    return sqrt((abs(a-c)*(abs(a-c)) + ((abs(b-d))* (abs(b-d)))));
}
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

int fp(int u)
{
    if(p[u] != u) p[u] = fp(p[u]);
    return p[u];
}
void uni(int u, int v)
{
    u = fp(u);
    v = fp(v);
    if(u == v) return;
    if(r[u] > r[v])
    {
        p[v] = u;
        r[u]++;
    }
    else
    {
        p[u] = v;
        r[v] ++;
    }
}
int main()
{
   // rfile("input.txt");
   // wfile("oooo.txt");
    int T;
    si(T);
    while(T--)
    {
        int S, P;
        si(S);
        si(P);
        int x, y;
        vector<Point> pnts;
        pnts.resize(P);
        lp(i, P)
        {
            si(x);
            si(y);
            pnts[i] = MP(x, y);
        }

        vector<pair<float, pii > > adj;

        int sz = 0;
        rep(i, 0, P-1) rep(j, i+1, P-1)
        {
            float w = dis(pnts[i].X, pnts[i].Y, pnts[j].X, pnts[j].Y);
            adj.pb(MP(w, MP(i, j)));
        }
        sort(all(adj));
        float ans = 0.0;


        init(P);
        int c = 0;
        lp(i, adj.size())
        {
            if(P-c == S)
                break;

            int x = adj[i].S.F;
            int y = adj[i].S.S;
            if(fp(x) != fp(y))
            {
                uni(x,y);
                c++;
                ans = adj[i].F;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

