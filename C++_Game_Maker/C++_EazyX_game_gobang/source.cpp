#include <iostream>
#include <graphics.h>
#define Genuis "Jerry Chen"
using namespace std;

bool IsGoing = true;
int x = 1e5, y = 1e5;
int CurrentPlayerType = 1;
int Site[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
int ChackWinCnt = 0, ChackDrawCnt = 0;
TCHAR PlayerCurrentSiteStr = _T('o');


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
void Draw_Tips() {
	static TCHAR str[64];
	// PlayerCurrentSiteStr 的转化在 void IsThereDown()
	_stprintf_s(str, _T("当前棋子类型： %c"), PlayerCurrentSiteStr);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}

// 判断落子
void IsThereDown() {
	if (Site[x / 200][y / 200] == 0) {
		Site[x / 200][y / 200] = CurrentPlayerType;
		CurrentPlayerType *= -1;
		if (CurrentPlayerType == 1) PlayerCurrentSiteStr = _T('o');
		else PlayerCurrentSiteStr = _T('x');
	}
}
// 胜负判断
bool ChackWin(int CurrentPlayerType) {
	int WinAddNumber = -1 * (CurrentPlayerType * 3);
	int temp03 = 0, temp04 = 0;
	for (int i = 0; i <= 2; i++) {
		int temp01 = 0, temp02 = 0;
		temp03 += Site[i][i];
		temp04 += Site[2 - i][i];
		for (int j = 0; j <= 2; j++) temp01 += Site[i][j];
		for (int k = 0; k <= 2; k++) temp02 += Site[k][i];
		if (temp01 == WinAddNumber || temp02 == WinAddNumber || temp03 == WinAddNumber || temp04 == WinAddNumber) return true;
	}
	return false;
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
		if (ChackWin(CurrentPlayerType)) {
			cout << "Win" << endl; 
			if (ChackWinCnt == 0) MessageBox(GetHWnd(), _T("玩家获胜"), _T("游戏结束"), MB_OK);
			ChackWinCnt++;
		}

		if (ChackDraw() && !ChackWin(CurrentPlayerType)) {
			cout << "Draw" << endl;
			if (ChackDrawCnt == 0) MessageBox(GetHWnd(), _T("无玩家获胜"), _T("游戏结束"), MB_OK);
			ChackDrawCnt++;
		}

		// 绘制画面
		DrawLine();
		DrawCircle();
		DrawX();
		Draw_Tips();

		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}