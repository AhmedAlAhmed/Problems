#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll modularExponentiation(ll x,ll n,ll M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        
        return modularExponentiation((x*x)%M,n/2,M);
    else                             
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

ll getAns(ll A, ll B, ll C, ll M)
{
    ll t1 = modularExponentiation(A, B, M);

    ll t2 = modInverse(C, M);

    return ((t1%M) * (t2%M) ) % M;


}
int main()
{

   ll A,B,C,M;
   scanf("%lld%lld%lld%lld", &A,&B,&C,&M);

    printf("%lld\n", getAns(A,B,C,M));

    return 0;
}

