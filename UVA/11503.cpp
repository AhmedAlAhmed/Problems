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
    
    const int MAX = 100000 + 9;
    
    int parent[MAX];
    int cnt[MAX];
    int rnk[MAX];
    
    void init(int N)
    {
        rep(i, 0, N)
        {
            cnt[i] = 1;
            parent[i] = i;
    
        }
    }
    
    int root(int u)
    {
        if(parent[u] != u)
            parent[u] = root(parent[u]);
        return parent[u];
    }
    
    int union1(int u, int v)
    {
        int ux = root(u);
        int vx = root(v);
    
        if(ux == vx)
        {
            return cnt[ux];
        }else
        {
            if(cnt[ux] > cnt[vx])
            {
                parent[vx] = ux;
                cnt[ux] += cnt[vx];
                return cnt[ux];
            }else
            {
                parent[ux] = vx;
                cnt[vx] += cnt[ux];
                return cnt[vx];
            }
        }
    }
    
    int main()
    {
      //  rfile("input.txt");
        // wfile("out.txt");
        map<string, int> m;
        string s1,s2;
    
        int t;
        si(t);
        rep(k, 1, t)
        {
            m.clear();
            int n;
            int ni = 0;
            si(n);
            init(min(2*n, MAX));
    
            cntr(n)
            {
    
                cin >> s1 >> s2;
                int n1 = m[s1];
                if(n1 == 0) {
                    m[s1] = ++ni;
                    n1 = m[s1];
                }
                int n2 = m[s2];
                if(n2 == 0) {
                    m[s2] = ++ni;
                    n2 = m[s2];
                }
    
                int p = union1(n1, n2);
                cout << p << endl;
    
    
    
    
        }
    
        }
        return 0;
    }

