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
const int res = 1e5 + 10;

int main()
{
    int n, test, a[res], sum, total, ans, digit, loop = 0;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        for( int i = 1; i <= n; i++ )
        {
            sf1( a[i] );
        }
        sum = 0;

        for( int i = 1; i <= n; i++ )
        {
            if( (a[i] - a[i-1]) > sum )
            {
                sum = a[i] - a[i-1];
            }
        }
        total = sum;

        for( int i = 1; i <= n; i++ )
        {
            if( (a[i] - a[i-1]) == sum )
            {
                sum--;
            }
            else if( (a[i] - a[i-1]) > sum )
            {
                total++;
                break;
            }
        }
        printf("Case %d: %d\n", ++loop, total );
    }
    return 0;
}

