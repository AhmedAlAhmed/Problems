#include <bits/stdc++.h>
#define lp(i,n) for(int i=0;i<(n);++i)
#define rep(i,s,n) for(int i=(s);i<=(n);i++)
#define rep(i,s,n) for(int i=(n);i>=(s);--i)
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

#define MAX 1003;
#define m 1000000007
using namespace std;


void multiply(ll f[][2],ll g[][2])
{
    ll a=(f[0][0]*g[0][0]+f[0][1]*g[1][0])%m;

    ll b=(f[0][0]*g[0][1]+f[0][1]*g[1][1])%m;
    ll c=(f[1][0]*g[0][0]+f[1][1]*g[1][0])%m;
    ll d=(f[1][0]*g[0][1]+f[1][1]*g[1][1])%m;

    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}
void power(ll f[2][2],ll n)
{
    ll g[2][2]={{1,1},{1,0}};
    if(n==0||n==1)
    return;
    power(f,n/2);
    multiply(f,f);

    if(n%2==1)
    multiply(f,g);
}
ll fib(ll n)
{
    ll f[2][2]={{1,1},{1,0}};
    if(n==0)
    return 0;
    power(f,n-1);
    return f[0][0]%m;
}

int parent[1000009];
int rnk[1000009];

void init(int N)
{
    rep(i, 1, N+10) parent[i] = i;
}

int findParent(int x)
{
    if(x != parent[x])
         parent[x]=findParent(parent[x]);

    return parent[x];
}

void merge1(int u, int v)
{
    int xu = findParent(u), yv = findParent(v);
    if(rnk[xu] < rnk[yv])
        parent[xu] = yv; // yv is the parent.
    else if (rnk[xu] > rnk[yv])
        parent[yv] = xu;
    else
    {
        parent[yv] = xu;
        rnk[xu]++;
    }
}


vector< pair<ll, pii > >   constructGraph(int N, ll K1, ll K2, ll K3, ll K4)
{
    vector< pair<ll, pii > > adjList;
    init(N*N);
    ll f1 = fib(K1), f2 = fib(K2), f3 = fib(K3), f4 = fib(K4);
    ll f_1 = fib(K1-1), f_2 = fib(K2-1), f_3 = fib(K3-1), f_4 = fib(K4-1);
    lp(i, N) lp(j , N-1)
    {
        int u = i*N + j;
        int v = u+1;

        ll c = (f1 + f2)%m;
        adjList.pb(MP(c, MP(u, v)));
        ll f11 = f1 + f_1;
        if(f11 >= m)
            f11 = f11%m;
        f_1 = f1;
        f1 = f11;

        ll f22 = f2 + f_2;
        if(f22 >= m) f22 = f22 % m;
        f_2 = f2;
        f2 = f22;
    }

    lp(i, N) lp(j , N-1)
    {
        int u = j*N + i;
        int v = u+N;

        ll c = (f3 + f4)%m;
        adjList.pb(MP(c, MP(u, v)));

        ll f33 = f3 + f_3;
        if(f33 >= m) f33 = f33 % m;
        f_3 = f3;
        f3 = f33;

        ll f44 = f4 + f_4;
        if(f44 >= m) f44 = f44%m;
        f_4 = f4;
        f4 = f44;
    }

    return adjList;
}

ll MST( vector< pair<ll, pii > > graph)
{
    ll sum = 0;
    sort(all(graph));


    lp(i, graph.size())
    {
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        ll cost = graph[i].first;

        if(findParent(u) != findParent(v))
        {
            sum += cost;
            merge1(u, v);
        }
    }

    return sum;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie();
    int N;
    ll K1,K2,K3,K4;
   // scanf("%d%lld%lld%lld%lld", &N, &K1, &K2, &K3, &K4);
    cin >> N >> K1 >> K2 >> K3 >> K4;
    vector< pair<ll, pii > > adjList= constructGraph(N, K1, K2, K3, K4);

   // printf("%lld\n", MST(adjList));

    cout << MST(adjList) << "\n";


    return 0;
}

