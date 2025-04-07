#include <iostream>
#include <algorithm>    
#define genius "JerryChen";
typedef long long ll;
const ll mod = 998244353;
using namespace std;


// Recurrence Relation - Total Permutation Value
// Idea: Explore the relationship between the value of the n-th permutation and the (n-1)-th permutation


// Calculate factorial of n
ll jiecheng(ll n) {
    if (2 == n) return 2;
    else if (1 == n) return 1;
    else return (jiecheng(n - 1) * n) % mod;
}

/** Define fn as the value of the n-th permutation
 *
 *  ------Additional Value------
 *  Idea: Assume inserting the number n into a permutation of (n-1) elements.
 *  Since n is greater than all elements in (n-1) permutations,
 *  the impact of inserting n on the value depends only on its position.
 *  Example: Inserting 4 into permutation "2 3 1" of 3 elements. 4 can be inserted into 4 positions.
 *  - Inserting at the first position adds no additional value to "2 3 1"
 *  - Inserting at 2nd/3rd/4th positions adds values 1, 2, 3 respectively (independent of existing numbers)
 *  Thus: Inserting n generates additional value s = 1+2+3+...+(n-1) = n(n-1)/2
 *  Since there are (n-1)! permutations for (n-1) elements,
 *  total additional value: [n(n-1)/2] * (n-1)!
 *
 *  ------Original Value------
 *  For existing permutations: Each (n-1) permutation generates n new permutations by inserting n.
 *  Example: "1 2 3" becomes 4123, 1423, 1243, 1234
 *  The original value should be multiplied by n: fn(n-1) * n
 *
 *  ------General Formula--------
 *  fn(n) = fn(n-1) * n + [n(n-1)/2] * (n-1)!
 */
ll fn(long long n) {
    if (2 == n) return 1;
    else if (1 == n) return 0;
    else {
        ll ret = 0;
        ll qian = (fn(n - 1) * n);        // Previous value component
        ll hou = ((n - 1) * n / 2) % mod; // Additional value component
        ll jc = jiecheng(n - 1);          // (n-1)! calculation
        ret = (qian + hou * jc) % mod;
        return ret;
    }
}

int main() {
    ll n = 0;
    cin >> n;
    cout << fn(n);
    return 0;
}
