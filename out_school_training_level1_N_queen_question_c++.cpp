#include <iostream>
using namespace std;

int put[13];
int board[13][13],flag[13][13];

void dfs(int n, int u, int board[][13], int flag[][13]){
    int i,j,k,l;
    if(u == n){
        for(i=0;i<n;i++){
            cout << put[i];
        }
        cout << endl;
    }else{
        for(i=0;i<n;i++){
            if(flag[i][u] == 0){
                put[u] = board[i][u];
                for(k=0;k<n;k++){
                    flag[k][u]+=1;
                    flag[i][k]+=1;
                }
                for(k=u,l=0;k<n;k++){
                    if(i+l<n)flag[i+l][k]+=1;
                    if(i-l>=0)flag[i-l][k]+=1;
                    l++;
                }
                for(k=u,l=0;k>=0;k--){
                    if(i+l<n)flag[i+l][k]+=1;
                    if(i-l>=0)flag[i-l][k]+=1;
                    l++;
                }
                dfs(n, u+1, board, flag);
                for(k=0;k<n;k++){
                    flag[k][u]-=1;
                    flag[i][k]-=1;
                }
                for(k=u,l=0;k<n;k++){
                    if(i+l<n)flag[i+l][k]-=1;
                    if(i-l>=0)flag[i-l][k]-=1;
                    l++;
                }
                for(k=u,l=0;k>=0;k--){
                    if(i+l<n)flag[i+l][k]-=1;
                    if(i-l>=0)flag[i-l][k]-=1;
                    l++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            board[i][j] = i+1;
            flag[i][j] = 0;
        }
    }
    dfs(n, 0, board, flag);
    return 0;
}
