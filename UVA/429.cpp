/*
 * main.cpp
 *
 *  Created on: Sep 3, 2017
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

vector<string> words;
string s1, s2;
bool found(string s) {
	return binary_search(words.begin(), words.end(), s);
}
void solve() {
	map<string, int> dist;
	map<string, bool> vis;
	dist[s1] = 0;
	queue<string> q;
	q.push(s1);
	while(q.size()) {
		string tp = q.front(); q.pop();

		if(tp == s2) {
			cout << s1 << " " << s2 << " " << dist[tp] << endl;
			return;
		}
		lp(i, (int)tp.length()) {
			rep(k,0,26) {
				char nc = 'a' + k;
				string cp = tp;
				cp[i] = nc;
				if(found(cp) && !vis[cp] && cp != tp) {
					vis[cp] = 1;
					q.push(cp);
					dist[cp] = dist[tp] + 1;
				}
			}
		}
	}

}
int main() {

	int t;
//	rfile("samples.txt");
//	wfile("asdas.txt");
	cin >> t;
	string str;
	rep(tc, 1, t) {
		words.clear();
		while(cin >> str && str[0] != '*') {
			words.push_back(str);
		}
		sort(all(words));
		string line;
		getline(cin, line);

		while(getline(cin, line) && !line.empty()) {
			istringstream iss(line);
			iss >> s1;
			iss >> s2;
			solve();

		}

		if(tc < t) cout << endl;
	}


	return 0;
}

