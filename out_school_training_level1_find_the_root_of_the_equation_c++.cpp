#include <iostream>
#include <cmath>
using namespace std;

double divide(double a, double b, double c){
    c = (a + b) / 2;
    if(fabs(pow(c, 3) - 5 * pow(c, 2) + 10 * c - 80) <= pow(10, -9)){
        return c;
    }else{
        if(pow(c, 3) - 5 * pow(c, 2) + 10 * c - 80 > 0){
            divide(a, c, b);
        }else{
            divide(c, b, a);
        }
    }
}

int main(int argc, char const *argv[])
{
    //x3 - 5 x2 + 10 x - 80 = 0
    double a = 0, b, c = 0;
    for(int i = 0; ; i++){
        if(pow(i, 3) - 5 * pow(i, 2) + 10 * i - 80 > 0){
            b = i;
            break;
        }
    }
    printf("%.9lf",divide(a, b, c));
    return 0;
}
