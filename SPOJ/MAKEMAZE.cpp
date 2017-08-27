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
const int MAX = 20 + 1;
int t,N, M;
char MZ[MAX][MAX];

bool vis[MAX][MAX];

bool accepted(int s, int e, int i, int j)
{
    bool b = (i == 0 || i == N-1);
    bool t = (j == 0 );
    bool r = (j == M-1 );

    return (MZ[i][j] == '.' && (s != i || e != j) && (b || t || r));

}
bool isvalid(int i, int j)
{
    return i >= 0 && i< N && j >=0 && j < M && MZ[i][j] == '.';
}

bool bfs(int s, int e)
{
    queue< pii > Q;
    vis[s][e] = 1;

    Q.push(MP(s,e));

    int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0,  0,-1};

    while(Q.size())
    {
        pii ty = Q.front();
        Q.pop();
        if(accepted(s, e, ty.F, ty.S)) return 1;
        lp(i, 4)
        {
            int X = ty.F + dx[i];
            int Y = ty.S + dy[i];

            if(isvalid(X, Y) && ! vis[X][Y])
            {
                vis[X][Y] = 1;
                if(accepted(s, e, X, Y)) return 1;
                Q.push(MP(X, Y));
            }
        }

    }

    return 0;
}


int main()
{
    //rfile("input.txt");

    si(t);
    rep(tc, 1, t)
    {

        int c = 0;
        clr(vis, 0);
        si(N);
        si(M);
        int s, e;
        lp(i, N) lp(j, M)
        {
            cin >> MZ[i][j];
            if(i == 0 && MZ[i][j] == '.')
            {
                c++;
                s = i;
                e = j;
            }
            if(i == N-1  && N-1 > 0 && MZ[i][j] == '.')
            {
                c++;
                s = i;
                e = j;

            }

            if(j == 0 && MZ[i][j] == '.' && i > 0 && i < N-1)
            {
                c++;
                s = i;
                e = j;
            }
            if(j == M-1 && MZ[i][j] == '.' && i > 0 && i < N-1 && M-1 > 0)
            {
                c++;
                s = i;
                e = j;
            }
        }


        if(c > 2 || c <= 1)
        {
            printf("invalid\n");
        }
        else
        {
            printf("%s\n", (bfs(s,e) ? "valid":"invalid"));
        }
    }
    return 0;
}

