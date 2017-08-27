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
#define Point pair<float, float>
#define X F
#define Y S
#define EPS 1e18
using namespace std;

const int MAX = 200 + 10;
int dist[MAX][MAX];
int main()
{
   // rfile("in.txt");
    //wfile("opp.txt");


    int n,M, w;
    string s1, s2;
    int cnt = 1;
    while(1)
    {
        si(n);
        si(M);
        if(n == 0 && M == 0) return 0;

        int pz = 0;
        map<string, int> m;

        rep(u, 1, n) rep(v, 1, n)
        {
            if(u == v) dist[u][v] = 0;
            else dist[u][v] = -1e5;
        }

        cntr(M)
        {
            cin >> s1 >> s2 >> w;
            int n1 = m[s1];
            if(n1 == 0)
            {
                m[s1] = ++pz;
                n1 = m[s1];
            }
            int n2 = m[s2];
            if(n2 == 0)
            {
                m[s2] = ++pz;
                n2 = m[s2];
            }

            dist[n1][n2] = w;
            dist[n2][n1] = w;


        }
        cin >> s1 >> s2;


        rep(k,1,n) rep(i,1,n) rep(j,1,n)
        {
           dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
        }

        cout << "Scenario #" << cnt++ << endl;
        cout << dist[m[s1]][m[s2]] <<" tons" << endl;

        cout << endl;
    }


    return 0;
}


