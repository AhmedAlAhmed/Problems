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
const int MAX = 10 + 1;
 
vi adj[MAX];
stack<int> st;
bool vis[MAX];
 
void dfs(int u)
{
    vis[u] = 1;
    for(auto& x: adj[u])
    {
        if(!vis[x])
            dfs(x);
    }
    st.push(u);
}
 
int main()
{
  //  rfile("in");
 
    int N, M;
    si(N); si(M);
    while(M--)
    {
        int a,b;
        si(a); si(b);
        adj[a].pb(b);
    }
 
    rep(i, 1, N)
        sort(all(adj[i]), greater<int>());
 
    for(int v = N;v>=1;--v)
        if(!vis[v])
            dfs(v);
 
    while(st.size())
    {
        int s = st.top();
        st.pop();
        if(st.empty()) cout <<s<< endl;
        else cout << s << " ";
    }
    return 0;
}
 

