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
const int MAX = 100 ;
int res[MAX][MAX];
char ch;
int acc = 0;
vi adj[MAX];
int mf = 0, f;
int p[MAX];
int s=0,t=37;
bool finish = 0;

bool read() {

	clr(res, 0);
	acc = 0;
	mf = 0;
	for(auto& c: adj) c.clear();


	rep(i, 27, 36) {
		res[i][t] = 1;
		adj[i].pb(t);
		adj[t].pb(i);
	}

	while(1) {
		if(finish) return 0;

		if(scanf("%c", &ch) == EOF) {
			finish = 1;
			break;
		}

		if(ch == '\n') break;


		int app = ch - 'A' + 1;




		scanf("%c", &ch);
		int n = ch - '0';

		acc += n;

		res[s][app] = n;
		adj[s].pb(app);
		adj[app].pb(s);

		scanf("%c", &ch); // one space.

		while(1) {
			scanf("%c", &ch);

			if(ch == ';') {
				scanf("%c", &ch); // \n
				break;
			}

			int pc = ch - '0' + 27;


			res[app][pc] = 1;
			res[pc][t] = 1;


			adj[app].pb(pc);
			adj[pc].pb(app);



		}
	}
	return 1;

}
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
void go() {
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

	go();

	if(mf != acc) {
		cout << "!" << endl;
		return ;
	}

	rep(i, 27, 36) {
		bool yes = 0;
		rep(j, 1, 26) {
			if(res[i][j] > 0) {
				cout << (char)(j+'A'-1) ;
				yes = 1;
				break;
			}
		}
		if(!yes) cout << "_";
	}

	cout << endl;


}
int main() {
	//rfile("in.txt");
	//wfile("ad.txt");

	while(read()) {

		solve();

		if(finish) break ;

	}

	return 0;
}

