/*
 * mian.cpp
 *
 *  Created on: Sep 2, 2017
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

const int MAX = 3000 ;

vector< pair<int, char> > Vec[MAX];

struct Triple{
	int Node, Value;
	char lastChar;
	Triple(int n, int v, char l) {
		Node = n;
		Value = v;
		lastChar = l;
	}
	bool operator < (const Triple& T) const {
		return Value > T.Value;
	}
};
vector< Triple > adj[MAX];

void dijkstra(int st, int en) {
	int dist[MAX][30];

	lp(i, MAX) lp(j, 30) {
		dist[i][j] = 1e9;

	}

	lp(i, 30) dist[st][i] = 0;

	priority_queue< Triple > pq;

	pq.push(Triple(st, 0, 'a'+26));

	while(pq.size()) {
		Triple P = pq.top(); pq.pop();

		if(P.Node == en) break;

		if(dist[P.Node][P.lastChar-'a'] <  P.Value)  continue;
			int u = P.Node;

			for(auto& ni : adj[u]) {
				int v = ni.Node;
				int w = ni.Value;
				char lc = ni.lastChar;

				if(lc == P.lastChar) continue;

				if(dist[v][lc - 'a'] > dist[u][P.lastChar-'a'] + w ) {
					dist[v][lc - 'a'] = dist[u][P.lastChar-'a'] + w;
					pq.push(Triple(v, dist[v][lc-'a'], lc));
				}
			}


	}
	//impossivel
	int ans = dist[en][0];
	lp(i, 30) {
		ans = min(ans, dist[en][i]);
	}
	if(ans == 1e9) {
		cout << "impossivel\n";
	}else {
		cout << ans << endl;
	}
}


int main() {

	rfile("in.txt");
	wfile("asd.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	map<string, int> m;
	int N;
	string L1, L2;
	string n1,n2,word;

	while(1) {

		for(auto& x : adj) x.clear();
		m.clear();

		cin >> N;

		int cnt = 1;
		if(N == 0) break;

		cin >> L1 >> L2;

		int src = m[L1] = cnt++;

		int dest = m[L2] = cnt++;

		while(N--) {

			cin >> n1 >> n2 >> word;

			int a = m[n1],b = m[n2];

			if(a == 0) {
				a = m[n1] = cnt++;
			}
			if(b == 0) {
				b = m[n2] = cnt++;
			}

			adj[a].pb(Triple(b, word.length(), word[0]));
			adj[b].pb(Triple(a, word.length(), word[0]));

		}

		dijkstra(src, dest);
	}
	return 0;
}


