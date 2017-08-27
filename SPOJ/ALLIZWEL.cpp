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
const int MAX = 100 + 1;

bool startWith(string s1, string s2)
{
    return (s1.substr(0, s2.length()) == s2);
}
int N, M;
char MZ[MAX][MAX];
bool valid = 0;
bool vis[MAX][MAX];
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
string ac = "ALLIZZWELL";

void dfs(int u, int v, string str)
{
    vis[u][v] = 1;

    if(str.length() > ac.length()) return ;


    if(str == ac)
    {
        valid = 1;

        return;
    }

    lp(k, 8)
    {
        int x = u + dx[k];
        int y = v + dy[k];


        if(x >=0 && x < N && y >= 0 && y < M && !vis[x][y])
        {
            string ss = str;
            ss.pb(MZ[x][y]);
            if(startWith(ac, ss))
            {
                dfs(x, y, ss);
            }

        }
    }
    vis[u][v] = 0;

}


int main()
{
   // rfile("input.txt");
    int t;
    si(t);

    int s, e;
    cntr(t)
    {
        clr(vis, 0);
        si(N);
        si(M);
        valid = 0;
        vector< pii > coords;
        lp(i, N) lp(j, M)
        {
            cin >> MZ[i][j];
            if(MZ[i][j] == 'A') { coords.pb(MP(i, j)); }

        }
        if(coords.size() == 0)
        {
            printf("NO\n");
        }
        else
        {

            lp(i, coords.size())
            {

                pii u = coords[i];

                dfs(u.F, u.S, "A");

            }

            printf("%s\n", (valid ? "YES":"NO"));
        }

    }



    return 0;
}

