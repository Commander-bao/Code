#include <iostream>
#include <algorithm>
using namespace std;

int list[100001], tmp[100001];

long long count(int nums[], int left, int right){
    if(left >= right) return 0;
    int mid = left + right >> 1;
    long long result = count(nums, left, mid) + count(nums, mid + 1, right);
    int k = 0, p = left, q = mid + 1;
    while(p <= mid && q <= right){
        if(nums[p] <= nums[q]){
            tmp[k++] = nums[p++];
        }else{
            result += mid - p + 1;
            tmp[k++] = nums[q++];
        }
    }
    while(p <= mid) tmp[k++] = nums[p++];
    while(q <= right) tmp[k++] = nums[q++];
    for(int i = left, k = 0; i <= right; i++, k++)nums[i] = tmp[k];
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    cout << count(list, 0, n-1);
    return 0;
}
