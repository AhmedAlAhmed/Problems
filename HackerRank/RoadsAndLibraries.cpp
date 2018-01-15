//============================================================================
// Name        : Roads.cpp
// Author      : Ahmed Al-Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


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
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
using namespace std;
const int MAX = 1e5 + 1;
int N,M, Clib, Croad;
vi adj[MAX];
bool vis[MAX];
int c = 0;
void dfs(int u) {
	vis[u] = 1;
	c++;
	for(auto&v : adj[u]) if (! vis[v]) dfs(v);
}
ll solve() {
	clr(vis, 0);
	ll cost = 0LL;
	lp(i, N) {
		if(!vis[i]) {
			c = 0;
			dfs(i);
			cost += Clib + (1LL*(c-1)*Croad);
		}
	}
	return cost;
}
int main() {

//	FI("in.txt");
	int t;
	si(t);
	lp(TC, t) {

		if(Clib > Croad) {
			for(auto&x : adj) x.clear();
		}
		si(N); si(M); si(Clib); si(Croad);
		lp(i, M) {
			int a,b;
			si(a); si(b);
			a--; b--;
			if(Clib > Croad) {
				adj[a].pb(b); adj[b].pb(a);
			}
		}
		if(Clib < Croad) {
			cout << 1LL * Clib * N << endl;
		}else{

			cout << solve() << endl;
		}

	}
	return 0;
}
