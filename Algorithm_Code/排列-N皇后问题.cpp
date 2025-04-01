#include <iostream>
#include <algorithm>    
#include <cmath>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;




/** N�ʺ�����
 *  ------��Ŀ����------
 *  ��N��N�ķ������̷�����N���ʺ�, ʹ�����ǲ��໥����
 *  ������2���ʺ�������ͬһ��,ͬһ��, Ҳ�������������̱߿��45�ǵ�б����
 *  ���������, ���ڸ�����N, ����ж����ֺϷ��ķ��÷���
 * 
 *  ------��������------
 *  ��������һ�������� N <=10, ��ʾ���̺ͻʺ������
 * 
 *  ------�������------
 *  Ϊһ��������, ��ʾ��Ӧ�����еĻʺ�Ĳ�ͬ��������
 */


/*  ------��������------
 *  n Ϊ��Ŀ�е� n ֵ, ret Ϊ��
 *  ans[i] ��ʾ�� i �е� ans[i] ����û�лʺ�
 *  ���� ans[3] = 2 ���ǵ� 3 �е� 2 ���лʺ�
 *  ���������в����ܳ��� ans[i] = ans[k] �����
 *  k Ϊ n �ĸ��Ʊ���, ��ֹ�� n ���иı� 
 */
int n = 0, ret = 0, k = 0;
int pos = 1, vis[11] = { 0 }, ans[11] = { 0 };
int cot = 0;

/** ------˼·------
 *  ���ǰ������ά��ƽ����������һ����������
 *  ����� arr[] �������������Ա�֤�ʺ󲻻��๥��
 *  ͬʱ������Ҫ��һ����������ֹ�Խ����Ϸ��ûʺ�
 *  ���Ƿ��� arr[i] ���±� i �����е����ֿ��Թ���һ����ά���� (i, arr[i])
 *  ���ǿ���������� arr[i] == i ��ô����ʺ���ڶԽ�����
 *  2 1 4 3
 */

int chk(int c) {
	for (int i = 1; i < c; i++) {
		if (abs(c - i) == abs(ans[i] - ans[c])) return 1;
	}
	return 0;
}

/** ------dfs------
 *  ��������㷨��������
 *  ���https://github.com/MeowWow520/Repostitory_For_Software_Technology/blob/main/Algorithm_Code/dfs��������㷨.cpp 
 */
void dfs(int pos, int k) {
	if (pos > k) {
		cot++;
		for (int l = 1; l <= k; l++) {
			if (chk(l) == 1) { 
				cot--; 
				break;
			}
		}
		return;
	}
	else {
		for (int i = 1; i <= k; i++) {
			if (vis[i] == 0) {
				vis[i] = 1;
				ans[pos] = i;
				dfs(pos + 1, k);
				vis[i] = 0;
				ans[pos] = 0;
			}
		}
	}
}



int main() {
	cin >> n;
	k = n;
	dfs(pos, k);
	cout << cot << endl;
}

/** ------��дʱ����������------
 *  1. for ѭ���г�ʼ��ʱû�ж� i ���и�ֵ
 *  2. û��ע�⺯����ǰ��, ���ȵ��õĺ�������֮����
 *    - int function_a(){fuction_b;}
 *    - int function_b(){}
 *  3. ��ӡ���˽��
 *
 */

