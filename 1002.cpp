#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define WRITE freopen("output.txt", "w", stdout);

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

int start, path[1000];

void printpath( int u )
{
    if( u == start )
    {
        printf("%d", u);
        return ;
    }
    printpath( path[u] );
    printf(" %d", u );
}

int main()
{
    //WRITE;
    int V, E, s, u, v, w, des, loop = 0, test;

    scanf("%d", &test );

    while( test-- )
    {
        vector<vii> AdjList;

        scanf("%d %d", &V, &E );

        AdjList.assign(V, vii()); // assign blank vectors of pair<int, int>s to AdjList
        for (int i = 1; i <= E; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));                             // directed graph
        }

        scanf("%d", &s);

        vi dist(V, INF);
        dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));

        while (!pq.empty())                                               // main loop
        {
            ii front = pq.top();
            pq.pop();     // greedy: pick shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist[u]) continue;   // this check is important, see the explanation
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];                       // all outgoing edges from u
                if (dist[v.first] > max( dist[u], v.second ))
                {
                    dist[v.first] = max( dist[u] , v.second );
                    path[v.first] = u;                 // relax operation
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }

        printf("Case %d:\n", ++loop );

        for( int i = 0; i < V; i++ )
        {
            if( dist[i] == INF )
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n", dist[i] );
            }
        }
    }
    return 0;
}
