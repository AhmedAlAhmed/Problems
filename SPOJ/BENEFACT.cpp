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
const int MAX = 50000 + 20;
int N;
bool vis[MAX];
ll dist[MAX];


pair<int, ll> bfs(int u, vector<pair<int, ll> >adj[MAX])
{
    fill(vis, vis+N+10, 0);
    fill(dist, dist+N+10, 0);

    queue<int> Q;
    vis[u] = 1;
    dist[u] = 0;
    Q.push(u);

    while(Q.size())
    {
        int s = Q.front(); Q.pop();
        for(int i=0;i<adj[s].size();++i)
        {
            pair<int, ll> child = adj[s][i];

            if(vis[child.F]) continue;

            dist[child.F] += (dist[s] + child.S);
            vis[child.F] = 1;
            Q.push(child.F);
        }
    }
    int node = 0;
    ll dx = 0;
    for(int i=1;i<=N;i++)
    {
        if(dx < dist[i])
        {
            dx = dist[i];
            node = i;
        }
    }

    return MP(node, dx);

}
ll solve(vector<pair<int, ll> > adj[MAX])
{
    pair<int, ll> A = bfs(1, adj);



    pair<int, ll> B = bfs(A.F, adj);
    return 1LL * B.S;
}

int main()
{
    //rfile("in");
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        vector<pair<int, ll> > adj[N+1];

        for(int c = 1; c<= N-1;c++)
        {
            int X, Y, Cost;
            cin >> X >> Y >> Cost;
            adj[X].pb(MP(Y, Cost));
            adj[Y].pb(MP(X, Cost));
        }
        cout << solve(adj) << endl;
    }
    return 0;
}









