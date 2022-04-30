#include <iostream>
#include <cstring>
using namespace std;

char put[8];

void dfs(int length, int now, char c[], int flag[]){
    if(now == length){
        for(int i = 0; i < length; i++){
            cout << put[i];
        }
        cout << endl;
    }else{
        for(int i = 0; i < length; i++){
            if(flag[i] == 0){
                put[now] = c[i];
                flag[i] = 1;
                dfs(length, now+1, c, flag);
                flag[i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char c[9];
    gets(c);
    int i,j;
    for(i=0;i<strlen(c);i++){
        for(j=0;j<strlen(c)-i-1;j++){
            if(c[j]>c[j+1]){
                char t = c[j];
                c[j] = c[j+1];
                c[j+1] = t;
            }
        }
    }
    int flag[strlen(c)]={0};
    dfs(strlen(c), 0, c, flag);
    return 0;
}
