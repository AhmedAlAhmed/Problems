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
const int MAX = 1000 + 10;

vi adj[MAX];
int N,M,a,b;
int cnt = 0;
int num[MAX], low[MAX], vis[MAX], P[MAX];
bool used[MAX][MAX] ;
void dfs(int u)
{
    vis[u] = 1;
    num[u] = low[u] = cnt++;
    for(auto& v : adj[u])
    {
        if(! vis[v] )
        {
            P[v] = u;
            dfs(v);

            low[u] = min(low[u], low    [v]);

            if(num[u] < low[v] )
            {
                cout << u << " " << v << endl;
                cout << v << " " << u << endl;
                used[u][v] = used[v][u] = 1;
            }
            else
            {
                if(! used[u][v] && !used[v][u])
                {
                    cout << u << " " << v << endl;
                    used[u][v] = used[v][u] = 1;
                }
            }

        }
        else if(P[u] != v)
        {
            low[u] = min(low[u], num[v]);
            if(! used[u][v] && !used[v][u])
            {
                cout << u << " " << v << endl;
                used[u][v] = used[v][u] = 1;
            }
        }
    }
}

int main()
{
 //   FI("in.txt");
    int tc = 1;
    while(cin >> N >> M && (N+M) > 0)
    {
        cout << tc++ << "\n\n";
        cnt = 0;
        for(auto&x : adj) x.clear();
        bool fc = 1;
        rep(i,0, N+1)
        {
            num[i] = low[i] = vis[i] = 0;
            P[i] = -1;
            rep(j, 0, N+1) used[i][j] = 0;
        }

        rep(it, 1, M)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1);
        cout << "#" << endl;
    }
    return 0;
}
