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
const int res = 1e4 + 10;

void reset();

int a[res], n, m, sum, total, ans, digit, test, loop = 0, x;

int check( int x )
{
    int take = 1, amount = 0, first = 0;
    for( int i = 0; i <= n; i++ )
    {
        if( a[i] > x )
        {
            return INT_MAX;
        }
        else if( amount + a[i] <= x )
        {
            amount += a[i];
        }
        else
        {
            amount = a[i];
            take++;
        }
    }
    return take;
}

void solve( int x )
{
    int take = 0, amount = 0, first = 0;
    for( int i = 0; i <= n; i++ )
    {
        if( amount + a[i] > x )
        {
            printf("%d\n", amount );
            take++;
            amount = a[i];
        }
        else if( amount + a[i] == x )
        {
            printf("%d\n", amount + a[i] );
            take++;
            amount = 0;
        }
        else if( n - i == m - take )
        {
            printf("%d\n", amount + a[i] );
            take++, amount = 0;
        }
        else
        {
            amount += a[i];
        }
    }
}

int main()
{
    //WRITE;
    sf1( test );

    while( test-- && sf2( n, m ) )
    {
        reset();
        //sf1( x );
        for( int i = 0; i <= n; i++ )
        {
            sf1( a[i] );
            sum += a[i];
        }

        int lo = 0, hi = sum, mid;

        for( int i = 0; i <= 100; i++ )
        {
            mid = ( lo + hi ) >> 1;
            if( check( mid ) <= m + 1 )
            {
                //deb( "HY", mid );
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        printf("Case %d: %d\n", ++loop, ans );

        solve( ans );
    }
    return 0;
}

void reset()
{
    sum = 0;
}



