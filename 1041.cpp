#include <bits/stdc++.h>

using namespace std;

#define WRITE  freopen("output.txt", "w", stdout);

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;


const int maxn = 12345;
int Rank[maxn], p[maxn];
int numSets;
vector <int> setSize;
map <string, int> m;

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        //setSize.assign( x+1, 1 );
        for( int i = 1; i <= x; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) );
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j);
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet(i), y = findSet(j);

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                //setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                //setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;
    }
    /*int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
    */

} UF;

int main()
{
    //WRITE;
    //freopen( "in.txt", "r", stdin );
    int V, E, nodes , Edges, sum, total, w, loop = 0, test, mst_cost, record;
    string s, s1;
    bool flag = false;
    vector < pair < int, ii > > Edgelist;

    scanf("%d", &test);

    while( test-- )
    {
        scanf("%d", &V );

        nodes = mst_cost = 0;
        record = 0;

        Edgelist.clear();
        m.clear();

        for( int i = 0; i < V; i++ )
        {
            cin >> s >> s1 >> w;

            if( !m.count(s) )
            {
                m[s] = ++nodes;
            }
            if( !m.count(s1) )
            {
                m[s1] = ++ nodes;
            }

            int a = m[s];
            int b = m[s1];

            Edgelist.push_back( {w, ii( a, b )} );
        }

        //cout << nodes << " " << Edgelist.size() << "\n";

        UF.make_set( nodes );

        sort( Edgelist.begin(), Edgelist.end() );

        for( int i = 0; i < Edgelist.size(); i++ )
        {
            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
            {
                mst_cost += Edgelist[i].first;

                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
            }
        }

        if( UF.numofdisjointset() == 1 ) record = 0;
        else record = 1;

        if( record == 0 )
        {
            printf("Case %d: %d\n", ++loop, mst_cost );
        }

        else if( record == 1 )
        {
            printf("Case %d: Impossible\n", ++loop );
        }

    }
    return 0;
}

