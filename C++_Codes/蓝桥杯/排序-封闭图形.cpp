#include <iostream>
#include <algorithm>    
#include <vector>
#define genius "JerryChen";
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;

/**
 * 在蓝桥王国，数字的大小不仅仅取决于它们的数值大小，还取决于它们所形成的“封闭图形”的个数。封闭图形是指数字中完全封闭的空间，例如数字1、2、3、5、7都没有形成封闭图形，而数字0、4、6、9分别形成了1个封闭图形，数字8则形成了 2个封闭图形。值得注意的是，封闭图形的个数是可以累加的。例如，对于数字68，由于6形成了1个封闭图形，而8形成了2个，所以68形成的封闭图形的个数总共为3。在比较两个数的大小时，如果它们的封闭图形个数不同，那么封闭图形个数较多的数更大。例如，数字41和数字18，它们对应的封闭图形的个数分别为1和2，因此数字41小于数字18。如果两个数的封闭图形个数相同，那么数值较大的数更大。例如，数字14和数字41，它们的封闭图形的个数都是1，但14<41，所以数字14小于数字41。如果两个数字的封闭图形个数和数值都相同，那么这两个数字被认为是相等的。小蓝对蓝桥王国的数字大小规则十分感兴趣。现在，他将给定你n个数Q1,Q2，···,Qn，请你按照蓝桥王国的数字大小规则，将这 n 数从小到大排序，并输出排序后结果。
 * 输入格式第一行包含一个整数n，表示给定的数字个数。
 * 第二行包含 n个整数α1,α2,·.·,Qn，表示待排序的数字。输出格式
 * 输出一行，包含n个整数，表示按照蓝桥王国的数字大小规则从小到大排序后的结果，每两个数字之间用一个空格分隔。
 */

// 定义结构体
struct FengBi {
	int a = 0; // 数值
	int b = 0; // 封闭图形
};

// 如果 b 相等, 比较 a
bool comp (FengBi m, FengBi n) {
	if (m.b == n.b) return m.a < n.a;
	else return m.b < n.b;
}

// main function
int main() {

	// 输入 input
	int n = 0;
	cin >> n;
	int ans = 0;
	int fengbib[10] = { 1,0,0,0,1,0,1,0,2,1 };
	vector <FengBi> arr(n); // 18 29 6
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a;
	}

	// 计算 封闭图形
	for (int i = 0; i < n; i++) {
		// 临时变量 temp 暂时储存 arr
		int temp = arr[i].a; // 80
		while(temp != 0) {
			int temp_num = 0;
			temp_num = temp % 10;
			arr[i].b += fengbib[temp_num];
			temp /= 10;
		}
	}

	sort(arr.begin(), arr.end(), comp);
	// 输出 output
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << arr[i].a;
		}
		else {
			cout << arr[i].a << " ";
		}
			
		 
	}
	return 0;
}
