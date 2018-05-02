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

const int res = 1e5 + 5;

char grid[25][25];
bool color[1000][1000];
int dist[1000][1000];

queue < ii > q;
int R, C;

void reset();

void floodfill( int x, int y )
{
    color[x][y] = 1;
    dist[x][y] = 0;
    q.push( { x, y } );

    while( !q.empty() )
    {
        ii u = q.front();
        q.pop();

        for( int i = 0; i < 4; i++ )
        {
            int r = u.ff + dr[i];
            int c = u.ss + dc[i];

            if( (r >= 0 && r < R && c >= 0 && c < C) && ( color[r][c] == 0 && (grid[r][c] != 'm' && grid[r][c] != '#' ) ) )
            {
                color[r][c] = 1;
                dist[r][c] =  dist[u.ff][u.ss] + 1;
                //deb( dist[r][c] );
                q.push( { r, c } );
            }
        }
    }
}

int main()
{
    int test, maxi, s1, s2, loop = 0, a1, a2, b1, b2, c1, c2;
    vii v;

    sf1( test );

    while( test-- )
    {
        sf2( R, C );

        maxi = -1;
        reset();

        for( int i = 0; i < R; i++ )
        {
            for( int j = 0; j < C; j++ )
            {
                cin >> grid[i][j];

                if( grid[i][j] == 'h' )
                {
                    s1 = i;
                    s2 = j;
                }

                else if( grid[i][j] == 'a' )
                {
                    a1 = i;
                    a2 = j;
                }

                else if( grid[i][j] == 'b' )
                {
                    b1 = i;
                    b2 = j;
                }

                else if( grid[i][j] == 'c' )
                {
                    c1 = i;
                    c2 = j;
                }
            }
        }

        floodfill( s1, s2 );

        int t1 = dist[a1][a2];
        int t2 = dist[b1][b2];
        int t3 = dist[c1][c2];

        //deb( t1, t2, t3 );

        maxi = max( max( t1, t2), max( t2, t3) );

        printf("Case %d: %d\n", ++loop, maxi );
        v.clear();
    }

    return 0;
}

void reset()
{
    clr( color );
    clr( dist );
    clr( grid );
}

