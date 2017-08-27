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
const int MAX = 10 + 1;
int N, M;

bool adj[MAX][MAX];
int disc[MAX];
int low[MAX];
bool visited[MAX];
int parent[MAX];
set<int> AP;
vector<pii> bridges;
int cnt = 0;
void solve(int v)
{
    visited[v] = 1;
    disc[v] = low[v] = ++cnt;
    int child = 0;
    lp(i, N)
    {
        if(adj[v][i])
        {
            if(! visited[i])
            {
                child++;
                parent[i] = v;
                solve(i);
                low[v] = min(low[v], low[i]);
                if(parent[v] == -1 && child > 1)
                    AP.insert(v);

                if(parent[v] != -1 && low[i] >= disc[v])
                    AP.insert(v);

                if(low[i] > disc[v]) bridges.pb(MP(min(v,i), max(v,i)));



            }else if (parent[v] != i)
            {
                low[v] = min(low[v], disc[i]);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    clr(visited, 0);
    clr(low, 0);
    clr(disc, 0);
    clr(parent, -1);
    ios::sync_with_stdio(0); cin.tie();
    cin >> N >> M;
    int X, Y;
    cntr(M)
    {
        cin >> X >> Y;
        adj[X][Y] = 1;
        adj[Y][X] = 1;
    }

    solve(0);
    cout << AP.size() << endl;
    for(set<int>::iterator it = AP.begin(); it != AP.end(); it++)
    {
        if(it != AP.begin())
            cout << " " << *it ;
        else cout << *it;
    }
    cout << endl;
    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << endl;
    lp(i, bridges.size())
        cout << bridges[i].F << " " << bridges[i].S << endl;

    return 0;
}

