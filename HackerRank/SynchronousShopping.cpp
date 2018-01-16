//============================================================================
// Name        : SynchronousShopping.cpp
// Author      : Ahmed Al-Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define lp(i,n) for(int i=0;i<(n);++i)
#define rep(i,s,n) for(int i=(s);i<=(n);i++)
#define repr(i,s,n) for(int i=(n);i>=(s);--i)
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
#define si3(x,y,k) scanf("%d %d %d", &x, &y, &k)
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
#define F first
#define S second
#define INF 1e9

using namespace std;



const int MAXM = 1024, MAXN = 1010;
int n,m,k;
vector < pair< int, int > > adj[MAXN];
int masks[MAXN];
int dist[MAXN][MAXM];
struct Node {
	int to, weight, mask;
	Node() {}
	Node(int t, int w, int m) {
		to = t;
		weight = w;
		mask = m;
	}
	bool operator < (const Node& N) const {
			return weight > N.weight;
	}
};

int SynchronousShopping() {


	lp(i, n) lp(j, MAXM) {
		dist[i][j] = INF;
	}

	priority_queue<Node> pq;
	dist[0][masks[0]] = 0;

	pq.push(Node(0, 0, masks[0]));

	while( ! pq.empty() ) {

		Node top = pq.top(); pq.pop();
		int u = top.to, msk = top.mask;

		for(auto& ni : adj[u]) {
			int v = ni.F, w = ni.S;
			int newmask = msk | masks[v];
			if(dist[v][newmask] > dist[u][msk] + w) {
				dist[v][newmask] = dist[u][msk] + w;
				pq.push(Node(v, dist[v][newmask], newmask));
			}
		}
	}

	int answer = INF;
	lp(i, (1<<k)) lp(j, (1<<k)) {
		if((i|j) == (1<<k)-1) {
			answer = min(answer, max(dist[n-1][i], dist[n-1][j]));
		}
	}
	return answer;
}

int main() {

	//FI("in.txt");
	si3(n,m,k);

	int a,x,b;
	lp(i, n) {
		si(a);
		lp(j, a) {
			si(x);
			masks[i] |= (1<<(--x));
		}
	}
	lp(i, m) {
		si3(a,b,x);
		a--;b--;
		adj[a].pb(MP(b, x));
		adj[b].pb(MP(a, x));
	}

	int answer = -1;
	answer = SynchronousShopping();

	pi(answer);
	pln();

	return 0;
}
