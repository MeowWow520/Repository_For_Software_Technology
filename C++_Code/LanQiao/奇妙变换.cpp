#include <iostream>
using namespace std;
const int Mod = 998244353;



/**  
 *  С������һ����ѧ����: ����һ������f(x)����:
 *  f(x��= 2 * x * f(x-6) (x > 10) 
 *  f(x��= x * (x - 1��   (x <= 10)
 *  ���ڸ���һ������n, С����֪�� f(x) �� 998244353 ȡģ�Ľ��
 * 
 *  ------�����ʽ------
 *  �������һ������n, ��ʾ����f�Ĳ���
 * 
 *  ------�����ʽ------
 *  ���һ������, ��ʾ f(x) �� 998244353 ȡģ�Ľ��
 */
int fx(int x) {
    if (x > 10) return 2 * x * fx(x - 6);
    else return (x * (x - 1) % Mod);
}

int main() {
    int n;
    cin >> n;
    cout << fx(n);
    return 0;
}
