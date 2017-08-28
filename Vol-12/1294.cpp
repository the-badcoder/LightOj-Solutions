//Bismillah HiR Rahmanir Rahim

#include <stdio.h>

int main()
{
   long long int m, n, sum;
   int i=0,t;

   scanf("%d",&t);

   while(t--){
        scanf("%lld %lld", &m,&n);
        sum = n * (m/2);

        printf("Case %d: %lld\n", ++i,sum);
   }
    return 0;
}
