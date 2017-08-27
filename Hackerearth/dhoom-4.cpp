#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int key,  real_key;
int N;
ll Arr[5000];

bool visisted[1000009];
ll dist[1000009];
ll getAns()
{

    queue<int> q;
    q.push(key);
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        for(int i=0;i<N;i++)
        {
            int v = ((val%100000) *(Arr[i]%100000))%100000;
            if(!visisted[v])
            {
                visisted[v] = 1;
                dist[v] = dist[val] + 1;
                if(v == real_key) return dist[real_key];
                q.push(v);
            }
        }
    }
    return dist[real_key];
}

int main()
{
   // freopen("input.txt", "r", stdin);
    memset(visisted, 0, sizeof visisted);
    memset(dist, 0, sizeof dist);
    cin >> key >> real_key;
    cin >> N;
    for(int i=0;i<N;i++) cin >> Arr[i];


    if(key == real_key) cout << "0\n";

    int a = getAns();
    if(a == 0) cout << "-1\n";
    else
        cout << a << endl;



    return 0;
}

