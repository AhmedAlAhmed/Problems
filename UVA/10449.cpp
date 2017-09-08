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
const int MAX = 200 + 10;
int cost[MAX];
int N;
ll r,q;
int a, b;
bool f = 0, cycle = 0;;

struct edge {
	int from, to;
	ll cost;
	edge(int f, int t, ll c) {
		from = f, to = t, cost = c;
	}
	edge() {}
};
ll OO = numeric_limits<ll>::max();
void bellman(vector<edge>& E, vector<ll>& ans) {
	f = 0;
	cycle = 0;
	rep(iter, 1, N) {
		lp(i, E.size()) {
			edge e = E[i];
			if(ans[e.from] >= OO || e.cost >= OO) continue;
			if(ans[e.to] > ans[e.from] + e.cost) {
				ans[e.to] = ans[e.from] + e.cost;
				f = 1;
				if(iter == N) {
					cycle = 1;
				}
			}
		}
		if(! f) break;
	}
}

int main() {
	//rfile("in.txt");
	//wfile("sfds.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll cnt = 1;

	while(cin >> N) {
        cout << "Set #" << (cnt++) << endl;;
		rep(i, 1, N) cin >> cost[i];


		cin >> r;
		vector<edge> edges;

		lp(i, r) {
			cin >> a >> b;

			ll c = cost[b]-cost[a];
			ll c1 = 1ll * (c*c*c);
			edges.push_back(edge(a, b, (c1)));

		}
		cin >> q;

		vector<ll> ans(MAX);
		lp(i, MAX) ans[i] = OO;
		ans[1] = 0;

		bool reachCycle[MAX];
		clr(reachCycle, 0);
		bellman(edges, ans);

		bool cc = 0;

		if(cycle) {
			cc = 1;
			vector<ll> Oans = ans;
			bellman(edges, ans);

			rep(i, 1, N) {
				reachCycle[i] = (Oans[i] != ans[i]);
			}
		}





		while(q--) {
			cin >> a;
			if((reachCycle[a] && cc ) || ans[a] < 3 || r == 0 || ans[a] >= OO) cout << "?\n";
			else cout << ans[a] << endl;
		}
	}
	return 0;
}

