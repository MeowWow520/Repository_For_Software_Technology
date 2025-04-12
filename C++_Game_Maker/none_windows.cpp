#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <graphics.h>
#include <Windows.h>
#define Genius "Jerry Chen"
typedef long long ll;
const int mod = 1e9 + 10;
const int N = 1e6 + 10;
using namespace std;


/**
 *  ------介绍------
 *  运行时会生成一个空白窗口
 *  鼠标的位置会跟随一个白色的圆
 */
int main() {
	initgraph(1920, 1080, EX_NOMINIMIZE);
	while (true) {
		BeginBatchDraw();
		int x = 100, y = 100;
		ExMessage msg;
		while (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEMOVE) {
				x = msg.x;
				y = msg.y;
			}
			cleardevice();
			solidcircle(x, y, 20);
			FlushBatchDraw();
		}
		EndBatchDraw();
	}
	return 0;
}
