
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
#define pln() printf("\n")
#define pll(x) printf("%lld", x)
#define cntr(Q) while(Q--)
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
#define INF (int) 1e12
using namespace std;

const int MAX = 800;
int p[MAX];
int rnk[MAX];

struct edge
{
int a,b,d;

}E[MAX*MAX];

void init(int N)
{
rep(i,0,N)
{
p[i] = i;
rnk[i] = 0;
}
}
int findp(int u)
{
if(u != p[u]) p[u] = findp(p[u]);
return p[u];
}

int joint(int u, int v)
{
u = findp(u), v = findp(v);
if(u == v) return 0;
else
{
if(rnk[u] > rnk[v])
{
p[v] = u;
rnk[u]++;
}else {
p[u] = v;
rnk[v]++;
}

return 1;
}
}
bool CMP(edge E1, edge E2)
{
return E1.d < E2.d;
}
int main()
{

rfile("in.txt");
int N;
int t;
scanf("%d", &t);

rep(tc,1, t)
{

int x[MAX], y[MAX];
scanf("%d", &N);
init(N);

rep(i,1,N)
{
scanf("%d%d", &x[i], &y[i]);
}

int cnt = 0;
rep(i,1,N) rep(j,i+1,N)
{
E[cnt].a = i;
E[cnt].b = j;
E[cnt].d = ((x[i]-x[j])*(x[i]-x[j])) + (((y[i]-y[j])*(y[i]-y[j])));
cnt++;
}
int c = 0,M,a,b;

scanf("%d", &M);
while(M--)
{
scanf("%d%d", &a, &b);
c += joint(a,b);
}
if(c == N-1)
{
puts("No new highways need");
}else
{
sort(E, E+cnt, CMP);
lp(i, cnt)
{
if(joint(E[i].a, E[i].b))
{
printf("%d %d\n", E[i].a, E[i].b);
}
}
}

if(tc < t) puts("");

}

return 0;
}
