//
// Created by 王泽 on 2021/3/1.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 1000 + 10;
//const int INF = INT_MAX;    //将无穷大定义为int的最大值
int arr[MAXN];
int Fun1(int n){
    int ans;
    if (n == 0){
        ans = 1;
    } else{
        ans = 1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < arr[n]){
                ans = max(ans, Fun1(i) + 1);
            }
        }
    }
    return ans;

}
int memo[MAXN];
int Fun2(int n){
    if(memo[n] != -1){
        return memo[n];
    }
    int ans;
    if (n == 0){
        ans = 1;
    } else{
        ans = 1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < arr[n]){
                ans = max(ans, Fun1(i) + 1);
            }
        }
    }
    memo[n] = ans;
    return ans;
}

int dp[MAXN];
void Fun3(int n){
    for (int j = 0; j < n; ++j) {
        int ans;
        if (j == 0){
            ans = 1;
        } else{
            ans = 1;
            for (int i = 0; i < j; ++i) {
                if (arr[i] < arr[j]){
                    ans = max(ans, dp[i] + 1);
                }
            }
        }
        dp[j] = ans;
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    //朴素递归
//    int maximum = 0;
//    for (int i = 0; i < n; ++i) {
//        maximum = max(maximum, Fun1(i));
//    }
//    cout << maximum << endl;

    //递归 + 记忆化
//    fill(memo, memo + n, -1);
//    int maximum = 0;
//    for (int i = 0; i < n; ++i) {
//        maximum = max(maximum, Fun2(i));
//    }
//    cout << maximum << endl;

    //自底向上递推
    fill(dp, dp + n, -1);
    Fun3(n);
    int maximum = 0;
    for (int i = 0; i < n; ++i) {
        maximum = max(maximum, dp[i]);
    }
    cout << maximum << endl;
    return 0;
}
