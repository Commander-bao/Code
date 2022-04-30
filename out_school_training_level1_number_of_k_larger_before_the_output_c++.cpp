#include <iostream>
#include <algorithm>
using namespace std;

bool comp (int a, int b){
    return a > b;
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d", &n);
    int list[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    scanf("%d", &k);
    sort(list, list + sizeof(list) / sizeof(list[0]), comp);
    for(int i = 0; i < k; i++){
        printf("%d\n", list[i]);
    }
    return 0;
}
