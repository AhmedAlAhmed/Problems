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
const int MAX = 1e5 + 10;
vi adj[MAX];
int num[MAX],low[MAX], P[MAX];
bool vis[MAX];
int cnt = 1;
int N, u, k,v;
vector < pii > ans;

void dfs(int a)
{
    vis[a] = 1;
    low[a] = num[a] = cnt++;
    for(auto& b : adj[a])
    {

        if(! vis[b])
        {
            P[b] = a;
            dfs(b);
            low[a] = min(low[a], low[b]);
            if(num[a] < low[b])
            {
                ans.pb({min(a,b), max(a,b)});
            }

        }
        else if(P[a] != b)
        {
            low[a] = min(low[a], num[b]);
        }
    }
}


int main()
{

    //FI("in.txt");
    //FO("asa.txt");
    while(scanf("%d", &N) != EOF)
    {
        cnt = 1;
        ans.clear();
        for(auto& x : adj) x.clear();
        rep(i,0, N+1)
        {
            vis[i] = low[i] = num[i] = 0;
            P[i] = -1;
        }

        rep(it, 1, N)
        {

            scanf("%d (%d)", &u, &k);
            rep(ik,1,k)
            {
                scanf("%d", &v);
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        rep(i, 1, N)
        {
            if(!vis[i]) dfs(i);
        }
        sort(all(ans));
        printf("%d critical links\n", sz(ans));
        for(auto& x : ans) printf("%d - %d\n", x.F, x.S);
        printf("\n");
    }
    return 0;
}
