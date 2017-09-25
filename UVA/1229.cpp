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
vector<int> ans;
bool vis[MAX];
stack<int> st;
map<string,int> R; map<int,string> T;

void dfs1(int u) {
	vis[u] = 1;
	for(auto&x : adj[u]) if(!vis[x]) dfs1(x);
	st.push(u);
}
vector<string> rs;
int a = 0;
void dfs2(int u) {
	ans.pb(u);
	vis[u] = 1;

	for(auto&x : radj[u]) if(!vis[x]) dfs2(x);
}

void dfs3(int u) {
	rs.pb(T[u]);
	vis[u] = 1;
	a++;
	for(auto&x : adj[u]) if(!vis[x]) dfs3(x);
}
void solve() {
	clr(vis,0);
	a = 0;
	rs.clear();
	rep(i,1,N) if(!vis[i]) dfs1(i);
	clr(vis, 0);
	vector<int> final;
	while(st.size()) {
		int u = st.top(); st.pop();
		if(vis[u]) continue;
		dfs2(u);
		if(sz(ans) > 1) {
			for(auto&x : ans) final.pb(x);
		}
		ans.clear();
	}


	clr(vis, 0);
	for(auto& u : final) if(!vis[u]) dfs3(u);
	sort(all(rs));
	cout << a << endl;
	lp(i, sz(rs)) {
		cout << rs[i] ;
		if(i < sz(rs)-1) cout << " ";
	}
	cout << endl;

}

int main() {
	//FI("in.txt");
	//FO("out.txt");
	string line,word;
	while(cin >> N && N) {
		cin.ignore();
		R.clear(); T.clear();
		for(auto&x : adj) x.clear();
		for(auto&x : radj) x.clear();
		ans.clear();

		int cnt = 1;
		rep(it,1,N) {
			getline(cin, line);
			istringstream iss(line);
			iss >> word;
			if(R.find(word) == R.end()) {
				R[word] = cnt++;
				T[cnt-1] = word;
			}
			int s = R[word];
			while(iss >> word) {
				if(R.find(word) == R.end()) {
					R[word] = cnt++;
					T[cnt-1] = word;
				}
				int t = R[word];
				adj[s].pb(t);
				radj[t].pb(s);
			}
		}
		solve();
	}
	return 0;
}


