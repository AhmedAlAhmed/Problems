/*
 * main.cpp
 *
 *  Created on: Oct 7, 2017
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
#define FI(f) freopen((f), "r", stdin)
#define FO(f) freopen((f), "w", stdout)
#define INF (int) 1e12
#define EPS 1e-9
#define sz(x) ((int)(x.size()))
using namespace std;

const int MAX = 2*100 + 20;

int s,t;
int p[MAX];

vi adj[MAX];
int res[MAX][MAX];
ll f,mf;
int N,M,a,b,c;

void augment(int v, int minEdge)
{

    if (v == s)
    {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {

        augment(p[v], min(minEdge, res[p[v]][v]));

        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void go()
{
    mf = 0;
    while (1)
    {

        f = 0;
        bool visited[MAX];
        clr(visited, 0);

        visited[s] = 1;
        queue<int> q;
        q.push(s);

        clr(p, -1);

        while (!q.empty())
        {
            int u = q.front();

            q.pop();
            if (u == t)
                break;
            for (int i = 0; i < (int) adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (res[u][v] > 0 && !visited[v])
                {
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

int A[MAX], B[MAX];

int main() {

	//FI("in.txt");
	ios::sync_with_stdio(0); cin.tie(); cout.tie();

	int N; cin >> N;

	lp(i, N) cin >> A[i];
	int M; cin >> M;
	lp(i, M) cin >> B[i];

	// construct the graph .

	lp(i, N) lp(j, M) {
		if(fabs(A[i]-B[j]) <= 1) {

			int u = i;
			int v = j + N;

			res[u][v] = 1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}

	s = N+M+2, t = N+M+3;

	lp(i, N) {
		res[s][i] = 1;
		adj[s].pb(i);
		adj[i].pb(s);
	}
	lp(j, M) {
		int v = j + N;
		res[v][t] = 1;
		adj[v].pb(t);
		adj[t].pb(v);
	}

	go();
	cout << mf << endl;

	return 0;
}



