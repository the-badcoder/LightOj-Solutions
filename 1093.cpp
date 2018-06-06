#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, 0, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)

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

#define ll long long
const int res = 1e5 + 10;

void reset();

int a[res];

struct info
{
    int mini, maxi;
} tree[ res * 4 ];

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[ node ].maxi = tree[ node ].mini = a[ b ];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    build( left, b, mid );
    build( right, mid + 1, e );

    tree[ node ].mini = min( tree[ left ].mini, tree[ right ].mini );
    tree[ node ].maxi = max( tree[ left ].maxi, tree[ right ].maxi );
}

info query( int node, int b, int e, int i, int j )
{
    info result;
    result.maxi = INT_MIN, result.mini = INT_MAX;

    if( i > e || j < b )
    {
        return result;
    }
    if( b >= i && e <= j )
    {
        return tree[ node ];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    info p1 = query( left, b, mid, i, j );
    info p2 = query( right, mid + 1, e, i, j );

    result.maxi = max( p1.maxi, p2.maxi );
    result.mini = min( p1.mini, p2.mini );

    return result;
}

int main()
{
    int n, q, sum, total, ans, test, loop = 0;

    sf1( test );

    while( test-- )
    {
        ans = 0;
        sf2( n, q );

        for( int i = 1; i <= n; i++ )
        {
            sf1( a[ i ] );
        }

        build( 1, 1, n );

        for( int i = 1; i + q - 1 <= n; i++ )
        {
            int maxi = query( 1, 1, n, i, i + q - 1 ).maxi;
            int mini = query( 1, 1, n, i, i + q - 1 ).mini;
            ans = max( ans, maxi - mini );
        }

        printf("Case %d: %d\n", ++loop, ans );
    }
    return 0;
}






