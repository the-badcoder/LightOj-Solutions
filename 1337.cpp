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

//using ll = long long;
const int res = 502;

int seen[ res ][ res ], dp[ res * res ], n, m;
char ch[ res ][ res ];

void dfs( int x, int y, int color )
{
    if( x < 0 || y < 0 || x >= n || y >= m || ch[ x ][ y ] == '#' || seen[ x ][ y ] ) return;
    seen[ x ][ y ] = color;

    if( ch[ x ][ y ] == 'C' )
    {
        dp[ color ]++;
    }

    dfs( x + 1, y, color );
    dfs( x - 1, y, color );
    dfs( x, y + 1, color );
    dfs( x, y - 1, color );

}

void reset();

int main()
{
    int test, loop = 0, query, ans, digit;

    sf1( test );

    while( test-- && sf3( n, m, query ) )
    {
        reset();
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", ch[ i ] );
        }

        for( int i= 0, color = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( ch[ i ][ j ] != '#' && seen[ i ][ j ] == false )
                {
                    dfs( i, j, ++color );
                }
            }
        }

        printf("Case %d:\n", ++loop );

        while( query-- )
        {
            int x, y;
            sf2( x, y );
            x--, y--;
            printf("%d\n", dp[ seen[ x ][ y ] ] );
        }
    }

}

void reset()
{
    clr( seen );
    clr( dp );
}
