#include <iostream>
using namespace std;

int fei(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else{
        return(fei(n-1)+fei(n-2));
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fei(n);
    return 0;
}
