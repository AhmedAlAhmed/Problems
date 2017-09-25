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
const int MAX = 26 + 5;
bool G[MAX][MAX], rG[MAX][MAX], vis[MAX];
int N;
set<int> s;
stack<int> st;
void dfs1(int u) {
	vis[u] = 1;
	for(auto&v : s) if(G[u][v] && !vis[v]) dfs1(v);
	st.push(u);
}
vi comp;
vector < vi > allcomp;
void dfs2(int u) {
	vis[u] = 1;
	comp.pb(u);
	for(auto&v : s) if(rG[u][v] && !vis[v]) dfs2(v);
}
void solve() {
	for(auto&x : allcomp) x.clear();
	for(auto& x : s) if(!vis[x]) dfs1(x);

	clr(vis, 0);
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue;
		comp.clear();
		dfs2(u);
		sort(all(comp));
		allcomp.pb(comp);
	}
	sort(all(allcomp));
	for(auto& ans : allcomp) {
		lp(i, sz(ans)) {
			cout << ((char)(ans[i] + 'A'));
			if(i < sz(ans)-1) cout << " ";
		}
		if(sz(ans) > 0)
			cout << endl;
	}

}
int main() {

	//FI("in.txt");
	bool f = 1;
	char ch ;
	vi tmp;
	while(cin >> N && N>0) {
		if(!f) cout << "\n";
		f = 0;
		s.clear();
		clr(G, 0); clr(rG, 0); clr(vis, 0);
		st = stack<int>();

		rep(cnt, 1, N) {
			tmp.clear();
			rep(it,1,5) {
				cin >> ch;
				tmp.pb(ch-'A');
				s.insert(ch-'A');
			}
			cin >> ch;
			s.insert(ch-'A');
			lp(i, sz(tmp)) {
				G[ tmp[i] ][ch-'A'] = 1;
				rG[ch-'A'][tmp[i]] = 1;
			}
		}
		solve();
	}

	return 0;
}
