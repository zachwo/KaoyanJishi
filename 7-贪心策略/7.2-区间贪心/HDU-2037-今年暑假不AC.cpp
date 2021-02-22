//
// Created by 王泽 on 2021/2/22.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
/**
 * 区间贪心：有开始，结束，持续时间等多个值
 * 选择结束时间最早的节目这一策略
 * 想要观看的节目尽可能的多，那么就应该选择看完一个节目之后剩下的时间尽可能的大，这样剩余的选择余地也会尽可能的多
 * @return
 */

struct progarm{
    int start;
    int end;
    int length;    //节目时长
};

bool compare(progarm p1, progarm p2){
    return p1.end < p2.end;
}
int main(){
    int n;
    cin >> n;
    while (n){
        progarm p[110];
        for (int i = 0; i < n; ++i) {
            cin >> p[i].start >> p[i].end ;
            p[i].length = p[i].end - p[i].start;
        }
        //按照结束时间从早到晚对节目进行排序
        sort(p, p+n,compare);
        //开始统计
        int sum = 0;
        int current = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i].start >= current){
//                不用考虑最后一个节目结束时间是否超过24点
//                if(current + p[i].length <= 24){
//                    sum ++;
//                    current = p[i].end;
//                }
                sum ++;
                current = p[i].end;
            }
        }
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}
