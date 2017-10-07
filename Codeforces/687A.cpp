/*
 * main.cpp
 *
 *  Created on: Oct 7, 2017
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
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) ((int)(x.size()))
using namespace std;

const int MAX = 1e6 + 10;

vi adj[MAX];
int color[MAX];
int N,M,a,b;
bool imp = 0;

int cnt[2] = {0};

vi tmp[2];

void go(int u) {
	queue<int> q;
	color[u] = 0;
	cnt[0]++;
	tmp[0].pb(u);
	q.push(u);
	while(q.size()) {
		int v = q.front(); q.pop();
		for(auto& ni : adj[v]) {
			if(color[ni] == INF) {
				color[ni] = 1 - color[v];
				cnt[color[ni]]++;
				q.push(ni);
				tmp[color[ni]].pb(ni);
			}

			else if (color[ni] == color[v]) {
				imp = 1;
			}
		}
	}
}
int main() {

	//FI("in.txt");
	cin >> N >> M;
	fill(color, color+N+2, INF);
	rep(it,1,M) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	rep(u,1,N) if(color[u] == INF) {
		go(u);
		if(imp) {
			cout << "-1" << endl;
			return 0;
		}
	}

	if(imp ) {
		cout << "-1" << endl;
		return 0;
	}

	lp(c,2) {
		cout << tmp[c].size() << endl;
		bool f = 1;
		for(auto&x : tmp[c]) {
			if(!f) cout << " ";
			cout << x ;
			f = 0;
		}
		cout << endl;
	}
	return 0;
}
