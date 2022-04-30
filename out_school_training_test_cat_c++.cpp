#include <iostream>
#include <algorithm>
using namespace std;

int cats[18];
int memory[18] = {0};
int Minn = 20;
int n, w;
bool comp(int a, int b){
    return a > b;
}

void dfs(int count, int Sum, int u){
    if(u == n){
        if(count < Minn) Minn = count;
    }else{
        for(int i = 0; i < n; i++){
            int t, flag = 0;
            if(memory[i] == 1){
                continue;
            }else if(memory[i] != 1){
                Sum += cats[i];
                memory[i] = 1;
            }
            t = Sum;
            if(Sum > w){
                Sum = 0;
                memory[i] = 0;
                count += 1;
                flag = 1;
            }
            dfs(count, Sum, u + 1);
            if(flag == 1){
                Sum = t;
                memory[i] = 1;
                count -= 1;
            }
            if(memory[i] == 1){
                Sum -= cats[i];
                memory[i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int count = 0;
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> cats[i];
    }
    sort(cats, cats + sizeof(cats) / sizeof(cats[0]), comp);
    dfs(0, 0, 0);
    cout << Minn + 1;
    return 0;
}