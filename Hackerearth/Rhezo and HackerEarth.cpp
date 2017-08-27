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
const int MAX = 100000 + 1;
int N, M;


vector<int> adj[MAX];

int disc[MAX];
int low[MAX];
bool visited[MAX];
int parent[MAX];
//set<int> AP;
map<pii , bool> bridges;
int cnt = 0;
void solve(int v)
{
    visited[v] = 1;
    disc[v] = low[v] = ++cnt;
    int child = 0;
    for(int k = 0; k<adj[v].size(); k++)
    {
        int i = adj[v][k];

        if(! visited[i])
        {
            child++;
            parent[i] = v;
            solve(i);
            low[v] = min(low[v], low[i]);
            // if(parent[v] == -1 && child > 1)
            //  AP.insert(v);

            // if(parent[v] != -1 && low[i] >= disc[v])
            // AP.insert(v);

            if(low[i] > disc[v]) bridges[(MP(min(v,i), max(v,i)))] = 1;

        }
        else if (parent[v] != i)
        {
            low[v] = min(low[v], disc[i]);
        }

    }
}

int main()
{
   // freopen("input.txt", "r", stdin);


    ios::sync_with_stdio(0);
    cin.tie();
    cin >> N >> M;

    rep(i, 1, N)
    {
        visited[i] = 0;
        disc[i] = 0;
        low[i] = 0;
        parent[i] = 0;
    }

    int X, Y;
    vector<pii> edges;
    edges.reserve(M);
    lp(i, M)
    {
        cin >> X >> Y;
        adj[X].pb(Y);
        adj[Y].pb(X);
        edges[i].F = min(X,Y);
        edges[i].S = max(X, Y);
    }
    rep(i, 1, N)
        if(!visited[i]) solve(i);


    int Q;
    cin >> Q;

    cntr(Q)
    {
        cin >> X;
        X-- ;
        pii P = edges[X];
        if(bridges[P]==1)
            cout << "Unhappy\n";
        else
            cout << "Happy\n";

    }

    return 0;
}

