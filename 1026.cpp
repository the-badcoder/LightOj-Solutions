#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE 0
#define DFS_BLACK 1

#define clr(ar)    memset(ar, 0, sizeof(ar))
#define WRITE      freopen("output.txt", "w", stdout);

const int res = 10005;
vi graph[res];
int node;
int dfs_num[res], dfs_low[res], rootChildren, dfsRoot, dfs_parent[res], dfsNumberCounter , cc ;
bool articulation_vertex[res];
vii store;

void reset();

void articulationPointAndBridge( int u )
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( dfs_num[v] == DFS_WHITE )
        {
            dfs_parent[v] = u;

            if( u == dfsRoot ) rootChildren++;

            articulationPointAndBridge( v );

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

            if( dfs_low[v] >= dfs_num[u] )
                articulation_vertex[u] = true;

            if( dfs_low[v] > dfs_num[u] )
                //printf("Edge (%d %d) is a bridge.\n", u, v);
                store.push_back( { min( u, v) , max( u, v ) } );
        }
        else if( v != dfs_parent[u] )
            dfs_low[u] = min( dfs_low[u], dfs_num[v] );
    }
}


int main()
{
    int test, edge, loop = 0, x, y;

    scanf("%d", &test);

    while( test-- )
    {
        scanf("%d", &node );

        reset();
        int a1, b1;

        for( int i = 0; i < node; i++ )
        {
            scanf("%d (%d)", &a1, &x );

            for( int i = 0; i < x; i++ )
            {
                scanf("%d", &b1 );
                graph[a1].push_back( b1 );
            }
        }
        for (int i = 0; i < node; i++)
        {
            if (dfs_num[i] == 0)
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        /*for (int i = 0; i < node; i++)
        {
            if ( articulation_vertex[i] )
            {
                cc++;
            }
        }
        */

        printf("Case %d:\n%d critical links\n", ++loop, store.size());

        sort( store.begin(), store.end() );
        for( int i = 0; i < store.size(); i++ )
        {
            printf("%d - %d\n", store[i].first, store[i].second );
        }
        //cout << endl;
    }
}

void reset()
{
    clr( articulation_vertex );
    store.clear();
    for( int i = 0; i < 10005; i++ )
    {
        graph[i].clear();
    }
    clr( dfs_num );
    clr( dfs_low );
    clr( dfs_parent );
    dfsNumberCounter = 0;
    dfsRoot = 0;
    cc = 0;
    rootChildren = 0;
}
