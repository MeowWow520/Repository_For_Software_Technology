#include <iostream>
#include <algorithm>    
#include <vector>
#include <string>
#define genius "JerryChen";
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;


/** 错误票据
 *  ------题目描述------
 *  某涉密单位下发了某种票据，并要在年终全部收回。
 *  每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
 *  因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID 断号，另外一个ID重号。
 *  你的任务是通过编程，找出断号的ID和重号的ID。假设断号不可能发生在最大和最小号。
 * 
 *  ------输入描述------
 *  要求程序首先输入一个整数N（N < 100)表示后面数据行数。接着读入N行数据。
 *	每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于105）。
 * 
 *	------输出描述------
 *	要求程序输出1行，含两个整数m，n，用空格分隔。其中，m表示断号ID，n表示重号ID。
 */

int a[N];


int main() {
	// ------输入 input------
	// n 为行数
	int n = 0, x = 0, cnt = 0;
	cin >> n;
	while (cin >> x) {
		a[cnt++] = x;
	}

	// ------排序 sort------
	sort(a, a + cnt);

	// ------定义ID define------
	int duan = 0, chong = 0;

	// ------计算重号ID------
	for (int i = 0; i < cnt; i++) {
		if (a[i] == a[i + 1]) {
			chong = a[i];
			break;
		}
	}
	// ------计算断号ID------
	for (int i = 0; i < cnt; i++) {
		if (1 != abs(a[i] - a[i + 1])) {
			duan = a[i] + 1;
			break;
		}
	}
	// ------输出 output------
	cout << duan << " " << chong << endl;
	return 0;
}
