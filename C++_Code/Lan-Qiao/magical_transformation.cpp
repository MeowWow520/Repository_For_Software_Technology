#include <iostream>
using namespace std;
const int Mod = 998244353;

// Translated By DeepSeek R1 From Chinese Version


/**
 * Problem:
 * Define a function f(x):
 * - f(x) = 2 * x * f(x-6)  (x > 10)
 * - f(x) = x * (x - 1)      (x ¡Ü 10)
 * Given an integer n, compute f(n) modulo 998244353.
 *
 * ------Input Format------
 * A single integer n.
 *
 * ------Output Format------
 * The result of f(n) modulo 998244353.
 */

int fx(int x) {
    if (x > 10) return (2LL * x * fx(x - 6)) % Mod;
    else return (x * (x - 1LL)) % Mod;
}

int main() {
    int n;
    cin >> n;
    cout << fx(n);
    return 0;
}
