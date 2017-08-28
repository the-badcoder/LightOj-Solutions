#include<stdio.h>


int main()
{
    int t,j=0;
    long long int n,rev,temp;

    scanf("%d",&t);

    while(t--){
            rev = 0;
        scanf("%lld",&n);

     temp = n;

      while(temp!=0){
        rev = rev * 10;
        rev = rev + (temp%10);
        temp = temp / 10;
      }

      if(n==rev){
        printf("Case %d: Yes\n",++j);
      }
      else {
        printf("Case %d: No\n",++j);
      }

    }
    return 0;
}

