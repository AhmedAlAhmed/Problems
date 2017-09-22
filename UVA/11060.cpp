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
vi adj[MAX];

int main()
{
    ios::sync_with_stdio(0); cin.tie(); cout.tie();
   // FI("in.txt");
   // FO("a.txt");
    int N, M;
    map<string,int> R1;
    map<int, string> R2;
    int cnt = 1;
    string s1,s2;
    int tc = 1;
    while(cin >> N)
    {
        R1.clear(); R2.clear();
        for(auto& x : adj) x.clear();
        cnt = 1;

        rep(it,1,N) {
            cin >> s1;
            R1[s1] = cnt;
            R2[cnt] = s1;
            cnt++;
        }
        cin >> M;
        int indeg[MAX];
        clr(indeg, 0);

        rep(it,1,M) {
            cin >> s1 >> s2;
            adj[R1[s1]].pb(R1[s2]);
        }
        rep(i,1,N) for(auto& v : adj[i]) indeg[v]++;

        priority_queue<int, vector<int>, greater<int> >q;
        rep(i,1,N) if(indeg[i] == 0) q.push(i);

        cout << "Case #"<<(tc++)<< ": Dilbert should drink beverages in this order:";
        while(q.size()) {
            int u = q.top(); q.pop();
            cout << " "<< R2[u] ;
            for(auto& v : adj[u]) {
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }

        }

        cout << ".\n\n";

    }
    return 0;
}
