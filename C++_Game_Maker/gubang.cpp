#include <iostream>
#include <cmath> 
#include <graphics.h>
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
int tic_tac_toe[ttt_length][ttt_length] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

// �������� - ���ݴ���
void Chack_Win(int player_site) {};

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

}
int main() {
	// ��ʼ������
	initgraph(Windows_length_X, Windows_length_Y, NULL);
	// ��ѭ��
	while (Is_Project_Work) {
		ExMessage Message_Pick;
		// ��ȡ����
		// ��������
		// ���ƻ���
		Draw_Line();
		Draw_Circle();
		Draw_X()
	}
	return 0;
}
