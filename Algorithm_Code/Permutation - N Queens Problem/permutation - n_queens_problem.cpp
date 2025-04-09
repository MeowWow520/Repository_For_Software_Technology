#include <iostream>
#include <algorithm>    
#include <cmath>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;

// Translated By DeepSeek V3 From Chinese Version

/**
 * N-Queens Problem
 * ------Problem Description------
 * Place N queens on an N¡ÁN chessboard such that no two queens attack each other.
 * This means no two queens can be in the same row, same column, or on the same diagonal (45-degree lines relative to the board borders).
 * Your task is to determine the number of valid placements for a given N.
 * 
 * ------Input Description------
 * A single integer N (N <= 10) representing the size of the board and number of queens.
 * 
 * ------Output Description------
 * The number of valid queen placements for the given N.
 */

/* ------Variable Declarations------
 * n: Input value from the problem.
 * ret: Unused variable in current implementation.
 * k: Copy of n to preserve the original input value.
 * pos: Current position in the DFS traversal.
 * vis[]: Array to track used columns (1-based indexing).
 * ans[]: ans[i] stores the column position of the queen in the i-th row.
 * cot: Counter for valid solutions.
 */
int n = 0, ret = 0, k = 0;
int pos = 1, vis[11] = { 0 }, ans[11] = { 0 };
int cot = 0;

/**
 * Check diagonal conflicts for the queen placed at column c.
 * Returns 1 if a conflict is found, 0 otherwise.
 */
int chk(int c) {
    for (int i = 1; i < c; i++) {
        if (abs(c - i) == abs(ans[i] - ans[c])) return 1;
    }
    return 0;
}

/**
 * Depth-First Search (DFS) for generating permutations and validating queen placements.
 * pos: Current row being processed.
 * k: Size of the board (copy of n).
 * 
 * For a detailed DFS explanation, refer to:
 * https://github.com/MeowWow520/Repostitory_For_Software_Technology/blob/main/Algorithm_Code/dfsÉî¶ÈÓÅÏÈËã·¨-ÅÅÁÐ.cpp 
 */
void dfs(int pos, int k) {
    if (pos > k) {
        cot++;
        // Validate diagonal constraints for the generated permutation
        for (int l = 1; l <= k; l++) {
            if (chk(l) == 1) { 
                cot--; 
                break;
            }
        }
        return;
    }
    else {
        for (int i = 1; i <= k; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                ans[pos] = i;
                dfs(pos + 1, k);
                vis[i] = 0;  // Backtrack
                ans[pos] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    k = n;
    dfs(pos, k);
    cout << cot << endl;
}

/** ------Issues Encountered During Development------
 * 1. Missing initialization of loop variable i in for-loops.
 * 2. Function order issues (e.g., function_a calls function_b before its declaration).
 * 3. Incorrect output printing (e.g., used wrong variable for result).
 */
