#include <iostream>
#include <cmath>
using namespace std;

double n;

double divide(double a, double b, double c){
    c = (a + b) /2;
    if(fabs(pow(c,3) - fabs(n)) < pow(10, -6)){
        return c;
    }else{
        if(pow(c,3) - fabs(n) > 0){
            divide(a, c, b);
        }else{
            divide(c, b, a);
        }
    }
}

int main(int argc, char const *argv[])
{
    double a = 0, b, c = 0;
    cin >> n;
    for(int i = 0; ; i++){
        if(pow(i, 3) > fabs(n)){
            b = i;
            break;
        }
    }
    if(n < 0)cout << '-';
    printf("%.6lf", divide(a, b, c));
    return 0;
}
