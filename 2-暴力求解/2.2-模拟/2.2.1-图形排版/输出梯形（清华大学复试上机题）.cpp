//
// Created by 王泽 on 2021/2/16.
//

#include "iostream"
using namespace std;

int main(){
    int h;
    cin >> h;
    int bottom = h + 2*(h-1);
    for (int i = 0; i < h; ++i) {
        int star = h + 2*i;
        int blankspace = bottom - star;
        for (int j = 0; j < blankspace; ++j) {
            cout << " ";
        }
        for (int j = 0; j < star; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}