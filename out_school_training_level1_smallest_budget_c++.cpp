#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cost[100001];
int n, m;
int minCost = pow(2, 31) - 1, total = 0;

bool isBudgetBigEnough(int x){
    int cnt = 1, subtotal = 0;
    for(int i = 0; i < n; i++){
        if(cost[i] > x)return false;
        if(cost[i] + subtotal > x){
            subtotal = cost[i];
            cnt++;
            if(cnt > m)return false;
        }else{
            subtotal += cost[i];
        }
    }
    return true;
}

int bsearch_1(int l, int r){
    while(l < r){
        int mid = l + r >> 1;
        if(isBudgetBigEnough(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    freopen("C:\\Users\\Commander\\Downloads\\problem_2565_test_cases\\7.in","r",stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
        minCost = min(minCost, cost[i]);
        total += cost[i]; 
    }
    cout << bsearch_1(minCost, total) << endl;
    fclose(stdin);
    return 0;
}
