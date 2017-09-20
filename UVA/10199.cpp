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

const int MAX = 100 + 10;
int N,M;
int cnt =1, timer = 1, tc = 1;
string s1,s2;
map<string, int> R;
vi adj[MAX] ;
int num[MAX], low[MAX], P[MAX];
bool vis[MAX], AP[MAX];
string T[MAX];
vector<string> ans;

void dfs(int u) {
    int child = 0;
    num[u] = low[u] = cnt ++ ;
    vis[u] = 1;
    for(auto& v : adj[u]) {
        if(!vis[v]) {

            child ++ ;
            P[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(P[u] == 0 && child > 1) AP[u] = 1;
            if(P[u] != 0 && num[u] <= low[v]) AP[u] = 1;

        }else if(P[u] != v) {
            low[u] = min(low[u], num[v]);
        }
    }
}


int main()
{
  //  FI("in.txt");
   // FO("ads.txt");
    ios::sync_with_stdio(0); cin.tie(); cout.tie();
    bool fst = 1;
    while(cin >> N && N) {
        if(!fst) cout << endl;
        fst = 0;
        cnt = timer = 1;
        R.clear();
        ans.clear();
        for(auto&x : adj) x.clear();
        rep(i,0,MAX-1) {
            num[i] = low[i] = vis[i] = P[i] = AP[i] = 0;
            T[i]  = "";
        }
        rep(it, 1, N) {
            cin >> s1;
            R[s1] = cnt++;
            T[cnt-1] = s1;
        }
        cin >> M ;
        rep(it, 1, M) {
            cin >> s1 >> s2;
            adj[R[s1]].pb(R[s2]);
            adj[R[s2]].pb(R[s1]);
        }
        rep(v, 1, N) {
            if(! vis[v] ) dfs(v);
        }
        rep(i,1,N) if(AP[i]) ans.pb(T[i]);
        sort(all(ans));
        cout << "City map #"
             << tc << ": "
             << ans.size()
             <<" camera(s) found"
             << endl;

        for(auto& x : ans) cout << x << endl;


        tc++;

    }
    return 0;
}
