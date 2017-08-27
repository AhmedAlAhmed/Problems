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
const int MAX = 11;
int Maz[MAX][MAX];
int N, M;
bool vis[MAX][MAX];
bool solve(int i, int j)
{
    if(i == N && j == M) return 1;
    if(i > N || j > M) return 0;
    if(i < 1 || j < 0) return 0;

    if(vis[i][j]) return 0;

    vis[i][j] = 1;

    if(Maz[i+1][j])
        if(solve(i+1, j)) return 1;

    if(Maz[i][j+1])
        if(solve(i, j+1)) return 1;

    if(Maz[i-1][j])
        if(solve(i-1, j)) return 1;

    if(Maz[i][j-1])
        if(solve(i, j-1)) return 1;

     return 0;

}

int main()
{

    //freopen("input.txt", "r", stdin);
    cin >> N >> M;
    clr(vis, 0);
    rep(i, 1, N) rep(j, 1, M) cin >> Maz[i][j];

    cout << (solve(1, 1)==1 ? "Yes" : "No") << endl;

    return 0;
}

