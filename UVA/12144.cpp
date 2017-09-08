/*
 * main.cpp
 *
 *  Created on: Sep 5, 2017
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
int N, M, a,b,w, S,T;
const int MAX = 500 + 10;
struct Node {
	int num, val;
	Node(int n, int v) {
		num = n, val = v;
	}
	bool operator < (const Node& O) const {
		return val > O.val;
	}
};
bool access[MAX][MAX];
vi Prev[MAX];
int dijkstra(vector< pii > adj[]) {
	vi dist(MAX, 1e9);

	priority_queue<Node> pq;
	pq.push(Node(S, 0));
	dist[S] = 0;
	while(pq.size()) {
		Node tp = pq.top(); pq.pop();
		if(dist[tp.num] < tp.val) continue;
		int u = tp.num;

		for(auto& ni : adj[u]) {
			int v = ni.F, w = ni.S;
			if(!access[u][v]) continue;

			if(dist[v] > dist[u] + w) {

				Prev[v].clear();
				Prev[v].pb(u);

				dist[v] = dist[u] + w;
				pq.push(Node(v, dist[u]+w));
			}
			if(dist[v] == dist[u] + w){
				Prev[v].pb(u);
			}
		}
	}
	return dist[T];

}


void MarkEdges(int v) {

	for(auto& u : Prev[v]) {
		access[u][v] = 0;
		MarkEdges(u);
	}
}

void solve(vector< pii > adj[]) {
	int ans = dijkstra(adj);

	if(ans == 1e9) {
		cout << "-1" << endl;
		return ;
	}


	MarkEdges(T);


	ans = dijkstra(adj);


	if(ans == 1e9) {
		cout << "-1" << endl;
		return ;
	}else cout << ans << endl;



}
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	rfile("in.txt");
//	wfile("asd.txt");
	while(cin >> N >> M && N+M > 0) {
		cin >> S >> T;

		lp(i, MAX) lp(j, MAX) access[i][j] = 1;

		for(auto& x: Prev) x.clear();

		vector< pii > adj[MAX];
		while(M--) {
			cin >> a >> b >> w;
			adj[a].pb({b, w});
		}
		solve(adj);
	}
	return 0;
}



