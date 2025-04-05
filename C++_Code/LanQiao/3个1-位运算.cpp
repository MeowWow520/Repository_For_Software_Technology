#include <iostream>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;



/** 3��1-λ����
 *  ------��������------
 *  �е���ת��Ϊ������֮��, ������ 3 ����λΪ 1
 *  ���� 7 ת��Ϊ������Ϊ 111, �� 3 ����λΪ1; ���� 11 ת��Ϊ������Ϊ 1011, �� 3 ����λΪ 1
 *  ����������ǰ����������Ϊ: 7, 11, 13, 14, 19, 21, .....����, �� 23 ���������������Ƕ���
 */

// ���� n �� m ����
ll pow(ll n, ll m) {
    ll ans = 1;
    for (int i = 1; i <= m; i++) ans *= n;
    return ans;
}

// ʮ����ת����������
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
