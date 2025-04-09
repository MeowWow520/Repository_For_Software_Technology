#include <bits/stdc++.h>
using namespace std;

/** Lucky Number - Loop
 *  ------Problem Description------
 *  Xiaolan believes that if a number has an even number of digits,
 *  and the sum of the first half of the digits equals the sum of the second half of the digits,
 *  then this number is his lucky number. For example, 2314 is a lucky number because it has 4 digits, and 2 + 3 = 1 + 4.
 *  Now, please help him calculate how many different lucky numbers there are between 1 and 100000000.
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
