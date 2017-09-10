/*
 * main.cpp
 *
 *  Created on: Sep 10, 2017
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

int t,N, M, a,b,c, Q;
string s1, s2;
map<string, int > mm;
int src, dest;

const int MAXM = 1000 + 10;
const int MAXN = 100 + 10;
int dist[MAXN][MAXN];

struct Node {
	int to, cost, ord=0;
	Node(int t, int c) {
		to = t, cost = c;
	}


	bool operator < (const Node& o ) const {
		return cost > o.cost;
	}
};
vector< Node > adj[MAXN];


int cc;
void go() {

	rep(i,0, N) rep(j, 0, N){
		dist[i][j] = 1e9;

	}

	dist[src][0] = 0;

	priority_queue<Node> pq;

	pq.push(Node(src, 0));
	while(pq.size()) {

		Node top = pq.top(); pq.pop();
		int u = top.to, c = top.cost, ord = top.ord;
		if(dist[u][ord] < c) continue;

		for(auto& Ni : adj[u]) {

			int v = Ni.to, w = Ni.cost;

			if(dist[v][ord+1] > dist[u][ord] + w) {
				dist[v][ord+1] = dist[u][ord]+w;
				Node tmp(v, dist[v][ord+1]);
				tmp.ord = ord+1;
				pq.push(tmp);
			}

		}
	}

}

bool cmp(pii V, const int x) {
	return V.F < x;
	return 0;
}

void solve(int len) {


	int ak = 1e9;

	rep(i ,1, N) {
		int l = i-1;
		if(len >= i-1) {
			ak = min(ak, dist[dest][i]);
		}else break;
	}

	if(ak == 1e9) {
		cout << "No satisfactory flights" << endl;
	}else {
		cout << "Total cost of flight(s) is $" << ak << endl;
	}
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//rfile("i.txt");
	//wfile("ads.tx");
	cin >> t;
	rep(tc, 1, t) {
		cout << "Scenario #" << tc << endl;
		for(auto& x : adj) x.clear();




		int cnt = 1;
		mm.clear();
		cin >> N;
		rep(i, 1, N) {
			cin >> s1;
			mm[ s1 ] = cnt ++ ;
			if(s1 == "Calgary") src = mm [ s1 ];
			if(s1 == "Fredericton") dest = mm [ s1 ];
		}
		cin >> M;
		cc = -1;
		lp(i, M) {
			cin >> s1 >> s2 >> c;
			a = mm [ s1 ], b = mm [ s2 ];
			Node np(b,c);
			np.ord = 0;
			adj[a].pb(Node(np));

			if(s1 == "Calgary" && s2 == "Fredericton")
			{
				cc = c;

			}
		}

		go();
		cin >> Q;
		rep(it, 1, Q) {
			cin >> a;
			solve(a);
		}
		if(tc < t) cout<<endl;
	}


	return 0;
}





