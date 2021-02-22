//
// Created by 王泽 on 2021/2/15.
//

#include <iostream>
using namespace std;

//习题2.2

int main(){
    int n;
//    int x, y, z;
    while (cin >> n){
        for (int x = 0; x <= 100 ; ++x) {
            for (int y = 0; y <= 100; ++y) {
                for (int z = 0; z <= 100; ++z) {
                    if (15*x + 9*y + z <= 3*n && x + y + z == 100)//既然1/3不方便运算那就等号两边同乘3
                        cout << "x="<< x << ",y=" << y <<",z=" << z << endl;
                }
            }
        }
    }
    return 0;
}






