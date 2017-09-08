/*
 * main.cpp
 *
 *  Created on: Sep 8, 2017
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

int t,N,M,a,b,c;
const int MAXM = 2000 + 10;
const int MAXN = 1000 + 10;

struct edge {
	int from, to, cost;

	edge(int f, int t, int c) {
		edge();
		from = f;
		to = t;
		cost = c;
	}
	edge() {}
};

edge E[MAXM];
vector < pii > adjList[MAXN];
void checkNegCycle() {
	vi dist(MAXN, 1e9);
	dist[0] = 0;
	bool r = 0;
	rep(it, 1, N) {
		lp(i, M) {
			edge e = E[i];
			if(dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] + e.cost;
				r = 1;
				if(it == N) {
					cout << "possible" << endl;
					return;
				}
			}
		}
		if(!r) {
			cout << "not possible" << endl;
			return;
		}
	}
	cout << "not possible" << endl;
}
void checkNegCycle1() {
	vi dist(MAXN, 1e9);
	dist[0] = 0;
	bool r = 0;
	rep(it, 1, N) {
		lp(u, N) {
			vector < pii > Pni = adjList[u];
			for(auto&ni : Pni) {
				int v = ni.F, c = ni.S;
					if(dist[v] > dist[u] + c) {
						dist[v] = dist[u] + c;
						r = 1;
						if(it == N) {
							cout << "possible" << endl;
							return;
						}
					}
			}
		}
		if(!r) {
			cout << "not possible" << endl;
			return ;
		}
	}
	cout << "not possible" << endl;
}
int main() {

	//rfile("in.txt");
	//wfile("sadsa.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t-- ) {
		for(auto&x: adjList) x.clear();
		cin >> N >> M;
		lp(i, M) {
			//cin >> E[i].from >> E[i].to >> E[i].cost;
			cin >> a >> b >> c;
			adjList[a].pb({b, c});
		}
		//checkNegCycle();
		checkNegCycle1();
	}

	return 0;
}


