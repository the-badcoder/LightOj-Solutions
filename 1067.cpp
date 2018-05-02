/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;


#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define EPS                   1e-9
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define setdp(ar)             memset(ar, -1, sizeof(ar))
#define DFS_BLACK             1
#define DFS_WHITE             0
#define White                 0
#define Black                 1

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

const int dr[] = { -1, 1, 0, 0 }; /// 4 side moves.
const int dc[] = { 0, 0, -1, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; /// 8 side moves.
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int kr[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; /// Knight Moves.
const int kc[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<string, string>      mss;
typedef  map<int,int>             mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<int,string>          mis;
typedef  pair<int,int>            ii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int>              vi;
typedef  vector<string>           vs;
typedef  vector<char>             vc;
typedef  vector<bool>             vb;
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

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.

const int res = 1e6 + 10;
#define mod 1000003

ll dp[res];

void pre_calc();
ll modinverse( ll a, ll m );

ll bigmod( ll b, ll p, ll m )
{
    if( p == 0 )
    {
        return 1LL;
    }
    else if( p % 2 == 0 )
    {
        return bigmod( ( b * b ) % m, p / 2, m );
    }
    else
    {
        return ( b * bigmod( ( b * b ) % m, ( p - 1 ) / 2, m ) ) % m;
    }
}


int main()
{
    pre_calc();
    int test, loop = 0;
    ll n, r, sum, inv, t1, t2, total, ans;

    sf1( test );

    while( test-- )
    {
        scanf("%lld %lld", &n, &r );

        sum = dp[ n ];
        t1 = ( dp[ r ] % mod ) ;
        t2 = ( dp[ n - r ] % mod );

        //deb( sum, t1, t2 );
        total = ( t1 * t2 ) % mod;
        inv = modinverse( total , mod );
        //deb( total, inv );

        ans = ( ( sum % mod ) * ( inv % mod ) ) % mod;
        printf("Case %d: %lld\n", ++loop, ans );


    }
    return 0;
}

ll modinverse( ll a, ll m )
{
    return bigmod( a, m - 2, m );
}

void pre_calc()
{
    dp[0] = 1, dp[1] = 1;

    for( int i = 2; i <= 1000000; i++ )
    {
        dp[i] = ( i % mod ) * ( dp[i-1] % mod );
    }
}

