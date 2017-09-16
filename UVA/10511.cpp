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

const int MAX = 5000;

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

int clubC,personC,partyC;
map<string,int> clubM,personM,partyM;
string clubName[MAX], personName[MAX];



void init() {
	clr(res, 0);
	for(auto&x : adj) x.clear();
	s = 0; t = MAX - 1;
	clubC = personC = partyC = 1;
	clubM.clear(); personM.clear(); partyM.clear();
}

int getPartyID(int nu) {
	return nu + 2000;
}
int getClubID(int nu) {
	return nu + 1000;
}
void read() {

	string line,club;
	vi tmp2;
	while(getline(cin, line) && line.length() > 0) {
		vi tmp;
		string name,party;
		istringstream iss(line);
		iss >> name >> party;

		if(personM.find(name) == personM.end()) {
			personM[name] = personC;
			tmp.pb(personC);
			personName[personC] = name;
			personC++;
		} else tmp.pb(personM[name]);

		if(partyM.find(party) == partyM.end()) {
			partyM[party] = partyC;
			tmp.pb(partyC);
			partyC++;
		}else tmp.pb(partyM[party]);

		while(iss >> club) {

			if(clubM.find(club) == clubM.end()) {
				clubM[club] = clubC;
				tmp.pb(clubC);
				clubName[clubC] = club;
				clubC++;
			}else tmp.pb(clubM[club]);

		}

		int prs = tmp[0];
		int prt = getPartyID(tmp[1]);

		rep(c,2,sz(tmp)-1) {

			int clb = getClubID(tmp[c]);

			res[s][clb] = 1;
			adj[s].pb(clb);
			adj[clb].pb(s);

			res[clb][prs] = 1;
			adj[clb].pb(prs);
			adj[prs].pb(clb);
		}


		res[prs][prt] = 1;
		adj[prs].pb(prt);
		adj[prt].pb(prs);

		adj[prt].pb(t);
		adj[t].pb(prt);

		tmp2.pb(prt);


	}
	clubC--;
	for(auto& it : tmp2) {
		res[it][t] = (clubC-1)/2;
	}
}

void solve(){
	go();

	if(mf < clubC) {
		cout << "Impossible." << endl;
	}else {
		rep(u,1,personC) rep(v,1,clubC) {
			int vv = getClubID(v);
			if(res[u][vv] > 0 && res[vv][u] == 0) {
				cout << personName[u] << " " << clubName[v] << endl;
				break;
			}
		}
	}

}


int main() {

//	FI("in.txt");
	int TC;
	cin >> TC;
	string ttm;
	getline(cin, ttm); char cc; scanf("%c", &cc);
	rep(tc,1,TC) {

		init();
		read();
		solve();
		if(tc < TC) cout << endl;
	}

	return 0;
}
