#include <bits/stdc++.h>
using namespace std;



/** ������ - ѭ��
 *  ------��������------
 *  С����Ϊ���һ��������ż������λ
 *  ����ǰ��һ�����λ֮�͵��ں���һ�����λ֮��
 *  ��������������������֡����� 2314 ��һ���������֣���Ϊ���� 4 ����λ, ���� 2 + 3 = 1 + 4��
 *  ����������������1��100000000֮�乲�ж��ٸ���ͬ����������
*/
bool IsLuck(int n) {
    if (((int)log10(n) + 1) % 2 == 1) return false;
    vector <int> arr;
    while (n > 0) {
        int temp = 0;
        temp = n % 10;
        n /= 10;
        arr.push_back(temp);
    }
    int len = arr.size();
    int a = 0, b = 0;
    for (int i = 0; i < len / 2; i++) {
        a += arr[i];
    }
    for (int i = len / 2; i < len; i++) {
        b += arr[i];
    }
    if (a == b) return true;
    else return false;
}
int main() {
    int ans = 0;
    for (int i = 11; i <= 100000000; i++) {
        if (IsLuck(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}
