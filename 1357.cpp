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

void reset();

vector <int> graph[ res ];
bool seen[ res ];
ll timer = 0, ans;
int n;

void dfs( int u )
{
    seen[ u ] = true;
    timer++;

    for( int i = 0; i < graph[ u ].size(); i++ )
    {
        int child = graph[ u ][ i ];
        if( seen[ child ] == false )
        {
            dfs( child );
        }
    }

    ans += ( n - timer );
}

int main()
{
    int test, sum, total, loop = 0;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        clr( seen );
        ans = 0, timer = 0;
        for( int i = 0; i < n - 1; i++ )
        {
            int u, v;
            sf2( u, v );
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }

        dfs( 1 );

        printf("Case %d: %d %lld\n", ++loop, n - 1, ans );

        for( int i = 0; i <= res; i++ )
        {
            graph[ i ].clear();
        }
    }
}
