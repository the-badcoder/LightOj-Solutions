/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define mod                   1e7
#define INF                   2147483647
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/


typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<int,int>            mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>         mis;
typedef  pair<int,int>           pii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int>             vi;
typedef  vector<string>          vs;
typedef  vector<char>            vc;
typedef  vector<bool>            vb;
typedef  vector< pii >           vii;


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

const int maxn = 1e4 + 10;
vector <int> graph[maxn], cost[maxn];
int reach[maxn];
bool used[maxn];
int nodes, edges, u, v, sum, a, b, total, weight, ans;

void dfs( int s )
{
    reach[s]++;
    used[s] = 1;

    for( int i = 0; i < graph[s].size(); i++ )
    {
        v = graph[s][i];
        if( used[v] == 0 )
        {
            dfs(v);
        }
    }
}

void reset()
{
    for( int i = 0; i < maxn; i++ )
    {
        graph[i].clear();
    }
}

int main()
{
    int test, k, n, m, a[1000], loop = 0, x, y;

    sf1( test );

    while( test-- )
    {
        sf3( k, n, m );
        clr( reach );

        for( int i = 1; i <= k; i++ )
        {
            sf1( a[i] );
        }

        while( m-- )
        {
            sf2( x, y );

            graph[x].push_back( y );
        }

        for( int i = 1; i <= k; i++ )
        {
            clr( used );
            dfs( a[i] );
        }

        for( int i = 1; i <= n; i++ )
        {
            if( reach[i] == k )
            {
                ans++;
            }
        }

        printf("Case %d: %d\n", ++loop, ans );
        reset();
        ans = 0;
    }

    return 0;
}

