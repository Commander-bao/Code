#include <iostream>
using namespace std;

int fen(int x, int y){
    if(y > x){
        return fen(x, x);
    }
    if(x == 0){
        return 1;
    }
    if(y <= 0){
        return 0;
    }
    return fen(x, y-1) + fen(x-y, y);
}

int main(int argc, char const *argv[])
{
    int n;
    int M, N;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> M >> N;
        cout << fen(M, N) << endl;
    }
    return 0;
}
