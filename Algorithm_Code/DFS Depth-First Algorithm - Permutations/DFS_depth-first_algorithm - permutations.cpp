#include <iostream>
#include <algorithm>    
#include <vector>
#include <string>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;

// Translated By DeepSeek V3 From Chinese Version

/** ------Depth-First Search (DFS)------
 *  Using recursion to solve permutation problems
 */

 /** ------Variable Declaration------
  *  n is the number for permutation.
  *  If n = 3,
  *  the results would be 123, 132, 213, 231, 312, 321.
  *  pos is the current layer, vis[] marks the selected numbers.
  *  In vis[], 0 means the "index" has not been selected, not that the number itself has been chosen.
  *  pos is the current layer.
  */

  /** ------Problem Description------
   *  Arrange the n positive integers from 1 to n in a row, shuffle them randomly, and output all distinct permutations in lexicographical order.
   *
   *  ------Input Format------
   *  Input a line containing a positive integer. (1 <= n <= 8)
   *
   *  ------Output Format------
   *  Output n! lines, each representing one permutation. Lexicographically smaller permutations are output first.
   */
int n = 0, vis[10] = { 0 }, ans[10] = { 0 };
void dfs(int pos, int n) {
    if (pos > n) {
        // If the current layer exceeds n, no more numbers can be selected.
        for (int j = 1; j <= n; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (vis[k] == 0) /* This number has not been selected yet */ {
            ans[pos] = k;
            vis[k] = 1; // Mark k as selected
            dfs(pos + 1, n); // Proceed to the next layer
            ans[pos] = 0; // Backtrack
            vis[k] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1, n);
    return 0;
}
