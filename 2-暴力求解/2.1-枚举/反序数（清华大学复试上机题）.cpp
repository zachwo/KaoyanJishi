//
// Created by 王泽 on 2021/2/15.
//

#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    for (int i = 1000; i <= 9999; ++i) {
        int t = i;
        a = t / 1000; // 千位
        t %= 1000;
        b = t / 100; // 百位
        t %= 100;
        c = t / 10; // 十位
        d = t % 10; // 个位

        if (9*i == d*1000 + c*100 + b*10 + a)
            cout << i << endl;
    }
    return 0;
}













