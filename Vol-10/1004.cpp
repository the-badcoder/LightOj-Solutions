#include <bits/stdc++.h>

using namespace std;

#define READ            freopen("input.txt", "r", stdin);
#define WRITE           freopen("output.txt", "w", stdout);
#define ll              long long int
#define space           " "
#define clr(ar)         memset( ar, 0, sizeof ar )


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

int main()
{
    //WRITE;

    ll a[205][205], total, dp[205][205], b[205][205], sum, ans, dp1[205][205];
    int test, n, loop = 0;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d", &n );

        clr( dp );
        clr( dp1 );
        clr( a );
        clr( b );

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= i; j++ )
            {
                scanf("%lld", &a[i][j] );
            }
        }

        int row = 2 * n - 1;

        for( int i = n+1; i <= row; i++ )
        {
            for( int j = 1; j <= 2*n-i; j++ )
            {
                scanf("%lld", &a[i][j] );
            }
        }

        /* for( int i = n+1; i <= row; i++ )
         {
             for( int j = 1; j <= 2*n-i; j++ )
             {
                 deb( i, j, a[i][j] );
             }
         }
         */


        sum = ans = 0;

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= i; j++ )
            {
                //deb( i, j, a[i][j] );
                dp[i][j] = ( max( dp[i-1][j], dp[i-1][j-1] ) ) + a[i][j];
                //deb( i, j, dp[i][j] );
            }
        }

        //cout << endl;

        for( int i = n + 1; i <= row; i++ )
        {
            for( int j = 1; j <= 2 * n - i; j++ )
            {
                //deb( i, j, a[i][j] );
                dp[i][j] = ( max( dp[i-1][j+1], dp[i-1][j] ) ) + a[i][j];
                //deb( i, j, dp[i][j] );
            }
        }

        printf("Case %d: %lld\n", ++loop, dp[row][1] );

    }

    return 0;
}

