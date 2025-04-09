#include <bits/stdc++.h>
using namespace std;



/** 幸运数 - 循环
 *  ------问题描述------
 *  小蓝认为如果一个数含有偶数个数位
 *  并且前面一半的数位之和等于后面一半的数位之和
 *  则这个数是他的幸运数字。例如 2314 是一个幸运数字，因为它有 4 个数位, 并且 2 + 3 = 1 + 4。
 *  现在请你帮他计算从1至100000000之间共有多少个不同的幸运数字
*/
bool IsLuck(int n) {
    if (((int)log10(n) + 1) % 2 == 1) return false;
    vector <int> arr;
    while (n > 0) {
        int temp = 0;
        temp = n % 10;
        n /= 10;
        arr.push_back(temp);
    }
    int len = arr.size();
    int a = 0, b = 0;
    for (int i = 0; i < len / 2; i++) {
        a += arr[i];
    }
    for (int i = len / 2; i < len; i++) {
        b += arr[i];
    }
    if (a == b) return true;
    else return false;
}
int main() {
    int ans = 0;
    for (int i = 11; i <= 100000000; i++) {
        if (IsLuck(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
