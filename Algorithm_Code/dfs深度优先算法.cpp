#include <iostream>
#include <algorithm>    
#include <vector>
#include <string>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;


/** ------dfs深度优先搜索------
 *  利用递归解决排列问题
 */

/** ------变量声明------
 *  n 为 排列的数字
 *  如果 n = 3
 *  那么结果为 123 132 213 231 312 321.
 *  pos 为层数, vis[] 为已经选过的数字
 *  vis[] 中 0 代表这个 "下标" 没有被选择过, 而不是记录那个数选过.
 *  pos 为层数
 */

/** ------问题描述------
 *  把 1～n 的 n 个正整数排成一行后随机打乱顺序, 按字典序输出所有不同的方案。
 * 
 *  ------输入格式------
 *  输入一行，包含一个正整数。（1 <= 8)
 * 
 *  ------输出格式------
 *  输出 n! 行, 每一行为一种方案。字典序较小的先输出。 
 */
int n = 0, vis[10] = { 0 }, ans[10] = { 0 };
void dfs(int pos, int n) {
    if (pos > n) {
        // 说明我们的层数大于数字 n, 没有更多数字可以选了.
        for (int j = 1; j <= n; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (vis[k] == 0) /* 说明这个数字没有选择 */ {
            ans[pos] = k;
            vis[k] = 1; // 标记 k 这个位置被选择了
            dfs(pos + 1, n); // 计算下一层
            ans[pos] = 0; // 回溯
            vis[k] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1, n);
    return 0;
}
