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
using namespace std;
int N, M;
const int MAX = 100000 + 5;

bool vis[MAX] = {0};
stack<int> st;
vi vec;

vi adj[MAX];
vi radj[MAX];

bool ans[MAX] = {0};

void dfs1(int v)
{
    vis[v] = 1;
    lp(i, adj[v].size())
    {
        if(! vis[adj[v][i]])
            dfs1(adj[v][i]);
    }
    st.push(v);
}

void dfs2(int v)
{
    vec.pb(v);

    vis[v] = 1;

    lp(i, radj[v].size())
    if(!vis[ radj[v][i] ])
        dfs2( radj[v][i] );

}

void go()
{
    rep(i, 1, N)
    if(!vis[i])
        dfs1(i);

    clr(vis, 0);

    while(!st.empty())
    {
        int h = st.top();

        st.pop();

        if(vis[h]) continue;

        dfs2(h);


        if(vec.size() > 1)
        {
            lp(k, vec.size())
                ans[vec[k]] = 1;

        }
        vec.clear();

    }
}


int main()
{
   // freopen("input.txt", "r", stdin);

    si(N);
    si(M);
    int x, y;

    cntr(M)
    {
        cin >> x >> y;
        adj[x].pb(y);
        radj[y].pb(x);

    }
    go();

    rep(i, 1, N)
    {
        if(i < N)
            cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }

    return 0;
}

