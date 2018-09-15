/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define cubert(x)             (exp(log(x)/3))
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<int,int>	          mii;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector< ii >             vii;

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

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)
#define sf4ll(a,b,c,d)        scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 100 + 5;
const ll mod = 1e8;


/**
        ACCEPT FAILURE.
**/


int SET( int n, int pos )
{
    return n = n | ( 1 << pos );
}
bool check( int n, int pos )
{
    return ( bool ) ( n & ( 1 << pos ) );
}

ll dp[ ( 1 << 17 ) ][ 21 ];
int n, k, len, a[ 25 ];
char s[ 25 ];

ll rec( int i, int amount )
{
    //deb( i, amount, len );
    if( i == ( 1 << len ) - 1 )
    {
        if( amount == 0 ) return 1ll;
        else return 0ll;
    }

    if( dp[ i ][ amount ] != -1 ) return dp[ i ][ amount ];
    ll one = 0;
    for( int j = 0; j < len; j++ )
    {
         if( !check( i, j ) )
         {
             int ans = ( amount * n ) + a[ j ];
             one += rec( ( SET( i, j ) ) , ( ans % k ) );
         }
    }
    return dp[ i ][ amount ] = one;
}


int main()
{
    int test, loop = 0;

    sf1( test );

    while( test-- )
    {
        memset( dp, -1, sizeof dp );
        sf2( n, k );
        scanf("%s", s );
        len = strlen( s );

        for( int i = 0; i < len; i++ )
        {
            if( s[ i ] >= 'A' and s[ i ] <= 'Z' )
            {
                a[ i ] = ( s[ i ] - 'A' ) + 10;
            }
            else {
                a[ i ] = s[ i ] - '0';
            }
        }
        ll ans = rec( 0, 0 );

        printf("Case %d: %lld\n" ,++loop, ans );
    }


    return 0;
}

