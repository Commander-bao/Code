#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
string Left[3];
string Right[3];
string result[3];

bool feitCoin(char coin, bool isLight){
    string c;
    c.push_back(coin);
    for(int i = 0; i < 3; i++){
        string l = Left[i], r = Right[i];
        if(!isLight) swap(l, r);
        switch (result[i][0])
        {
        case 'e':
            if(l.find(c) != string::npos || r.find(c) != string::npos)
                return false;
            break;
        case 'u':
            if(r.find(c) == string::npos)return false;
            break;
        case 'd':
            if(l.find(c) == string::npos)return false;
            break;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n, i;
    cin >> n;
    while(n--){
        for(i = 0; i < 3; i++){
            cin >> Left[i] >> Right[i] >> result[i];
        }
        for(char coin = 'A'; coin <= 'L'; coin++){
            if(feitCoin(coin, true)){
                cout << coin << " is the counterfeit coin and it is light. " << endl;
                break;
            }else if(feitCoin(coin, false)){
                cout << coin << " is the counterfeit coin and it is heavy. " << endl;
                break;
            }
        }
    }
    return 0;
}