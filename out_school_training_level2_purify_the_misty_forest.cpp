#include <iostream>
using namespace std;

int count = 1;

void dfs(char list[20][20], int x, int y, int m, int n){
    list[x][y] = '#';
    if(list[x][y - 1] == '.' && y > 0){
        count += 1;
        dfs(list, x, y - 1, m, n);
    }
    if(list[x - 1][y] == '.' && x > 0){
        count += 1;
        dfs(list, x - 1, y, m, n);
    }
    if(list[x][y + 1] == '.' && y < m - 1){
        count += 1;
        dfs(list, x, y + 1, m, n);
    }
    if(list[x + 1][y] == '.' && x < n - 1){
        count += 1;
        dfs(list, x + 1, y, m, n);
    }
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    while(m != 0 && n != 0){
        char list[20][20];
        int startX, startY;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> list[i][j];
                if(list[i][j] == '@'){
                    startX = i;
                    startY = j;
                }
            }
        }
        dfs(list, startX, startY, m, n);
        cout << count << endl;
        cin >> m >> n;
        count = 1;
    }
    return 0;
}