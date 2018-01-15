//============================================================================
// Name        : Even.cpp
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
const int MAX  = 100 + 5;

vi adj[MAX];
bool vis[MAX];
int cnt[MAX];

void dfs(int u) {
	vis[u] = 1;
	cnt[u] = 1;
	for(auto&v : adj[u]) if (!vis[v]) {
		dfs(v);
		cnt[u] += cnt[v];
	}
}

int N, M;
int main() {
	//FI("in.txt");
	si(N); si(M);

	int a,b;
	rep(tc, 1, M) {
		si(a); si(b);
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(0);
	int c = 0;
	lp(i, N) {
		//cout << i+1 << " : " << cnt[i] << endl;
		if(cnt[i]%2 == 0 && i > 0) c++;

	}
	cout << c << endl;
	return 0;
}
