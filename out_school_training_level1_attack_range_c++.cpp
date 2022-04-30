#include <iostream>
#include <algorithm>
using namespace std;

int nums[100001];

int main(int argc, char const *argv[])
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &nums[i]);
	}
	while(q--){
		int k;
		scanf("%d", &k);
		int left = 0, right = n - 1;
		while(left < right){
			int mid = left + right >> 1;
			if(nums[mid] >= k){
				right = mid;
			}else{
				left = mid + 1;
			}
		}
		if(nums[left] != k){
			cout << "-1 -1" << endl;
		}else{
			cout << left << " ";
			left = 0, right = n - 1;
			while(left < right){
				int mid = left + right + 1 >> 1;
				if(nums[mid] <= k){
					left = mid;
				}else{
					right = mid - 1;
				}
			}
			cout << left << endl;
		}
	}
	return 0;
}


/*
struct numberList{
	int start = -1;
	int end = -1;
};

struct numberList list[10001];

int main(){
	int n, q;
	int j,k;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> k;
		if(i == 0){
			j = k;
			list[k].start = 0;
		}else{
			if(k != j){
				list[j].end = i - 1;
				list[k].start = i;
				j = k;
			}
			if(i == n - 1){
				list[k].end = n - 1;
			}
		}
	}
	for(int i = 0; i < q; i++){
		cin >> k;
		cout << list[k].start << ' ' << list[k].end << endl;
	}
	return 0;
}*/
