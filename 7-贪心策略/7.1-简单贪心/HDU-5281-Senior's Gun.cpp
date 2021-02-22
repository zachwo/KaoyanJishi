//
// Created by 王泽 on 2021/2/22.
//

//
// Created by 王泽 on 2021/2/22.
//
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
/**
 * 贪心策略：
 * 问题分解成为多个子问题
 * 子问题求局部最优解
 * 局部最优解组合成原问题的解
 *
 * 排序函数：sort(begin, end, cmp)，
 * 其中begin为指向待sort()的数组的第一个元素的指针，
 * end为指向待sort()的数组的最后一个元素的下一个位置的指针，
 * cmp参数为排序准则，如果没有的话，默认以非降序排序。
 * sort函数需要#include <algorithm>
 * @return
 */

/**
 * 降序排列
 * 当比较函数返回值为true时，表示的是比较函数的第一个参数x将会排在第二个参数前面
 * @param x
 * @param y
 * @return
 */
bool compare(long long x,long long y){
    return x > y;
}
int main(){
    int t;
    cin >> t;
    while (t){
        int n, m;   // n把枪，m只怪物
        cin >> n >>m;
        long long a[100010], b[100010];//a[i]为第i把枪的攻击力；b[j]为第j只怪物的防御力；
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];
        //攻击力降序排列
        sort(a,a+n, compare);
        //防御力生序排列
        sort(b,b+m);
        //计算赏金
        long long bonus = 0;
        for (int i = 0; i < (n<m ? n : m); ++i) {
            if (a[i] <= b[i])
                break;
            bonus += (a[i]-b[i]);
        }
        cout << bonus << endl;

        t--;
    }
    return 0;
}
