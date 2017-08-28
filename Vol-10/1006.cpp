#include<bits/stdc++.h>
using namespace std;
long long dp[10004],a,b,c,d,e,f,n,mod=10000007;
long long rec(int ii)
{
    if(ii==0)return a;
    if(ii==1)return b;
    if(ii==2)return c;
    if(ii==3)return d;
    if(ii==4)return e;
    if(ii==5)return f;
    if(dp[ii]!=-1)return dp[ii];
    return dp[ii]=(rec(ii-1)+rec(ii-2)+rec(ii-3)+rec(ii-4)+rec(ii-5)+rec(ii-6))%mod;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);
        a%=mod;
        b%=mod;
        c%=mod;
        d%=mod;
        e%=mod;
        f%=mod;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": "<<rec(n)<<"\n";
    }
    return 0;
}

