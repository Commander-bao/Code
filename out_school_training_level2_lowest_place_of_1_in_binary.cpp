#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;
    int n;
    cin >> n;
    for(int i = 0; i < 32; i++){
        if(n & 1 == 1){
            break;
        }else{
            n = n >> 1;
            count ++;
        }
    }
    cout << count;
    return 0;
}
