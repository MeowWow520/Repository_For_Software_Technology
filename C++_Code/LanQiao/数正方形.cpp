#include <iostream>
#include <algorithm>    
#include <vector>
#include <string>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;


/** 数正方形
 * 
 *  ------题目描述------
 *  在一个 N * N 的点阵上，取其中 4 个点恰好组成一个正方形的 4 个顶点，一共有多少种不同的取法？
 *  由于结果可能非常大，你只需要输出模 1e9+7 的余数。
 * 
 *  ------输入描述------
 *  输入包含一个整数 N (2≤N≤1e6) 
 * 
 *  ------输出描述------
 *  输出一个整数代表答案。
 */


/** 
 *  ------思路------
 *  我们容易知道 2*2 时的答案, 可以探究 2*2 与 3*3 结果的关系
 *  也就是寻找 n*n 和 (n+1)*(n+1) 结果的关系
 *  
 *  ------举例------
 *  对于 2*2 的点阵, 我们把他抽象成一个 1*1 的方块
 *  即把 (n+1)*(n+1) 的点阵抽象成一个 n*n 的方块
 *  2*2 的点阵的答案是 1,
 *  3*3 的点阵的答案是 5,
 *  4*4 的点阵的答案是 由两部分组成: 
 *  第一部分  9 个 1*1 的方块, 4 个 2*2 的方块, 1 个 3*3 的方块。
 *  第二部分  对于 1*1 的方块会重复计算舍去, 偶数*偶数 的方块只有 1 种"摆法", 而奇数则有两个
 *  推广到: 
 *  n*n 的点阵的答案是 (n-1)*(n-1) 个 1*1 的方块, (n-2)*(n-2) 个 2*2 的方块, (n-3)*(n-3) 个 3*3 的方块     
 */

// ------构造∑(n-i)^2的函数------
ll pf(ll n) {
	ll ret = 0;
	for (int i = 1; i < n; i++) {
		ret += i * i;
	}
	return ret % mod;
}

// ------构造函数------
// 这一部分又bug
ll fn(ll n) {
	ll ans = 0;
	if (2 == n) return 1;
	else if (3 == n) return 6;
	else {
		ans += pf(n);
		for (ll i = 2; i < n; i++) {
			if (1 == i % 2) ans += (n - i )*(n - i) * 2;
			else ans += (n - i) * (n - i);
		}
		return ans % mod;
	}
}
int main() {
	// ------输入 input------
	int n = 0;
	cin >> n;
	ll ans = fn(n);
	cout << ans;
	return 0;
}
