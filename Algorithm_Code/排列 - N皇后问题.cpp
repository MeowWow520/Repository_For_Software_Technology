#include <iostream>
#include <algorithm>    
#include <cmath>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;




/** N皇后问题
 *  ------题目描述------
 *  在N×N的方格棋盘放置了N个皇后, 使得它们不相互攻击
 *  即任意2个皇后不允许处在同一排,同一列, 也不允许处在与棋盘边框成45角的斜线上
 *  你的任务是, 对于给定的N, 求出有多少种合法的放置方法
 * 
 *  ------输入描述------
 *  输入中有一个正整数 N <=10, 表示棋盘和皇后的数量
 * 
 *  ------输出描述------
 *  为一个正整数, 表示对应输入行的皇后的不同放置数量
 */


/*  ------变量声明------
 *  n 为题目中的 n 值, ret 为答案
 *  ans[i] 表示第 i 行的 ans[i] 列有没有皇后
 *  例如 ans[3] = 2 就是第 3 行第 2 列有皇后
 *  排列问题中不可能出现 ans[i] = ans[k] 的情况
 *  k 为 n 的复制变量, 防止对 n 进行改变 
 */
int n = 0, ret = 0, k = 0;
int pos = 1, vis[11] = { 0 }, ans[11] = { 0 };
int cot = 0;

/** ------思路------
 *  我们把这个二维的平面问题抽象成一个排列问题
 *  上面的 arr[] 变量的声明可以保证皇后不互相攻击
 *  同时我们需要另一个条件来阻止对角线上放置皇后
 *  我们发现 arr[i] 的下标 i 和其中的数字可以构成一个二维坐标 (i, arr[i])
 *  我们可以利用如果 arr[i] == i 那么这个皇后就在对角线上
 *  2 1 4 3
 */

int chk(int c) {
	for (int i = 1; i < c; i++) {
		if (abs(c - i) == abs(ans[i] - ans[c])) return 1;
	}
	return 0;
}

/** ------dfs------
 *  深度优先算法变量声明
 *  详见https://github.com/MeowWow520/Repostitory_For_Software_Technology/blob/main/Algorithm_Code/dfs深度优先算法-排列.cpp 
 */
void dfs(int pos, int k) {
	if (pos > k) {
		cot++;
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
				vis[i] = 0;
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

/** ------编写时遇到的问题------
 *  1. for 循环中初始化时没有对 i 进行赋值
 *  2. 没有注意函数的前后, 把先调用的函数至于之后了
 *    - int function_a(){fuction_b;}
 *    - int function_b(){}
 *  3. 打印错了结果
 *
 */

