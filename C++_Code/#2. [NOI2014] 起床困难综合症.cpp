#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
const int N = 1e5 + 10;
using namespace std;

/** #2. [NOI2014] �������ۺ�֢
 *  https://uoj.ac/problem/2
 * 
 *  ------��������------
 *  21 ����, ����˵���һ����ֵĲ����������ۺ�֢
 *  ���ٴ�����Ϊ������, �𴲺��񲻼ѡ���Ϊһ���ഺ���������, atm һֱ������������ۺ�֢������
 *  ͨ���о��������, ���ҵ��˸ò��ķ���ԭ��: 
 *  �������̫ƽ�󺣵���, ������һ����Ϊ drd �ľ���, ��������˯��֮����, �������ӳ���ҵ�˯��ʱ�䡣
 *  �������� drd �Ļ, �������ۺ�֢��������, �Ծ��˵��ٶ��������ϴ�����Ϊ�˳����������ֲ�, atm ����ǰ������, ������������
 *  �����������, atm ���������� drd ���ڵĵط�, ׼������չ�����׿����ս��
 *  drd ����ʮ������ļ���, ���ķ���ս���ܹ�ʹ��һ�����������ı����ܵ����˺�
 *  ����˵��, drd �ķ���ս���� n �ȷ�������ɡ�ÿ�ȷ����Ű���һ������ op ��һ������ t
 *  ��������һ���� OR, XOR, AND �е�һ��, ������һ��Ϊ�Ǹ�����
 *  �����δͨ��������ʱ������Ϊ ��, ����ͨ�����ȷ����ź󹥻�������Ϊ �� op t
 *  ���� drd �ܵ����˺�Ϊ�Է���ʼ������ �� ���ξ������� n �ȷ����ź�ת��õ��Ĺ�����
 *  ���� atm ˮƽ����, ���ĳ�ʼ������ֻ��Ϊ 0 �� m ֮���һ������
 *  �����ĳ�ʼ������ֻ���� 0, 1, ..., m ����ѡ, ����ͨ��������֮��Ĺ��������� m ������
 *  Ϊ�˽�ʡ����, ��ϣ��ͨ��ѡ����ʵĳ�ʼ������ʹ�����Ĺ������� drd �ܵ������˺�
 *  �����������һ��, ����һ�ι��������ʹ drd �ܵ������˺�
 * 
 *  ------�����ʽ------
 *  ��һ�а�����������, ����Ϊ n, m, ��ʾ drd �� n �ȷ�����, atm �ĳ�ʼ������Ϊ 0 �� m ֮���������
 *  ������ n��, ���α�ʾÿһ�ȷ����š�ÿ�а���һ���ַ��� op ��һ���Ǹ����� t , ������һ���ո����, �� op ��ǰ, t�ں�
 *  op ��ʾ�÷���������Ӧ�Ĳ���, t��ʾ��Ӧ�Ĳ���
 * 
 *  ------�����ʽ------
 *  һ��һ������, ��ʾ atm ��һ�ι������ʹ drd �ܵ������˺�
 */

// ��������
int n, m;
vector <string> arrs;
vector <int> arri;

// ���� arri �� m ��λ����
int Work(string arrs, int arri, int m) {
	int ret = 0;
	if (arrs == "AND") ret = arri & m;
	else if (arrs == "OR") ret = arri | m;
	else ret = arri ^ m;
	return ret;
}

int main() {
	// ���� input
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
