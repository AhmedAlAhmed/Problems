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
#define sz(x) x.size()
using namespace std;

const int MAX =200;

int s,t;
int p[MAX];

vi adj[MAX];
int res[MAX][MAX];
int f,mf;

int N,M;

string sizes[6] = {"XXL", "XL","L", "M" , "S", "XS"};
				//   1	   2    3    4     5     6
map<string, int> msz1;

void augment(int v, int minEdge) {

	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {

		augment(p[v], min(minEdge, res[p[v]][v]));

		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
void EdmondKarps() {
	mf = 0;
	while (1) {

		f = 0;
		bool visited[MAX];
		clr(visited, 0);

		visited[s] = 1;
		queue<int> q;
		q.push(s);

		clr(p, -1);

		while (!q.empty()) {
			int u = q.front();

			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i];
				if (res[u][v] > 0 && !visited[v]) {
					q.push(v);
					p[v] = u;

					visited[v] = 1;
				}
			}
		}

		augment(t, INF);
		if (f == 0)
			break;
		mf += f;
	}
}


void solve() {
	s = 0;
	t = 7 + M;


	rep(i,1,6) {
		res[s][i] = N/6;
		adj[s].pb(i);
		adj[i].pb(s);
	}

	rep(i, 1, M) {
		int p = i+6;
		res[p][t] = 1;
		adj[p].pb(t);
		adj[t].pb(p);
	}

	EdmondKarps();

	if(mf == M) {
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}

int main() {

	rep(i,1,6) msz1[sizes[i-1]] = i;
	string s1,s2;

	//FI("in.txt");
	//FO("out.txt");
	int tc; si(tc);

	rep(TC, 1, tc) {
		map<string, int > freq;
		for(auto&x : adj) x.clear();
		clr(res, 0);

		si2(N, M);
		rep(i,1, M) {
			cin >> s1 >> s2;
			freq[s1]++;
			freq[s2]++;



			res[ msz1[s2] ] [i+6] = 1;

			adj[ msz1[s2] ].pb(i+6);
			adj[i+6].pb( msz1[s2] );

			res[ msz1[s1] ][i+6] = 1;

			adj[ msz1[s1] ].pb(i+6);
			adj[i+6].pb( msz1[s1] );

		}

		solve();
	}

	return 0;
}
