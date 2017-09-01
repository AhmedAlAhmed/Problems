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
const int MAX = 100 + 10;
ll dist[MAX][MAX];
ll MIN(ll a, ll b) {
	if(a < b) return a;
	return b;
}
int main() {

	//rfile("in.txt");
	//wfile("asd.txt");
	int t, N, M, E, T,a,b;
	ll w;
	si(t);
	rep(tc, 1, t) {
		si3(N,E,T);

		rep(i, 0, N) rep(j, 0, N) {
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
		si(M);
		cntr(M) {
			si2(a,b);
			sll(w);
			dist[a][b] = MIN(dist[a][b], w);
		}
		rep(k, 1, N) rep(i, 1, N) rep(j, 1, N) {
			dist[i][j] = MIN(dist[i][j], dist[i][k]+dist[k][j]);
		}
		int ans = 0;
		rep(i, 1, N){
			if(dist[i][E] <= T) ans ++ ;
		}
		pi(ans); pln(); if(tc < t) pln();
	}
	return 0;
}

