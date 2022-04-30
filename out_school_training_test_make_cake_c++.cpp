#include <iostream>
using namespace std;

int v, n;
int sumV = 0, sumS = 0;
int minSum = 0;
void dfs(int u, int r, int h){
    if(u == n && sumV ==v){
        if(sumV == v){
            if(minSum == 0){
                minSum = sumS;
            }else if(sumS < minSum){
                minSum = sumS;
            }
        }
    }else{
        for(int i = 1; i < r; i++){
            for(int j = 1; j < h; j++){
                if(u == 0){
                    sumS = i * i;
                }
                sumV += i * i * j;
                sumS += 2 * i * j;
                dfs(u + 1, i, j);
                sumV -= i * i * j;
                sumS -= 2 * i * j;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> v >> n;
    dfs(0, v + 1, v + 1);
    cout << minSum;
    return 0;
}
