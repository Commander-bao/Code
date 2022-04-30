#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double polish(){
    string str;
    cin >> str;
    switch(str[0]){
        case '+':
            return polish() + polish();
            break;
        case '-':
            return polish() - polish();
            break;
        case '*':
            return polish() * polish();
            break;
        case '/':
            return polish() / polish();
            break;
        default:
            return stof(str);
            break;
    }
}

int main(int argc, char const *argv[])
{
    printf("%lf",polish());
    return 0;
}
