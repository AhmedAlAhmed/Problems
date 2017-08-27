#include <bits/stdc++.h>
#include <vector>
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
#define EPS 1e-9
using namespace std;
 
const int MAX = 100;
int N;
 
int P[MAX + 1], rnk[MAX + 1], CNT[MAX + 1];
 
 
 
struct Circle
{
    float x, y, r;
 
} C[MAX + 1];
 
 
 
bool intersect(int i, int j)
{
 
    float dis = (C[i].x - C[j].x)*(C[i].x - C[j].x) +
                (C[i].y - C[j].y)*(C[i].y - C[j].y);
 
 
    float d1 = (C[i].r - C[j].r)*(C[i].r - C[j].r);
    float d2 = (C[i].r + C[j].r)*(C[i].r + C[j].r);
 
    return dis >= d1 && dis <= d2;
 
}
 
void init()
{
    rep(i, 1, N) {
        P[i] = i;
        rnk[i] = 0;
        CNT[i] = 1;
    }
}
 
int findSet(int u) {
 
    if(u != P[ u ]) {
 
        P[ u ] = findSet( P [ u ] ) ;
    }
    return P [ u ];
}
 
void Union(int u, int v) {
    u = findSet(u), v = findSet(v);
 
    if(u != v) {
 
        if(rnk[u] > rnk[v]) {
            P[v] = u;
            rnk[u] ++ ;
            CNT[u] += CNT[v];
        }else {
 
            P[u] = v;
            rnk[v] ++;
            CNT[v] += CNT[u];
        }
    }
}
 
int go()
{
    int mx = 0;
 
    rep(i,1,N)
    {
        rep(j, i+1, N)
        {
            if(intersect(i, j)) {
                Union(i, j);
            }
        }
    }
 
    rep(i, 1, N) {
        if(i == findSet(i)) {
            mx = max(mx, CNT[i]);
        }
    }
 
    return mx;
}
 
int main()
{
   // rfile("in.txt");
   // wfile("dddd.txt");
    while(1)
    {
        scanf("%d", &N);
        if(N == -1) break;
 
        init();
        rep(i,1,N)
        {
            scanf("%f%f%f", &C[i].x, &C[i].y, &C[i].r);
        }
        int ans = go();
        if(ans == 1)
            printf("The largest component contains %d ring.\n", ans);
        else printf("The largest component contains %d rings.\n", ans);
 
 
    }
    return 0;
}
 

