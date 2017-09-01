/*
 * main.cpp
 *
 *  Created on: Sep 1, 2017
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
const int MAX = 1e5 + 10;
int P[MAX], R[MAX];
void init() {
	lp(i, MAX) {
		P[i] = i;
		R[i] = 0;
	}
}

int findSet(int u) {
	if(u != P[u]) P[u] = findSet(P[u]);

	return P[u];
}

int Merge(int u, int v) {
	u = findSet(u), v = findSet(v);

	if(u == v) return 1;

	if(R[u] > R[v]) {
		P[v] = u;
		R[u]++;
	}else {
		P[u] = v;
		R[v]++;
	}
	return 0;
}
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//rfile("in.txt");
	//wfile("dd.txt");
	int a,b;
	init();
	ll ans = 0;
	while(cin >> a) {
		if(a == -1) {
			cout << ans << "\n";
			init();
			ans = 0;
		}else {
			cin >> b;
			ans += Merge(a, b);
		}
	}
	return 0;
}
