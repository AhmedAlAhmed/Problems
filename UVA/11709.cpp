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
const int MAX = 1000 + 5;
vi adj[MAX], radj[MAX];

bool vis[MAX];
int P,T,cnt = 1;
stack<int> st;
void dfs1(int u) {
	vis[u] = 1; for(auto&v : adj[u]) if(!vis[v]) dfs1(v);
	st.push(u);
}

void dfs2(int u) {
	vis[u] = 1; for(auto&v : radj[u]) if(!vis[v]) dfs2(v);
}
void solve() {
	rep(u,1,P) if(!vis[u]) dfs1(u);
	rep(u,0,P+1) vis[u] = 0;
	int ans = 0;
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue;
		dfs2(u);
		ans ++;
	}
	cout << ans << endl;
}
int main() {

	//FI("in.txt");

	while(cin >> P >> T && (P+T) > 0) {
		for(auto&x : adj) x.clear();
		for(auto&x : radj) x.clear();

		lp(i, P+1) vis[i] = 0;
		cnt = 1;
		map<string,int> R;
		st = stack<int>();
		cin.ignore();
		string l1,l2;
		rep(it,1,P) {
			getline(cin,l1);
			R[l1] = cnt++;
		}
		l1 = l2  = "";
		rep(it,1,T) {
			getline(cin,l1);
			getline(cin,l2);
			int a = R[l1], b = R[l2];

			adj[a].pb(b);
			radj[b].pb(a);
		}
		solve();
	}
	return 0;
}
