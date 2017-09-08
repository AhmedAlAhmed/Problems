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

const int MAX = 10000 + 9;
int n,m,D;
char grid[109][109];
int cost [ 500 + 10 ][500 + 10];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

struct Node {
	int i,j,cost;
	Node(int a, int b, int c) {
		i = a;
		j = b;
		cost = c;
	}
	bool operator < (const Node& O) const {
		return cost > O.cost;
	}
};
bool valid(int x, int y) {
	return x >= 0 && x<n && y >=0 && y<m && grid[x][y] != '#';
}
bool isDir(int x, int y) {
	char ch = grid[x][y];

	return (ch == 'W' || ch == 'E' ||
							ch == 'N' || ch == 'S');
}

bool isW(int s, int e, int NS, int NE) {
	return NE < e && s == NS;
}
bool isE(int s, int e, int NS, int NE) {
	return NE > e && s == NS;
}
bool isN(int s, int e, int NS, int NE) {
	return NS < s && e == NE;
}
bool isS(int s, int e, int NS, int NE) {
	return NS > s && e == NE;
}

bool DirValid(int x, int y, int X, int Y) {
	if(isS(X,Y, x,y) && grid[X][Y] == 'S') return 1;
	if(isW(X,Y, x,y) && grid[X][Y] == 'W') return 1;
	if(isE(X,Y, x,y) && grid[X][Y] == 'E') return 1;
	if(isN(X,Y, x,y) && grid[X][Y] == 'N') return 1;

	return 0;
}
int fd(char c1, char c2, int indx, int indy) {
	int cst = cost[indx][indy];

	if(c1 == 'W' && (c2 =='N' || c2 == 'S')) return cst;
	if(c1 == 'W' && c2 == 'E') return 2*cst;
	if(c1 == 'S' && (c2 == 'W' || c2 == 'E')) return cst;
	if(c1 == 'S' && c2 == 'N') return 2*cst;

	if(c1 == 'N' && (c2 == 'W' || c2 == 'E')) return cst;
	if(c1 == 'N' && c2 == 'S') return 2*cst;

	if(c1 == 'E' && (c2 == 'N' || c2 == 'S')) return cst;
	if(c1 == 'E' && c2 == 'W') return 2*cst;

	return 0;
}

int dijkstra() {
	int dist[109][109];
	lp(i, 109) lp(j, 109) {
		dist[i][j] = 1e9;
	}
	priority_queue<Node> pq;
	dist[n-1][0] = 0;
	pq.push(Node(n-1,0,0));

	while(pq.size()) {
		Node tp = pq.top(); pq.pop();

		if(tp.i == 0 && tp.j == m-1) {
			return dist[0][m-1];
		}

		if(dist[tp.i][tp.j] < tp.cost) continue;

		lp(i, 4) {
			int X = tp.i + dx[i];
			int Y = tp.j + dy[i];

			if(valid(X,Y)) {

				if(isDir(X, Y) && !DirValid(tp.i, tp.j, X, Y)) continue;

				int addCost = 0;

				if(isDir(tp.i, tp.j)) {
					char ch = '-';
					if(isW(tp.i, tp.j, X, Y)) ch = 'W';
					if(isE(tp.i, tp.j, X, Y)) ch = 'E';
					if(isN(tp.i, tp.j, X, Y)) ch = 'N';
					if(isS(tp.i, tp.j, X, Y)) ch = 'S';

					addCost = fd(grid[tp.i][tp.j], ch, tp.i, tp.j);
				}

				if(dist[X][Y] > dist[tp.i][tp.j] + 1 + addCost) {
					dist[X][Y] = dist[tp.i][tp.j] + 1 + addCost;
					pq.push(Node(X,Y, dist[X][Y]));
				}
			}
		}
	}

	return 1e9;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//rfile("in.txt");
	//wfile("asd.txy");
	int t;
	cin >> t;
	while(t--) {
			D = 0;
			cin >> n >> m;
			vector < pii > vec;
			lp(i, n) lp(j, m) {
				cin >> grid[i][j];
				char ch = grid[i][j];
				if(ch == 'W' || ch == 'E' ||
						ch == 'N' || ch == 'S') {
					D++;
					vec.pb({i,j});
				}

			}

			lp(i,D) {
				int a;
				cin >> a;
				cost[vec[i].F][vec[i].S] = a;
			}

			int ans = 1e9;
			ans = dijkstra();

			if(ans == 1e9) cout << "Poor Kianoosh" << endl;
			else cout << ans << endl;
	}


	return 0;
}



