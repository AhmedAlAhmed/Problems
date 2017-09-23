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
#define FASTIO ios::sync_with_stdio(0); cin.tie(); cout.tie();
using namespace std;
const int MAX = 1000005;
int N, M, a, b, cnt;
vi adj[MAX];
int in[MAX];
int main()
{
    FASTIO ;
   // FI("in.txt");
   // FO("iaa.txt");
    while(cin >> N >> M && (N+M) > 0) {
        cnt = 0 ;
        rep(it,0, N+1) {
            adj[it].clear();
            in[it] = 0;
        }
        rep(it,1,M) {
            cin >> a >> b;
            adj[a].pb(b);
            in[b]++;
        }
        priority_queue<int, vi , greater<int> > q;
        rep(i,1,N) if(in[i]==0) q.push(i);
        int indx = 0;
        int ans[MAX];
        while(q.size()) {
            int u = q.top(); q.pop();
            ans[indx++] = u;
            cnt++;
            for(auto&v : adj[u]) {
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        if(cnt == 0 || cnt != N)
            cout << "IMPOSSIBLE" << endl;
        else lp(i,N) cout << ans[i] << endl;
    }
    return 0;
}
