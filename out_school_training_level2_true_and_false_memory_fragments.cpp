#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string matrix[9] = 
{{"530070000"},{"600195000"},{"098000060"}
,{"800060003"},{"400803001"},{"700020006"}
,{"060000280"},{"000419005"},{"000080079"}};

int a[9][9], b[9][9];

bool checkInput(){
    string line;
    for(int i = 0; i < 9; i++){
        cin >> line;
        if(line.size() != 9){
            return false;
        }
        for(int j = 0; j < 9; j++){
            int t = line[j] - '0';
            if(t < 0 || t > 9)return false;
            if(a[i][j] != 0 && a[i][j] != t)return false;
            b[i][j] = t;
        }
    }
    return true;
}

bool checkRow(){
    for(int i = 0; i < 9; i++){
        int memory[9] = {0};
        int sum = 0;
        for(int j = 0; j < 9; j++){
            memory[b[i][j] - 1] = 1;
        }
        for(int j = 0; j < 9; j++){
            sum += memory[j];
        }
        if(sum != 9)return false;
    }
    return true;
}

bool checkColumn(){
    for(int i = 0; i < 9; i++){
        int memory[9] = {0};
        int sum = 0;
        for(int j = 0; j < 9; j++){
            memory[b[j][i] - 1] = 1;
        }
        for(int j = 0; j < 9; j++){
            sum += memory[j];
        }
        if(sum != 9)return false;
    }
    return true;
}

bool checkBlock(){
    for(int x = 0; x < 9; x += 3){
        for(int y = 0; y < 9; y += 3){
            int memory[9] = {0};
            int sum = 0;
            for(int dx = 0; dx < 3; dx++){
                for(int dy = 0; dy < 3; dy++){
                    memory[b[x + dx][y + dy] - 1] = 1;
                }
            }
            for(int i = 0; i < 9; i++){
                sum += memory[i];
            }
            if(sum != 9)return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            a[i][j] = matrix[i][j] - '0';
        }
    }    
    if(checkInput() && checkRow() && checkColumn()){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
