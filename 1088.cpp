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

int main()
{
    int test, a[ res ], loop = 0, n, q, sum, total, ans, digit;

    sf1( test );

    while( test-- && sf2( n, q ) )
    {
        for( int i = 0; i < n; i++ )
        {
            sf1( a[ i ] );
        }

        printf("Case %d:\n", ++loop );

        while( q-- )
        {
            int x, y;
            sf2( x, y );

            int lb = lower_bound( a, a + n, x ) - a;
            int ub = upper_bound( a, a + n, y ) - a;

            printf("%d\n", ub - lb );

        }
    }
    return 0;
}
