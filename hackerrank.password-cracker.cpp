//============================================================================
// Name        : Training.cpp
// Author      : Ahmed Al-Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : https://www.hackerrank.com/challenges/password-cracker/
//============================================================================

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
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
using namespace std;

string attemp;
string words[11];
int n;

string build(vector<string> vs) {
	string s = "";
	for(auto&x : vs) s+=x;
	return s;
}
string build_(vector<string> vs) {
	string s = "";
	for(auto&x : vs) s+=x + " ";
	return s.substr(0, s.length()-1);
}

bool fnd = 0;
bool hasSamePrefix(string s1, string s2) {
	lp(i, min(s1.length(), s2.length())) {
		if(s1[i]!=s2[i])return 0;
	}
	return 1;
}
map<string, bool> hashtbl;
void gen(vector<string> vs) {

	string s = build(vs);
	if(fnd == 1) return;
	if(s.length() > attemp.length()) return;
	if(!hasSamePrefix(attemp, s)) return ;

	if(hashtbl[s] == 1) return ;
	hashtbl[s] = 1;
	if(s == attemp) {
		fnd = 1;
		cout << build_(vs) << endl;
		return ;
	}else {
		lp(i, n) {
			vs.pb(words[i]);
			gen(vs);
			vs.pop_back();
		}
	}
}
void solve() {
	vector<string> vs;

	gen(vs);
	if(fnd == 0)
		cout << "WRONG PASSWORD" << endl;
	else {

	}

}

bool cmp(string s1 , string s2) {
	return s1.length() > s2.length();
}
int main() {



	//FI("in.txt");
	int t;
	cin >> t;

	while(t--) {

		cin >> n;
		hashtbl.clear();
		lp(i,n) {
			cin >> words[i];
		}

		sort(words, words+n, cmp);
		cin >> attemp;
		fnd = 0;
		solve();
	}


	return 0;
}
