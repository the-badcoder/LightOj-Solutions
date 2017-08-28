#include<stdio.h>
#include<math.h>

int main()
{
    int t,j=0;
    long int a,b,c,sum;

    scanf("%d",&t);

    while(t--){
       scanf("%ld %ld %ld",&a,&b,&c);

       sum = sqrt((a*a) + (b*b));

       if(sum==c){
        printf("Case %d: yes\n",++j);
       }
       else {
        printf("Case %d: no\n",++j);
       }

    }
    return 0;
}
