#include <iostream>
#include <graphics.h>
#define Genuis "Jerry Chen"
using namespace std;

bool IsGoing = true;
int x = 1e5, y = 1e5;
int CurrentPlayerType = 1;
int Site[3][3] = { {0,0,0},{0,0,0},{0,0,0} };



// 绘制画面
void DrawLine() {
	// 第 1, 2, 3, 4 条直线
	int line_1_XY_Begin[2] = { 600 / 3, 0 };
	int line_1_XY_End[2] = { 600 / 3, 600 };
	int line_2_XY_Begin[2] = { (600 / 3) * 2, 0 };
	int line_2_XY_End[2] = { (600 / 3) * 2, 600 };
	int line_3_XY_Begin[2] = { 0, 600 / 3 };
	int line_3_XY_End[2] = { 600,  600 / 3 };
	int line_4_XY_Begin[2] = { 0, (600 / 3) * 2 };
	int line_4_XY_End[2] = { 600, (600 / 3) * 2 };
	// 绘制
	line(line_1_XY_Begin[0], line_1_XY_Begin[1], line_1_XY_End[0], line_1_XY_End[1]);
	line(line_2_XY_Begin[0], line_2_XY_Begin[1], line_2_XY_End[0], line_2_XY_End[1]);
	line(line_3_XY_Begin[0], line_3_XY_Begin[1], line_3_XY_End[0], line_3_XY_End[1]);
	line(line_4_XY_Begin[0], line_4_XY_Begin[1], line_4_XY_End[0], line_4_XY_End[1]);

};
void DrawCircle() {
	const int site = 1;
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 2; y++) {
			if (Site[x][y] == site) {
				int cir_x = (600 / 6) * (2 * (x + 1) - 1);
				int cir_y = (600 / 6) * (2 * (y + 1) - 1);
				circle(cir_x, cir_y, 75);
			}
		}
	}
}
void DrawX() {
	const int site = -1;
	int space = 25;
	int line_length_xy = 150;
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 2; y++) {
			if (Site[x][y] == site) {
				// 定义坐标
				// 第 1, 2 条直线
				int line_x_1 = 200 * (x + 1) - line_length_xy - space;
				int line_y_1 = 200 * (y + 1) - line_length_xy - space;
				int line_1_XY_Begin[2] = { line_x_1, line_y_1 };
				int line_1_XY_End[2] = { line_x_1 + line_length_xy, line_y_1 + line_length_xy };
				int line_x_2 = 200 * (x + 1) - space;
				int line_y_2 = 200 * (y + 1) - line_length_xy - space;
				int line_2_XY_Begin[2] = { line_x_2, line_y_2 };
				int line_2_XY_End[2] = { line_x_2 - line_length_xy, line_y_2 + line_length_xy };
				// 绘制
				line(line_1_XY_Begin[0], line_1_XY_Begin[1], line_1_XY_End[0], line_1_XY_End[1]);
				line(line_2_XY_Begin[0], line_2_XY_Begin[1], line_2_XY_End[0], line_2_XY_End[1]);
			}
		}
	}
}

// 判断落子
void IsThereDown() {
	if (Site[x / 200][y / 200] == 0) {
		Site[x / 200][y / 200] = CurrentPlayerType;
		CurrentPlayerType *= -1;
	}
}
void ChackWin(int CurrentPlayerType) {
	for (int i = 1; i <= 2; i++) 
}
// 平局判断
bool ChackDraw() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (Site[i][j] == 0) return false;
		}
	}
	return true;
}

int main() {
	// 初始化
	initgraph(600, 600, NULL);

	// Main
	BeginBatchDraw();
	while (IsGoing) {
		ExMessage Message_Pick;
		// 读取操作
		while (peekmessage(&Message_Pick)) {
			if (Message_Pick.message == WM_LBUTTONDOWN) {
				x = Message_Pick.x;
				y = Message_Pick.y;
				// Line 001
				IsThereDown();
			}
		}
		/** 处理数据
		 *	- 这个地方能落子吗？ !! in Line 001
		 *    - 能： 落子并更改玩家的棋子类型
		 *    - 不能： 不做变化
		 *  - 玩家赢了吗？
		 *  - 有没有平局？
		 */
		if (ChackDraw()) {
			// 平局
		}
		// 绘制画面
		DrawLine();
		DrawCircle();
		DrawX();
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}
