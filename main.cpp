//
// Created by 王泽 on 2021/2/22.
//
#include <iostream>
#include <iomanip>
using namespace std;
/**
 * 贪心策略：
 * 问题分解成为多个子问题
 * 子问题求局部最优解
 * 局部最优解组合成原问题的解
 *
 * 传递数组的引用void test(int (&a)[n])，调用的时候必须要传递一个元素有n个的数组
 * @return
 */
void exchange(double &a,double &b ){
    double t = a;
    a = b;
    b = t;
}
/**
 * m:老鼠拥有多少猫粮
 * n:仓库的房间数（给出每个房间存储的咖啡豆数量以及交换这些咖啡豆共需要多少猫粮）
 * @return
 */
int main(){
    int t;
    cin >> t;
    while (t){
        int n, m;   // n把枪，m只怪物
        cin >> n >>m;
        int a[100010], b[100010];//a[i]为第i把枪的攻击力；b[j]为第j只怪物的防御力；
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];

        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < m; ++i)
            cout << b[i] << " ";
        cout << endl;


        t--;
    }
    return 0;
}


