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
const int MAX = 200*200 + 1;
bool vis[MAX];
float dist[MAX];

void dijkstra(int su, vector<pair<float, int> > adj[MAX], int k)
{
    rep(i, 0, k-1)
    {
        vis[i] = 0;
        dist[i] = 0.0;
    }
    dist[su] = 0.0;

    multiset< pair<float, int> > s;
    s.insert({0.0, su});
    while(! s.empty())
    {
        pair<float, int>  P = *s.begin();

        s.erase(s.begin());
        int x = P.S;
        float w = P.F;
        if(vis[x]) continue;

        vis[x] = 1;
        lp(i, adj[x].size())
        {
            int e = adj[x][i].S;
            float wi = adj[x][i].F;

            if((dist[e] - (dist[x] + wi)) <  EPS)
            {
                dist[e] = dist[x] + wi;
                s.insert({dist[e], e});
            }
        }
    }

}
int main()
{
    //rfile("insert.txt");
   // wfile("oppp.txt");
    int n;
    int x,y;
    int cnt = 1;
    while(cin >> n && n != 0)
    {
        vector<Point> points;
        points.resize(n);
        lp(i,n)
        {
            cin >> x >> y;

            points[i] = MP(x,y);

        }


        vector<pair<float, int> > adj[MAX];
        int k = 0;

        float ans[n+1][n+1];
        for(int i=0; i<n; i++) lp(j, n)
            if(i == j) ans[i][j] = 0;
            else ans[i][j] = 1e9;

        for(int u=0; u<n; u++) for(int v=u+1; v < n; v++)
            {


                float a1 = points[v].X - points[u].X;
                float b1 = points[v].Y - points[u].Y;
                float w = sqrt((a1*a1) + (b1*b1));

                ans[u][v] = w;
                ans[v][u] = w;

                //adj[u+1].pb(MP(w, v+1));
                //adj[v].pb(MP(w, u));
                //k+=2;
            }

        lp(k, n) lp(i, n) lp(j, n)
        {
            ans[i][j] = min(ans[i][j], max(ans[i][k],  ans[k][j]));
        }

        printf("Scenario #%d\n", cnt++);
        printf("Frog Distance = %.3f\n", ans[0][1]);
        pln();

    }

    return 0;
}





