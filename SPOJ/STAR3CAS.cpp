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
int vals[MAX];
bool vis[MAX];
int dist[MAX];
int n;
int bfs(int v)
{
   queue<int> Q;
   vis[v] = 1;
   dist[v] = 0;
   Q.push(v);
   while(Q.size())
   {
       int p = Q.front();
       Q.pop();
        //cout << p << endl;
       // First Choice ..
       if(p+1 <= n && ! vis[p+1])
       {
           vis[p+1] = 1;
           dist[p+1] = dist[p] + 1;
           if(p+1 == n) return dist[p+1];
           Q.push(p+1);
       }

       // Second Choice ...
       if(vals[p] >= 0)
       {
           // positive ..
           if(p + vals[p] <= n && !vis[p + vals[p]])
           {
               vis[ p + vals[p] ] = 1;
               dist[p + vals[p]] = dist[p] + 1;
               if(p + vals[p] == n) return dist[p + vals[p]];
               Q.push(p + vals[p]);
           }

       }else
       {
           // negative ..
           if(p + vals[p] >= 0 && !vis[p + vals[p]])
           {
               vis[ p + vals[p] ] = 1;
               dist[p + vals[p]] = dist[p] + 1;
               if(p + vals[p] == n) return dist[p + vals[p]];
               Q.push(p + vals[p]);
           }

       }



   }

   return dist[n];
}


int main()
{

   // rfile("input.txt");
    int t;
    si(t);

    cntr(t)
    {

        lp(i, MAX)
        {
            vis[i] = 0;
            dist[i] = 0;
        }

        si(n);
        lp(i, n) si(vals[i]);

        int ans = bfs(0);
        cout << ans << endl;

    }




    return 0;
}

