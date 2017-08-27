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
#define pln() printf("\n")
#define pll(x) printf("%lld", x)
#define cntr(Q) while(Q--)
using namespace std;
int N, M;
ll dist[110][110];
int main()
{
// freopen("input.txt", "r", stdin);
ios::sync_with_stdio(0); cin.tie();
cin >> N >> M;
map<string, int> mapper;
string str;
rep(i, 1, N)
{
cin >> str;
mapper[str] = i; // 1 2 3 ... N

}
string str2;
ll w;

rep(i, 1, N) rep(j, 1, N)
{
if(i==j) dist[i][j] = 0;
else
dist[i][j] = 1e18;
}

rep(i, 1, M)
{
cin >> str >> str2 >> w;
dist[mapper[str]] [ mapper[str2] ] = w;
dist[mapper[str2]] [ mapper[str] ] = w;
}

rep(k, 1, N) rep(i, 1, N) rep(j, 1, N)
{
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
int Q;
cin >> Q;
cntr(Q)
{
cin >> str >> str2 ;
cout << dist[ mapper[str] ][ mapper[str2] ] << endl;
}
return 0;
}
