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

int test, n, loop = 0, a[res], freq[res], b[res], sum, total, ans;
bool mark[ res ], mark1[res];

int main()
{
    //WRITE;
    sf1( test );

    while( test-- && sf1( n ) )
    {
        reset();
        sum = ans = total = 0;

        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
        }
        for( int i = 0; i < n; i++ )
        {
            sf1( b[i] );
        }

        sort( a, a + n );
        sort( b, b + n, greater<int>() );

        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( mark1[ j ] == true ){
                    continue;
                }
                //deb( "HY", a[i], b[j] );
                else if( a[i] > b[j] )
                {
                    sum += 2;
                    mark[ i ] = true;
                    mark1[ j ] = true;
                    break;
                }
            }
        }

        for( int i = 0; i < n; i++ )
        {
            if( mark[ i ] == true ){
                continue;
            }
            for( int j = 0; j < n; j++ )
            {
                if( mark1[ j ] == true ){
                    continue;
                }
                else if( a[i] == b[j] ){
                    mark1[ j ] = true;
                    mark[ i ] = true;
                    sum++;
                    break;
                }
            }
        }


        printf("Case %d: %d\n", ++loop, sum );
    }
    return 0;
}

void reset()
{

    memset( mark, false, sizeof mark );
    memset( mark1, false, sizeof mark1 );
}



