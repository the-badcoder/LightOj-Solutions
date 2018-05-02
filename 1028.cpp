#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Size 1000007

int flag[Size];
vector < int > Primes;

void seive()
{
    flag[1] = 1;
    for( int i = 4; i <= 1000000; i += 2 )
    {
        flag[i] = 1;
    }
    for( int i = 3; i <= 1000; i += 2 )
    {
        if( flag[i] == 0 )
        {
            for( int j = (i * i); j <= 1000000; j += (i << 2) )
            {
                flag[j] = 1;
            }
        }
    }
    Primes.push_back( 2 );

    for( int i = 3; i <= 1000000; i += 2 )
    {
        if( flag[i] == 0 )
        {
            Primes.push_back(i);
        }
    }
}

int NOD( ll n )
{
    int power, sum, ans = 1;
    vector <int> :: iterator it;
    ans = 1;
    for( it = Primes.begin(); it != Primes.end(); it++ ){
        ll sum = *it;

        if( sum * sum > n ){
            break;
        }
        power = 1;
        while( n % sum == 0 ){
            power++;
            n /= sum;
        }
        ans *= power;
    }
    if( n != 1 ){
        ans *= 2;
    }
    return ans;
}

int main()
{
    seive();
    ll n, sum;
    int test, loop = 0;

    scanf("%d", &test);

    while( test-- )
    {
        scanf("%lld", &n);

        sum = NOD(n);
        printf("Case %d: %lld\n", ++loop, sum - 1);
    }

    return 0;

}
