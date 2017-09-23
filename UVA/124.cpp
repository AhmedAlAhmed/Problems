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
const int MAX = 26 ;
vi adj[MAX];
vi nds;
vector<char> ans;
int indeg[MAX];
bool visited[MAX];
void init()
{
    for(auto&x : adj) x.clear();
    nds.clear();
    ans.clear();
    clr(indeg, 0);
    clr(visited, 0);
}
bool read()
{
    string line;
    if(getline(cin, line) && line.length() > 0)
    {
        lp(i, line.length())
        {
            if(line[i] != ' ') nds.pb(line[i]-'a');
        }
        getline(cin, line);
        for(int i=0; i<line.length(); i+=4)
        {
            adj[line[i]-'a'] .pb(line[i+2]-'a');
            indeg[ line[i+2]-'a' ] ++ ;
        }
        return 1;
    }
    return 0;
}

void solve()
{
    sort(all(nds));
    priority_queue<int, vi, greater<int> > q;
    bool f = 0;
    for(auto& a : nds) if(!visited[a] && indeg[a] == 0) {
        for(auto& ni : adj[a]) indeg[ni]--;
        ans.pb(a+'a');
        visited[a] = 1;
        solve();
        visited[a] = 0;
        ans.pop_back();
        for(auto& ni : adj[a]) indeg[ni]++;
        f = 1;
    }
    if(!f) {
        for(auto&o : ans) cout << o ;
        cout << endl;
    }

}
int main()
{
    FASTIO;
  //  FI("in.txt"); FO("out.txt");
    init();
    bool newline = 0;
    while(read())
    {
        if(newline) cout << endl;
        newline = 1;
        solve();
        init();

    }
    return 0;
}
