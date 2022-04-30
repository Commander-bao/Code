#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a[11];
    int change[11];
    int best[11];
    int minCount = 999999;
    for(int i = 1;i<=9;++i){
        cin >> a[i];
    }
    memset(change,0,sizeof(change));
    int sum = 0;
        for(change[1] = 0;change[1]<4;change[1]++)
        for(change[2] = 0;change[2]<4;change[2]++)
        for(change[3] = 0;change[3]<4;change[3]++)
        for(change[4] = 0;change[4]<4;change[4]++)
        for(change[5] = 0;change[5]<4;change[5]++)
        for(change[6] = 0;change[6]<4;change[6]++)
        for(change[7] = 0;change[7]<4;change[7]++)
        for(change[8] = 0;change[8]<4;change[8]++)
        for(change[9] = 0;change[9]<4;change[9]++)
        {
            sum = 0;
            sum+= (a[1]+change[1]+change[2]+change[4])%4;
            sum+= (a[2]+change[1]+change[2]+change[3]+change[5])%4;
            sum+= (a[3]+change[2]+change[3]+change[6])%4;
            sum+= (a[4]+change[1]+change[4]+change[5]+change[7])%4;
            sum+= (a[5]+change[1]+change[3]+change[5]+change[7]+change[9])%4;
            sum+= (a[6]+change[3]+change[5]+change[6]+change[9])%4;
            sum+= (a[7]+change[4]+change[7]+change[8])%4;
            sum+= (a[8]+change[5]+change[7]+change[8]+change[9])%4;
            sum+= (a[9]+change[6]+change[8]+change[9])%4;
            if(sum == 0){
                int count = 0;
                for(int j = 1; j <= 9; j++){
                    count += change[j];
                }
                if(count < minCount){
                    minCount = count;
                    memcpy(best,change,sizeof(change));
                }
                for(int j = 1; j <= 9; j++){
                    while(best[j]--){
                        cout << j << " ";
                    }
                }
            }
        }
    return 0;
 }