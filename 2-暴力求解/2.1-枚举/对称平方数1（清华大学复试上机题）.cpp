//
// Created by 王泽 on 2021/2/15.
//

#include <iostream>
using namespace std;

/**
 *  求反序数
 * @param x
 * @return
 */
int Reverse(int x){
    int revx = 0;
    while (x != 0){
        revx *= 10;
        revx += x % 10;
        x /= 10;
    }
    return revx;
}


int main(){
    for (int i = 0; i <= 256 ; ++i) {
        int x = i*i;
        if (x == Reverse(x))
            cout << i << endl;
    }
    return 0;
}








