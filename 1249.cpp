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
const int res = 2e5 + 10;

int main()
{
    int test, n, sum, total, ans, digit, loop = 0;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        vector < pair < int, string > > v;
        set <int> st;
        int maxi = -1, mini = -1;

        for( int i = 0; i < n; i++ )
        {
            string s;
            int x, y, z;
            cin >> s;
            sf3( x, y, z );
            sum = x * y * z;
            st.insert( sum );
            maxi = max( maxi, sum );
            mini = min( mini, sum );
            v.push_back( make_pair( sum, s ) );
        }

        sort( v.begin(), v.end() );
        reverse( v.begin(), v.end() );

        if( st.size() == 1 )
        {
            printf("Case %d: no thief\n", ++loop );
        }
        else
        {

            int miniCount = 0, maxiCount = 0;

            for( int i = 0; i < v.size(); i++ )
            {
                int temp = v[ i ].first;
                if( temp == mini )
                {
                    miniCount++;
                }

            }
            if( mini == v.size() - 1 )
            {
                printf("Case %d: ", ++loop );
                cout << v[ 0 ].second << space << "took chocolate from all\n";
            }
            else
            {
                printf("Case %d: ", ++loop );
                cout << v[ 0 ].second << space << "took chocolate from " << v[ v.size() - 1 ].second << endl;
            }
        }
    }
    return 0;
}


