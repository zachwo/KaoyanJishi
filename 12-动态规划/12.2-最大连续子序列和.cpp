//
// Created by 王泽 on 2021/3/1.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = INT_MAX;    //将无穷大定义为int的最大值

// 朴素递归
long long arr[MAXN];
long long Fun1(int n){
    long long ans;
    if (n == 0){
        ans = arr[0];
    } else{
        ans = max(arr[n], Fun1(n-1) + arr[n]);
    }
    return ans;
}
//递归策略 + 记忆化
long long memo[MAXN];
long long Fun2(int n){
    if (memo[n] != -1){
        return memo[n];
    }
    long long ans;
    if (n == 0){
        ans = arr[0];
    } else{
        ans = max(arr[n], Fun2(n-1) + arr[n]);
    }
    memo[n] = ans;
    return ans;
}
//自底向上递推
long long dp[MAXN];
void Fun3(int n){
    for (int i = 0; i < n; ++i) {
        long long ans;
        if (i == 0){
            ans = arr[i];
        } else{
            ans = max(arr[i],dp[i-1] + arr[i] );
        }
        dp[i] = ans;
    }
}

int main(){
    int n;
    while (cin >> n){
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        // Fun1 : recursive朴素递归
//        long long maximum = - INF;
//        for (int i = 0; i < n; ++i) {
//            maximum = max(maximum , Fun1(i));
//        }
//        cout << maximum << endl;

        //Fun2: recursive + memorize
//        fill(memo, memo + n, -1);
//        long long maximum = - INF;
//        for (int i = 0; i < n; ++i) {
//            maximum = max(maximum , Fun2(i));
//        }
//        cout << maximum << endl;

        //Fun3:recurrent
        fill(dp, dp + n, -1);
        long long maximum = -INF;
        Fun3(n);
        for (int i = 0; i < n; ++i) {
            maximum = max(maximum, dp[i]);
        }
        cout << maximum << endl;
    }
    return 0;
}
