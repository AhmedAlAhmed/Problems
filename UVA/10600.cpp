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
const int MAX = 200;
const int EDGEMAX = 1e6;
struct Edge {
	int x,y,w;
} E[EDGEMAX];

bool cmp(Edge e1, Edge e2) {
	return e1.w < e2.w;
}
int P[MAX], R[MAX];

void init(){
	for (int i = 0; i < MAX; ++i) {
		P[i] = i;
		R[i] = i;
	}
}

int findp(int u) {
	if(u != P[u]) P[u] = findp(P[u]);
	return P[u];
}

void UnionSet(int u, int v) {

	u = findp(u), v = findp(v);
	if(u == v) return;

	if(R[u] > R[v]) {
		P[v] = u;
		R[u]++;
	}else {
		P[u] = v;
		R[v]++;
	}
}

int t, N, M, x,y,w;

ll MIN(ll a, ll b) {
	return a < b;
}
int main() {

	//rfile("in.txt");
	//wfile("asd.txt");
	si(t);

	rep(TC, 1, t) {

		si(N); si(M);
		init();


		lp(i, M) {
			si(x); si(y); si(w);
			E[i].x = x;
			E[i].y = y;
			E[i].w = w;
		}
		sort(E, E+M, cmp);

		int cost = 0; // best cost.
		vector<int> used;

		lp(i, M) {
			if(findp(E[i].x) != findp(E[i].y)) {
				UnionSet(E[i].x, E[i].y);
				cost += E[i].w;
				used.push_back(i);
			}
		}

		int secCost = 1e9;
		for(int idx = 0; idx < (int)used.size();idx++) {
			int edgeID = used[idx];
			init();
			int sCost = 0;
			int cnt = 0;
			for (int i = 0; i < M; ++i) {
					if(i == edgeID) continue;

					if(findp(E[i].x) != findp(E[i].y)) {
						UnionSet(E[i].x, E[i].y);
						sCost += E[i].w;
						cnt ++ ;
					}
				}
			if(cnt == N-1)
				secCost = min(secCost, sCost);

		}

		if(M == 0) {
			printf("0 0\n");
		}else
			cout << cost << " " << secCost << endl;

	}
	return 0;
}
