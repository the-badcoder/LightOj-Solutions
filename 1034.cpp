#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
vector <int> graph[maxn];
vector <int> Ts;
int visit[maxn];

void dfs (int u)
{
    visit[u] = 1;

    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];

        if ( visit[v] == 0)
        {
            dfs( v );
        }
    }
    Ts.push_back (u);
}

void DFS(int u )
{
    visit[u] = 1;

    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];

        if ( visit[v] == 0 )
        {
            DFS(v);
        }
    }
}
int main ()
{
    int test, loop = 0, n, e, digit;

    scanf("%d", &test );

    while ( test-- )
    {
        scanf("%d %d", &n, &e );

        for (int i = 0; i < e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v );

            graph[ u ].push_back( v );
        }
        memset( visit, 0, sizeof visit );

        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                dfs(i);
            }
        }

        memset( visit, 0, sizeof visit );

        digit = 0;

        for (int i = Ts.size() - 1; i >= 0; i-- )
        {
            if ( visit[ Ts[i] ] == 0 )
            {
                digit++;
                DFS( Ts[i] );
            }
        }

        printf ("Case %d: %d\n", ++loop, digit );
        Ts.clear();

        for( int i = 0; i < maxn; i++ ){
            graph[i].clear();
        }
    }
    return 0;
}
