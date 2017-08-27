/*
 * main.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: ahmed
 */
#include <bits/stdc++.h>
#include <vector>
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
 
const int MAX = 20 + 1;
bool vis[MAX] ;
 
struct Edge
{
 
    int u,v,c;
};
int timer = 1;
int num[MAX];
int dfn[MAX];
vi adj[MAX] ;
 
bool dfs(int u, int p) {
 
	dfn[u] = num[u] = timer++;
	vis[u] = 1;
 
	for(auto& x : adj[u]) {
 
		if(x == p) continue;
 
		if(! vis[x]) {
			if(! dfs(x, u)) return 0;
 
			if(num[x] > num[u]) return 0;
			num[u] = min(num[u], num[x]);
		}else {
			num[u] = min(num[u], dfn[x]);
		}
	}
	return 1;
}
int main() {
 
	   // rfile("input.txt");
	    int tc = 1;
	    int N, M;
	    while( 1 )
	    {
	        si(N);
	        si(M);
	        if(!N && !M ) break;
 
	        vector<Edge> edges;
	        rep(mt, 1, M)
	        {
	            Edge e;
	            si(e.u);
	            si(e.v);
	            si(e.c);
	            edges.pb(e);
	        }
 
	        ll ans = numeric_limits<ll>::max();
	        bool fnd = 0;
	        for (int mask = 0; mask < (1<<M); ++mask) {
	        	ll cost = 0;
	        	for (int v = 0;  v <= N; ++ v) {
					adj[v].clear();
					clr(vis, 0);
					num[v] = dfn[v] = 0;
				}
	        	timer = 0;
 
	        	for(int j=0;j<M;j++) {
	        		if(mask & (1 << j)) {
	        			Edge e = edges[j];
	        			adj[e.v].pb(e.u);
	        			adj[e.u].pb(e.v);
	        			cost += e.c;
	        		}
	        	}
 
	        	if(dfs(1, -1) && timer == N) {
	        		if(cost < ans) {
	        			ans = cost;
	        			fnd = true;
	        		}
	        	}
			}
 
	        if(fnd) {
	        	printf("The minimal cost for test case %d is %lld.\n", tc, ans);
	        }else {
	        	printf("There is no reliable net possible for test case %d.\n", tc);
	        }
 
	        tc++;
 
	    }
	return 0;
}
 
 
 
 
