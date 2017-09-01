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
const int MAX = 1000 + 1;
int t, N, M;
int mat[MAX][MAX];
int num[MAX][MAX];
int dist[MAX*MAX +10];

struct Node {
	int i, j, w;
	Node(int r, int c, int cost) {
		i = r;
		j = c;
		w = cost;
	}
	bool operator < (const Node& N) const {
		return w > N.w;
	}
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
void solve() {
	priority_queue<Node> pq;
	dist[1] = mat[1][1];
	pq.push(Node(1,1,mat[1][1]));
	while(pq.size()) {
		Node tq = pq.top(); pq.pop();
		if(tq.i == N && tq.j == M) {
			cout << dist[ num[tq.i][tq.j] ] << endl;
			break;
		}
		int u = num[tq.i][tq.j];
		if(dist[u] < tq.w) continue;
		lp(i, 4) {
			int DX = tq.i + dx[i];
			int DY = tq.j + dy[i];

			if(DX >= 1 && DX <= N && DY >= 1 && DY <= M) {
				int v = num[DX][DY];
				if(dist[v] > dist[u] + mat[DX][DY]) {
					dist[v] = dist[u] + mat[DX][DY];
					pq.push(Node(DX, DY, dist[v]));
				}
			}
		}
	}
}
int main() {

//	rfile("in.txt");
//	wfile("asd.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int w;
	cin >> t;
	rep(tc, 1, t) {
		cin >> N >> M;
		int cnt = 1;
		rep(i, 1, N) rep(j, 1, M) {
			cin >> mat[i][j];
			num[i][j] = cnt++;
			dist[cnt] = INF;
		}

		solve();

	}
	return 0;
}

