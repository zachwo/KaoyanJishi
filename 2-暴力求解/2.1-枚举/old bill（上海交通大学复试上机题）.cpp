//
// Created by 王泽 on 2021/2/15.
//

#include <iostream>
using namespace std;
//int main(){
//    int n;
//    int x, y, z;
//    while ((cin >> n) && (cin >> x >> y >> z)){
//        int wanwei, gewei;
//        int highPrice = -1;
//        for (int i = 1; i <= 9 ; ++i) {
//            for (int j = 0; j <= 9 ; ++j) {
//                for (int price = 100; price < 100000 ; ++price) {   //最高售为99999/1 = 99999；最低售价为10000/99 ≈ 101.01
//                    if (n*price == i*10000 + x*1000 + y*100 + z*10 + j){
//                        highPrice = price;
//                        wanwei = i;
//                        gewei = j;
//                    }
//                }
//            }
//        }
//        if (highPrice != -1)
//            cout << wanwei << " " << gewei << " " << highPrice << endl;
//        if (highPrice == -1) // 无法找出符合输入要求的输出则输出0
//            cout << 0 << endl;
//    }
//    return 0;
//}

int main(){
    int n;
    int x, y, z;
    while ((cin >> n) && (cin >> x >> y >> z)){
        int wanwei, gewei;
        int highPrice = -1;
        for (int i = 1; i <= 9 ; ++i) {
            for (int j = 0; j <= 9 ; ++j) {
                int totalPrice = i*10000 + x*1000 + y*100 + z*10 + j;
                if (totalPrice % n == 0){
                    highPrice = totalPrice/n;
                    wanwei = i;
                    gewei = j;
                }
            }
        }
        if (highPrice != -1)
            cout << wanwei << " " << gewei << " " << highPrice << endl;
        if (highPrice == -1) // 无法找出符合输入要求的输出则输出0
            cout << 0 << endl;
    }
    return 0;
}





