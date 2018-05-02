/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

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
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4ll(a,b,c,d)        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e5 + 10;
const ll mod = 1e9 + 7;

vi graph[res];
bool seen[res];
int a[res], sum, cost, digit;

void dfs( int u )
{
    if( seen[u] == true ){
        return;
    }
    seen[u] = true;
    digit++;
    sum += a[u];

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( seen[v] == false )
        {
            dfs( v );
        }
    }
}

void reset()
{
    memset( seen, false, sizeof seen );
    for( int i = 0; i < res; i++ )
    {
        graph[i].clear();
    }
}

int main()
{
    //WRITE;
    int test, n, m, total, loop = 0;

    sf1( test );

    while( test-- && sf2( n, m ) )
    {
        total = 0;
        reset();

        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
            total += a[i];
        }

        for( int i = 0; i < m; i++ )
        {
            int u, v;
            sf2( u, v );

            u--, v--;
            graph[u].push_back( v );
            graph[v].push_back( u );
        }

        int avg = total / n;
        bool flag = true;

        if( total % n == 1 )
        {
            flag = false;
            printf("Case %d: No\n", ++loop );
            continue;
        }
        else
        {
            for( int i = 0; i < n; i++ )
            {
                sum = digit = 0;
                if( seen[i] == false )
                {
                    dfs( i );
                    //deb( digit, avg, sum );
                    if( digit * avg != sum )
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if( flag == true )
        {
            printf("Case %d: Yes\n", ++loop );
        }
        else
        {
            printf("Case %d: No\n", ++loop );
        }
    }

    return 0;
}


