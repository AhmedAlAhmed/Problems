/*
 * main.cpp
 *
 *  Created on: Aug 28, 2017
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
int t, N, M;
const int MAX = 10000 + 2;
const int MAXN = 100 + 2;
struct Edge {
	int x,y,w;
}E[MAX];

int P[MAXN], rnk[MAXN];

void init(int n) {

	lp(i, n) {
		P[i] = i;
		rnk[i] = 0;
	}
}
int findSet(int u) {
	if( u != P [u])
		P[u] = findSet(P[u]);
	return P[u];
}
void Union(int u, int v) {
	u = findSet(u), v = findSet(v);
	if(u == v) return;

	if(rnk[u] > rnk[v])
	{
		P[v] = u;
		rnk[u]++;
	}else {
		P[u] = v;
		rnk[v] ++ ;
	}
}
bool cmp(Edge e1, Edge e2) {
	return e1.w > e2.w;
}
int main() {

//	rfile("in.txt");
//	wfile("ww.txt");
	si(t);
	int x,y,c;
	rep(tc, 1, t) {

		si(N); si(M);
		init(N);
		lp(i, M){
			si3(x,y,c);
			E[i].x = x;
			E[i].y = y;
			E[i].w = c;
		}


		sort(E, E+M, cmp);
		int cnt = 0;

		lp(i, M) {
			if(findSet(E[i].x) != findSet(E[i].y)) {
				cnt ++ ;
				Union(E[i].x, E[i].y);
				if(cnt == N-1) {
					printf("Case #%d: %d\n", tc, E[i].w);
					break;
				}
			}
		}

	}


	return 0;
}
