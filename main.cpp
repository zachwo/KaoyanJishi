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
int main(){
    int m, n;
    cin >> m >> n;
    while (m!= -1 || n!= -1){
        double JF[1100][3];   //接收数据：～30咖啡豆数量，需要猫粮数量，单位猫粮可换的咖啡豆数量
        for (int i = 0; i < n; ++i) {
            cin >> JF[i][0] >> JF[i][1];
            JF[i][2] = 1.0 * JF[i][0] / JF[i][1];

        }
        //性价比从高到低排序
        for (int i = 0; i < n-1; ++i) {
            for (int j = i; j < n; ++j) {
                if (JF[i][2] < JF[j][2]){
                    exchange(JF[i][0],JF[j][0]);
                    exchange(JF[i][1],JF[j][1]);
                    exchange(JF[i][2],JF[j][2]);
                }
            }
        }
        //计算m磅猫粮最多可换多少咖啡豆
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            if (m > 0){
                if (m > JF[i][1]){
                    sum += JF[i][0];
                    m -= JF[i][1];
                } else{
                    sum += m*JF[i][2];
                    m = 0;
                }
            } else
                break;
        }
        cout << fixed << setprecision(3) << sum << endl;


        cin >> m >> n;
    }
    return 0;
}

