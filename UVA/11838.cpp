/*
 * main.cpp
 *
 *  Created on: Sep 25, 2017
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
const int MAX = 2000 + 5;
int N;
vi adj[MAX], radj[MAX];
bool vis[MAX];
stack<int> st;
void dfs1(int u) {
	vis[u] = 1;
	for(auto&x : adj[u]) if(!vis[x]) dfs1(x);
	st.push(u);
}
void dfs2(int u) {
	vis[u] = 1;
	for(auto&x : radj[u]) if(!vis[x]) dfs2(x);
}
void solve() {
	clr(vis,0);
	rep(i,1,N) if(!vis[i]) dfs1(i);
	clr(vis, 0);
	int a = 0;
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue;
		dfs2(u);
		a++;
	}
	if(a == 1) cout << "1" << endl;
	else cout << "0" << endl;
}
int main() {

	//FI("in.txt");
	int M,a,b,c;
	while(cin >> N >> M && (N+M) > 0) {

		st = stack<int>();
		for(auto&x : adj) x.clear();
		for(auto&x : radj) x.clear();

		rep(it,1,M) {
			cin >> a >> b >> c ;
			if(c == 1) {
				adj[a].pb(b);
				radj[b].pb(a);
			}else {
				adj[a].pb(b);
				adj[b].pb(a);
				radj[b].pb(a);
				radj[a].pb(b);
			}
		}
		solve();
	}

	return 0;
}
