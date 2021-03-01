#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 100;
// 朴素递归，时间复杂度 O(2^n)
int Fibonacci1(int n){
    int ans;
    if (n==0 || n==1){
        ans = n;
    } else{
        ans = Fibonacci1(n-1) + Fibonacci1(n-2);
    }
    return ans;
}
// 朴素递归+记忆化, 时间复杂度 O(n)
int memo[MAXN];
int Fibonacci2(int n){
    if (memo[n] != -1){
        return memo[n];
    }
    int ans;
    if (n==0 || n==1){
        ans = n;
    } else{
        ans = Fibonacci2(n-1) + Fibonacci2(n-2);
    }
    memo[n] = ans;
    return ans;
}
//自底向上基于递推求解，与Fibonacci2本质上一致
int fib[MAXN];
int Fibonacci3(int n){
    for (int i = 0; i <= n; ++i) {
        int ans;
        if (i == 0 || i == 1){
            ans = n;
        }else{
            ans = fib[i-1] + fib[i-2];
        }
        fib[i] = ans;
    }
    return fib[n];
}

int main(){
    int n;
    cin >> n;
    cout << Fibonacci1(n) << endl;
    fill(memo, memo + MAXN, -1);
    cout << Fibonacci2(n) << endl;
    return 0;
}
