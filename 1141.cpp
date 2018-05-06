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
const int res = 1e4 + 1;

vector <int> graph[res], primes, factors;
int visited[res], dist[res], start, nodes;
bool mark[ res ];

void siv()
{
    clr( mark );

    for( int i = 4; i <= res; i += 2 )
    {
        mark[ i ] = true;
    }

    primes.push_back( 2 );

    for( int i = 3; i  <= res; i += 2 )
    {
        if( mark[ i ] == false )
        {
            primes.push_back( i );
            for( int j = i * i; j <= res; j += i )
            {
                mark[ j ] = true;

            }
        }
    }
}


int bfs(int s,int d)
{
    memset( visited, -1, sizeof(visited) );

    queue <int> q;
    q.push( s );
    visited[ s ] = 0;

    while( !q.empty() )
    {
       int u = q.front();
        q.pop();

        for( int i = 0; primes[i] < u; i++ )
        {
            if( u % primes[i] == 0)
            {
                factors.push_back( primes[i] );
            }
        }

        for( int i = 0; i < factors.size(); i++ )
        {
            int v = u + factors[i];

            if( visited[ v ] == -1 && v <= d)
            {
                visited[ v ] = visited[ u ] + 1;
                q.push( v );

            }
        }
        factors.clear();
    }
    return visited[d];


}

int main()
{
    siv();

    int test, s, t, loop = 0, ans;

    sf1( test );

    while (test-- && sf2( s, t ) )
    {
        memset( visited, 0, sizeof visited );
        memset( dist, 0, sizeof dist );

        if( s == t )
        {
            printf("Case %d: 0\n", ++loop );
        }
        else if( s > t )
        {
            printf("Case %d: -1\n", ++loop );
        }
        else
        {
            printf("Case %d: %d\n", ++loop, bfs( s, t ) );
        }
    }


    return 0;
}

