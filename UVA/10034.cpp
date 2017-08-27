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

#define Point pair<float,float>
#define X F
#define Y S
using namespace std;

const int MAX = 100 + 9;
int p[MAX], r[MAX];
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
    if(u != p[u])
        p[u] = findp(p[u]);
    return p[u];
}
void uni(int u, int v)
{
    u = findp(u), v = findp(v);
    if(u == v) return ;

    if(r[u] > r[v])
    {
       p[v] = u;
       r[u]++;
    }else
    {
        p[u] = v;
        r[v]++;
    }

}
float solve(vector< pair<float, pii > > edges)
{
    float sum = 0.0;
    for(auto edge :  edges)
    {
        int r1 = findp(edge.S.F);
        int r2 = findp(edge.S.S);

        if(r1 != r2)
        {
            uni(edge.S.F, edge.S.S);
            sum += edge.F;
        }
    }
    return sum;
}
int main()
{
    //rfile("in.txt");
    //wfile("ioo.txt");
    int t, N;
    float x,y;
    si(t);
    rep(tc, 1, t)
    {
        si(N);
        init(N);
        vector<Point> PS;
        PS.resize(N);
        lp(i, N)
        {
            scanf("%f%f", &x, &y);
            PS[i] = MP(x, y);
        }
        vector< pair<float, pii > > edges;
        rep(i, 0, N-1) rep(j, i+1, N-1)
        {
            float a1 = PS[i].X - PS[j].X;
            float b1 = PS[i].Y - PS[j].Y;

            float Di = sqrt(a1*a1 + b1*b1);
            edges.pb(MP(Di, MP(i, j)));
        }
        sort(all(edges));
        printf("%.2f\n", solve(edges));
        if(tc < t) pln();
    }
    return 0;
}














