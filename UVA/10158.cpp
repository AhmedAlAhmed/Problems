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
const int MAX = 20000 + 4;
int P[MAX], rnkP[MAX] ;

void init() {
	lp(i, MAX) {
		P[i] = i;
		rnkP[i] = 0;
	}
}
int Get_Enemy(int u) {
	return u+10000; // the enemy of current
}
int findSet(int u) {
	if( u != P [u])
		P[u] = findSet(P[u]);
	return P[u];
}
void Union(int u, int v) {
	u = findSet(u), v = findSet(v);
	if(u == v) return;

	if(rnkP[u] > rnkP[v])
	{
		P[v] = u;
		rnkP[u]++;
	}else {
		P[u] = v;
		rnkP[v] ++ ;
	}
}

void setFriend(int u, int v) {
	Union(u, v);
	Union(Get_Enemy(u), Get_Enemy(v));
}

void setEnemy(int u, int v) {
	Union(u, Get_Enemy(v)); // enemy of enemy is friend
	Union(Get_Enemy(u), v);

}

bool isFriend(int u, int v) {
	return findSet(u) == findSet(v) || findSet(Get_Enemy(u)) == findSet(Get_Enemy(v)) ;
}

bool isEnemy(int u, int v) {
return findSet(u) == findSet(Get_Enemy(v)) ||
		findSet(v) == findSet(Get_Enemy(u));
}
bool canSetFriend(int u, int v) {
	if(findSet(u) == findSet(Get_Enemy(v))) return 0;
	if(findSet(v) == findSet(Get_Enemy(u))) return 0;
	return 1;
}
bool canSetEnemy(int u, int v) {
	if(u == v ) return 0;
	if (findSet(u) == findSet(v)) return 0;
	if(findSet(Get_Enemy(u)) == findSet(Get_Enemy(v))) return 0;
	return 1;
}
int main() {
	//rfile("in.txt");
	//wfile("asd.txt");
	int n;
	si(n);
	init();

	int c, x, y;
	while(1) {
		si3(c,x,y);
		if(c+x+y == 0) break;

		if(c == 1) {
			if(canSetFriend(x, y)) setFriend(x, y);
			else printf("-1\n");
		}else if (c == 2) {

			if(canSetEnemy(x, y)) setEnemy(x, y);
			else printf("-1\n");
		}else if(c == 3) {

			if(isFriend(x, y)) printf("1\n");
			else printf("0\n");
		}else {
			if(isEnemy(x, y)) printf("1\n"); else printf("0\n");
		}

	}

	return 0;
}

