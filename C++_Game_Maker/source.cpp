#include <iostream>
#include <cmath> 
#include <graphics.h>
#include <Windows.h>
#include <winuser.h>
#define Genuis "Jerry Chen"
using namespace std;

// ���ݶ���
bool Is_Project_Work = true;
const int ttt_length = 3;
const int player_1 = 1; // Բ���
const int player_2 = 2; // �����
const int player_none = 0; // ��λ��
const int Windows_length_X = 600;
const int Windows_length_Y = 600;
const int circle_r = 75;
int tic_tac_toe[ttt_length][ttt_length] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }; // ������ת�õ�����
int player_current_site = 1;
TCHAR player_current_site_str = _T('o');

// �������� - ���ݴ���
// ʤ���ж�
int Chack_Win(int player_site) {
	// �жϺ���
	for (int i = 0; i <= 2; i++) {
		int count = 0;
		for (int j = 0; j <= 2; j++) {
			if (tic_tac_toe[i][j] == player_site) count++;
		}
		if (count == 3) return 1;
	}
	// �ж�����
	for (int i = 0; i <= 2; i++) {
		int count = 0;
		for (int j = 0; j <= 2; j++) {
			if (tic_tac_toe[j][i] == player_site) count++;
		}
		if (count == 3) return 1;
	}
	// �ж����Խ� 
	int count = 0;
	for (int i = 0; i <= 2; i++) {
		if (tic_tac_toe[i][i] == player_site) count++;
		if (count == 3) return 1;
	}
	// �жϸ��Խ� 
	count = 0;
	for (int i = 0; i <= 2; i++) {
		if (tic_tac_toe[i][2 - i] == player_site) count++;
		if (count == 3) return 1;
	}
}
// ƽ���ж�
int Chack_Draw() {
	int count_site_number = 0;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) count_site_number += tic_tac_toe[i][j];
	}
	if (count_site_number == 13) return 1;
}
// �������� - ����ͼ��
// ����ֱ��
void Draw_Line() {
	// ��������
	// �� 1 ��ֱ��
	int line_1_XY_Begin[2] = { Windows_length_X / 3, 0 };
	int line_1_XY_End[2] = { Windows_length_X / 3, Windows_length_Y };
	// �� 2 ��ֱ��
	int line_2_XY_Begin[2] = { (Windows_length_X / 3) * 2, 0 };
	int line_2_XY_End[2] = { (Windows_length_X / 3) * 2, Windows_length_Y };
	// �� 3 ��ֱ��
	int line_3_XY_Begin[2] = { 0, Windows_length_Y / 3 };
	int line_3_XY_End[2] = { Windows_length_X,  Windows_length_Y / 3 };
	// �� 4 ��ֱ��
	int line_4_XY_Begin[2] = { 0, (Windows_length_Y / 3) * 2 };
	int line_4_XY_End[2] = { Windows_length_X, (Windows_length_Y / 3) * 2 };

	// ����
	line(line_1_XY_Begin[0], line_1_XY_Begin[1], line_1_XY_End[0], line_1_XY_End[1]);
	line(line_2_XY_Begin[0], line_2_XY_Begin[1], line_2_XY_End[0], line_2_XY_End[1]);
	line(line_3_XY_Begin[0], line_3_XY_Begin[1], line_3_XY_End[0], line_3_XY_End[1]);
	line(line_4_XY_Begin[0], line_4_XY_Begin[1], line_4_XY_End[0], line_4_XY_End[1]);

};
// ����Բ
void Draw_Circle() {
	const int site = 1;
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 2; y++) {
			if (tic_tac_toe[x][y] == site) {
				int cir_x = (Windows_length_X / 6) * (2 * (x + 1) - 1);
				int cir_y = (Windows_length_Y / 6) * (2 * (y + 1) - 1);
				circle(cir_x, cir_y, circle_r);
			}
		}
	}
}
// ���Ʋ�
void Draw_X() {
	const int site = 2;
	int space = 25;
	int line_length_xy = 150;
	for (int x = 0; x <= 2; x++) {
		for (int y = 0; y <= 2; y++) {
			if (tic_tac_toe[x][y] == site) {
				// ��������
				// �� 1 ��ֱ��
				int line_x_1 = 200 * (x + 1) - line_length_xy - space;
				int line_y_1 = 200 * (y + 1) - line_length_xy - space;
				int line_1_XY_Begin[2] = { line_x_1, line_y_1 };
				int line_1_XY_End[2] = { line_x_1 + line_length_xy, line_y_1 + line_length_xy };
				// �� 2 ��ֱ��
				int line_x_2 = 200 * (x + 1) - space;
				int line_y_2 = 200 * (y + 1) - line_length_xy - space;
				int line_2_XY_Begin[2] = { line_x_2, line_y_2 };
				int line_2_XY_End[2] = { line_x_2 - line_length_xy, line_y_2 + line_length_xy };

				line(line_1_XY_Begin[0], line_1_XY_Begin[1], line_1_XY_End[0], line_1_XY_End[1]);
				line(line_2_XY_Begin[0], line_2_XY_Begin[1], line_2_XY_End[0], line_2_XY_End[1]);
			}
		}
	}
}
// ������ʾ��Ϣ
void Draw_Tips() {
	static TCHAR str[64];
	_stprintf_s(str, _T("��ǰ�������ͣ� %c"), player_current_site_str);
	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}


int main() {
	// ��ʼ������
	initgraph(Windows_length_X, Windows_length_Y, NULL);
	// ��ѭ��
	BeginBatchDraw();
	while (Is_Project_Work) {
		ExMessage Message_Pick;
		// ��ȡ����
		int x = 10000, y = 10000;
		while (peekmessage(&Message_Pick)) {
			if (Message_Pick.message == WM_LBUTTONDOWN) {
				x = Message_Pick.x;
				y = Message_Pick.y;
		
			// ��������
				int index_x = x / 200;
				int index_y = y / 200;
				if (tic_tac_toe[index_x][index_y] == 0) {
					tic_tac_toe[index_x][index_y] = player_current_site;
					// ���Ծ����
					if (Chack_Draw() == 1) MessageBox(GetHWnd(), _T("����һ�ʤ"), _T("��Ϸ����"), MB_OK);
					if (Chack_Win(player_current_site) == 1) MessageBox(GetHWnd(), _T("��һ�ʤ"), _T("��Ϸ����"), MB_OK);
					// ������������
					if (player_current_site == 2) {
						player_current_site = 1;
						player_current_site_str = _T('o');
					}
					else { 
						player_current_site = 2; 
						player_current_site_str = _T('x');
					}
				}
			}
		}
		// ���ƻ���
		cleardevice();
		Draw_Tips();
		Draw_Line();
		Draw_Circle();
		Draw_X();
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}