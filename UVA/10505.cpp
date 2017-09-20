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

const int MAX = 300 + 10;
vi adj[MAX];
int t, N, M, k, v ;
int ac[2];

bool isbir = 1;
vi dst(MAX, INF);
void bfs(int u)
{

    if(dst[u] != INF) return;

    queue<int> q;
    q.push(u);
    dst[u] = 0;
    ac[0]++;

    while(q.size())
    {
        int tp = q.front();
        q.pop();
        for(auto ni : adj[tp])
        {
            if(dst[ni] == INF)
            {
                dst[ni] = 1 - dst[tp];
                ac[dst[ni]]++;
                q.push(ni);
            }
            else if(dst[ni] == dst[tp])
            {
                isbir = 0;
            }

        }
    }
}



int main()
{
  //  FI("in.txt");

    //FO("oo.txt");
    cin >> t;
    while(t--)
    {
        for(auto& x : adj) x.clear();
        cin >> N;
        rep(i,0,N+5) dst[i] = INF;

        rep(u, 1, N)
        {
            cin >> k;
            rep(cnt, 1, k)
            {
                cin >> v;
                if(v <= N) {
                    adj[u].pb(v);
                    adj[v].pb(u);
                }
            }
        }

        int ans = 0;
        rep(j, 1, N)
        {
            ac[0] = ac[1] = 0;
            isbir = 1;
            bfs(j);

            if(isbir) ans += max(ac[0], ac[1]);
        }

        cout << ans << endl;
    }
    return 0;
}


