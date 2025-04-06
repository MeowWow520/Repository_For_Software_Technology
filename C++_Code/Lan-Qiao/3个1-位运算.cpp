#include <iostream>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;



/** 3个1-位运算
 *  ------问题描述------
 *  有的数转换为二进制之后, 正好有 3 个数位为 1
 *  例如 7 转换为二进制为 111, 有 3 个数位为1; 又如 11 转换为二进制为 1011, 有 3 个数位为 1
 *  满足条件的前几个数依次为: 7, 11, 13, 14, 19, 21, .....请问, 第 23 个满足条件的数是多少
 */

// 计算 n 的 m 次幂
ll pow(ll n, ll m) {
    ll ans = 1;
    for (int i = 1; i <= m; i++) ans *= n;
    return ans;
}

// 十进制转化到二进制
ll ten_two(int n) {
    ll ans = 0;
    while (n != 0) {
        for (int i = 0;; i++) {
            if (pow(2, i) > n) {
                ans += pow(10, i - 1);
                n -= pow(2, i - 1);
                break;
            }
        }
    }
    return ans;
}

int main() {
    int a = 0;
    int b = 0;
    for (ll i = 22;; i++) {
        int cot = 0;
        ll id = ten_two(i);
        while (id != 0) {
            int temp = 0;
            temp = id % 10;
            id /= 10;
            if (temp == 1) cot++;
        }
        if (cot == 3) {
            a++;
            b = i;
        }
        if (a == 17) break;
    }
    cout << b;
    return 0;
}
