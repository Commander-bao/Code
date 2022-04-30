#include <iostream>
using namespace std;

int flag = 0, p, q;
char list[26][26];

struct chess{
    char column;
    int row;
}Chess[26][26], storage[26];

int stepX[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, 
stepY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void dfs(int u, int x, int y){
    if(u == p * q){
        for(int i = 0; i < p * q; i++){
            cout << storage[i].column << storage[i].row;
        }
        cout << endl;
        flag = 1;
    }else{
        if(u == 1){
            list[x][y] = '1';
            storage[0] = Chess[x][y];
        }
        for(int i = 0; i < 8; i++){
            int x1 = x + stepX[i], y1 = y + stepY[i];
            if(x1 >= 0 && x1 < q && y1 >= 0 && y1 < p && list[x1][y1] == '0'){
                list[x1][y1] = '1';
                storage[u] = Chess[x1][y1];
                dfs(u + 1, x1, y1);
                list[x1][y1] = '0';
                if(flag == 1)break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, num = 1;
    cin >> n;
    for(char i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            Chess[i][j].column = i + 'A';
            Chess[i][j].row = j + 1;
        }
    }
    while(n--){
        flag = 0;
        cin >> p >> q;
        cout << "#" << num++ << ':'<< endl;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                list[i][j] = '0';
            }
        }
        if(p == 1 && q == 1){
            cout << "A1" << endl;
        }else if(p <= 2 || q <= 2){
            cout << "none" << endl;
        }else{
            dfs(1, 0, 0);
            if(flag == 0)cout << "none" << endl;
        }
    }
    return 0;
}