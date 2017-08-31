/*
 * main.cpp
 *
 *  Created on: Aug 31, 2017
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
int N,M;
const int MAX = 510;

struct Node {
	int value,cost, flag;
	Node(int n, int c, int f) {
		value = n;
		cost = c;
		flag = f;
	}
	bool operator < (const Node& N) const{
		return cost > N.cost;
	}
};
void Dijkstra(vector< pii > adj[], int dist[MAX][2]) {
	priority_queue<Node> pq;
	dist[0][0] = 0;
	pq.push(Node(0,0,0));

	while(pq.size()) {
		Node top = pq.top(); pq.pop();

		int from = top.value;
		int cost = top.cost;
		bool flag = top.flag;

		if(dist[from][flag] < cost ) continue;
		for(auto& X : adj[from]) {

			int ni = X.first;
			int w = X.second;

			if(dist[ni][!flag] == -1 ||
					dist[ni][!flag] > dist[from][flag] + w) {

				dist[ni][!flag] = dist[from][flag] + w ;
				pq.push(Node(ni, dist[ni][!flag], !flag));
			}
		}
	}
}
void solve(vector< pii > adj[]) {
	int dist[MAX][2];
	clr(dist, -1);
	Dijkstra(adj, dist);
	if(dist[N-1][0] == -1) {
		cout << "?" << endl;
	}else {
		cout << dist[N-1][0] << endl;
	}
}
int main() {

	//rfile("in.txt");
	//wfile("ff.txt");
	int cnt = 1;
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();
	
	int a,b,w;
	while(cin >> N >> M) {
		vector< pii > adj[MAX] ;
		while(M--) {
			cin >> a >> b >> w;
			adj[a].pb({b,w});
			adj[b].pb({a,w});
		}
		cout << "Set #" << cnt++ << endl;
		solve(adj);
	}
	return 0;
}

