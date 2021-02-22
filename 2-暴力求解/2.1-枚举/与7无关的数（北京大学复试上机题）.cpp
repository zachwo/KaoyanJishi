//
// Created by 王泽 on 2021/2/15.
//

#include <iostream>
using namespace std;

//习题2.1
bool relate7(int x){
    if (x%7 == 0)
        return true;
    while (x != 0){
        int t = x % 10;
        if (t == 7)
            return true;
        x /= 10;
    }
    return false;
}

int main(){
    int n;
    while (cin >> n){
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (!relate7(i))
                sum += i*i;
        }
        cout << sum << endl;
    }
    return 0;
}






