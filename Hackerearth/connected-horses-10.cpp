#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

bool visited[1009][1009];
bool used[1009][1009];
long long dp [1000000 + 1];
void build_dp()
{

    dp[0] = 1;
    for(long long i = 1; i <= 1e6; i++)
    {
        dp[i] = (dp[i - 1] * i) % mod;
    }
}

ll sum = 0;
int dx[] = {2,1,-1,-2, -2, -1, 1, 2};
int dy[] = {1,2,2, 1, -1, -2, -2, -1};
 int N,M, Q  ;


void dfs(int i, int j)
{
    used[i][j] = 1;
    sum ++;
    for(int k=0;k<8;k++)
    {
        int X = i+dx[k];
        int Y = j + dy[k];
        if(X >= 1 && X <= N && Y >=1 && Y <= M)
        {
            if(!used[X][Y] && visited[X][Y])
            {
                dfs(X,Y);
            }
        }
    }
}

ll BFS(int i,  int j)
{
    queue<pair<int,int>> q;
    int c = 0;
    q.push({i,j});
    used[i][j] = 1;
    while(! q.empty())
    {
        pair<int,int> P = q.front();
        q.pop();

        c++;
        for(int k=0; k<8; k++)
        {
            int X = P.first + dx[k];
            int Y = P.second + dy[k];
            if(X >= 1 && X <= N && Y >=1 && Y <= M && !used[X][Y] && visited[X][Y])
            {
                used[X][Y] = 1;
                q.push({X,Y});

            }

        }
    }
   // cout << "aaaaaaa : c = " << c << endl;
    return dp[c];

}



int main()
{

    //freopen("input.txt", "r", stdin);
    build_dp();
    int t;

    cin>>t;

    while(t--)
    {


        memset(visited, 0, sizeof visited);
        memset(used, 0, sizeof used);

        cin >> N >> M >> Q;
        pair<int,int> Arr[Q];
        int x,y;

        for(int i=0; i<Q; i++)
        {
            cin >> x >> y;
            visited[x][y] = 1;
        }


        ll res = 1;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
        {
            if(!used[i][j] && visited[i][j])
            {
                sum = 0;
                //dfs(i,j);
               // res = (res*(dp[sum]))%mod;
                res = (res*BFS(i,j))%mod;
            }

        }
        cout << res <<endl;

    }

    return 0;
}

