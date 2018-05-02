#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE 0
#define DFS_BLACK 1

#define clr(ar)    memset(ar, 0, sizeof(ar))
#define WRITE      freopen("output.txt", "w", stdout);

const int res = 2e4 + 10;
vi graph[res];
int node;
int dfs_num[res], dfs_low[res], rootChildren, dfsRoot, dfs_parent[res], dfsNumberCounter , cc ;
bool articulation_vertex[res];

void reset();

void articulationPointAndBridge( int u )
{
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( dfs_num[v] == 0 )
        {
            dfs_parent[v] = u;

            if( u == dfsRoot ) rootChildren++;

            articulationPointAndBridge( v );

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

            if( dfs_low[v] >= dfs_num[u] )
                articulation_vertex[u] = true;

            /*if( dfs_low[v] > dfs_num[u] )
                printf("Edge (%d %d) is a bridge.\n", u, v);
                */


        }
        else if( v != dfs_parent[u] )
            dfs_low[u] = min( dfs_low[u], dfs_num[v] );
    }
}

int main()
{
    //WRITE;
    int test, edge, loop = 0;

    scanf("%d", &test );

    while( test-- )
    {
        reset();
        scanf("%d %d", &node, &edge );

        while ( edge-- )
        {
            int u, v;

            scanf("%d %d", &u, &v );
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= node; i++)
        {
            if (dfs_num[i] == 0)
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        //cout  << endl;
        //cout << "Articulation point:\n";
        for (int i = 1; i <= node; i++)
        {
            if ( articulation_vertex[i] )
                //cout << i << endl;
                cc++;
        }

        printf("Case %d: %d\n", ++loop, cc );

    }
}

void reset()
{
    clr( articulation_vertex );
    for( int i = 1; i <= 20005; i++ ){
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

