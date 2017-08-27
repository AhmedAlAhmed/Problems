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
using namespace std;
const int MAX = 10000 + 9;
int N, M;

map<ll, ll> dist;
map<ll, bool> vis;
ll bfs(int s, int e)
{
    dist[s] = 0;
    vis[s] = 1;
    queue<int> Q;
    Q.push(s);
    while(Q.size())
    {
        int p = Q.front();
        Q.pop();

        ll ch1 = p-1;
        ll ch2 = p<<1;

        if(ch1 > 0)
        {
            if(!vis[ch1])
            {
                Q.push(ch1);
                dist[ch1] = dist[p] + 1;
                vis[ch1] = 1;
                if(ch1 == e) return dist[ch1];
            }

        }
        if(ch2 > 0 && ch2 <= 10000)
        {
            if(!vis[ch2])
            {
                Q.push(ch2);
                dist[ch2] = dist[p] + 1;
                vis[ch2] = 1;
                if(ch2 == e) return dist[ch2];
            }

        }
    }
    return dist[e];
}
int main()
{
   // freopen("input.txt", "r", stdin);

    cin >> N >> M;

    cout << bfs(N, M) << endl;
    return 0;
}

