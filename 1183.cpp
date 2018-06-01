#include <bits/stdc++.h>

using namespace std;
//using ll = long long;
const int res = 1e5 + 10;

template <class T> T gcd(T a,T b)
{
    if(b == 0) return a;
    return gcd( b,a % b );
}

int a[ res ], tree[ res * 3 ], lazy[ res * 3 ];

void build_tree( int node, int b, int e )
{
    if( b == e )
    {
        tree[ node ] = a[ b ];
        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    build_tree( Left, b, mid );
    build_tree( Right, mid + 1, e );
    tree[ node ] = tree[ Left ] + tree[ Right ];
}

void pushDown( int node, int b, int e )
{
    if( lazy[ node ] != -1 )
    {
        tree[ node ] = ( e - b + 1 ) * lazy[ node ]; // update it.
        if( b != e )
        {
            lazy[ node * 2 ] = lazy[ node ];
            lazy[ node * 2 + 1 ] = lazy[ node ];
        }
        lazy[ node ] = -1; // reset.
    }
}

void update_tree( int node, int b, int e, int i, int j, int value )
{

    pushDown( node, b, e );

    if( e < i || j < b )
    {
        return;
    }
    if( b >= i && e <= j )
    {
        tree[ node ] = ( e - b + 1 ) * value;
        if( b != e )
        {
            lazy[ node * 2 ] = value;
            lazy[ node * 2 + 1 ] = value;
        }
        return;
    }
    int mid = ( b + e ) / 2;
    int Left = node * 2;
    int Right = node * 2 + 1;
    update_tree( Left, b, mid, i, j, value );
    update_tree( Right, mid + 1, e, i, j, value );

    tree[ node ] = tree[ Left ] + tree[ Right ];
}

int query( int node, int b, int e, int i, int j )
{
    pushDown( node, b, e );

    if( i > e || j < b )
    {
        return 0;
    }

    if( b >= i && e <= j )
    {
        return tree[ node ];
    }

    int mid = ( b + e ) >> 1;
    int Left = node << 1;
    int Right = Left | 1;
    return query( Left, b, mid, i, j ) + query( Right, mid + 1, e, i, j );
}


int main()
{
    int test, n, q, loop = 0;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d %d", &n, &q );

        memset( lazy, -1, sizeof lazy );
        memset( a, 0, sizeof a );
        build_tree( 1, 0, n - 1 );

        printf("Case %d:\n", ++loop );

        for( int i = 0; i < q; i++ )
        {
            int type;
            scanf("%d", &type );
            if( type == 1 )
            {
                int x, y, v;
                scanf("%d %d %d", &x, &y, &v );
                //x++, y++;
                update_tree( 1, 0, n - 1, x, y, v );
            }
            else
            {
                int x, y;
                scanf("%d %d", &x, &y );
                //x++, y++;
                int ans = query( 1, 0, n - 1, x, y );
                //cout << "HELLO " << ans << endl;
                int range = y - x + 1;
                if( ans % range == 0 )
                {
                    printf("%d\n", ans / range );
                }
                else
                {
                    int g = gcd( range, ans );
                    //cout << "HY " << g << " " << ans << " " << range << endl;
                    printf("%d/%d\n", ans / g, range / g );
                }
            }
        }
    }
    return 0;
}
