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

const int MAX = 150;

int s,t;

struct Edge
{
    int v ;

    int flow ;

    int C;

    int rev ;
};


class Graph
{
    int V;
    int *level ;
    vector< Edge > *adj;
public :
    Graph(int V)
    {
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }


    void addEdge(int u, int v, int C)
    {

        Edge a{v, 0, C, adj[v].size()};


        Edge b{u, 0, 0, adj[u].size()};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxflow(int s, int t);
};


bool Graph::BFS(int s, int t)
{
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;

    level[s] = 0;


    list< int > q;
    q.push_back(s);

    vector<Edge>::iterator i ;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C)
            {

                level[e.v] = level[u] + 1;

                q.push_back(e.v);
            }
        }
    }

    return level[t] < 0 ? false : true ;
}


int Graph::sendFlow(int u, int flow, int t, int start[])
{

    if (u == t)
        return flow;


    for (  ; start[u] < adj[u].size(); start[u]++)
    {

        Edge &e = adj[u][start[u]];

        if (level[e.v] == level[u]+1 && e.flow < e.C)
        {

            int curr_flow = min(flow, e.C - e.flow);

            int temp_flow = sendFlow(e.v, curr_flow, t, start);


            if (temp_flow > 0)
            {

                e.flow += temp_flow;

                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }

    return 0;
}


int Graph::DinicMaxflow(int s, int t)
{

    if (s == t)
        return -1;

    int total = 0;
    while (BFS(s, t) == true)
    {
        int *start = new int[V+1];

        while (int flow = sendFlow(s, INT_MAX, t, start))

            total += flow;
    }


    return total;
}
int N,M,a,b,c,cap;;
int main()
{

 //   FI("in.txt");
  //  FO("a.txt");
    ios::sync_with_stdio(0); cin.tie(); cout.tie();

    while(cin >> N >> M && (N+M) > 0) {

        Graph g(2*N + 10);


        s = 1, t = N;

        g.addEdge(s, s+N, INF);



        rep(it, 1, N-2) {
            cin >> a >> cap;

            g.addEdge(a, a+N, cap);
            g.addEdge(a+N, a, cap);


        }
        rep(it, 1, M) {
            cin >> a >> b >> c;

            if(a == b) continue;
            g.addEdge(a+N, b, c);
            g.addEdge(b+N, a, c);
        }

        t = 2*N;
        g.addEdge(N, t, INF);
        g.addEdge(t, N, INF);


        cout << g.DinicMaxflow(s, t) << endl;

    }
    return 0;
}
