#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 20010;
 
int P[MAX]; long long CNT[MAX];
 
void init(int N)
{
    for( int i=0; i<=N; i++ )
    {
 
        P[ i ] = i;
        CNT [ i ] = 0;
    }
 
}
 
int findSet(int u)
{
 
    if( u != P[ u ] )
    {
        int n = P[u];
 
        P [ u ] = findSet(P [ u ]);
        CNT[u] += CNT [ n ];
 
    }
    return P[u];
}
 
void Union(int u, int v)
{
 
    if(findSet(u) == findSet(v)) return;
 
    P[u] = v;
 
    CNT[u] = ( ( int )fabs(u-v) )% 1000;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int t, N, L, R;
    char c;
    scanf("%d", &t);
 
    while(t--)
    {
 
        scanf("%d", &N);
 
        init(N);
 
        while ( 1 )
        {
            scanf("%*c%c", &c);
 
            if( c == 'O' ) break;
 
            if( c == 'E' )
            {
 
                scanf("%d", &L) ;
 
                findSet(L);
 
                printf("%lld\n", CNT [ L ]);
 
            }
            else
            {
 
                scanf("%d%d", &L, &R);
                Union(L, R);
            }
 
        }
 
    }
 
}

