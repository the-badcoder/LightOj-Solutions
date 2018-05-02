/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;


#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define EPS                   1e-9
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define setdp(ar)             memset(ar, -1, sizeof(ar))
#define DFS_BLACK             1
#define DFS_WHITE             0
#define White                 0
#define Black                 1

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

const int dr[] = { -1, 1, 0, 0 }; /// 4 side moves.
const int dc[] = { 0, 0, -1, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; /// 8 side moves.
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int kr[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; /// Knight Moves.
const int kc[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<string, string>      mss;
typedef  map<int,int>             mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<int,string>          mis;
typedef  pair<int,int>            ii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int>              vi;
typedef  vector<string>           vs;
typedef  vector<char>             vc;
typedef  vector<bool>             vb;
typedef  vector< ii >             vii;

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

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.

int maxi;

struct node
{
    bool mark;
    int digit = 0;
    //int maxi;
    node* next[ 5 + 1 ];
    node()
    {
        //maxi = INT_MIN;
        mark = false;
        for( int i = 0; i < 5; i++ )
        {
            next[i] = NULL;
        }
    }
} * root;

int add_trie( string s, int len )
{
    node* curr = root;
    for( int i = 0; i < len; i++ )
    {
        int id;

        if( s[i] == 'A' ) id = 0;
        else if( s[i] == 'C' ) id = 1;
        else if( s[i] == 'G' ) id = 2;
        else id = 3;

        if( curr->next[id] == NULL )
        {
            curr->next[id] = new node();
            //curr = curr->next[id];
        }
        curr = curr->next[id];
        curr->digit++;

        int total = curr->digit;
        int sz = i + 1;

        if( total * sz >= maxi ){
            maxi = total * sz;
        }
    }
    curr->mark = true;
}

int search_trie( string s, int len )
{
    node* curr = root;
    for( int i = 0; i < len; i++ )
    {
        int id = (int) s[i] - 48;
        //if( curr->next[id] == NULL )
        //return false;
        curr = curr->next[id];
    }
    return curr->digit;
}

void del_trie( node* curr )
{
    for( int i = 0; i < 5; i++ )
        if( curr->next[i] )
            del_trie( curr->next[i] );
    delete( curr );
}

int main()
{
    int test, n, loop = 0, sum, total;

    sf1( test );

    while( test-- )
    {
        maxi = INT_MIN;
        root = new node();
        sf1( n );
        string s;

        for( int i = 0; i < n; i++ ){
            cin >> s;

            add_trie( s, s.size() );
        }

        printf("Case %d: %d\n", ++loop, maxi );
        del_trie( root );
    }

    return 0;
}

