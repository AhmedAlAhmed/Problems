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

struct Time
{
    int hour, minites;
    char flag; // p => pm , a => am
};

void DBG(Time SS)
{
    cout <<SS.hour << " " << SS.minites << " " << SS.flag <<endl;
}
bool visited[100][100][5];
int dist[100][100][5];

Time construct(string s1, string s2)
{
    Time tmp;
    tmp.flag = (s2 == "am" ? 'a' : 'p');
    stringstream strem;
    string ss1 = s1.substr(0,2);
    strem << ss1;
    strem >> tmp.hour ;
    ss1 = s1.substr(3,5);
    strem.clear();
    strem << ss1;
    strem >> tmp.minites;

    return tmp;
}

Time toggleTime(Time tmm)
{
    Time time = tmm;
    if(time.flag == 'a') time.flag = 'p';
    else time.flag = 'a';
    return time;
}

Time dec_time(Time tmm, char t)
{
    Time time = tmm;
    if(t == 'h')
    {
        if(time.hour > 1)
        {
            time.hour --;
            if(time.hour == 11)
            {
                time  = toggleTime(time);
            }
        }
        else if (time.hour == 1)
        {
            time.hour = 12;

        }
    }
    else
    {
        if(time.minites > 0) time.minites --;
        else if (time.minites == 0)
        {
            time.minites = 59;
            if(time.hour > 1)
            {
                time.hour --;
                if(time.hour == 11)
                {
                    time  = toggleTime(time);
                }
            }
            else if (time.hour == 1)
            {
                time.hour = 12;
                // time = toggleTime(time);
            }
        }
    }

    return time;


}
Time add_to_time(Time tmm, char t)
{
    Time time = tmm;


    if(t == 'h')
    {
        // add hours
        if(time.hour < 12)
        {
            time.hour++;
            if(time.hour == 12)
            {
                // now becomes 11 -> 12
                time = toggleTime(time);
            }
        }
        else if(time.hour == 12)
        {
            time.hour = 1;
            //time = toggleTime(time);
        }

    }
    else
    {
        // add min.
        if(time.minites < 59) time.minites++;
        else if(time.minites == 59)
        {
            time.minites = 0;
            if(time.hour < 12)
            {
                time.hour++;
                if(time.hour == 12)
                {
                    // now becomes 11 -> 12
                    time = toggleTime(time);
                }
            }
            else if(time.hour == 12)
            {
                time.hour = 1;
                //time = toggleTime(time);
            }
        }
    }

    return time;
}


int bfs(Time T, Time target)
{
    queue<Time> Q;
    Q.push(T);
    visited[T.hour][T.minites][T.flag=='a'? 0:1] = 1;
    dist[T.hour][T.minites][T.flag=='a'? 0:1] = 0; // default.
    while(Q.size())
    {
        Time ty = Q.front(); Q.pop();
        Time arr[5];

        arr[0] = add_to_time(ty, 'h');
        arr[1] = add_to_time(ty, 'm');
        arr[2] = dec_time(ty, 'h');
        arr[3] = dec_time(ty, 'm');
        arr[4] = toggleTime(ty);

        lp(i, 5)
        {
            Time c = arr[i];
            if(visited[c.hour][c.minites][c.flag=='a'?0:1] == 0)
            {
                visited[c.hour][c.minites][c.flag=='a'?0:1] = 1;
                Q.push(c);
                dist[c.hour][c.minites][c.flag=='a'?0:1] = (dist[ty.hour][ty.minites][ty.flag=='a'?0:1]) + 1;
                if(c.hour == target.hour && c.minites == target.minites && c.flag == target.flag)
                {
                    return dist[c.hour][c.minites][c.flag=='a'?0:1];
                }
            }
        }
    }
    return dist[target.hour][target.minites][target.flag=='a'?0:1];
}


int main()
{


   // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    string s1, mode;
    while(t--)
    {
        memset(visited, 0, sizeof visited);
        memset(dist, 0, sizeof dist);
        cin >> s1 >> mode;
        Time t1 = construct(s1,mode);
        cin >> s1 >> mode;
        Time t2 = construct(s1,mode);


        cout << bfs(t1, t2) << endl;
    }
    return 0;
}

