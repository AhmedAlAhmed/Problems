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

const int MAX = 3000;

int s,t;
int p[MAX];

vi adj[MAX];
int res[MAX][MAX];
int f,mf;


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


void fuckString(string& str) {
	transform(all(str), str.begin(), ::tolower);
	str[0] = toupper(str[0]);
}



int main() {

	//FI("in.txt");
	//FO("out.txt");
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TC, N, k;
	string name;


	cin >> TC;
	rep(tc, 1, TC) {
		int wordCnt = 27;

		map<int, string> mm1;
		for(auto& x : adj) x.clear();
		clr(res, 0);

		cin >> N;
		rep(i, 1, N) {
			cin >> k;
			rep(r,1,k) {
				cin >> name;
				fuckString(name);
				mm1[wordCnt] = name;

				res[wordCnt][ 1000 + i  ] = 1;
				res[ name[0]-'A' + 1  ][wordCnt] = 1;

				adj[wordCnt].pb(1000+i);
				adj[1000+i].pb(wordCnt);

				adj[ name[0] -'A' + 1 ].pb(wordCnt);
				adj[wordCnt].pb( name[0] - 'A' + 1 );

				wordCnt ++ ;
			}
		}
		s = 0, t = 1028;

		rep(i,1,26) {

			res[s][i] = 1;
			adj[s].pb(i);
			adj[i].pb(s);

		}
		rep(i,1,N) {
			res[1000+i][t] = 1;
			adj[1000+i].pb(t);
			adj[t].pb(1000+i);
		}


		cout << "Case #" << tc<<":"<<endl;
		EdmondKarps();

		vector<string> vss;

		rep(i, 1, N) {
			int u = 1000+i;
			rep(v,27,wordCnt-1) {

				if(res[u][v] > 0 && res[v][u] == 0) {
					string str = mm1[v];
					fuckString(str);
					vss.pb(str);
					break;
				}
			}
		}
		sort(all(vss));
		lp(i, sz(vss))
			cout << vss[i] << endl;
	}



	return 0;
}
