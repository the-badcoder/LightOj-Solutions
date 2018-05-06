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

int Lroad[res], Rroad[res], sum, total, ans, digit, loop = 0, n, test;

int main()
{
    sf1( test );

    while( test-- && sf1( n ) )
    {
        reset();
        for( int i = 0; i < n; i++ )
        {
            int u, v, w;
            sf3( u, v, w );

            if( !Lroad[ u ] && !Rroad[ v ] )
            {
                Lroad[ u ] = Rroad[ v ] = true;
                sum += w;
            }
            else {
                Lroad[ v ] = Rroad[ u ] = true;
                ans += w;
            }
        }
        printf("Case %d: %d\n", ++loop, min( ans, sum ) );
    }

    return 0;
}

void reset()
{
    clr( Lroad );
    clr( Rroad );
    sum = ans = 0;
}
