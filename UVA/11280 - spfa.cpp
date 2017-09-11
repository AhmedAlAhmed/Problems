/*
 * main.cpp
 *
 *  Created on: Sep 10, 2017
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

int t,N, M, a,b,c, Q;
string s1, s2;
map<string, int > mm;
int src, dest;

const int MAXM = 1000 + 10;
const int MAXN = 100 + 10;

vector< pii > adj[MAXN];

bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];

struct edge {
	int to, O;
	edge(int t, int o){
		to = t;
		O = o;
	}
};

void spfa() {

	lp(u, MAXN) lp(v, MAXN) {
					dist[u][v] = 1e9;
					if(u==v) dist[u][v] = 0;
					vis[u][v]  = 0;
	}
	queue< edge > q;

	q.push(edge(src, 0));

	vis[src][0] = 1;
	dist[src][0] = 0;

	while(q.size()) {
		edge e = q.front(); q.pop();

		int u = e.to, o = e.O;
		vis[u][o] = 0;
		if(dist[u][o] >= 1e9) continue ;

		for(auto& ni : adj[u]) {
			int v = ni.F, w = ni.S;
			if(w >= 1e9) continue;
			if(dist[v][o+1] > dist[u][o] + w) {
				dist[v][o+1] = dist[u][o] + w;

				if(! vis[v][o+1]) {
					q.push(edge(v, o+1));
					vis[v][o+1] = 1;
				}
			}
		}

	}
}



void solve1(int len) {
	int ak = 1e9;

	rep(k ,1, N-1) {
		if(len >= k-1) ak = min(ak, dist[dest][k]);
	}

	if(ak == 1e9) {
		cout << "No satisfactory flights" << endl;
	}else {
		cout << "Total cost of flight(s) is $" << ak << endl;
	}
}





int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//rfile("i.txt");
	//wfile("ads.tx");
	cin >> t;
	rep(tc, 1, t) {

		for(auto& x : adj) x.clear();
		mm.clear();
		cout << "Scenario #" << tc << endl;





		int cnt = 1;

		cin >> N;
		rep(i, 1, N) {
			cin >> s1;
			mm[ s1 ] = i;
			if(s1 == "Calgary") src = mm [ s1 ];
			if(s1 == "Fredericton") dest = mm [ s1 ];
		}
		cin >> M;
		lp(i, M) {

			cin >> s1 >> s2 >> c;
			a = mm [ s1 ], b = mm [ s2 ];

			adj[a].pb({b, c});

		}

		spfa();
		cin >> Q;
		int uj;
		lp(k,Q) {
			cin >> uj;
			solve1(uj);
		}
		if(tc < t) cout<<endl;
	}


	return 0;
}





