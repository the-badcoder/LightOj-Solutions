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

int test, n, loop = 0, a[res], freq[res], in[res];

int main()
{
    //WRITE;
    sf1( test );

    while( test-- && sf1( n ) )
    {
        bool flag = true, hasZero = false;
        int digit = 0;
        reset();

        for( int i = 1; i <= n; i++ )
        {
            sf1( a[i] );
            freq[ a[i] ]++;

            if( a[i] >= n )
            {
                flag = false;
            }
        }

        if( flag == false )
        {
            printf("Case %d: no\n", ++loop );
            continue;
        }

        if( n == 1 )
        {
            if( ( a[ 1 ] == 0 ) )
            {
                printf("Case %d: yes\n", ++loop );
            }
            else
            {
                printf("Case %d: no\n", ++loop );
            }
        }

        else if( n == 2 )
        {
            if( ( a[ 1 ] == 0 || a[ 1 ] == 1 ) && ( a[ 2 ] == 0 || a[ 2 ] == 1 ) )
            {
                printf("Case %d: yes\n", ++loop );
            }
            else
            {
                printf("Case %d: no\n", ++loop );
            }
        }
        else
        {
            for( int i = 1; i <= n; i++ )
            {
               // deb( i, i - 1, n - i );
                if( freq[ i - 1 ] > 0 )
                {
                    digit++;
                    freq[ i - 1 ]--;
                }
                else if( freq[ n - i ] > 0 )
                {
                    digit++;
                    freq[ n - i ]--;
                }
            }
            //deb("HY", digit );
            if( digit == n )
            {
                printf("Case %d: yes\n", ++loop );
            }
            else
            {
                printf("Case %d: no\n", ++loop );
            }
        }
    }
    return 0;
}

void reset()
{
    memset( freq, 0, sizeof freq );
}


