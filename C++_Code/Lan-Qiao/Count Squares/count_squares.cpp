#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;

// Translated By DeepSeek R1 From Chinese Version


/**
 * Count Squares
 *
 * ------Problem Description------
 * Given an N¡ÁN grid of points, count the number of distinct ways to select 4 points forming a square.
 * Output the result modulo 1e9+7.
 *
 * ------Input------
 * An integer N (2 ¡Ü N ¡Ü 1e6).
 *
 * ------Output------
 * The number of squares modulo 1e9+7.
 */

 /**
  * ------Approach------
  * For an n¡Án grid:
  * - The total squares include contributions from all possible sub-squares.
  * - Summation and parity adjustments are needed for overlapping counts.
  */

  // Sum of squares function
ll pf(ll n) {
    ll ret = 0;
    for (int i = 1; i < n; i++) {
        ret = (ret + 1LL * i * i) % mod;
    }
    return ret;
}

ll fn(ll n) {
    ll ans = 0;
    if (n == 2) return 1;
    else if (n == 3) return 6;
    else {
        ans = pf(n);
        for (ll i = 2; i < n; i++) {
            ll term = (n - i) * (n - i) % mod;
            if (i % 2 == 1) term = (term * 2) % mod;
            ans = (ans + term) % mod;
        }
        return ans;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fn(n);
    return 0;
}
