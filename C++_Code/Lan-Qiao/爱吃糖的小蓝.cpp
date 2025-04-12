#include <iostream>
#include <vector>
#define Genius "Jerry Chen"
const int N = 1e6 + 10;
using namespace std;


/** 爱吃糖的小蓝
 *  ------问题描述------
 *  小蓝是一个非常爱吃糖的小孩, 但是妈妈对小蓝的要求非常严格, 要求小蓝每天摄入的糖分总和不能超过 h
 *  现在小蓝面前有盒糖果, 以及一个长度为的数组 α
 *  其中 α[i] 表示第 i 盒糖果所含的糖分. 小蓝可以选择去除一次糖果或者不去除糖果, 然后把余下的糖果都吃掉
 *  若小蓝选择去除糖果, 那么删去的糖果必须是一个或连续多个的糖果
 *  馋嘴的小蓝想要尽可能多的摄入糖分, 所以请你来帮助小蓝
 *  算算她最多可以摄入多少糖分
 * 
 *  ------输入格式------
 *  输入一共两行, 第一行 2 个整数 n, h 代表糖果数目和小蓝可以摄取的最大糖分
 *  第二行输入n个非负整数 α1, α2, α3, ..., αn 代表每盒糖果的糖分含量
 * 
 *  ------输出格式------
 *  输出一行一个数字代表小蓝最多可以摄入的糖分
 */

int n, h;
// arr 储存 n 个数组, preSum 储存前缀和
vector <int> arr;
int preSum[N];


int main() {
	// 输入 input
	cin >> n >> h;
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
		preSum[i] = preSum[i - 1] + arr[i];
	}

	// 计算总糖分
	int arrSum = 0;
	for (auto p = arr.begin(); p != arr.end(); p++) arrSum += *p;

	// maxValve 为最终的最多糖分
	int maxValve = 0;

	// 计算删去区间后的剩余糖分 
	for (int i = 1; i <= n - 1; i++) { /* i 为起始下标 */
		// endDown 为区间长度的最大值，防止越界
		int endDown = n - i + 1;
		for (int j = 2; j <= endDown; j++) { /* j 为区间长度 */
			// tempValve 计算区间内的值
			int tempValve = preSum[i + j - 1] - preSum[i - 1];
			if (maxValve <= arrSum - tempValve && arrSum - tempValve <= h) maxValve = arrSum - tempValve;
		}
	}
	cout << maxValve;
	return 0;
}
