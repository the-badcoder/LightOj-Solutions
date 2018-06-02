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

ll a[res], tree[ res * 4 ], seen[ res ], ans[ res ];

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( b + e ) / 2;

    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node] = tree[left] + tree[right];
}

ll query( int node, int b, int e, int i, int j )
{
    if( i > e or j < b )
    {
        return 0;
    }
    if( b >= i and e <= j )
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    ll p1 = query( left, b, mid, i, j );
    ll p2 = query( right, mid + 1, e, i, j );
    return p1 + p2;
}

void update( int node, int b, int e, int i, ll value )
{
    if( i > e or i < b )
    {
        return;
    }
    if( b >= i and e <= i )
    {
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;

    update( left, b, mid, i, value );
    update( right, mid + 1, e, i, value );
    tree[ node ] = tree[left] + tree[right];
}


int main()
{
    int test, n, q, sum, total, loop = 0;

    sf1( test );

    while( test-- && sf2( n, q ) )
    {
        for( int i = 1; i <= n; i++ )
        {
            sf1( a[ i ] );
        }
        memset( seen, -1, sizeof seen );
        memset( tree, 0, sizeof tree );
        vector < pair < int, pair < int, int > > >v;

        for( int i = 0; i < q; i++ )
        {
            int l, r;
            sf2( l, r );
            v.push_back( make_pair( r, make_pair( l, i ) ) );
        }

        sort( v.begin(), v.end() );

        int idx = 0;

        for( int i = 1; i <= n; i++ )
        {
            int value = a[ i ];
            if( seen[ value ] == -1 )
            {
                seen[ value ] = i;
                update( 1, 1, n, i, 1 );
            }
            else
            {
                update( 1, 1, n, seen[ value ], 0 );
                update( 1, 1, n, i, 1 );
                seen[ value ] = i;
            }

            //deb("CHECK", v[ i - 1 ].first, i  );

            if( idx < q )
            {
                while( v[ idx ].first == i )
                {
                    int l = v[ idx ].second.first;
                    int r = v[ idx ].first;
                    int index = v[ idx ].second.second;
                    ans[ index ] = query( 1, 1, n, l, r );
                    //deb("HY", ans[ index ] );
                    idx++;
                }
            }

        }
        printf("Case %d:\n", ++loop );
        for( int i = 0; i < q; i++ )
        {
            printf("%d\n", ans[ i ] );
        }
    }


    return 0;
}




