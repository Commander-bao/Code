#include <iostream>
#include <cmath>
using namespace std;

void p(int n){
    int list[20];
    int i=0,j;
    do{
        list[i] = n % 2;
        n /= 2;
        i++;
    }while(n/2>=0 && n!=0);
    i-=1;
    int count=1;
    for(j=i;j>=0;j--){
        if(list[j]==1){
            if(count!=1){
                printf("+");
            }
            count++;
            if(j==1){
                printf("2");
            }else if(j==0){
                printf("2(0)");
            }else{
                printf("2(");
                p(j);
                printf(")");
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    p(n);
    return 0;
}
