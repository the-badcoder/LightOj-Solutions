/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/
/// Author: Tareq Aziz Khan

#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <ctime>
#include <string>
#define PI 2 * acos(0.0)
#define LL long long

using namespace std;

int bin( int n )
{
    int rem, i = 1, binary = 0;

    while( n != 0 )
    {
        rem = n % 2;
        n /= 2;
        binary += rem * i;
        i *= 10;
    }
    return binary;

}
int main()
{
    int test, a, b, c, d, a1, b1, c1, d1, loop = 0;

    cin >> test;

    while( test-- )
    {
        scanf("%d.%d.%d.%d %d.%d.%d.%d", &a, &b, &c, &d, &a1, &b1, &c1, &d1);

        if( bin(a) == a1 && bin(b) == b1 && bin(c) == c1 && bin(d) == d1 )
        {
            printf("Case %d: Yes\n", ++loop);
        }
        else
        {
            printf("Case %d: No\n", ++loop);
        }
    }
    return 0;
}

