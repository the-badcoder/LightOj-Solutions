#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, n, sum, loop = 0;
    string s, s1, s2, store;

    cin >> test;

    while( test-- )
    {
        stack <string> in, out;
        store = "http://www.lightoj.com/";

        printf("Case %d:\n", ++loop);

        while( cin >> s && s != "QUIT" )
        {
            if( s == "BACK" )
            {
                if( out.empty() )
                {
                    cout << "Ignored\n";
                }
                else
                {
                    in.push(store);
                    store = out.top();
                    out.pop();
                    cout << store << endl;
                }
            }
            else if( s == "FORWARD" )
            {
                if( in.empty() )
                {
                    cout << "Ignored\n";
                }
                else
                {
                    out.push(store);
                    store = in.top();
                    in.pop();
                    cout << store << endl;
                }
            }
            else
            {
                out.push(store);
                cin >> store;
                cout << store << endl;;

                while( !in.empty() )
                {

                    in.pop();
                }

            }
        }
    }
    return 0;
}
