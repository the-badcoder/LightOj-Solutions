#include <bits/stdc++.h>

using namespace std;
#define WRITE                 freopen("output.txt", "w", stdout);

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

map<string, int> m;

const int maxn = 1234;
int Rank[maxn], p[maxn];
int numSets;
vector <int> setSize;

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        setSize.assign( x, 1 );

        for( int i = 0; i < x; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int x )
    {
        if( p[x] != x ) return findSet( p[x] );
        else return x;
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
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];

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
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;

int main()
{
    int V, E, u, v, w, mst_cost, mst_cost1, test, loop = 0, sum, n, x;
    string s, s1;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d", &n );

        mst_cost1 = mst_cost = sum = x = 0;

        vector < pair < int, ii > > Edgelist;
        Edgelist.clear();

        while( 1  )
        {
            cin >> u >> v >> w;

            if( u == 0 && v == 0 && w == 0 )
            {
                break;
            }

            Edgelist.push_back( make_pair( w, ii ( u, v ) ) );

            /// W == First Value. U == Second.Second. V == Second.first
        }

        UF.make_set( n+1 );

        sort( Edgelist.begin(), Edgelist.end() );

        for( int i = 0; i < Edgelist.size(); i++ )
        {
            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
            {
                mst_cost += Edgelist[i].first;

                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
            }
        }

        /* for( int i = 0; i < V; i++ ){
             cout << Edgelist[i].first << " " << Edgelist[i].second.first << " " << Edgelist[i].second.second << endl;
         }
         */

        UF.make_set( n+1 );

        for( int i = Edgelist.size()-1; i >= 0; i-- )
        {
            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
            {
                mst_cost1 += Edgelist[i].first;

                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
            }
        }

        //cout << mst_cost << " " << mst_cost1 << endl;

        sum = ( mst_cost1 + mst_cost );

        if( sum % 2 == 0 )
        {
            printf("Case %d: %d\n", ++loop, sum / 2 );
        }
        else
        {
            cout << "Case " << ++loop << ": " << sum << "/" << 2 << endl;
        }

    }
    return 0;
}
