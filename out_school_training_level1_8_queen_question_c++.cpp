#include <iostream>
using namespace std;

int board[8][8], flag[8][8];
int storage[8];
int put[92][8],count=0;
void dfs(int u, int board[][8],int flag[][8]){
    int i,j,k,l;
    if(u == 8){
        for(i=0;i<8;i++){
            put[count][i]=storage[i];
        }
        count+=1;
    }else{
        for(i=0;i<8;i++){
            if(flag[i][u]==0){
                storage[u]=board[i][u];
                for(k=0;k<8;k++){
                    flag[i][k]+=1;
                    flag[k][u]+=1;
                }
                for(k=u,j=0;k<8;k++,j++){
                    if(i-j>=0)flag[i-j][k]+=1;
                    if(i+j<8)flag[i+j][k]+=1;
                }
                for(k=u,j=0;k>=0;k--,j++){
                    if(i-j>=0)flag[i-j][k]+=1;
                    if(i+j<8)flag[i+j][k]+=1;
                }
                dfs(u+1, board, flag);
                for(k=0;k<8;k++){
                    flag[i][k]-=1;
                    flag[k][u]-=1;
                }
                for(k=u,j=0;k<8;k++,j++){
                    if(i-j>=0)flag[i-j][k]-=1;
                    if(i+j<8)flag[i+j][k]-=1;
                }
                for(k=u,j=0;k>=0;k--,j++){
                    if(i-j>=0)flag[i-j][k]-=1;
                    if(i+j<8)flag[i+j][k]-=1;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int i,j;
    int n,k;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            board[i][j]=i+1;
            flag[i][j]=0;
        }
    }
    dfs(0, board, flag);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> k;
        for(j=0;j<8;j++){
            cout << put[k-1][j];
        }
        cout << endl;
    }
    return 0;
}
