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
#define INF (int) 1e12
using namespace std;
const int MAX = 100 + 1;
int dist[MAX][MAX];
 
int main()
{
  //  rfile("in.txt");
  //  wfile("out.txt");
    int N,M,Q;
    int x,y,c;
    int tc = 1;
    bool f = 0;
    while(1)
    {
        si(N); si(M); si(Q);
        if(!N && !M && !Q) break;
        if(f) printf("\n");
        f = 1;
        rep(i, 1, N) rep(j, 1, N)
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
 
        cntr(M)
        {
            si(x); si(y); si(c);
            dist[x][y] = c;
            dist[y][x] = c;
        }
 
        rep(k,1,N) rep(i,1,N) rep(j,1,N)
            dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
 
        printf("Case #%d\n", tc++);
        cntr(Q)
        {
            si(x);si(y);
            if(dist[x][y] == INF)
                printf("no path\n");
            else printf("%d\n", dist[x][y]);
        }
 
 
    }
    return 0;
}
