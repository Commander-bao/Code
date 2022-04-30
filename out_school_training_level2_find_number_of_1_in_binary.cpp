#include <iostream>
using namespace std;

int lowbit(int n){
    return n & -n;
}

int NumberOf1(int n){
    int res = 0;
    for (int i = n; i; i -= lowbit(i))res++;
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << NumberOf1(n);
    return 0;
}
