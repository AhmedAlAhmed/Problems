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
const int MAX = 300;
int N, M;

bool adj[MAX][MAX];
int disc[MAX];
int low[MAX];
bool visited[MAX];
int parent[MAX];
bool AP[MAX];

int cnt = 0;
void solve(int v)
{
    visited[v] = 1;
    disc[v] = low[v] = ++cnt;
    int child = 0;
    rep(i, 1, N)
    {
        if(adj[v][i])
        {
            if(! visited[i])
            {
                child++;
                parent[i] = v;
                solve(i);
                low[v] = min(low[v], low[i]);
                if(parent[v] == 0 && child > 1)
                    AP[v] = 1;

                if(parent[v] != 0 && low[i] >= disc[v])
                    AP[v] = 1;


            }else if (parent[v] != i)
            {
                low[v] = min(low[v], disc[i]);
            }
        }
    }
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("oo.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie();
    cin >> N >> M;

    rep(i, 0, N+10)
    {
        visited[i] = 0;
        low[i] = 0;
        disc[i] = 0;
        parent[i] = 0;
        AP[i] = false;
    }
    int X, Y;
    while(M--)
    {
        cin >> X >> Y;
        adj[X][Y] = 1;
        adj[Y][X] = 1;
    }
    rep(i, 1, N)
        if(!visited[i])
            solve(i);

    int Q;
    cin >> Q;

    while(Q--)
    {
        cin >> X;
        if(AP[X])
        {
            int H = 0;
            rep(i, 1, N)
                if(adj[X][i]) H++;
            cout << "Satisfied " << H << "\n";
        }

        else
            cout << "Not Satisfied\n";
    }


    return 0;
}

