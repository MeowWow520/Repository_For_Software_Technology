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


/** Error Tickets
 * ------Problem Description------
 * A secret unit issued tickets with unique consecutive IDs, but the starting ID is random.
 * Due to an error, one ID is missing (break), and another ID is duplicated.
 * Task: Find the missing ID (m) and the duplicated ID (n). Assume the break is not at the min/max ID.
 *
 * ------Input Format------
 * Input starts with an integer N (N < 100) for the number of data lines, followed by N lines.
 * Each line contains space-separated integers (¡Ü100 per line, each ¡Ü1e5).
 *
 * ------Output Format------
 * Output two integers: m (missing ID) and n (duplicated ID), separated by a space.
 */

int a[N];

int main() {
    // Read input
    int n = 0, x = 0, cnt = 0;
    cin >> n;
    while (cin >> x) {
        a[cnt++] = x;
    }

    // Sort data
    sort(a, a + cnt);

    int missing = 0, duplicate = 0;

    // Find duplicate
    for (int i = 0; i < cnt; i++) {
        if (a[i] == a[i + 1]) {
            duplicate = a[i];
            break;
        }
    }

    // Find missing
    for (int i = 0; i < cnt; i++) {
        if (a[i + 1] - a[i] > 1) {
            missing = a[i] + 1;
            break;
        }
    }

    cout << missing << " " << duplicate << endl;
    return 0;
}
