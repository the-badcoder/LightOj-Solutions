/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/

///Containers Start..
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>
#include <bitset>
#include <algorithm>
///Container End.

/// **** So be patient. Indeed, the promise of ALLAH is truth - QURAN - 30:60 ****

///Macro Start..
#define High        1000001
#define PI          acos(-1.0)
#define pii         pair <int, int>
#define ppi         pair <pii, int>
#define ff          first
#define ss          second
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define nn          '\n'
#define all(c)      (c).begin(), (c).end()
#define tr(c, i)    for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define prsnt(c,x)  ((c).find(x) != (c).end())
#define cprsnt(c,x)  (find(all(c), x) != (c).end())
///Macro End.

using namespace std;


int main()
{
    int test, len, sum, x, digit, loop = 0;
    string s, s1, s2, s3;

    cin >> test;
    cin.ignore();
    while( test-- )
    {
        getline(cin, s);
        getline(cin, s1);
        s2 = s3 = "";

        for( int i = 0; i < s.size(); i++ )
        {
            if( isspace(s[i]))
            {
                continue;
            }
            else
            {
                s2 += tolower(s[i]);
            }
        }
        for( int j = 0; j < s1.size(); j++ )
        {
            if( isspace(s1[j]))
            {
                continue;
            }
            else
            {
                s3 += tolower(s1[j]);
            }
        }

        sort( s2.begin(), s2.end() );
        sort( s3.begin(), s3.end() );

        //cout << s2 << endl;
        //cout << s3 << endl;

        if( s2 == s3 )
        {
            printf("Case %d: Yes\n", ++loop );
        }
        else
        {
            printf("Case %d: No\n", ++loop );
        }


    }
    return 0;
}
