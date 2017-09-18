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
#define si2(x,y) scanf("%d %d", &x, &y)
#define si3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) ((int)(x.size()))
using namespace std;

const int MAX = 70;

int s,t;
int p[MAX];

vi adj[MAX];
int res[MAX][MAX];
ll f,mf;
int N,M,a,b,c;

void augment(int v, int minEdge)
{

    if (v == s)
    {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {

        augment(p[v], min(minEdge, res[p[v]][v]));

        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void go()
{
    mf = 0;
    while (1)
    {

        f = 0;
        bool visited[MAX];
        clr(visited, 0);

        visited[s] = 1;
        queue<int> q;
        q.push(s);

        clr(p, -1);

        while (!q.empty())
        {
            int u = q.front();

            q.pop();
            if (u == t)
                break;
            for (int i = 0; i < (int) adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (res[u][v] > 0 && !visited[v])
                {
                    q.push(v);
                    p[v] = u;

                    visited[v] = 1;
                }
            }
        }

        augment(t, INF);
        if (f == 0)
            break;
        mf += f;
    }
}

bool vis[MAX];
void dfs(int u) {
    vis [ u ] = 1;
    rep(i, 1, N) {
        if(! vis[i] && res[u][i] > 0) dfs(i);
    }
}

bool graph[MAX][MAX];
int main()
{
   // FI("in.txt");
    while(cin >> N >> M) {

        if(N+M == 0) break;

        clr(vis, 0);
        clr(res, 0);
        clr(graph, 0);
        for(auto& x : adj) x.clear();

        rep(it, 1, M) {
            cin >> a >> b >> c;

            res[a][b] = c;
            res[b][a] = c;
            graph[a][b] = 1;
            graph[b][a] = 1;

            adj[a].pb(b);
            adj[b].pb(a);
        }
        s = 1, t = 2;
        go();
        dfs(1);
        rep(i,1,N) {
            for(auto&x : adj[i]) {
                if(vis[i] && !vis[x])
                    cout << i << " " << x << endl;
            }
        }

        cout << endl;

    }
    return 0;
}
