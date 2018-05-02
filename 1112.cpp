#include <bits/stdc++.h>

using namespace std;

const int res = 1e5 + 10;
//using ll = long long;

int a[res], tree[ res * 4 ], ans;

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node] = tree[left] + tree[right];
}

int query( int node, int b, int e, int i, int j )
{
    if( i > e || j < b )
    {
        return 0;
    }
    if( b >= i && e <= j )
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    int p1 = query( left, b, mid, i, j );
    int p2 = query( right, mid + 1, e, i, j );
    return p1 + p2;
}

void update( int node, int b, int e, int i, int value )
{
    if( i > e || i < b )
    {
        return;
    }
    if( b >= i && e <= i )
    {
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    update( left, b, mid, i, value );
    update( right, mid + 1, e, i, value );
    tree[node] = tree[left] + tree[right];
}

void reset()
{
    memset( tree, 0, sizeof tree );
    memset( a, 0, sizeof a );
}

int main()
{
    int test, n, q, loop = 0;

    scanf("%d", &test);

    while( test-- && scanf("%d %d",&n, &q ) )
    {
        reset();
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &a[i] );
        }

        build( 1, 1, n );

        printf("Case %d:\n", ++loop );

        while( q-- )
        {
            int type;
            scanf("%d", &type );

            if( type == 1 )
            {
                int x;
                scanf("%d", &x );
                int temp = query( 1, 1, n, x+1, x+1 );
                printf("%d\n", temp );
                update( 1, 1, n, x + 1, 0 );
            }
            else if( type == 2 )
            {
                int i, v;
                scanf("%d %d", &i, &v );
                int temp = query( 1, 1, n, i + 1, i + 1 );
                update( 1, 1, n, i + 1, temp + v );
            }
            else
            {
                int i, j;
                scanf("%d %d", &i, &j );
                int sum = query( 1, 1, n, i + 1, j + 1  );
                printf("%d\n", sum );
            }
        }
    }
    return 0;
}

