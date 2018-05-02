#include<stdio.h>

int main()
{
    int t,a,b,sum,i=0;

    scanf("%d",&t);
    if(t<=125){
        while(t--){
            scanf("%d %d",&a,&b);
            if((a>=0 && a<=10) && (b>=0 && b<=10)){
                sum = a + b;
            }
            printf("Case %d: %d\n",++i,sum);
        }
    }
    return 0;
}
