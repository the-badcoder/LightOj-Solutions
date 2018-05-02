#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, -1, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

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

const int res = 1e6 + 10;
const int mod = 1e8 + 7;
#define ll long long
#define ull unsigned long long

void reset();

int test;
ll n, sum, total, ans, row, col;

int main()
{
    //WRITE;
    int loop = 0;
    sf1( test );

    while( test-- && sf1ll( n ) )
    {
        ll k = ceil( sqrt( n ) );
        ll seq = ( k * k ) - k + 1;

        //deb( k, k * k, seq );

        if( k % 2 == 0 )
        {
            if( n > seq )
            {
                col = k;
                row = seq + k - n;;
            }
            else
            {
                col = n - seq + k;
                row = k;
            }
        }
        else
        {
            if( n > seq )
            {
                col = seq + k - n;
                row = k;
            }
            else
            {
                col = k;
                row = n - seq + k;
            }
        }

        //deb( row, col );
        printf("Case %d: %lld %lld\n", ++loop, col, row );

    }
    return 0;

}

void reset()
{


}

