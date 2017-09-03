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

const int MAX = 1e5 + 1;
int nums[10 + 1];
int lockNum, unlockNum, btnsCount;

int GET(int num) {
	if(num <= 9999) return num;
	string str;
	stringstream ss;
	ss << num;
	ss >> str;
	ss.clear();
	str = str.substr(str.length()-4);
	int k ;
	ss << str;
	ss >> k;
	return k;
}

ll bfs() {
	queue<int> q;
	vi dist(MAX, -1), vis(MAX, 0);
	dist[lockNum] = 0;
	q.push(lockNum);
	while(q.size()) {
		int tp = q.front(); q.pop();
		if(tp == unlockNum) {
			return dist[tp];
		}
		lp(i, btnsCount){
			int np = GET(nums[i] + tp);
			if(! vis[np]) {
				vis[np] = 1;
				dist[np] = dist[tp] + 1;
				q.push(np);
			}
		}
	}
	return -1;
}

int main() {

	//rfile("samples.txt");
	//wfile("asd.txt");
	ios::sync_with_stdio(0); cin.tie(); cout.tie();
	int cnt = 1;
	while(1) {
		cin >> lockNum >> unlockNum >> btnsCount ;
		if(lockNum+unlockNum+btnsCount == 0) break;
		lp(i, btnsCount) cin >> nums[i];
		ll ans = bfs();
		cout << "Case " << (cnt++) << ": ";
		if(bfs() != -1) {
			cout << ans << endl;
		}else {
			cout << "Permanently Locked" << endl;
		}
	}
	return 0;
}





