#include <bits/stdc++.h>

using namespace std;

#define WRITE freopen("output.txt", "w", stdout);

long long get( long long n)
{
    long long z = 0;
    while (n > 0)
    {
        n /= 5;
        z += n;
    }
    return z;
}

int main()
{
    //WRITE;

    int k, loop = 0, test;

    scanf("%d", &test);

    while( test-- )
    {
        scanf("%d", &k);

        long long low = 0, high = (long long) 1e9;

        while (low < high)
        {
            long long mid = (low + high) >> 1;

            long long cnt = get(mid);

            if ( cnt < k )
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        vector <long long> res;

        while ( get(low) == k )
        {
            res.push_back(low);
            low++;
        }

        int sz = res.size();

        if( sz == 0 )
        {
            printf("Case %d: impossible\n", ++loop );
        }

        else
        {
            sort( res.begin(), res.end() );
            for( int i = 0; i < sz; i++ ){
                printf("Case %d: %lld\n", ++loop, res[i] );
                break;
            }
        }
    }
    return 0;
}

