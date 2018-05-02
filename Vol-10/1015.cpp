#include<stdio.h>

int main()
{
    int t,a,sum,n,b[1000],i=0;

    scanf("%d",&t);

        while(t--){
            scanf("%d",&n);
            sum = 0;
            for(a=1;a<=n;a++){
                scanf("%d",&b[n]);
                sum +=b[n];
            }
            printf("Case %d: %d\n",++i,sum);
        }
    return 0;
}
