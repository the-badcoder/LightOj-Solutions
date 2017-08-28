#include <iostream>
#include <cstdio>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

double a[1000005];


int main()
{
    long long n, b, res;
    double store;
    int loop = 0, test;

    for( int i = 1; i <= 1000005; i++ )
    {
        a[i] = a[i-1] + log((double)i);
    }

    cin >> test;

    while( test-- )
    {
        scanf("%lld %lld", &n, &b);
        double sum = 0;
        sum = a[n];
        sum /= log( (double) b );
        sum = floor(sum);
        sum += 1;
        res = sum;

        printf("Case %d: %lld\n", ++loop, res);

    }
}
