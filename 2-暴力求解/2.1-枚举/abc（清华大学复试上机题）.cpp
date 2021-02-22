#include <iostream>
using namespace std;


//1、枚举策略

int main(){
    for (int  a = 1;  a <= 9; ++ a) {
        for (int b = 1; b <= 9; ++b) {
            for (int c = 0; c < 9; ++c) {
                if (100*a + 110*b + 12*c == 532)
                    cout << a << " " << b << " " << c << endl;
            }
        }
    }
    return 0;
}