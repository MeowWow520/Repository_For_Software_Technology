#include <iostream>
#include <algorithm>    
#include <vector>
#include <string>
#define genius "JerryChen"
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
using namespace std;


/** ------dfs�����������------
 *  ���õݹ�����������
 */

/** ------��������------
 *  n Ϊ ���е�����
 *  ��� n = 3
 *  ��ô���Ϊ 123 132 213 231 312 321.
 *  pos Ϊ����, vis[] Ϊ�Ѿ�ѡ��������
 *  vis[] �� 0 ������� "�±�" û�б�ѡ���, �����Ǽ�¼�Ǹ���ѡ��.
 *  pos Ϊ����
 */

/** ------��������------
 *  �� 1��n �� n ���������ų�һ�к��������˳��, ���ֵ���������в�ͬ�ķ�����
 * 
 *  ------�����ʽ------
 *  ����һ�У�����һ������������1 <= 8)
 * 
 *  ------�����ʽ------
 *  ��� n! ��, ÿһ��Ϊһ�ַ������ֵ����С��������� 
 */
int n = 0, vis[10] = { 0 }, ans[10] = { 0 };
void dfs(int pos, int n) {
    if (pos > n) {
        // ˵�����ǵĲ����������� n, û�и������ֿ���ѡ��.
        for (int j = 1; j <= n; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (vis[k] == 0) /* ˵���������û��ѡ�� */ {
            ans[pos] = k;
            vis[k] = 1; // ��� k ���λ�ñ�ѡ����
            dfs(pos + 1, n); // ������һ��
            ans[pos] = 0; // ����
            vis[k] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1, n);
    return 0;
}
