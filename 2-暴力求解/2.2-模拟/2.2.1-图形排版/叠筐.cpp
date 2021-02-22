//
// Created by 王泽 on 2021/2/16.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    char center, outer;
    char matrix[80][80];
    bool firstCase = true;  // 题目要求每一个测试用例之间输入一个换行，由于不知道用例个数，所以设计每一个用例之前输出换行，第一个用例不输出换行
    while (cin >> n >> center >> outer){

        if (firstCase){
            firstCase = false;
        } else{
            cout << endl;
        }

        //预处理：先把矩阵所有元素设为空格方便调试
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = ' ';
            }
        }

        //第一步：确定对角线上的数值
        for (int i = 0; i <= n/2; ++i) {
            if ((n/2)%2 == 0){
                if (i%2 == 0){
                    matrix[i][i] = center;
                    matrix[n-1-i][n-1-i] = center;
                } else{
                    matrix[i][i] = outer;
                    matrix[n-1-i][n-1-i] = outer;
                }
            } else{
                if (i%2 == 0){
                    matrix[i][i] = outer;
                    matrix[n-1-i][n-1-i] = outer;
                } else{
                    matrix[i][i] = center;
                    matrix[n-1-i][n-1-i] = center;
                }
            }
        }

        //第二步：自外向内一圈圈补齐
        for (int i = 0; i <= n/2 ; ++i) {   //补上三角
            for (int j = i; j <= n-1-i ; ++j) {
                matrix[i][j] = matrix[i][i];
                matrix[j][i] = matrix[i][i];
            }
        }
        for (int i = n-1; i >= n/2 ; --i) { //补下三角
            for (int j = i; j >= n-1-i ; --j) {
                matrix[i][j] = matrix[i][i];
                matrix[j][i] = matrix[i][i];
            }
        }

        //第三步：去掉四个角
        if (n!= 1)
            matrix[0][0] = matrix[0][n-1] = matrix[n-1][0] = matrix[n-1][n-1] = ' ';

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}

