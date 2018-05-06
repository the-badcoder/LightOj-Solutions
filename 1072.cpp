#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, -1, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)


typedef pair< int, int >        ii;
typedef vector< int >           vi;
typedef vector< ii >            vii;

template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

const int res = 1e5 + 5;
const int mod = 1e8 + 7;
#define ll long long
#define ull unsigned long long
#define PI  acos(-1)
void reset();

template <class T> bool is_prime( T n )
{
    if( n == 2 or n == 3 ) return true;
    if( n < 2 or !( n % 2 ) or !( n % 3 ) ) return false;
    for( T i = 5, w = 4; i * i <= n; i += ( w = 6 - w) )
        if( n % i == 0 ) return false;
    return true;
}

int main()
{
    int n;

    sf1( n );

    for( int i = 2; i <= n; i++ )
    {
        if( is_prime( i ) == false and is_prime( n - i ) == false )
        {
            deb( i, n - i );
            return 0;
        }
    }

    return 0;
}


void reset()
{



}

