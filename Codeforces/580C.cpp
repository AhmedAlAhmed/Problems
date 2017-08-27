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
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
#define INF (int) 1e12
using namespace std;



const int MAX = 79800 + 10;
int N,M, C;
int p[400+1];
int rnk[400+1];

void init(int n)
{
    rep(i,0,n)
    {
        p[i] = i;
        rnk[i] = 0;
    }
}
int findp(int x)
{
    if(x != p[x]) p[x] = findp(p[x]);
    return p[x];
}
void uni(int x, int y)
{
    x = findp(x), y = findp(y);
    if(x == y) return;

    if(rnk[x] > rnk[y])
    {
        p[y] = x;
        rnk[x] ++ ;
    }else
    {
        p[x]  =y;
        rnk[y]++;
    }
}

ll solve(vector< pair<ll, pii > > adj)
{
    ll sum = 0;
    int cnt = 0;
    lp(i, adj.size())
    {
        int X =adj[i].S.F;
        int Y = adj[i].S.S;
        ll Cost = adj[i].F;

        if(findp(X) != findp(Y))
        {
            sum += Cost;
            uni(X, Y);
            cnt++;

        }
    }

    return (cnt == N-1 ? sum : -1);
}
int tmm = 1;
int main()
{

   // rfile("in");
 //   wfile("sss");
    string str, str2;
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    while(1)
    {
        cin >> N >> M;
        tmm = 1;
        if(N == 0 && M == 0) return 0;

        init(N);


        map<string, int> mapp;
        vector< pair<ll, pii > >  adj;

        rep(i,1,N)
        {
            cin >> str;
            mapp[str] = tmm++;
        }


        rep(i, 1, M)
        {
            cin >> str >> str2;
            cin >> C;
            adj.pb(MP(C, MP(mapp[str], mapp[str2])));
        }
        cin >> str;
        int sn = mapp[str];

        sort(all(adj));
        ll ans = solve(adj);
        if(ans == -1)
            cout << "Impossible" << endl;
        else cout << ans << endl;


    }
    return 0;
}











