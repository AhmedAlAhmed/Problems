/*
 * main.cpp
 *
 *  Created on: Sep 3, 2017
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

struct Node {
	int N, V, E;
	Node(int n, int v, int e) {
		N = n, V = v, E = e;
	}
	bool operator < (const Node& other) const {
		return V > other.V;
	}
};
int n, k;
int Time[10];
vi nums[10];

vector<Node> adj[102];

void solve() {
	int dist[102];
	fill(dist, dist+102, 1e9);
	dist[0] = 0;
	priority_queue<Node> pq;
	pq.push(Node(0, 0, 0));
	bool f = 1;
	while(pq.size()) {
		Node tp = pq.top(); pq.pop();
		if(tp.N == k) {
			cout << dist[k] << endl;
			return;
		}

		if(dist[tp.N] < tp.V) continue;
		int u = tp.N;
		for(auto& ni : adj[u]) {
			int v = ni.N;
			int w = ni.V;
			if(ni.E != tp.E && !f) w += 60;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(Node(v, dist[v], ni.E));
			}
		}
		f = 0;
	}
	if(dist[k] == 1e9) {
		cout << "IMPOSSIBLE" << endl;
	}
}



int main() {
//	rfile("samples.txt");
//	wfile("asdasd.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string line ;
	while(cin >> n >> k) {
		rep(i,1,n) cin >> Time[i];

		for(auto& x : nums) x.clear();
		for(auto& x : adj) x.clear();
		getline(cin, line);

		stringstream ss;
		rep(I, 1, n) {
			getline(cin, line);
			ss.clear();
			//cout << line << endl;
			int a;
			ss << line;
			while(ss >> a) nums[I].pb(a);
		}



		rep(E, 1, n) {
			rep(a, 0, sz(nums[E])-1)
					rep(b, a+1, sz(nums[E])-1) {
				adj[nums[E][a]].pb(Node(nums[E][b], fabs(nums[E][a]-nums[E][b])*Time[E], E));
				adj[nums[E][b]].pb(Node(nums[E][a], fabs(nums[E][a]-nums[E][b])*Time[E], E));
			}
		}


		solve();

	}
	return 0;
}
