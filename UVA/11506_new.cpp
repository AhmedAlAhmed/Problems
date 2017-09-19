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
const int MAX = 200;

int s,t;
int p[MAX];

vi adj[MAX];
int res[MAX][MAX];
ll f,mf;
int N,M,a,b,c,cap;

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

int in(int i){ return 2*i; }
int out(int i){ return 2*i+1; }
int main()
{

   // FI("in.txt");
   // FO("a.txt");
    ios::sync_with_stdio(0); cin.tie(); cout.tie();

    while(cin >> N >> M && (N+M) > 0) {

       clr(res, 0);
       for(auto& x : adj) x.clear();


        s = 1, t = N;

        res[in(s)][out(s)] = res[in(t)][out(t)] = INF;

        adj[in(s)].pb(out(s));
        adj[out(s)].pb(in(s));

        adj[in(t)].pb(out(t));
        adj[out(t)].pb(in(t));

        rep(it, 1, N-2) {
            cin >> a >> cap;

            res[in(a)][out(a)] = res[out(a)][in(a)] = cap;

            adj[in(a)].pb(out(a));
            adj[out(a)].pb(in(a));


        }

        rep(it, 1, M) {
            cin >> a >> b >> c;

            res[out(a)][in(b)] += c;
            res[out(b)][in(a)] += c;

            adj[out(a)].pb(in(b));
            adj[in(b)].pb(out(a));
            adj[out(b)].pb(in(a));
            adj[in(a)].pb(out(b));
        }


        s = in(1), t = out(N);

        go();
        cout << mf << endl;

        //cout << g.DinicMaxflow(s, t) << endl;

    }
    return 0;
}
