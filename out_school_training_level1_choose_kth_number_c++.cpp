#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    int list[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    sort(list, list + sizeof(list) / sizeof(list[0]));
    printf("%d", list[k-1]);
    return 0;
}
