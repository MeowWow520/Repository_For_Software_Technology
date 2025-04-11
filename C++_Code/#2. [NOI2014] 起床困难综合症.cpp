#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;

/** #2. [NOI2014] 起床困难综合症
 *  https://uoj.ac/problem/2
 * 
 *  ------问题描述------
 *  21 世纪, 许多人得了一种奇怪的病：起床困难综合症
 *  其临床表现为：起床难, 起床后精神不佳。作为一名青春阳光好少年, atm 一直坚持与起床困难综合症作斗争
 *  通过研究相关文献, 他找到了该病的发病原因: 
 *  在深邃的太平洋海底中, 出现了一条名为 drd 的巨龙, 它掌握着睡眠之精髓, 能随意延长大家的睡眠时间。
 *  正是由于 drd 的活动, 起床困难综合症愈演愈烈, 以惊人的速度在世界上传播。为了彻底消灭这种病, atm 决定前往海底, 消灭这条恶龙
 *  历经干辛万苦, atm 终于来到了 drd 所在的地方, 准备与其展开艰苦卓绝的战斗
 *  drd 有着十分特殊的技能, 他的防御战线能够使用一定的运算来改变他受到的伤害
 *  具体说来, drd 的防御战线由 n 扇防御门组成。每扇防御门包括一个运算 op 和一个参数 t
 *  其中运算一定是 OR, XOR, AND 中的一种, 参数则一定为非负整数
 *  如果还未通过防御门时攻击力为 α, 则其通过这扇防御门后攻击力将变为 α op t
 *  最终 drd 受到的伤害为对方初始攻击力 α 依次经过所有 n 扇防御门后转变得到的攻击力
 *  由于 atm 水平有限, 他的初始攻击力只能为 0 到 m 之间的一个整数
 *  即他的初始攻击力只能在 0, 1, ..., m 中任选, 但在通过防御门之后的攻击力不受 m 的限制
 *  为了节省体力, 他希望通过选择合适的初始攻击力使得他的攻击能让 drd 受到最大的伤害
 *  请你帮他计算一下, 他的一次攻击最多能使 drd 受到多少伤害
 * 
 *  ------输入格式------
 *  第一行包含两个整数, 依次为 n, m, 表示 drd 有 n 扇防御门, atm 的初始攻击力为 0 到 m 之间的整数。
 *  接下来 n行, 依次表示每一扇防御门。每行包括一个字符串 op 和一个非负整数 t , 两者由一个空格隔开, 且 op 在前, t在后
 *  op 表示该防御门所对应的操作, t表示对应的参数
 * 
 *  ------输出格式------
 *  一行一个整数, 表示 atm 的一次攻击最多使 drd 受到多少伤害
 */

// 变量声明
int n, m;
vector <string> arrs;
vector <int> arri;

// 计算 arri 和 m 的位运算
int Work(string arrs, int arri, int m) {
	int ret = 0;
	if (arrs == "AND") ret = arri & m;
	else if (arrs == "OR") ret = arri | m;
	else ret = arri ^ m;
	return ret;
}

int main() {
	// 输入 input
	cin >> n >> m;
	int tempn = n;
	while (n--) {
		string tempstr = " ";
		int tempint = 0;
		cin >> tempstr >> tempint;
		arrs.push_back(tempstr);
		arri.push_back(tempint);
	}
	int arrend[N] = { 0 };
	for (int i = 1; i <= m; i++) {
		int midValve = Work(arrs[0], arri[0], i);
		for (int j = 1; j < tempn; j++) {
			midValve = Work(arrs[j], arri[j], midValve);
		}
		arrend[i] = midValve;
	}

	int result = 0;
	for (int i = 1; i <= m; i++) {
		if (result <= arrend[i]) result = arrend[i];
	}
	cout << result;
	return 0;
}


/** 
 *  Test #1:
 *  score: 0
 *  Wrong Answertime: 1ms
 *  memory: 3660kb
 *
 *  Test #2:
 *  score: 10
 *  Acceptedtime: 5ms
 *  memory: 3712kb
 * 
 *  Test #3:
 *  score: 10
 *  Acceptedtime: 24ms
 *  memory: 3900kb
 *
 *  Test #4:
 *  score: 0
 *  Time Limit Exceeded
 *
 *  Test #5:
 *  score: 0
 *  Time Limit Exceeded
 * 
 *  Test #6:
 *  score: 0
 *  Time Limit Exceeded
 * 
 *  Test #7:
 *  score: 0
 *  Time Limit Exceeded
 * 
 *  Test #8:
 *  score: 0
 *  Time Limit Exceeded
 * 
 *  Test #9:
 *  score: 0
 *  Time Limit Exceeded
 * 
 *  Test #10:
 *  score: 0
 *  Time Limit Exceeded
 */
