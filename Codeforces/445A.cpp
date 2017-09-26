/*
 * main.cpp
 *
 *  Created on: Sep 26, 2017
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
const int MAX = 100 + 5;
int N,M;
char Map[MAX][MAX];
bool vis[MAX][MAX];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1, 0};
void dfs(int x,int y, int c) {
	vis[x][y] = 1;
	if(Map[x][y] == '.')  {
		if(c == 0) Map[x][y] = 'B';
			else Map[x][y] = 'W';
	}
	lp(i,4) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if(X >= 0 && X<N && Y >= 0 && Y< M)
			if(!vis[X][Y]) dfs(X,Y, 1 - c);
	}

}
void go() {
	lp(i, N) lp(j, M) if(!vis[i][j]) dfs(i,j, 0);
}
int main() {

	//FI("in.txt");
	
	si2(N, M);
	lp(i,N) lp(j,M) cin >> Map[i][j];

	go();
	lp(i,N) {
		lp(j,M) cout << Map[i][j];
		cout << endl;
	}
	return 0;
}


