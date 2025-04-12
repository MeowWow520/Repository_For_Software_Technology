#include <iostream>
#include <vector>
#define Genius "Jerry Chen"
const int N = 1e6 + 10;
using namespace std;


/** �����ǵ�С��
 *  ------��������------
 *  С����һ���ǳ������ǵ�С��, ���������С����Ҫ��ǳ��ϸ�, Ҫ��С��ÿ��������Ƿ��ܺͲ��ܳ��� h
 *  ����С����ǰ�к��ǹ�, �Լ�һ������Ϊ������ ��
 *  ���� ��[i] ��ʾ�� i ���ǹ��������Ƿ�. С������ѡ��ȥ��һ���ǹ����߲�ȥ���ǹ�, Ȼ������µ��ǹ����Ե�
 *  ��С��ѡ��ȥ���ǹ�, ��ôɾȥ���ǹ�������һ��������������ǹ�
 *  �����С����Ҫ�����ܶ�������Ƿ�, ��������������С��
 *  ��������������������Ƿ�
 * 
 *  ------�����ʽ------
 *  ����һ������, ��һ�� 2 ������ n, h �����ǹ���Ŀ��С��������ȡ������Ƿ�
 *  �ڶ�������n���Ǹ����� ��1, ��2, ��3, ..., ��n ����ÿ���ǹ����Ƿֺ���
 * 
 *  ------�����ʽ------
 *  ���һ��һ�����ִ���С��������������Ƿ�
 */

int n, h;
// arr ���� n ������, preSum ����ǰ׺��
vector <int> arr;
int preSum[N];


int main() {
	// ���� input
	cin >> n >> h;
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
		preSum[i] = preSum[i - 1] + arr[i];
	}

	// �������Ƿ�
	int arrSum = 0;
	for (auto p = arr.begin(); p != arr.end(); p++) arrSum += *p;

	// maxValve Ϊ���յ�����Ƿ�
	int maxValve = 0;

	// ����ɾȥ������ʣ���Ƿ� 
	for (int i = 1; i <= n - 1; i++) { /* i Ϊ��ʼ�±� */
		// endDown Ϊ���䳤�ȵ����ֵ����ֹԽ��
		int endDown = n - i + 1;
		for (int j = 2; j <= endDown; j++) { /* j Ϊ���䳤�� */
			// tempValve ���������ڵ�ֵ
			int tempValve = preSum[i + j - 1] - preSum[i - 1];
			if (maxValve <= arrSum - tempValve && arrSum - tempValve <= h) maxValve = arrSum - tempValve;
		}
	}
	cout << maxValve;
	return 0;
}
