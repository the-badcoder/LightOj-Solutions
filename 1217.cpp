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
const int res = 1e3 + 10;

void reset();


ll dp[ res ][ 2 ];
int a[ res ], n;

ll rec( int i, int flag )
{
    if( ( i >= n ) ) return 0;
    if( i == n - 1 && flag ) return a[ i ];

    if( dp[ i ][ flag ] != -1 ){
        return dp[ i ][ flag ];
    }

    return dp[ i ][ flag ] = max( rec( i + 1, flag ), rec( i + 2, flag ) + a[ i ] );


}

int main()
{

    int test, loop = 0;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
        }
        memset( dp, -1, sizeof dp );
        ll x = rec( 2, 1  ) + a[ 0 ];
        memset( dp, -1, sizeof dp );
        ll y = rec( 1, 0 );

        printf("Case %d: %lld\n", ++loop, max( x, y ) );
    }


    return 0;
}




