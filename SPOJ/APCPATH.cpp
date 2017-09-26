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
const int MAX = 50 + 5;
int dx[] = {1,0,-1,0, -1,1,-1,1};
int dy[] = {0,1,0,-1, -1,-1,1,1};
int N,M;
bool vis[MAX][MAX];
int cnt = 0;
char A[MAX][MAX];
void dfs(int x, int y, int c) {
	vis[x][y] = 1;
	cnt = max(cnt, c);
	lp(i,8) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if(X >= 0 && X < N && Y >= 0 && Y< M && !vis[X][Y]) {
			if(A[X][Y]-A[x][y] == 1) {
				dfs(X,Y, c+1);
			}
		}
	}
}
int main() {
	//FI("in.txt");
	int tc = 1;

	while(cin >> N >> M && (N+M) > 0) {
		clr(vis, 0);
		int ans = 0;
		vector< pii > v;
		lp(i,N) lp(j, M) {
			cin >> A[i][j];
			if(A[i][j] == 'A') v.pb({i,j});
		}

		if(sz(v) == 0) {
			printf("Case %d: %d\n", tc++, 0);
			continue;
		}
		for(auto&P : v) {

			cnt = 0;

			dfs(P.F, P.S, 1);
			ans = max(ans, cnt);
		}
		printf("Case %d: %d\n", tc++, ans);
	}

	return 0;
}



