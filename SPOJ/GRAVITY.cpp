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
char MZ[ MAX ][ MAX ];
int xT, yT;
int O, N, M;

int dist[MAX][MAX] = {0};
bool vis[MAX][MAX] = {0};

int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};

bool Go(int u, int v) {
    vis[u][v] = 1;
    dist[u][v] = 0;
    queue< pii > Q;
    Q.push(MP(u, v));
    while (Q.size()) {
        pii P = Q.front();
        Q.pop();

        lp(i, 8) {
            int x = P.F + dx[i];
            int y = P.S + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < M 
                    && !vis[x][y] && MZ[x][y] != '#') {
                
                vis[x][y] = 1;
                dist[x][y] = dist[P.F][P.S] + 1;
                
                if (MZ[x][y] == 'T' && dist[x][y] <= O) 
                    return 1;
                
                Q.push(MP(x, y));
            }
        }
    }
    
    return dist[xT][yT] <= O && dist[xT][yT] > 0;
}

int main() {

   // rfile("input.txt");
    int t;
    cin >> t;
    while (t--) {
        xT = -1;
        yT = -1;
        int xS = -1, yS = -1;

        si(O);
        si(N);
        si(M);
        char ch;
        scanf("%c", &ch);

        lp(i, N) {
            lp(j, M) {
                scanf("%c", &ch);

                MZ[i][j] = ch;

                dist[i][j] = 0;
                vis[i][j] = 0;

                if (ch == 'S') {
                    xS = i;
                    yS = j;
                } else if (ch == 'T') {
                    xT = i;
                    yT = j;
                }
            }
            scanf("%c", &ch);
        }

        if (xS == -1 || yS == -1 || xT == -1 || yT == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << (Go(xS, yS) ? "Possible" : "Impossible") << endl;
        }
    }

    return 0;
}


