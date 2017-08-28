//============================================================================
// Name        : uva11733.cpp
// Author      : Ahmed Al-Ahmed
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

int t,N,M,A;
const int MAX = 1e5 + 2;
int P[MAX], rnk[MAX];

struct Edge {
    int x, y, w;
};

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void init(int n) {
    rep(i, 1, n) {
        P[i] = i;
        rnk[i] = 0;
    }
}

int findSet(int u) {

    if( u != P [ u ] ) P [ u ] = findSet( P [ u ] );
    return P [ u ];
}

void Union(int u, int v) {

    u = findSet(u), v = findSet(v);
    if(u == v) return ;

    if(rnk[u] > rnk[v])
    {
        P[v] = u;
        rnk[u] ++ ;
    }else {

        P[u] = v;
        rnk[v] ++ ;
    }

}
int main(){

	//rfile("in.txt");
	//wfile("asd.txt");


	si(t);

	rep(tc, 1, t) {
		si(N); si(M); si(A);

		init(N);

		int x, y, c;
		Edge edges[M];
		lp(i, M) {
			si(x); si(y); si(c);
            edges[i].x = x;
            edges[i].y = y;
            edges[i].w = c;
		}

		sort(edges, edges+M, cmp);

        ll sum = 0;
        int k = N;

        lp(i, M) {

            if( edges[i].w >= A) break; // cost to build airport is smaller than the weight of edge.

            if(findSet(edges[i].x) != findSet(edges[i].y)) {

                sum += edges[i].w ;
                Union(edges[i].x, edges[i].y);
                k--;
            }
        }




        sum += A * k;
        printf("Case #%d: %lld %d\n", tc, sum, k);

	}

	return 0;
}
