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
#define PI 2 * acos(0.0)

using namespace std;

int main()
{
     int test, a, b, lift, enter, exit, time, total, loop = 0;

    cin >> test;

    while( test-- )
    {

        cin >> a >> b;

        time = (int) abs( (double) (a - b) ) * 4 + a * 4 + 19;

        printf("Case %ld: %ld\n", ++loop, time);

    }
    return 0;
}
