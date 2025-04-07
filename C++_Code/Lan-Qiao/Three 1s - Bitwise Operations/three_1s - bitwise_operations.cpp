#include <iostream>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;

/** Three 1s - Bitwise Operations
 *  ------Problem Description------
 *  A number is considered valid if its binary representation has exactly 3 bits set to 1.
 *  For example: 7 in binary is 111 (3 ones); 11 in binary is 1011 (3 ones).
 *  The first few numbers satisfying the condition are: 7, 11, 13, 14, 19, 21, ... Find the 23rd such number.
 */

// Calculate n raised to the power of m
ll pow(ll n, ll m) {
    ll ans = 1;
    for (int i = 1; i <= m; i++) ans *= n;
    return ans;
}

// Convert decimal to binary (returns a pseudo-binary number in decimal form)
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
