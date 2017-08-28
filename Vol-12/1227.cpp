//Bismillah Hir Rahmanir Rahim
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    /* Practice of C++ :D */

    int test, n, p , q , egg[35], sum, serial , c=0;

    scanf("%d",&test);

    while(test--){
        cin >> n >> p >> q;

        for(int i=0; i<n; i++){
            scanf("%d",&egg[i]);
        }
        sum = serial = 0;

        for(int i=0; i<n; i++){
            sum += egg[i];

            if(sum > q || serial>=p){
                break;
            }
            else {
                serial++;
            }
        }
        cout << "Case "<< ++c << ": "  <<  serial << endl;
    }

    return 0;
}
