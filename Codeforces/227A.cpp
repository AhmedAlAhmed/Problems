/*
 * main.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: ahmed
 */

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
#define si2(x,y) scanf("%d %d", &x, &y)
#define si3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) ((int)(x.size()))
using namespace std;

const int MAX = 100 + 1;
vi adj[2*MAX + 10];
bool vis[2*MAX + 10];

void dfs(int u) {
	vis[u] = 1;
	for(auto&x : adj[u]) if(!vis[x])
		dfs(x);

}
int main() {

	//FI("in.txt");
	int N,M,k,a;
	cin >> N >> M;
	bool f = 1;
	rep(i, 1, N) {
		cin >> k;
		if(k > 0) f = 0;
		while(k--) {
			cin >> a;
			a = a + MAX;
			adj[i].pb(a);
			adj[a].pb(i);
		}
	}
	if(f) {
		cout << N << endl;
		return 0;
	}

	int cnt = 0;
	rep(i,1,N) {
		if(!vis[i]) {
			dfs(i);cnt++;
		}
	}
	if(cnt > 0) cout << cnt-1 << endl;
	else cout << cnt << endl;

	return 0;
}


// http://codeforces.com/problemset/problem/277/A
