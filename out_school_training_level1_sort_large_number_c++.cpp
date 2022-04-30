#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    long long list[n];
    for(int i = 0; i < n; i++){
        scanf("%ld",&list[i]);
    }
    sort(list, list+sizeof(list)/sizeof(list[0]));
    for(int i = 0; i < n; i++){
        printf("%ld",list[i]);
        if(i != n-1)printf(" ");
    }
    return 0;
}
