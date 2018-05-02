/// Bismillah Hir Rahmanir Rahim

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <climits>
#include <stdbool.h>


using namespace std;


#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define mod                   1e7
#define EPS                   1e-9
#define INF                   INT_MAX
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

typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<string, string>     mss;
typedef  map<int,int>            mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>         mis;
typedef  pair<int,int>           ii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int>             vi;
typedef  vector<string>          vs;
typedef  vector<char>            vc;
typedef  vector<bool>            vb;
typedef  vector< ii >            vii;

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

const int res = 5e6 + 1;
unsigned long long phi[res];

void call_phi()
{
    int i, j;
    phi[1] = 1;

    for( int i = 2; i < res; i++ )
    {
        phi[i] = i;
    }
    for( i = 2; i < res; i++ )
    {
        if( phi[i] == i )
        {
            for( j = i; j < res; j += i )
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    for( int i = 2; i < res; i++ )
    {
        phi[i] = phi[i-1] + ( phi[i]*phi[i] );
    }
}


int main()
{
    int n, m, test, loop = 0;

    call_phi();

    sf1( test );

    while( test-- )
    {
        sf2( n, m );

        printf("Case %d: ", ++loop );

        printf("%llu\n", phi[m] - phi[n-1] );
    }
    return 0;
}

