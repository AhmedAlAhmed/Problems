/*
 * main.cpp
 *
 *  Created on: Sep 4, 2017
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
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) x.size()
using namespace std;
const int MAX = 1e4 + 10;
int t,N,M,S,T,P,a,b,w;

struct Node {
	int Num, Value;
	Node(int n, int v) {
		Num = n, Value = v;
	}
	bool operator < (const Node& O) const {
		return Value > O.Value;
	}
};

void dijkstra(int src, vector< pii > adj[], vi& dist) {
	dist[src] = 0;
	priority_queue<Node> pq;
	pq.push(Node(src, 0));

	while(pq.size()) {
		Node tp = pq.top(); pq.pop();
		if(dist[tp.Num] < tp.Value) continue; // visited.

		for(auto& X : adj[tp.Num]) {
			if(dist[X.F] > dist[tp.Num] + X.S && dist[tp.Num] + X.S <= P){
				dist[X.F] = dist[tp.Num] + X.S;
				pq.push(Node(X.F, dist[tp.Num]));
			}
		}

	}
}

int main() {

//	rfile("samples.txt");
//	wfile("asd.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	rep(tc, 1, t) {
		vector< pii > adj[MAX];
		vector< pii > adj2[MAX];
		cin >> N >> M >> S >> T >> P;
		while(M-- ) {
			cin >> a >> b >> w;
			if(w > P) continue;
			adj[a].pb({b, w});
			adj2[b].pb({a, w});

		}

		vi dist1(MAX, 1e7), dist2(MAX, 1e7);
		dijkstra(S, adj, dist1);

		if(dist1[T] == 1e7) {
			cout << "-1" << endl;
			continue;
		}
		dijkstra(T, adj2, dist2);

		if(dist2[S] == 1e7) {
			cout << "-1" << endl;
			continue;
		}

		int ans = -1;
		rep(u, 1, N) for(auto& ni: adj[u]) {
			if(dist1[u]+dist2[ni.F]+ni.S <= P)
				ans = max(ans, ni.S);
		}
		cout << ans << endl;
	}


	return 0;
}




