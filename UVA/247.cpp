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

const int MAX = 25 + 5;
map<string, int> mapper;
map<int, string> mapper2;
vi adjList[MAX];
vi rev_AdjList[MAX];
int N, M;
bool vis[MAX];
stack<int> st;
int f = 0;
vi answers;

void dfs1(int v)
{
    vis[v] = 1;
    lp(i, adjList[v].size())
    {
        int ni = adjList[v][i];
        if( ! vis[ ni ])
            dfs1(ni);
    }
    st.push(v);
}

void dfs2(int v)
{
    vis[v] = 1;
    answers.pb(v);
    lp(i, rev_AdjList[v].size())
    {
        int ni = rev_AdjList[v][i];
        if( ! vis[ni] )
        {
            dfs2(ni);
        }
    }
    st.push(v);
}

void solve(int tc)
{
    st = stack<int>();
    if(f == 1)
        cout << endl;
    clr(vis, 0);

    rep(i, 1, N)
    {
        if(! vis[i]) dfs1(i);
    }
    clr(vis, 0);
    printf("Calling circles for data set %d:\n", tc);
    while(st.size())
    {
        int s = st.top();
        st.pop();

        if(vis[s]) continue;
        answers.clear();
        dfs2(s);
        for(int i=0; i<answers.size(); i++)
        {
            int ans = answers[i];
            cout << mapper2[ ans ];
            if(i < answers.size()-1) cout << ", ";
            else cout << "\n";
        }

    }

    f = 1;

}


int main()
{

    //rfile("in");
    string s1,s2;
    int tc = 1;
    while(1)
    {
        si(N);
        si(M);
        if(N == 0 && M == 0) break;
        int cnt = 0;


        mapper.clear();
        mapper2.clear();
        for(auto& v : adjList) v.clear();
        for(auto& v : rev_AdjList) v.clear();

        cntr(M)
        {
            cin >> s1 >> s2;
            if(mapper[s1] == 0)
                mapper[s1] = ++cnt;
            if (mapper[s2] == 0)
                mapper[s2] = ++cnt;

            mapper2 [ mapper[s1] ] = s1;
            mapper2 [ mapper[s2] ] = s2;

            adjList[mapper[s1]].pb(mapper[s2]);
            rev_AdjList[mapper[s2]].pb(mapper[s1]);

        }
        solve(tc);

        tc++;
    }
    return 0;
}



