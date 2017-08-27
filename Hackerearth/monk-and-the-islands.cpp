#include <bits/stdc++.h>
#define lp(i,n) for(int i=0;i<(n);++i)
#define rep(i,s,n) for(int i=(s);i<=(n);i++)
#define rep(i,s,n) for(int i=(n);i>=(s);--i)
#define F first
#define S second
#define MP make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long>
#define ll long long
#define llu unsigned long long
#define vll vector<ll>
#define vllu vector<llu>
#define clr(m,v) memset(m, v, sizeof m)
#define pb push_back
using namespace std;
int N,M;

const int MAX = 10009;
ll bfs(vi adjList[MAX])
{
    bool visited[MAX]; clr(visited, 0);
    ll dist[MAX] ; clr(dist, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    dist[0] = 0;
    while(! q.empty())
    {
        int val = q.front();
        q.pop();
        int k = adjList[val].size();
        lp(i, k)
        {
            if(!visited[ adjList[val][i]  ])
            {
                visited[ adjList[val][i]  ] = 1;
                dist[ adjList[val][i]  ] = dist[val] + 1;
                if(adjList[val][i] == N-1) return dist[ adjList[val][i]  ];
                q.push(adjList[val][i]);
             }
        }
    }

    return dist[N-1];


}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        vi adjList[MAX];
        cin >> N >> M;
        int x,y;
        while(M--)
        {
            cin >> x >> y;
            x--;
            y--;
            adjList[x].pb(y);
            adjList[y].pb(x);
        }
        cout << bfs(adjList) << endl;
    }
    return 0;
}

