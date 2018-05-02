#include<stdio.h>
#define pi 3.1415926535897932384626433832795

int main()
{
    int t,j=0;
    double a,b,r;

    scanf("%d",&t);

    while(t--){
       scanf("%lf",&r);

       a = 4 * r * r;

      b = pi * r * r;

      printf("Case %d: %.2lf\n",++j,a - b);
    }
    return 0;
}
