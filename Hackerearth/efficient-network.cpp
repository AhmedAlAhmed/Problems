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
#define clrv(v) v.clear()
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 1e5 + 10;

pair<int, pair<int,int> > adjList[MAX];
int N,M,x,y,q,cost;

/*
int ids[MAX];

void init()
{
    lp(i, MAX) ids[i] = i;
}

int root(int x)
{
    while(x != ids[x]) x = ids[x];
    return x;
}

void union1(int x, int y)
{
    int p = root(x), q =root(y);
    ids[p] = ids[q];
}
*/


int parent[100005],rnk[100005];

int find(int x)
{
    if(parent[x]!=x)
        parent[x]=find(parent[x]);
    return parent[x];
}
void merge(int x,int y)
{
    int xroot=find(x),yroot=find(y);

    if(rnk[xroot]<rnk[yroot])
        parent[xroot]=yroot;
    else if(rnk[xroot]>rnk[yroot])
        parent[yroot]=xroot;
    else
    {
        parent[yroot]=xroot;
        rnk[xroot]++;
    }
}


void init2()
{
    for(int i=1; i<=N; i++)
        parent[i]=i;
}

vi best;
int MAX_BEST = 0;
int Best[MAX];

int MST()
{
    int minCost = 0, cost;
    lp(i, M)
    {
        int x = adjList[i].second.first;
        int y = adjList[i].second.second;
        cost = adjList[i].first;

        if(find(x) != find(y))
        {
            Best[MAX_BEST++] = cost;
            merge(x,y);
        }
    }
}
ll solve(vi VCost)
{
    MST();
    sort(Best, Best+MAX_BEST, greater<int>());
    int j = 0;
    ll sum = 0;
    lp(i, MAX_BEST)
    {
        if(j < VCost.size())
        {

            if(VCost[j] < Best[i])
            {
                sum += VCost[j];
                j++;
            }
            else sum += Best[i];
        }
        else sum += Best[i];
    }
    return sum;

}
int main()
{
   // freopen("input.txt", "r", stdin);


    scanf("%d%d", &N, &M);
    init2();
    map<pair<int,int>, int> Map;
    lp(i, M)
    {
        scanf("%d%d%d", &x, &y,&cost);
        adjList[i] = MP(cost, make_pair(x,y));
    }


    scanf("%d", &q);
    sort(adjList, adjList + M);
    vector<int> VCost;
    VCost.resize(q);

    lp(i,q) scanf("%d", &VCost[i]);

    sort(all(VCost));

    printf("%lld\n", solve(VCost));

    return 0;
}

