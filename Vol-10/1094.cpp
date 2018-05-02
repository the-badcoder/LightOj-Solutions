#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

// Tree DiaMeter.

#define DFS_BLACK 1
#define DFS_WHITE 0

vector <int> graph[30005], cost[30005];
bool used[30005];
int taka[30005];

void reset();

void dfs( int u )
{
    used[u] = DFS_BLACK;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( used[v] == DFS_WHITE )
        {
            taka[v] = taka[u] + cost[u][i];
            dfs( v );
        }
    }
}

int main()
{
    int test, money, loop = 0, nodes, edges, weight, from, to, maxi, index;

    scanf("%d", &test);

    while( test-- )
    {
        //reset();
        scanf("%d", &nodes);

        for( int i = 0; i < nodes - 1; i++ )
        {
            scanf("%d %d %d", &from, &to, &weight );

            graph[from].push_back( to );
            graph[to].push_back( from );

            cost[from].push_back( weight );
            cost[to].push_back( weight );
        }

        memset( used, 0, sizeof used );
        memset( taka, 0, sizeof taka );

        dfs(0);

        maxi = 0, index = 0;

        for( int i = 0; i < nodes; i++ )
        {
            if( taka[i] > maxi )
            {
                maxi = taka[i];
                index = i;
            }
        }

        memset( used, 0, sizeof used );
        memset( taka, 0, sizeof taka );

        dfs( index );
        maxi = 0;

        for( int i = 0; i < nodes; i++ )
        {
            if( taka[i] > maxi )
            {
                maxi = taka[i];
            }
        }

        printf("Case %d: %d\n", ++loop, maxi );
        reset();
    }
    return 0;
}

void reset()
{
    //maxi = index = 0;
    for( int i = 0; i < 30005; i++ )
    {
        graph[i].clear();
        cost[i].clear();
    }
}

