/*
 * Main.cpp
 *
 *  Created on: Aug 15, 2017
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
#define pi(x) printf("%d", x)
#define pln()   printf("\n")
#define pll(x)  printf("%lld", x)
#define cntr(Q) while(Q--)
#define rfile(f) freopen((f), "r", stdin)
#define wfile(f) freopen((f), "w", stdout)
using namespace std;
 
const int MAX = 100000 + 1;
int N;
 
vi adj[MAX];
 
int ev[MAX];
int lv[MAX];
bool vis[MAX];
int cnt = 1;
 
 
void dfs(int u)
{
    vis[u] = 1;
    ev[u] = cnt++;
    for(auto& x : adj[u])
        if(! vis[x]) dfs(x);
 
    lv[u] = cnt++;
}
 
bool onSamePath(int x, int y)
{
    return (ev[x] < ev[y] && lv[x] > lv[y]);
}
int main()
{
    //rfile("in");
    si(N);
    int x,y,Q,t;
    rep(c,1, N-1)
    {
        si(x);
        si(y);
        adj[x].pb(y);
    }
 
    dfs(1);
 
    si(Q);
    rep(c, 1, Q)
    {
        si(t);
        si(x);
        si(y);
        if(t == 0)
            cout << (onSamePath(x,y) ? "YES":"NO") << endl;
        else cout << (onSamePath(y,x) ? "YES":"NO") << endl;
    }
    return 0;
}
 
 
