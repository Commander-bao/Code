#include <iostream>
using namespace std;

int matrix[30][50] = {0};
long long count = 0;
void dfs(int u, int n, int list[][50], int i, int j){
    if(u == n){
        count += 1;
    }else{
        if(list[i + 1][j] == 0){
            list[i + 1][j] = 1;
            dfs(u + 1, n, list, i + 1, j);
            list[i + 1][j] = 0;
        }
        if(list[i][j + 1] == 0){
            list[i][j + 1] = 1;
            dfs(u + 1, n, list, i, j + 1);
            list[i][j + 1] = 0;
        }
        if(list[i][j - 1] == 0){
            list[i][j - 1] = 1;
            dfs(u + 1, n, list, i, j - 1);
            list[i][j - 1] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    matrix[0][25] = 1;
    dfs(0, n, matrix, 0, 25);
    cout << count;
    return 0;
}
