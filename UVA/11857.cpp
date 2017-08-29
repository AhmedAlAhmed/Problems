/*
 * main.cpp
 *
 *  Created on: Aug 29, 2017
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
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) x.size()

using namespace std;
int N, M;
const int MAX = 1e6 + 10;
struct Edge {
	int x, y, w;
} Edges[MAX];
int P[MAX], R[MAX];
bool vis[MAX];
vi adj[MAX];

void init(int n) {
	lp(i, n+2){
		P[i] = i;
		R[i] = 0;
		vis[i] = 0;
	}
}

int findp(int u){
	if(u != P[u]) P[u] = findp(P[u]);

	return P[u];
}

void Union(int u, int v) {
	u = findp(u), v = findp(v);
	if(u == v) return;

	if(R[u] > R[v]) {
		P[v] = u;
		R[u]++;
	}else {
		P[u] = v;
		R[v]++;
	}

}
void dfs(int u) {
	vis[u] = 1;
	for(auto&x : adj[u])
		if(! vis[x]) dfs(x);
}
bool cmp(Edge e1, Edge e2) {
	return e1.w < e2.w;
}
int main() {

	int x,y,z;
	//rfile("in.txt");
	//wfile("iii.txt");

	while(true) {
		scanf("%d%d", &N, &M);
		init(N+1);
		if(N+M == 0) break;
		for(auto&x : adj) x.clear();
		lp(i,M) {
			scanf("%d%d%d", &x, &y, &z);
			Edges[i].w = z;
			Edges[i].y = y;
			Edges[i].x = x;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int cnt = 0;
		lp(i, N) {
			if(! vis[i]) {
				cnt++;
				if(cnt > 1) break;
				dfs(i);
			}
		}
		if(cnt > 1) {
			printf("IMPOSSIBLE\n");
			continue;
		}else {
			int ans = 0;

			sort(Edges, Edges+M, cmp);


			cnt = 0;
			lp(i, M) {
				if(cnt == N-1) break;
				int x = findp(Edges[i].x);
				int y = findp(Edges[i].y);
				if( x != y ){
					Union( Edges[i].x, Edges[i].y );
					cnt++;
					ans = max(ans, Edges[i].w);

				}
			}

			printf("%d\n", ans);
		}
	}
	return 0;
}
